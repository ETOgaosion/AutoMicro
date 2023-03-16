#pragma once

#include <vector>
#include <map>
#include <set>
#include <sw/redis++/redis++.h>
#include <mutex>
#include <pthread.h>

#include "lrucache.h"
// #include "lock.h"
#include "CommonTypes.grpc.pb.h"

namespace redis {

class RedisCacheLine {
public:
    RedisCacheLine() { start = 1; end = 0; data = {}; }
    ~RedisCacheLine() = default;
    int start;
    int end;
    std::map<int, std::string> data;

    void set_data(int key, std::string value) { data[key] = value; };
    std::string get_data(int key) { return data[key]; };
    int size() { return data.size(); };

private:
};

class RedisTools
{
private:
    /* data */
    static std::string url;
    static int cache_size;
    static std::set<std::string> configured_key;
    static std::map<std::string, int> key_end_num;
    static std::map<std::string, int> key_cur_num;
    static std::map<std::string, std::mutex *> key_num_lock_set;
    static std::map<std::string, int> key_cache_size_map;
    // static std::map<std::string, cache::lru_cache<int, int> *> id_cache;
    static std::map<std::string, std::map<int, ::Common::Types::BytesListWithStartEnd *>> cache;
    static std::map<std::string, std::mutex *> cache_write_lock_set;
    static std::map<std::string, std::mutex *> cache_read_lock_set;
    static pthread_mutex_t plock;

public:
    static std::string getUrl();
    static int fetchAfterAdd(std::string key, bool with_batch);
    static void configureKey(std::string key, int cache_size);
    static void finishKey(std::string key);
    static void hset(std::string key, std::string id, std::string value);
    static void hset(std::string key, unsigned long id, std::string value, bool with_batch);
    static void pushSlice(std::string key, int end_num);
    static void pushSlices(std::string key);
    static std::string hget(std::string key, unsigned long id, bool with_batch);
    static std::string hget(std::string key, std::string id);
};
}
