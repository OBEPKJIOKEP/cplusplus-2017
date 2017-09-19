//
//  future.hpp
//  Future
//
//  Created by Greg Pevnev on 18/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#ifndef future_hpp
#define future_hpp

#include <memory>

#include "shared_state.hpp"

template <typename T>
class promise;

template <typename T>
class future {
public:
    // no copy
    future(future &) = delete;
    future& operator=(future &) = delete;
    
    // move is allowed
    future(future &&) = default;
    future& operator=(future &&) = default;
    
    T get() const;
    
    void wait() const;
    
    bool ready() const;
    
private:
    friend class promise<T>;
    
    explicit future(std::shared_ptr<shared_state<T>> state) :_state {state} {};
    
    std::shared_ptr<shared_state<T>> _state;
};

// get general template
template <typename T>
T future<T>::get() const {
    wait();
    return _state->value;
}

// get() patrial specialization for void
template<>
void future<void>::get() const {
    wait();
}

template <typename T>
void future<T>::wait() const {
    if (!_state)
        throw std::runtime_error("future invalidated");
    
    if (_state->is_ready)
        return;
    std::unique_lock<std::mutex> lk(_state->m);
    _state->cv.wait(lk);
}

template <typename T>
bool future<T>::ready() const {
    return _state->is_ready.load();
}

#endif /* future_hpp */
