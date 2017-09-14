        //
//  thread_pool.cpp
//  ThreadPool
//
//  Created by Greg Pevnev on 07/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include "thread_pool.hpp"
#include <iostream>
#include "syncronized_ostream.hpp"

thread_pool::thread_pool(std::size_t size) :running {true} {
    if (size == 0)
        throw std::invalid_argument("nothing to do without threads");
    
    for (std::size_t i = 0; i < size; ++i)
        threads.emplace_back(&thread_pool::run, this);
}

void thread_pool::execute(const func& task) {
    std::lock_guard<std::mutex> lk(m);
    funcs.push(task);
    cv.notify_one();
}

void thread_pool::run() {
//    s_cout << "thread started\n";
    do {
        func current_func;
        {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this](){ return !(running && funcs.empty()); });
            if (funcs.empty())
                break;
            current_func = funcs.front();
            funcs.pop();
        }
        current_func();
    } while (running);
//    s_cout << "thread finished\n";
}

thread_pool::~thread_pool() {
    running = false;
    
    cv.notify_all();
    
    for (auto& t: threads)
        t.join();
}


