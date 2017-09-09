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
    for (std::size_t i = 0; i < size; ++i)
    {
        threads.push_back(thread([this]()
        {
            {
                //std::lock_guard<std::mutex> lg(m);
                std::cout << "thread " << std::this_thread::get_id() << " started\n";
            }
            while (true)
            {
                std::unique_lock<std::mutex> lk(m);
                if (funcs.empty())
                {
                    if (running)
                        cv.wait(lk);
                    else
                    {
                        std::cout << "done thread" << std::endl;
                        return;
                    }
                }
                auto current_func = funcs.front();
                funcs.pop();
                lk.unlock();
                current_func();
            }
        }
        ));
        
    }
}

void thread_pool::execute(const func& task)
{
    {
        std::lock_guard<std::mutex> lk(m);
        funcs.push(task);
    }
    cv.notify_one();
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


