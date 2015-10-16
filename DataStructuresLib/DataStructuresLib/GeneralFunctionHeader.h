#pragma once
#include<time.h>
#include<stdlib.h>

#define ERR_NULLINPUTARRAY -2
#define ERR_INVALIDARRAYSIZE -3

int QuickSortIntegers(int *pIntArray, int nSizes, bool bAscending);
int PartitionQuickSort(int* pIntArray, int nlow, int nhigh, bool bAscending);
int RandomizedPartition(int* pIntArray, int nlow, int nhigh, bool bAscending);
int RandomizedQuickSort(int* pIntArray, int nlow, int nhigh, bool bAscending);