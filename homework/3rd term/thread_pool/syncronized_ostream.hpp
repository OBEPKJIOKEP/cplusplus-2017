//
//  syncronized_ostream.hpp
//  ThreadPool
//
//  Created by Greg Pevnev on 14/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#pragma once

#include <iostream>
#include <sstream>

class syncronized_ostream {
public:
    explicit syncronized_ostream(std::ostream& os)
        :ostream {os}
    {};
    
    // no copy
    syncronized_ostream(syncronized_ostream&) = delete;
    syncronized_ostream& operator=(syncronized_ostream&) = delete;
    
    // no move
    syncronized_ostream(syncronized_ostream&&) = delete;
    syncronized_ostream& operator=(syncronized_ostream&&) = delete;
    
    template <typename T>
    syncronized_ostream& operator<<(const T& other) {
        std::lock_guard<std::mutex> lk(ostream_mutex);
        ostream << other;
        return *this;
    }
    template <typename ...Args>
    void print_pack(const Args... args) {
        std::stringstream ss;
        build_string(ss, args...);
        *this << ss.str();
    }
    
private:
    std::ostream& ostream;
    std::mutex ostream_mutex;
    
    template <typename Head, typename ...Tail>
    void build_string(std::stringstream& sstream, const Head head, const Tail... tail) {
        sstream << head;
        build_string(sstream, tail...);
    }
    
    void build_string(std::stringstream& sstream) {
        sstream << '\n';
    }
};
