//
//  main.cpp
//  Future
//
//  Created by Greg Pevnev on 17/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include <iostream>
#include <thread>

#include "shared_state.hpp"
#include "future.hpp"
#include "promise.hpp"
#include "../../ThreadPool/ThreadPool/syncronized_ostream.hpp"

syncronized_ostream s_cout(std::cout);

int main(int argc, const char * argv[]) {
    promise<int> pi;
    promise<float> pf;
    
    std::thread t0([&](){
        s_cout << "starting to sleep\n";
        std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(2));
        pi.set(1);
        s_cout << "exiting thread\n";
    });
    std::thread t1([&](){
        s_cout << "starting to sleep\n";
        std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(2));
        pi.set(1);
        s_cout << "exiting thread\n";
    });
    std::cout << pi.get_future().get() << std::endl;
    t0.join();
    t1.join();
}
