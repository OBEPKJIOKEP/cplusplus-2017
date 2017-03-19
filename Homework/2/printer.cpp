//
//  printer.cpp
//  ASCII Printer
//
//  Created by Greg Pevnev on 16/03/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include "printer.hpp"

void Printer::putCharacter(char c)
{
    line.push_back(c);
}

void Printer::putInteger(int i)
{
    string number;
    if(i < 0)
    {
        putCharacter('-');
        i *= -1;
    }
    if( i == 0)
    {
        putCharacter('0');
    }
    while (i != 0)
    {
        number.push_back('0' + (i % 10));
        i /= 10;
    }
    reverse(number.begin(), number.end());
    line.append(number);
}

void Printer::print()
{
    vector<string> ASCII = translateToASCII();
    for(int j = 0; j < ASCII_HEIGHT; ++j)
    {
        cout << ASCII[j] << endl;
    }
    
}

void Printer::clear()
{
    line.clear();
}

vector<string> Printer::translateToASCII()
{
    vector<string> result(ASCII_HEIGHT);
    for(int i = 0; i < ASCII_HEIGHT; ++i)
    {
        for(size_t j = 0; j < line.size(); ++j)
        {
            
            int letNumber;
            switch(line[j])
            {
                case '+':
                    letNumber = 10;
                    break;
                    
                case '-':
                    letNumber = 11;
                    break;
                    
                case '(':
                    letNumber = 12;
                    break;
                    
                case ')':
                    letNumber = 13;
                    break;
                    
                case '*':
                    letNumber = 14;
                    break;
                
                case '/':
                    letNumber = 15;
                    break;
                    
                    
                    default:
                    letNumber = line[j] - '0';
            }
            result[i].append(symbols[letNumber][i]);
        }
    }
    return result;
}



