#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include<stdlib.h>
#include<time.h>

int MergeSortAlgo(int* pIntArray, int nStart, int nSize);
int MergeArray(int *pIntArray, int nStart, int nSize);
int BuildMaxHeap(int* pIntArray, int nSize);
int ParentHeap(int index);
int RightChildHeap(int index);
int LeftChildHeap(int index);
int MaxHeapify(int* pIntArray, int nSize, int nIndex);
int PartitionQuickSort(int* pIntArray, int nlow, int nhigh);
int RandomizedPartition(int* pIntArray, int nlow, int nhigh);
int RandomizedQuickSort(int* pIntArray, int nlow, int nhigh);

#ifdef __cplusplus
extern "C" {
#endif

	_declspec(dllimport) int InsertionSortIntegers(int* arNumbers, int nSize);
	_declspec(dllimport) int MergeSortIntegers(int* pIntArray, int nSize);
	_declspec(dllimport) int SelectionSortIntegers(int* pIntArray, int nSize);
	_declspec(dllimport) int BubbleSortIntegers(int* pIntArray, int nSize);
	_declspec(dllimport) int HeapSortIntegers(int* pIntArray, int nSize);
	_declspec(dllimport) int QuickSortIntegers(int* pIntArray, int nSize);

#ifdef __cplusplus
}
#endif

#endif