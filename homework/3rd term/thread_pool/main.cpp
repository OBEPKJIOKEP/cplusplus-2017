//
//  main.cpp
//  ThreadPool
//
//  Created by Greg Pevnev on 07/09/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "thread_pool.hpp"
#include "syncronized_ostream.hpp"

syncronized_ostream s_cout(std::cout);

func sleep(int secs) {
    using namespace std;
    using this_thread::sleep_for;
    
    return [secs]() {
        s_cout.print_pack("sleeping for ", secs, '\n');
        sleep_for(chrono::seconds(secs));
        s_cout.print_pack("done ", secs, '\n');
    };
}


int main(int argc, const char * argv[]) {
    thread_pool a(3);

    func sleep1 = sleep(1);
    func sleep2 = sleep(2);
    func sleep3 = sleep(3);
    func sleep15 = sleep(15);
    
    for (int i = 0; i < 10; ++i) {
        a.execute(sleep1);
    }

//
//    a.execute(sleep1);
//    a.execute(sleep2);
//    a.execute(sleep3);
//    a.execute(sleep1);
//    a.execute(sleep2);
//    a.execute(sleep3);
//    a.execute(sleep15);
    sleep15();
//    a.execute(sleep1);
    return 0;
}


