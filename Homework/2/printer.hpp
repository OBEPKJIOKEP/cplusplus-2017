//
//  printer.hpp
//  ASCII Printer
//
//  Created by Greg Pevnev on 16/03/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//
#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define ASCII_HEIGHT 7
using namespace std;

const vector<vector<string>> symbols = {
    {"   ___  ",
     "  / _ \\ ",
     " | | | |",
     " | | | |",
     " | |_| |",
     "  \\___/ ",
     "        "},
                    {"  __ ",
                     " /_ |",
                     "  | |",
                     "  | |",
                     "  | |",
                     "  |_|",
                     "     "},
                                {"  ___  ",
                                 " |__ \\ ",
                                 "    ) |",
                                 "   / / ",
                                 "  / /_ ",
                                 " |____|",
                                 "       "},
                                                {"  ____  ",
                                                 " |___ \\ ",
                                                 "  __) | ",
                                                 " |__ <  ",
                                                 "  ___)| ",
                                                 " |____/ ",
                                                 "        "},
                                                                {"  _  _   ",
                                                                 " | || |  ",
                                                                 " | || |_ ",
                                                                 " |__   _|",
                                                                 "    | |  ",
                                                                 "    |_|  ",
                                                                 "         "},
                                                                                {"  _____ ",
                                                                                 " | ____|",
                                                                                 " | |__  ",
                                                                                 " |___ \\ ",
                                                                                 "  ___) |",
                                                                                 " |____/ ",
                                                                                 "        "},
                                                                                                {"    __  ",
                                                                                                 "   / /  ",
                                                                                                 "  / /_  ",
                                                                                                 " | '_ \\ ",
                                                                                                 " | (_) |",
                                                                                                 "  \\___/ ",
                                                                                                 "        "},
    {"  ______ ",
     " |____  |",
     "     / / ",
     "    / /  ",
     "   / /   ",
     "  /_/    ",
     "         "},
                    {"   ___  ",
                     "  / _ \\ ",
                     " | (_) |",
                     "  > _ < ",
                     " | (_) |",
                     "  \\___/ ",
                     "        "},
                                    {"   ___  ",
                                     "  / _ \\ ",
                                     " | (_) |",
                                     "  \\__, |",
                                     "    / / ",
                                     "   /_/  ",
                                     "        "},
                                                    {"        ",
                                                     "    _   ",
                                                     "  _| |_ ",
                                                     " |_   _|",
                                                     "   |_|  ",
                                                     "        ",
                                                     "        "},
                                                                    {"         ",
                                                                     "         ",
                                                                     "  ______ ",
                                                                     " |______|",
                                                                     "         ",
                                                                     "         ",
                                                                     "         "},
                                                                                    {"   __",
                                                                                     "  / /",
                                                                                     " | | ",
                                                                                     " | | ",
                                                                                     " | | ",
                                                                                     " | | ",
                                                                                     "  \\_\\"},
                                                                                                {" __  ",
                                                                                                 " \\ \\ ",
                                                                                                 "  | |",
                                                                                                 "  | |",
                                                                                                 "  | |",
                                                                                                 "  | |",
                                                                                                 " /_/ "},
    {"     _     ",
     "  /\\| |/\\  ",
     "  \\ ` ' /  ",
     " |_     _| ",
     "  / , . \\  ",
     "  \\/|_|\\/  ",
     "           "},
                            {"      __ ",
                             "     / / ",
                             "    / /  ",
                             "   / /   ",
                             "  / /    ",
                             " /_/     ",
                             "         "}
};

class Printer
{
private:
    string line;
    
    vector<string> translateToASCII();
    
public:
    void putCharacter(char);
    
    void putInteger(int);
    
    void print();
    
    void clear();
};


