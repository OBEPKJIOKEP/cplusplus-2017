//
//  main.cpp
//  ASCII Printer
//
//  Created by Greg Pevnev on 16/03/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include "printer.hpp"

int main(int argc, const char * argv[]) {
    Printer p;
    p.putCharacter('(');
    p.putInteger(1234567890);
    p.putCharacter('+');
    p.putCharacter('-');
    p.putCharacter(')');
    p.print();
    return 0;
}
