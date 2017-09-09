//
//  Calculator.cpp
//  CalculatorASCII
//
//  Created by Greg Pevnev on 16/03/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include "Calculator.hpp"

long long parseNumber(string& rest)
{
    long long i = 0, number = 0;
    if(rest[0] == ',')
        return 0;
    bool isNegative = false;
    if(rest[0] == '-')
    {
        isNegative = true;
        rest = rest.substr(1);
    }
    while(i < rest.length() && rest[i] >= '0' && rest[i] <= '9')
        number = number * 10 + (rest[i++] - '0');
    if(i == 0)
    {
        cout << "Incorrect expression!" << endl;
        exit(1);
    }
    rest = rest.substr(i);
    return isNegative ? -number : number;
}

long long parseAddSub(string& rest)
{
    long long current = parseMulDiv(rest), acc  = current;
    while(rest.length() > 0)
    {
        char operation = rest[0];
        if (operation != '+' && operation != '-')
            break;
        current = parseMulDiv(rest = rest.substr(1));
        if (operation == '+' )
            acc += current;
        else
            acc -= current;
    }
    return acc;
}

long long parseBracket(string& rest)
{
    if(rest[0] == '(')
    {
        long long result = parseAddSub(rest = rest.substr(1));
                if(rest.length() == 0 || rest[0] != ')')
        {
            cout << "Incorrect expression!" << endl;
            exit(1);
        }
        rest = rest.substr(1);
        return result;
    }
    return parseBinomialCoefficient(rest);
}

long long parseMulDiv(string& rest)
{
    long long current = parseBracket(rest), acc = current;
    while(true)
    {
        if(rest.length() == 0)
            return current;
        char operation = rest[0];
        if(operation != '*' && operation != '/')
            return current;
        long long right = parseBracket(rest = rest.substr(1));
        if(operation == '*')
            acc *= right;
        else {
            if(right == 0)
            {
                cout << "Zero division!" << endl;
                exit(1);
            }
            acc /= right;
        }
        current = acc;
    }
}

long long parseBinomialCoefficient(string &rest)
{
    if(rest[0] == 'c' || rest[0] == 'C')
    {
        if(rest[1] != '(')
        {
            cout << "Incorrect expression!" << endl;
            exit(1);
        }
        rest = rest.substr(2);
        long long n = parseAddSub(rest);
        rest = rest.substr(1);
        long long k = parseAddSub(rest);
        rest = rest.substr(1);
        if(n < k)
            return 0;
        return nChooseK(n, k);
    }
    return parseNumber(rest);
}

long long nChooseK(long long n, long long k)
{
    double result = 1;
    for(long long i = 1; i <= k; ++i)
        result *= (n - k + i) / i;

    return static_cast<long long>(result + 0.01);
}

long long Calculator::calculate()
{
    string rest = printer.getExpression();
    long long result = parseAddSub(rest);
    if(rest.size() != 0)
    {
        cout << "Incorrect expression!" << endl;
        exit(1);
    }
    return result;
}
