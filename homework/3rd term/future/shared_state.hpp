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

using synced_bool = std::atomic_bool;

template <typename T>
struct shared_state {
    shared_state() = default;
    
    std::mutex m;
    std::condition_variable cv;
    T value;
    synced_bool is_ready;
};

template <>
struct shared_state<void> {
    shared_state() = default;
    
    std::mutex m;
    std::condition_variable cv;
    synced_bool is_ready;
};

#endif /* shared_state_hpp */
