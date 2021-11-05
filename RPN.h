//
// Assignment 02: Implement an expression calculator
// Created by weikang on 2021/11/2.
//

/*
 * ./RPN.h
 * This file defined two types of stacks, one is used to store strings,
 * the other is used to store double-precision floating-point numbers.
 * */

#ifndef ASSIGN02_RPN_H
#define ASSIGN02_RPN_H
#include "pch.h"

// Implementation of std::substr() function in cpp
string RPN_substr(const char * from, int length)
{
    string subtext = ALLOC_ARR(char, length+1);
    strncpy(subtext, from, length);
    subtext[length] = '\0';
    return subtext;
}

// Node of string stack
struct str_Node
{
    const string value;
    struct str_Node* next;
};

// constructor of str_Node
struct str_Node* newNode(const char* v)
{
    struct str_Node* n = ALLOC(struct str_Node);
    n->value = v;
    n->next = NULL;
    return n;
}

// string stack
struct str_Stack
{
    int count;
    struct str_Node* top;

};

// constructor of str_Stack
struct str_Stack* initStack()
{
    struct str_Stack* s = ALLOC(struct str_Stack);
    s->top = NULL;
    s->count = 0;
    return s;
}

// push value to the str_Stack
void pushStrStack(struct str_Stack* stack, const string value)
{
    if (stack->count)
    {
        struct str_Node* n = newNode(value);
        n->next = stack->top;
        stack->top = n;
        stack->count ++;
    }
    else
    {
        stack->top = newNode(value);
        stack->count ++;
    }
}

// pop value from the top of str_Stack
const string stack_pop(struct str_Stack* stack)
{
    if (stack->count)
    {
        const string value = stack->top->value;
        struct str_Node* temp = stack->top;
        stack->top = stack->top->next;
        stack->count--;
        free(temp);
        return value;
    }
    else
    {
        return NULL;
    }
}

// return if the str_Stack is empty
bool stack_isEmpty(struct str_Stack* s)
{
    return s->count == 0;
}

// get the inverse stack of the original str_Stack
struct str_Stack* stack_inverse(struct str_Stack* s)
{
    struct str_Stack* i = initStack();
    while (!stack_isEmpty(s))
        pushStrStack(i, stack_pop(s));
    return i;
}

// print the str_Stack
void stack_print(struct str_Stack* stack)
{
    struct str_Node* cur = stack->top;
    while (cur)
    {
        printf("%s, ", cur->value);
        cur = cur->next;
    }
}

// Node of num stack
struct num_Node
{
    double value;
    struct num_Node* next;
};

// constructor of num_Node
struct num_Node* numNodeInit(double v)
{
    struct num_Node* n = ALLOC(struct num_Node);
    n->value = v;
    n->next = NULL;
    return n;
}

// double stack
struct num_Stack
{
    struct num_Node* top;
    int count;
};

// constructor of num_Stack
struct num_Stack* numStackInit()
{
    struct num_Stack* s = ALLOC(struct num_Stack);
    s->count = 0;
    s->top = NULL;
    return s;
};

// push value to the num_Stack
void pushNumStack(struct num_Stack* stack, double value)
{
    if (stack->count)
    {
        struct num_Node* n = numNodeInit(value);
        n->next = stack->top;
        stack->top = n;
        stack->count ++;
    }
    else
    {
        stack->top = numNodeInit(value);
        stack->count ++;
    }
}

// pop value from the top of num_Stack
double popNumStack(struct num_Stack* stack)
{
    if (stack->count)
    {
        double v = stack->top->value;
        struct num_Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->count --;
        return v;
    }
}

#endif //ASSIGN02_RPN_H
