//
//  Calculator.hpp
//  CalculatorASCII
//
//  Created by Greg Pevnev on 16/03/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//
#pragma once

#include "printer.hpp"

class Calculator
{
private:
    Printer printer;
    
public:
    Calculator(string s)
    {
        printer.putExpression(s);
    }
    
    void putCharacter(char c)
    {
        printer.putCharacter(c);
    }
    
    void putLongLong(long long i)
    {
        printer.putLongLong(i);
    }
    
    void printExpression()
    {
        printer.print();
    }
    
    long long calculate();
};

long long parseNumber(string&);

long long parseAddSub(string&);

long long parseMulDiv(string&);

long long parseBracket(string&);

long long parseBinomialCoefficient(string &);

long long nChooseK(long long, long long);
