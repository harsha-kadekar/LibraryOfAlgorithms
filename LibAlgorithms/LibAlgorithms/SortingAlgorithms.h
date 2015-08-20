#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include<stdlib.h>

int MergeSortAlgo(int* pIntArray, int nStart, int nSize);
int MergeArray(int *pIntArray, int nStart, int nSize);

#ifdef __cplusplus
extern "C" {
#endif

	_declspec(dllimport) int InsertionSortIntegers(int* arNumbers, int nSize);
	_declspec(dllimport) int MergeSortIntegers(int* pIntArray, int nSize);

#ifdef __cplusplus
}
#endif

#endif