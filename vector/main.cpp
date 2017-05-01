//
//  main.cpp
//  vector
//
//  Created by Greg Pevnev on 22/04/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "vector.hpp"

vector<int> my(5);

void push_pop_test()
{
    for (int i = 0; i < 100; ++i)
    {
        for(int j = 0; j < 100000; ++j)
            my.push_back(i);
        for(int j = 0; j < 100000; ++j)
            my.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    push_pop_test();
    vector<int> a(my);
    return 0;
}
