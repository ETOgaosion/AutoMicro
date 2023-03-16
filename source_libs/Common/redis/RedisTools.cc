#include "RedisTools.h"
#include "CommonTypes.grpc.pb.h"

#include <string>
#include "omp.h"
#include <atomic>

#include "barrier.h"

using namespace redis;
using namespace sw::redis;
using namespace ::Common::Types;
using namespace ::cache;

std::string RedisTools::url = "tcp://127.0.0.1:6379";
int RedisTools::cache_size = 100;
std::set<std::string> RedisTools::configured_key = {};
std::map<std::string, int> RedisTools::key_end_num = {};
std::map<std::string, int> RedisTools::key_cur_num = {};
std::map<std::string, std::mutex *> RedisTools::key_num_lock_set = {};
std::map<std::string, int> RedisTools::key_cache_size_map = {};
// std::map<std::string, lru_cache<int, int> *> RedisTools::id_cache = {};
std::map<std::string, std::map<int, BytesListWithStartEnd *>> RedisTools::cache = {};
std::map<std::string, std::mutex *> RedisTools::cache_write_lock_set = {};
std::map<std::string, std::mutex *> RedisTools::cache_read_lock_set = {};
pthread_mutex_t RedisTools::plock;

std::string RedisTools::getUrl() {
    return url;
}

int RedisTools::fetchAfterAdd(std::string key, bool with_batch) {
    int res = 0;
    std::string suffix = "Num";
    auto key_num = key + suffix;
    if (!with_batch) {
        auto redis = Redis(url);
        auto tx = redis.transaction();
        auto r = tx.redis();
        r.watch(key_num);
        auto id_str = redis.get(key_num);
        int id = 1;
        if (id_str.has_value()) {
            id = std::stoi(id_str.value()) + 1;
        }
        tx.set(key_num, std::to_string(id)).exec();
        return id;
    }
    key_num_lock_set[key]->lock();
    if (key_cur_num[key] > key_end_num[key]) {
        auto redis = Redis(url);
        auto tx = redis.transaction();
        auto r = tx.redis();
        r.watch(key_num);
        auto id_str = redis.get(key_num);
        int id = 0;
        if (id_str.has_value()) {
            id = std::stoi(id_str.value());
        }
        id += key_cache_size_map[key];
        tx.set(key_num, std::to_string(id)).exec();
        key_end_num[key] = id;
        key_cur_num[key] = id - key_cache_size_map[key] + 1;
    }
    res = key_cur_num[key]++;
    key_num_lock_set[key]->unlock();
    return res;
}

void RedisTools::configureKey(std::string key, int cache_size) {
    if (configured_key.contains(key)) {
        return;
    }
    #pragma omp critical
    {
        if (!configured_key.contains(key)) {
            key_end_num[key] = 0;
            key_cur_num[key] = 1;
            key_num_lock_set[key] = new std::mutex();
            key_cache_size_map[key] = cache_size;
            // id_cache[key] = new lru_cache<int, int>((size_t)cache_size);
            cache[key] = {};
            cache_write_lock_set[key] = new std::mutex();
            cache_read_lock_set[key] = new std::mutex();
            configured_key.insert(key);
        }
    }
}

void RedisTools::finishKey(std::string key) {
        key_cur_num[key] = key_end_num[key] + 1;
}

void RedisTools::hset(std::string key, std::string id, std::string value) {
    auto redis = Redis(url);
    redis.hset(key, id, value);
}

