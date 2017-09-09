//
//  main.cpp
//  ThreadPool
//
//  Created by Greg Pevnev on 07/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include <iostream>
#include "thread_pool.hpp"

void f()
{
    auto a = (struct timespec){.tv_sec=2};
    nanosleep(&a, NULL);
    {
        //std::lock_guard<std::mutex> lg(io_mutex);
        std::cout << "done\n";
    }
    
}

int main(int argc, const char * argv[]) {
    thread_pool a(3);
    a.execute(f);
    a.execute(f);
    a.execute(f);
    a.execute(f);
    return 0;
}


