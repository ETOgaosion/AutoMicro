#pragma once

#include <mutex>
#include <unordered_map>
#include "omp.h"

namespace lock {

class LockSet {
public:
    LockSet() { locks.clear(); };
    ~LockSet() = default;

    bool try_lock(int index) { 
        mb();
        bool lock_status = false;
        if (locks.size() > index) {
            lock_status = locks[index]->try_lock();
        }
        else {
            #pragma omp critical
            {
                if (locks.size() <= index) {
                    for (int i = locks.size(); i <= index + 1; i++) {
                        locks.push_back(new std::mutex());
                    }
                    mb();
                    lock_status = locks[index]->try_lock();
                    mb();
                }
                else {
                    lock_status = locks[index]->try_lock();
                    mb();
                }
            }
        }
        return lock_status;
    };

    void lock(int index) {
        mb();
        if (locks.size() > index) {
            locks[index]->lock();
        }
        else {
            #pragma omp critical
            {
                if (locks.size() <= index) {
                    for (int i = locks.size(); i <= index + 1; i++) {
                        locks.push_back(new std::mutex());
                    }
                    mb();
                    locks[index]->lock();
                    mb();
                }
                else {
                    locks[index]->lock();
                    mb();
                }
            }
        }
    };

    void unlock(int index) {
        locks[index]->unlock();
        mb();
    };

private:
    std::vector<std::mutex *> locks;

};

};