//
//  shared_state.hpp
//  Future
//
//  Created by Greg Pevnev on 18/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#ifndef shared_state_hpp
#define shared_state_hpp

#include <condition_variable>
#include <atomic>

using my_bool = std::atomic_bool;

template <typename T>
class shared_state {
public:
    shared_state() = default;
    
    std::mutex m;
    std::condition_variable cv;
    T value;
    my_bool is_ready;
    
    ~shared_state() {
//        std::cout << "shared_state destructor\n";
    }
};

#endif /* shared_state_hpp */
