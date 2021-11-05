//
// Assignment 02: Implement an expression calculator
// Created by weikang on 2021/11/2.
//

/*
 * ./pch.h
 * This is pre-compiled header of the program
 * */

#ifndef ASSIGN02_PCH_H
#define ASSIGN02_PCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // for pow()

#define bool int
#define true 1
#define false 0

#ifndef ALLOC
#define ALLOC(_struct) (_struct*)malloc(sizeof(_struct))
#endif
#ifndef ALLOC_ARR
#define ALLOC_ARR(_struct, n) (_struct*)malloc((n) * sizeof(_struct))
#endif
#ifndef string
#define string char*
#endif
#ifndef nameOfVar
#define nameOfVar(x) #x
#endif

#endif //ASSIGN02_PCH_H
