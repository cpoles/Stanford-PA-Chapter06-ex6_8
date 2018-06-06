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

int main() {
    
    
    
    
    
    return 0;
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
