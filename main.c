//
// Assignment 02: Implement an expression calculator
// Created by weikang on 2021/11/2.
//

/*
 * ./main.c
 * This is the entry point of the program
 * */

#include "parser.h"

void printTestCase(const char* expression, const char* caseName)
{
    const char* n_exp = removeSpaces(expression);  // remove all spaces
    printf("test %s: %s\n", caseName, n_exp);
    struct str_Stack* RPN = reversedPolishNotation(n_exp);
    printf("\tthe reversed polish notation of the original expression:\n\t\t");
    stack_print(RPN);
    printf("\n\tthe solution of the expression is:\n\t\t");
    printf("%s=%lf\n\n",n_exp, parse(RPN));
}

int main() {

    printf("The program support [+,-,*,/,^,%%] and round/square/curly brackets\n\n");

    const char* case_01 = "-3*(-2.5*-7-6.5)";
    const char* case_02 = "2+3.1/2.5*(7-6.3)^3^2";

    printTestCase(case_01, nameOfVar(case_01));
    printTestCase(case_02, nameOfVar(case_02));

    return 0;
}
