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

//std::mutex io_mutex;


class thread_pool
{
public:
    thread_pool(std::size_t);
    
    thread_pool(thread_pool&);
    
    thread_pool& operator=(thread_pool&);
    
    void execute(const func&);
    
    ~thread_pool();
    
private:
    std::vector<thread> threads;
    std::queue<func> funcs;
    std::condition_variable cv;
    std::mutex m;
    bool running = true;
};
