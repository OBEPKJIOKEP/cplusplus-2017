//
//  thread_pool.hpp
//  ThreadPool
//
//  Created by Greg Pevnev on 07/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#pragma once

#include <cstdlib>
#include <functional>
#include<queue>
#include <vector>
#include <thread>

typedef std::function<void()> func;
using std::thread;

class thread_pool {
public:
    explicit thread_pool(std::size_t);
    
    // no copy
    thread_pool(const thread_pool&) = delete;
    thread_pool& operator=(const thread_pool&) = delete;

    // no move
    thread_pool(thread_pool&&) =delete;
    thread_pool& operator=(thread_pool&&) = delete;
    
    void execute(const func&);
    
    ~thread_pool();
    
private:
    std::vector<thread> threads;
    std::queue<func> funcs;
    std::condition_variable cv;
    std::mutex m;
    std::atomic_bool running;
    
    void run();
};
