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
    if(c == ' ')
        return;
    expression.push_back(c);
}

void Printer::putLongLong(long long i)
{
    string number;
    if(i == 0)
    {
        expression.push_back('0');
        return;
    }
    bool isNegative = false;
    if(i < 0)
    {
        isNegative = true;
        i *= -1;
    }
    while (i != 0)
    {
        number.push_back('0' + (i % 10));
        i /= 10;
    }
    reverse(number.begin(), number.end());
    if(isNegative)
        number = '-' + number;
    expression.append(number);
}

void Printer::putExpression(string s)
{
    for (int i = 0; i < s.length(); ++i)
            putCharacter(s[i]);
}

int Printer::getMaxNested(int& i, int currentNested)
{
    if (expression[i] == ')' || expression[i] == ',')
    {
        i++;
        return currentNested;
    }
        if (expression[i] == 'C' || expression[i] == 'c') {
            ++++i;
            int n = getMaxNested(i, 2 * currentNested);
            int k = getMaxNested(i, 2 * currentNested);
            return max(n, k);
        } else {
            i++;
            getMaxNested(i, currentNested);
        }
    return currentNested;
}

void printSymbol(vector<string>& field, int letterNumber, int beginLineNumber, int multiplier) {
    for(int i = 0; i < ASCII_HEIGHT * multiplier; ++i)
    {
        field[beginLineNumber + i].append(symbols[letterNumber][i / multiplier]);
    }
}

void Printer::printLine(vector<string>& field, int& currentPosition, int beginLineNumber, int multiplier)
{
    while(currentPosition < expression.length()) {
        if(expression[currentPosition] == ',' ||  expression[currentPosition] == ')')
            return;
        int letNumber = -1;
        switch (expression[currentPosition])
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
            case 'c':
            case 'C':
            case ',':
                break;


            default:
                letNumber = expression[currentPosition] - '0';
        }
        if (letNumber != -1)
        {
            printSymbol(field, letNumber, beginLineNumber, multiplier);
            currentPosition++;
        }
        else {
            if (expression[currentPosition] == 'c' || expression[currentPosition] == 'C') {
                printSymbol(field, 16, beginLineNumber, multiplier);
                printLine(field, ++++currentPosition, beginLineNumber + ASCII_HEIGHT * multiplier / 2, multiplier / 2);
                printLine(field, ++currentPosition, beginLineNumber, multiplier / 2);
                int maximum = 0;
                for (int i = beginLineNumber; i < beginLineNumber + ASCII_HEIGHT * multiplier; ++i)
                {
                    maximum = max(maximum, static_cast<int>(field[i].size()));
                }
                for (int i = beginLineNumber; i < beginLineNumber + ASCII_HEIGHT * multiplier; ++i)
                {
                    int current = field[i].length();
                    while (current++ < maximum)
                    {
                        field[i].push_back(' ');
                    }
                }
                currentPosition++;
            }
        }
    }
}

vector<string> Printer::translateToASCII()
{
    int i = 0;
    i = 0;
    int currentZoom = getMaxNested(i, 1);
    vector<string> result(ASCII_HEIGHT * currentZoom);
    i = 0;
    printLine(result, i, 0, currentZoom);
    return result;
}

void Printer::print()
{
    vector<string> ASCII = translateToASCII();
    for(int i = 0; i < ASCII.size(); ++i)
    {
        cout << ASCII[i] << endl;
    }
    
}



