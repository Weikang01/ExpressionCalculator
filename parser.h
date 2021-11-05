//
// Assignment 02: Implement an expression calculator
// Created by weikang on 2021/11/2.
//

/*
 * ./parser.h
 * This is the main algorithm of the program
 * reversedPolishNotation(expression): takes a string of expression and convert it into a stack of string
 * parse(RPN): takes an RPN stack and calculate the solution
 * */

#ifndef ASSIGN02_PARSER_H
#define ASSIGN02_PARSER_H

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include "RPN.h"
#include "operator.h"

const char leftBrackets[] = "([{";
const char rightBrackets[] = ")]}";

// remove spaces
char* removeSpaces(const char *str)
{
    int count = 0;
    char* cur = (char*) str;
    while (strlen(cur))
    {
        if (*cur != ' ')
            count ++;
        cur++;
    }

    char* n_str = ALLOC_ARR(char, count + 1);

    for (int i = 0, k = 0; str[i] != '\0'; i++)
        if (str[i] != ' ')
            n_str[k++] = str[i]; // here count is
    n_str[count] = '\0';
    return  n_str;
}

// convert char to char*
string charToString(char ch)
{
    char *c = ALLOC_ARR(char, 2);
    c[0] = ch;
    c[1] = '\0';
    return c;
}

// check if char is between '0' to '9', or '.'/'-' if accept decimal and negative number respectively
bool isNumber_char(const char c, bool* acceptDecimal, bool* acceptNegative, bool firstChar)
{
    if (c == '.' && *acceptDecimal)
    {
        *acceptDecimal = false;
        return true;
    }
    else if (c == '-' && firstChar && *acceptNegative)
    {
        *acceptNegative = false;
        return true;
    }
    else return c >= '0' && c <= '9';
}

// check if the entire string is a number
bool isNumber_str(const char* str)
{
    char* cur = (char*)str;
    bool acceptDecimal = true;
    bool acceptNegative = true;
    bool firstChar = true;
    while (strlen(cur))
    {
        if (!isNumber_char(*cur, &acceptDecimal, &acceptNegative, firstChar))
            return false;
        if (*cur == '-')
            if (!strlen(cur+1)|| !isNumber_char(*(cur+1), &acceptDecimal, false, firstChar))
            {
                return false;
            }
        firstChar = false;
        cur++;
    }
    return true;
}

// if given char can be found in the set
bool contains(const char * set, const char value)
{
    char * cur = (char*)set;
    while (*cur != '\0')
    {
        if (value == *cur)
            return true;
        cur++;
    }
    return false;
}

// if given char can be found in leftBrackets
bool isLeftBracket(const char value)
{
    return contains(leftBrackets, value);
}

// if given char can be found in rightBrackets
bool isRightBracket(const char value)
{
    return contains(rightBrackets, value);
}

struct str_Stack* reversedPolishNotation(const char* infix)
{
    // init two stack, one for the final output, another for the shunting yard algorithm
    struct str_Stack* rpn = initStack();
    struct str_Stack* stack = initStack();

    // initialize the position of the cursor
    int curIndex = 0;

    // initialize params to determine a multiple-char token (for now only support numbers)
    int opFirst = 0;  // the start position of the token
    int opLength = 1;  // the length of the token
    bool wasNum = false;  // was the previous token a number?
    bool acceptDecimal = true;  // a number can only accept one '.'
    bool acceptNegative = true;   // a number can only accept one '-'
    bool started = false;  // if it is the beginning of the token

    bool finished = false;  // if the process is down
    while (true)
    {
        const char* cur = (infix + curIndex);
        if (!strlen(cur)) finished = true;
        if (finished && !wasNum) break;
//        printf("\n%c:", *cur);

        if (isNumber_char(*cur, &acceptDecimal, &acceptNegative, !wasNum))
        {
            if (!started)
            {
                opFirst = curIndex;
                started = true;
                wasNum = true;
            }
//            printf("%s", RPN_substr(&infix[opFirst], opLength));
            opLength ++;
        }
        else
        {
            if (wasNum)
            {
                // if the previous token was a number, then push it into the rpn
                pushStrStack(rpn, RPN_substr(&infix[opFirst], opLength - 1));
                if (finished) break;  // if the traversal is finished, break the loop
            }

            // Reset the params used to determine the number
            opFirst = 0;
            opLength = 1;
            acceptDecimal = true;
            acceptNegative = true;
            started = false;
            wasNum = false;

            if (isOperator(*cur))
            {
                // rules of NOT pop element from the stack:
                // 1. if the stack is already empty
                // 2. if the top of the stack is a left bracket
                // 3. if the top of the stack is an operator and:
                //          * it has a higher precedence than current operator
                //          * it has an equal precedence AND it is a left associative operator
                while (
                        !stack_isEmpty(stack) &&
                        !isLeftBracket(*stack->top->value) &&
                        (isOperator(*stack->top->value) && (
                                (operator_hasLowerPrecedence(*cur, *stack->top->value))
                                || ((operator_hasEqualPrecedence(*cur, *stack->top->value)) &&
                                !(isOperator(*stack->top->value)->leftAssociative))
                                )
                        )
                       )
                    pushStrStack(rpn, stack_pop(stack));

                // push the new(cur) operator into the stack
                pushStrStack(stack, charToString(*cur));
            }
            else if (isLeftBracket(*cur))
            {
                pushStrStack(stack, charToString(*cur));
            }
            else if (isRightBracket(*cur))
            {
                // push all elements popped out from the stack into rpn,
                // until the top of stack is a left bracket
                while (!isLeftBracket(*stack->top->value))
                    pushStrStack(rpn, stack_pop(stack));

                // pop out the left bracket
                stack_pop(stack);
            }
        }

        // update the index
        curIndex++;
    }

    // pop out all remained elements in the stack into rpn
    while(!stack_isEmpty(stack))
        pushStrStack(rpn, stack_pop(stack));

    // inverse the rpn
    rpn = stack_inverse(rpn);
//    stack_print(rpn);
    return rpn;
}

double parse(struct str_Stack* rpn)
{
    struct num_Stack* stack = numStackInit();
    while (!stack_isEmpty(rpn))
    {
        const string token = stack_pop(rpn);

        // if the token is a number, push it into the stack
        if (isNumber_str(token))
            pushNumStack(stack, strtod(token, (void*)0));
        // if the token is an operator, evaluate the result and push it back to the stack
        else if (isOperator(token[0]))
        {
            struct Operator* op = isOperator(token[0]);
            if (op->isBinary)
                pushNumStack(stack, Operator_eval(op, popNumStack(stack), popNumStack(stack)));
            else pushNumStack(stack, Operator_eval(op, popNumStack(stack), 0));
        }
    }

    // the last element of the stack is the result of the expression
    return popNumStack(stack);
}

#endif //ASSIGN02_PARSER_H