void RedisTools::hset(std::string key, unsigned long id, std::string value, bool with_batch) {
    if (with_batch) {
        if (id == 0) {
            throw std::runtime_error("id must > 0");
        }
        // if (key_end_num.contains(key)) {
        auto cache_size = key_cache_size_map[key];
        auto index = (id - 1)/cache_size;
        auto offset = (id - 1) % cache_size;
        // Critical area
        cache_write_lock_set[key]->lock();
        // index has been created
        if (cache[key].contains(index)) {
            auto cache_line = cache[key][index];
            // bl list size matched
            if (cache_line->bl_size() > offset) {
                cache_line->set_bl(offset, value);
                cache_line->set_counter(cache_line->counter() + 1);
                if (cache_line->counter() < cache_size) {
                    cache_write_lock_set[key]->unlock();
                    return;
                }
            }
            // bl size too small, need to resize
            else if (cache_line->bl_size() <= offset) {
                for (int i = cache_line->bl_size(); i < offset; i++) {
                    cache_line->add_bl("");
                }
                cache_line->add_bl(value);
                cache_line->set_counter(cache_line->counter() + 1);
                if (cache_line->counter() < cache_size) {
                    cache_write_lock_set[key]->unlock();
                    return;
                }
            }
            if (cache_line->counter() == cache_size) {
                cache_line->set_end(cache_line->start() + cache_size);
                auto redis = Redis(url);
                redis.hset(key + "Batch", std::to_string(index), cache_line->SerializeAsString());
                cache_write_lock_set[key]->unlock();
                return;
            }
        }
        else {
            cache[key][index] = new BytesListWithStartEnd();
            auto cache_line = cache[key][index];
            cache_line->set_start(index * cache_size + 1);
            cache_line->set_end(0);
            cache_line->set_counter(1);
            cache_line->clear_bl();
            for (int i = 0; i < offset; i++) {
                cache_line->add_bl("");
            }
            cache_line->add_bl(value);
        }
        cache_write_lock_set[key]->unlock();
    }
    else {
        auto redis = Redis(url);
        redis.hset(key, std::to_string(id), value);
    }
}

void RedisTools::pushSlice(std::string key, int end_num) {
    auto cache_size = key_cache_size_map[key];
    auto index = (end_num - 1)/cache_size;
    if (cache[key].contains(index)) {
        cache[key][index]->set_end(end_num);
        auto redis = Redis(url);
        redis.hset(key + "Batch", std::to_string(index), cache[key][index]->SerializeAsString());
        // if (!id_cache[key]->find(index)) {
            cache[key].erase(index);
        // }
    }
}

void RedisTools::pushSlices(std::string key) {
    for (auto it : cache[key]) {
        if (/* !id_cache[key]->find(it.first) && */it.second->counter() < key_cache_size_map[key]) {
            cache[key][it.first]->set_end(cache[key][it.first]->start() + cache[key][it.first]->bl_size());
            auto redis = Redis(url);
            redis.hset(key + "Batch", std::to_string(it.first), cache[key][it.first]->SerializeAsString());
            cache[key].erase(it.first);
        }
    }
}

std::string RedisTools::hget(std::string key, unsigned long id, bool with_batch) {
    if (with_batch) {
        if (id == 0) {
            throw std::runtime_error("in batch id must > 0");
        }
        auto cache_size = key_cache_size_map[key];
        auto index = (id - 1)/cache_size;
        auto offset = (id - 1) % cache_size;
        // Critical area
        cache_read_lock_set[key]->lock();
        if (cache[key].contains(index)) {
            auto ret = cache[key][index]->bl(offset);
            cache_read_lock_set[key]->unlock();
            return ret;
        }
        else {
            auto redis = Redis(url);
            cache[key][index] = new BytesListWithStartEnd();
            cache[key][index]->ParseFromString(redis.hget(key + "Batch", std::to_string(index)).value());
            auto ret = cache[key][index]->bl(offset);
            cache_read_lock_set[key]->unlock();
            return ret;
        }
    }
    else {
        auto redis = Redis(url);
        if (redis.hget(key, std::to_string(id)).has_value()) {
            return redis.hget(key, std::to_string(id)).value();
        }
        else {
            return {};
        }
    }
}

std::string RedisTools::hget(std::string key, std::string id) {
    auto redis = Redis(url);
    if (redis.hget(key, id).has_value()) {
        return redis.hget(key, id).value();
    }
    else {
        return {};
    }
}
