#ifndef CONSUMERDLLALGOS_H
#define CONSUMERDLLALGOS_H

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int TestSortingFunctions();
int TestSearchingFunctions();

//typedef int(*InsertionSortFunc)(int*, int);
typedef int(*GeneralSortFunc)(int*, int);
typedef int(*GeneralSearchFunc)(int*, int, int);

#endif
