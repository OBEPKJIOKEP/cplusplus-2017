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

int main(int argc, const char * argv[]) {
    shared_state<int> ssi;
    shared_state<float> ssf;
    
    future<int> fi;
    future<float> ff;
    
    promise<int> pi;
    promise<float> pf;
    
    std::thread t([&](){
        std::cout << "starting to sleep\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        pi.set(1);
        std::cout << "exiting thread\n";
    });
    std::cout << pi.get_future().get() << std::endl;
    t.join();
}
