//
//  promise.hpp
//  Future
//
//  Created by Greg Pevnev on 18/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#ifndef promise_hpp
#define promise_hpp

#include <memory>

#include "shared_state.hpp"
#include "future.hpp"

template <typename T>
class promise {
public:
    // TODO
    promise() :_state {new shared_state<T>()} {};
    
    void set(const T &);
//    void set(const T &&);
    
    future<T> get_future();
    
    ~promise() {
//        std::cout << "promise destructor\n";
    }
    
private:
    std::shared_ptr<shared_state<T>> _state;
};

template <typename T>
void promise<T>::set(const T & value) {
    if (_state->is_ready)
        throw std::runtime_error("value already set");
    {
        std::lock_guard<std::mutex> lk(_state->m);
        _state->value = value;
    }
    _state->is_ready = true;
    _state->cv.notify_one();
}

template <typename T>
future<T> promise<T>::get_future() {
    return future<T>(_state);
}

#endif /* promise_hpp */
