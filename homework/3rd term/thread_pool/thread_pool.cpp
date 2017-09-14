//
//  thread_pool.cpp
//  ThreadPool
//
//  Created by Greg Pevnev on 07/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include "thread_pool.hpp"
#include <iostream>

thread_pool::thread_pool(std::size_t size)
{
    if (size == 0)
        throw std::invalid_argument("nothing to do without threads");
    
    running = true;
    
    for (std::size_t i = 0; i < size; ++i)
        threads.push_back(thread(&thread_pool::run, this));
}

void thread_pool::execute(const func& task)
{
    std::lock_guard<std::mutex> lk(m);
    funcs.push(task);
    cv.notify_one();
}

void thread_pool::run()
{
    std::cout << "thread started\n";
    do {
        func current_func;
        {
            std::unique_lock<std::mutex> lk(m);
            while (running && funcs.empty())
                cv.wait(lk);
            if (funcs.empty())
                break;
            current_func = funcs.front();
            funcs.pop();
        }
        current_func();
    } while (running);
    std::cout << "thread finished\n";
}

thread_pool::~thread_pool()
{
    running = false;
    
    cv.notify_all();
    
    for (auto& t: threads)
    {
        t.join();
    }
}


