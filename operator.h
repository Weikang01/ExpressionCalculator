//
// Assignment 02: Implement an expression calculator
// Created by weikang on 2021/11/2.
//

/*
 * ./operator.h
 * This is the header file to handle the behavior of operators
 * */

#ifndef ASSIGN02_OPERATOR_H
#define ASSIGN02_OPERATOR_H
#include "pch.h"
#define OPERATOR_SIZE 6

// operator has its precedence, its evaluation function, and two booleans
// to determine whether it is a binary operation or a left associative.
struct Operator
{
    int precedence;
    bool isBinary;
    bool leftAssociative;
    double (*unary_eval)(double);
    double (*binary_eval)(double, double);
};

// constructor of operator
struct Operator* initOperator(int precedence, bool isBinary, bool leftAssociative, double (*unary_eval)(double), double (*binary_eval)(double, double))
{
    struct Operator* o = ALLOC(struct Operator);
    o->precedence = precedence;
    o->isBinary = isBinary;
    o->leftAssociative = leftAssociative;
    o->unary_eval = unary_eval;
    o->binary_eval = binary_eval;
    return o;
}

// two more constructor for unary and binary operators respectively
struct Operator* initUnaryOperator(int precedence, bool leftAssociative, double (*unary_eval)(double))
{
    return initOperator(precedence, false, leftAssociative, unary_eval, NULL);
}

struct Operator* initBinaryOperator(int precedence, bool leftAssociative, double (*binary_eval)(double, double))
{
    return initOperator(precedence, true, leftAssociative, NULL, binary_eval);
}

// evaluation function
double Operator_eval(struct Operator* op, double x, double y)
{
    if (op->isBinary)
        return op->binary_eval(x,y);
    else
        return op->unary_eval(x);
}

// store operator in to a pair<char, struct Operator*>, in which the sign is the key of the pair
struct OperatorPair
{
    char sign;
    struct Operator* operator;
};

struct OperatorPair* initOperatorPair(const char sign, struct Operator* operator)
{
    struct OperatorPair* pair = ALLOC(struct OperatorPair);
    pair->sign = sign;
    pair->operator = operator;
    return pair;
}

// if the given char is equal to the key
bool isOperatorPair(const char sign, const struct OperatorPair* pair)
{
    return pair->sign == sign;
}

// functions for operations
double operator_add(double x, double y)
{
    return x+y;
}

double operator_sub(double x, double y)
{
    return x-y;
}

double operator_mul(double x, double y)
{
    return x*y;
}

double operator_div(double x, double y)
{
    return x/y;
}

double operator_mod(double x, double y)
{
    double mod;
    if (x < 0)
        mod = -x;
    else mod = x;
    if (y < 0)
        y = -y;

    while (mod >= y)
        mod = mod - y;

    return mod;
}

struct OperatorPair** Operators;

// register the operators that currently supported
bool listInitialized = false;
void initOperatorList()
{
    Operators = ALLOC_ARR(struct OperatorPair*, OPERATOR_SIZE);
    Operators[0] = initOperatorPair('+', initBinaryOperator(2, false, operator_add));
    Operators[1] = initOperatorPair('-', initBinaryOperator(2, false, operator_sub));
    Operators[2] = initOperatorPair('/', initBinaryOperator(3, false, operator_div));
    Operators[3] = initOperatorPair('*', initBinaryOperator(3, false, operator_mul));
    Operators[4] = initOperatorPair('%', initBinaryOperator(3, true, operator_mod));
    Operators[5] = initOperatorPair('^', initBinaryOperator(4, true, pow));

    listInitialized = true;
}

// determine if a char is an operator
struct Operator* isOperator(const char sign)
{
    if (!listInitialized) initOperatorList();
    for (int i = 0; i < OPERATOR_SIZE; ++i) {
        if (isOperatorPair(sign, Operators[i]))
            return Operators[i]->operator;
    }
    return NULL;
}

// compare precedence of two operators
bool operator_hasEqualPrecedence(const char a, const char b)
{
    return isOperator(a)->precedence == isOperator(b)->precedence;
}

bool operator_hasLowerPrecedence(const char a, const char b)
{
    return isOperator(a)->precedence < isOperator(b)->precedence;
}

#endif //ASSIGN02_OPERATOR_H
