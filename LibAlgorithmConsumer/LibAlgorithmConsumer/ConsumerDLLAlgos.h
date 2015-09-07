#ifndef CONSUMERDLLALGOS_H
#define CONSUMERDLLALGOS_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int TestSortingFunctions();
int TestSearchingFunctions();
int TestGeneralAlgorithms();

//typedef int(*InsertionSortFunc)(int*, int);
typedef int(*GeneralSortFunc)(int*, int);
typedef int(*GeneralSearchFunc)(int*, int, int);
typedef int(*MatrixMultiplicationBasic)(int**, int, int, int**, int , int, int**);
typedef int(*MatrixMultiplicationStrassen)(int** , int** , int , int** );

#endif
