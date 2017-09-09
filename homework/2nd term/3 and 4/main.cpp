//
//  main.cpp
//  CalculatorASCII
//
//  Created by Greg Pevnev on 16/03/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include "Calculator.hpp"

int main(int argc, const char * argv[]) {
    string expr;
    Printer p;
    getline(cin, expr);
    Calculator c(expr);
    long long answer;
    try {
        answer = c.calculate();
    }
    catch (exception e)
    {
        cout << "Incorrect expression!" << endl;
        exit(1);
    }
    cout << answer << endl;
    p.putLongLong(answer);
    c.printExpression();
    cout << endl;
    p.print();
    return 0;
}
