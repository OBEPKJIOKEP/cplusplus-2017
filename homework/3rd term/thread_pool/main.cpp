//
//  main.cpp
//  ThreadPool
//
//  Created by Greg Pevnev on 07/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <sstream>
#include "thread_pool.hpp"

using std::this_thread::sleep_for;

func sleep(int secs)
{

    return [=]() {
        std::cout << std::string("sleeping for ").append(std::to_string(secs)).append("\n");
        sleep_for(std::chrono::seconds(secs));
        std::cout << std::string("done ").append(std::to_string(secs)).append("\n");
    };
}


int main(int argc, const char * argv[])
{

    thread_pool a(2);

    func sleep1 = sleep(1);
    func sleep2 = sleep(2);
    func sleep3 = sleep(3);
    func sleep15 = sleep(15);


    a.execute(sleep1);
    a.execute(sleep2);
    a.execute(sleep3);
    a.execute(sleep1);
    a.execute(sleep2);
    a.execute(sleep3);
    a.execute(sleep15);
    sleep15();
    a.execute(sleep1);
    return 0;
}


