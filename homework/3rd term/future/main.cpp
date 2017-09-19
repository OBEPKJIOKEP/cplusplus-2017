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
    
    promise<void> pv;
    
//    auto vf = pv.get_future();
    
    std::thread t0 {[&](){
        s_cout.print_pack("starting to sleep");
        std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(2));
        auto f = pv.get_future();
        
        auto f1 = std::move(f);
        f1.get();
        s_cout.print_pack("exiting thread");
    }};
    std::thread t1 {[&](){
        s_cout.print_pack("starting to sleep");
        std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(2));
//        pv.get_future();
        s_cout.print_pack("exiting thread");
    }};
//    auto pv2 {std::move(pi)};
    pv.set();
    std::cout << pi.get_future().get() << std::endl;
    t0.join();
    t1.join();
}
