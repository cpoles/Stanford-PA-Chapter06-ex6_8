//
//  main.cpp
//  ex6_8
//
//  Created by Carlos Poles on 6/6/18.
//  Copyright © 2018 Carlos Poles. All rights reserved.
//

/*
 Reimplement the RPN calculator from Figure 5-4 so that it performs its
 internal calculations using rational instead of floating-point numbers.
*/

#include <iostream>
#include <cctype>
#include <string>
#include "error.h"
#include "stack.h"
#include "strlib.h"
#include "rational.hpp"

/* Function prototypes */
void applyOperator(char op, Stack<Rational> & operandStack);
void helpCommand();
Rational stringToRational(std::string line);

int main() {
    std::cout << "RPN Calculator Simulation (type H for help)" << std::endl;
    Stack<Rational> operandStack;;
    while (true) {
        std::cout << "> ";
        std::string line;
        getline(std::cin, line);
        if (line.length() == 0) line = "Q";
        char ch = toUpperCase(line[0]);
        if (ch == 'Q') {
            break;
        } else if (ch == 'C') {
            operandStack.clear();
        } else if (ch == 'H') {
            helpCommand();
        } else if (isdigit(ch)) {
            operandStack.push(stringToRational(line));
        } else {
            applyOperator(ch, operandStack);
        }
    }
    return 0;
}

/*
 Function: applyOperator
 Usage: applyOperator(ap, operandStack);
 ---------------------------------------
 This function applies the operator to the top two elements
 on the operand stack. Because the elements on the stack are popped
 in reverse order, the right operand is popped before the left operand.
 */
void applyOperator(char op, Stack<Rational> & operandStack) {
    Rational result;
    Rational rhs = operandStack.pop();
    Rational lhs = operandStack.pop();
    
    switch (op) {
        case '+':
            result = lhs + rhs; break;
        case '-':
            result = lhs + rhs; break;
        case '*':
            result = lhs * rhs; break;
        case '/':
            result = lhs / rhs; break;
        default:
            error("Illegal operator.");
    }
    std::cout << result << std::endl;
    operandStack.push(result);
}

/*
 Function: helpCommand
 Usage: helpCommand();
 ---------------------
 This function generates a help message for the user
*/

void helpCommand() {
    std::cout << "Enter expressions in Reverse Polish Notation," << std::endl;
    std::cout << "in which operators follow the operands to which" << std::endl;
    std::cout << "the apply. Each line consists of a number, an" << std::endl;
    std::cout << "operator, or one of the following commands: " << std::endl;
    
    std::cout << "  Q -- Quit the program" << std::endl;
    std::cout << "  H -- Display this help message" << std::endl;
    std::cout << "  C -- Clear the calculator stack" << std::endl;
}


/*
 Function: stringToRational
 Usage: Rational rat = stringToRational(line);
 ---------------------
 This function converts a valid line into a Rational number
 */
Rational stringToRational(std::string line) {
    int ratNum;
    int ratDen;
    std::string divisor = "/";
    std::string::size_type divIndex;
    if ((divIndex = line.find(divisor)) != std::string::npos) {
        ratNum = stringToInteger(line.substr(0, divIndex));
        ratDen = stringToInteger(line.substr(divIndex + 1, line.length() - divIndex));
    } else {
        ratNum = stringToInteger(line);
        ratDen = 1;
    }
    return Rational(ratNum, ratDen);
}
