//
//  printer.hpp
//  ASCII Printer
//
//  Created by Greg Pevnev on 16/03/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define ASCII_HEIGHT 6
using namespace std;

const vector<vector<string>> symbols = {
    {"### ", "# # ", "# # ", "# # ", "### ", "    "}, {" #  ", "##  ", " #  ", " #  ", "### ", "    "},
    {"### ", "  # ", "### ", "#   ", "### ", "    "}, {"### ", "  # ", " ## ", "  # ", "### ", "    "},
    {"# # ", "# # ", "### ", "  # ", "  # ", "    "}, {"### ", "#   ", "### ", "  # ", "### ", "    "},
    {"### ", "#   ", "### ", "# # ", "### ", "    "}, {"### ", "  # ", "  # ", "  # ", "  # ", "    "},
    {"### ", "# # ", "### ", "# # ", "### ", "    "}, {"### ", "# # ", "### ", "  # ", "### ", "    "},
    {"    ", " #  ", "### ", " #  ", "    ", "    "}, {"    ", "    ", "### ", "    ", "    ", "    "},
    {"  # ", " #  ", " #  ", " #  ", "  # ", "    "}, {"#   ", " #  ", " #  ", " #  ", "#   ", "    "},
    {"    ", "    ", " #  ", "    ", "    ", "    "}, {"  # ", "  # ", " #  ", "#   ", "#   ", "    "},
    {" ## ", "#   ", "#   ", "#   ", "#   ", " ## "}
};

class Printer
{
private:
    string expression;

    vector<string> translateToASCII();

    int getMaxNested(int&, int);

    bool expressionChecker(int &);

    void printLine(vector<string>& field, int& currentPosition, int beginLineNumber, int multiplier);
public:
    string getExpression()
    {
        return expression;
    }

    void putCharacter(char);
    
    void putLongLong(long long);
    
    void putExpression(string);
    
    void print();
    
};


