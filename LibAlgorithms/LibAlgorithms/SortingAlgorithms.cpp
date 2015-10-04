/*
This file has all the functions which help in sorting the give input. 
Developer: Harsha Kadekar
Date: 0/19/2015
*/

#include "SortingAlgorithms.h"
#include "ErrorCodes.h"

/*
Name: InsertionSortInteger
Description: This function sorts a given array of integers into increasing order using Insertion sort algorithm.
Parameters: arNumbers -> Array of integers which needs to be sorted.
			nSize -> Size of the array of integers
ReturnValue: ErrorCode of the function exection. 0 for success. Array would have sorted if everything goes fine.
*/
int InsertionSortIntegers(int* arNumbers, int nSize)
{
	int nReturnValue = 0;

	if (0 >= nSize)
	{
		//Size of the array cannot be 0 or less than zero
		return ERR_INVALIDARRAYSIZE;
	}

	if (0 == arNumbers)
	{
		//Integer array cannot be null
		return ERR_NULLINPUTARRAY;
	}

	/*
	//This logic was implemented without seeing book. Now problem in this is you have an extra loop block. 1st one you are using to find the position
	//Then next block you are using to place the key into particular position. You can merge them into single loop
	//Take each number and place it in correct position
	for (int i = 1; i <= nSize; i++)
	{
		int nKey = arNumbers[i];
		int nPos = i;

		//Find the position of the new number to be placed
		for (int j = 0; j < i; j++)
		{
			if (arNumbers[j] > nKey)
			{
				nPos = j;
				break;
			}
		}

		if (nPos != i)
		{
			//Move all the numbers to the right to make the position for new number
			for (int k = i - 1; k > nPos; k--)
			{
				arNumbers[k + 1] = arNumbers[k];
			}

			arNumbers[nPos] = nKey;

		}
	}
	*/

	for (int i = 1; i < nSize; i++)
	{
		int nKey = arNumbers[i];
		int j = i - 1;
		while (j >= 0)
		{
			if (arNumbers[j] > nKey)
			{
				arNumbers[j + 1] = arNumbers[j];
			}
			else
			{
				break;
			}
			j--;
		}

		arNumbers[j + 1] = nKey;

	}

	return nReturnValue;
}

/*
Name: MergeSortIntegers
Description: This function will sort an array of integers in increasing order using merge sort algorithm
Parameters: pInstArray -> This is the array of integers to be sorted
			nSize -> Size of the array to be sorted
ReturnValue: 0 for success. Else error codes. Also sorting will be done in array pInstArray same as input.
*/
int MergeSortIntegers(int* pIntArray, int nSize)
{
	int nReturnValue = 0;

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	MergeSortAlgo(pIntArray, 0, nSize);

	return nReturnValue;
}

/*
Name: MergeSortAlgo
Description: This is a recursive funcion. This function actually does the sorting using merge sort algorithm
Parameter: pIntArray -> This is an array of integer whose elements needs to be sorted.
		   nStart -> Start index of the array
		   nSize -> Size of the array to be considered for sorting
ReturnValue: 0 for success, else error code.
*/
int MergeSortAlgo(int* pIntArray, int nStart, int nSize)
{
	int nReturnValue = 0;
	int nMid = -1;

	nMid = nSize / 2;
	if (nMid > 0)
	{
		//This is divide part of the algorithm. That is we are dividing the array into smaller sub arrays.
		MergeSortAlgo(pIntArray, nStart, nMid);
		MergeSortAlgo(pIntArray, nStart + nMid, nSize - nMid);
		//This is conquering part of the algorithm. Here once after division of the array we are trying to merge them into one.
		MergeArray(pIntArray, nStart, nSize);
	}

	return nReturnValue;
}

/*
Name: MergeArray
Description: This function merges two sub arrays into one single array
Parameter: pIntArray -> Actual array containing two sub arrays
			nStartIndex -> Start Index of the First Sub Array
			nSize -> Total size of the array including two sub arrays
Returns: 0 for success else error code for error. 
*/
int MergeArray(int *pIntArray, int nStart, int nSize)
{
	int nReturnValue = 0;
	int nMid = nSize / 2;
	int nFirstStart = nStart;
	int nSecondStart = nStart + nMid;
	int nFirstEnd = nStart + nMid - 1;
	int nSecondEnd = nStart + nSize - 1;
	//int nFirstSize = nFirstEnd - nFirstStart + 1;
	//int nSecondSize = nSecondEnd - nSecondStart + 1;

	int i = nFirstStart, j = nSecondStart, k = 0;

	int* pTempArray = 0;
	pTempArray = (int*)malloc(nSize*sizeof(int));
	if (pTempArray == 0)
	{
		//Error Dynamic memory not allocated.
		return ERR_DYNAMICMEMNOTALLOC;
	}
	else
	{
		while (k < nSize && (i <= nFirstEnd && j <= nSecondEnd))
		{
			if (pIntArray[i] < pIntArray[j])
			{
				pTempArray[k++] = pIntArray[i++];
			}
			else
			{
				pTempArray[k++] = pIntArray[j++];
			}
		}

		while (i <= nFirstEnd)
			pTempArray[k++] = pIntArray[i++];

		while (j <= nSecondEnd)
			pTempArray[k++] = pIntArray[j++];

		i = 0, j = 0, k = 0;

		for (k = 0; k < nSize; k++)
			pIntArray[nStart++] = pTempArray[k];

		free(pTempArray);

	}

	return nReturnValue;
}

/*
Name:	SelectionSortIntegers
Description:	This function sorts the given integer array using Selection Sort
Parameters:	pIntArray -> Integer Array which needs to be sorted
			nSize -> Size of the integer array
ReturnValue:	0 for success, else error codes. Also sorted array will be present in pIntArray.
*/
int SelectionSortIntegers(int* pIntArray, int nSize)
{
	int nReturnValue = 0;
	int nSmallestIndex = 0;
	int nTemp = 0;

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	//Find the smallest number's index and swap it with ith element.
	for (int i = 0; i < nSize; i++)
	{
		nSmallestIndex = i;
		for (int j = i + 1; j < nSize; j++)
		{
			if (pIntArray[nSmallestIndex] > pIntArray[j])
				nSmallestIndex = j;
		}

		if (nSmallestIndex != i)
		{
			nTemp = pIntArray[i];
			pIntArray[i] = pIntArray[nSmallestIndex];
			pIntArray[nSmallestIndex] = nTemp;
		}
	}

	return nReturnValue;
}

/*
Name:	BubbleSortIntegers
Description:	This function will sort the given integer array in increasing order based on Bubble sort agorithm
Parameters:	pIntArray -> This is the integer array which needs to be sorted.
			nSize -> This the size of the array
ReturnValue: 0 for success else error codes. Sorted array will be present in the pIntArray.
*/
int BubbleSortIntegers(int* pIntArray, int nSize)
{
	int nReturnValue = 0;
	int nTemp = -1;
	bool bNeverEntered = true;

	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	//Bubbling out the largest number to the end of array
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 1; j < nSize-i; j++)
		{
			if (pIntArray[j] < pIntArray[j - 1])
			{
				bNeverEntered = false;
				nTemp = pIntArray[j];
				pIntArray[j] = pIntArray[j - 1];
				pIntArray[j - 1] = nTemp;
			}
		}

		//The array is already sorted.
		if (bNeverEntered)
			break;
	}

	return nReturnValue;
}

/*
Name: MaxHeapify
Description: This function will heapify the given array. It is following rule that always parent has highest value.
Parameters: pIntArray -> Array which needs to be heapified
			nSize -> Size of the array
			nIndex -> Index of array from where below subtree needs to be heapified.
ReturnValue: 0 for success else error codes
*/
int MaxHeapify(int* pIntArray, int nSize, int nIndex)
{
	int nReturnValue = 0;
	int nLeftIndex = LeftChildHeap(nIndex);
	int nRightIndex = RightChildHeap(nIndex);
	int nLargestIndex = nIndex;
	int nTemp = 0;

	if (nLeftIndex < nSize && pIntArray[nLeftIndex] > pIntArray[nLargestIndex])
	{
		nLargestIndex = nLeftIndex;
	}

	if (nRightIndex < nSize && pIntArray[nRightIndex] > pIntArray[nLargestIndex])
	{
		nLargestIndex = nRightIndex;
	}

	if (nLargestIndex != nIndex)
	{
		nTemp = pIntArray[nLargestIndex];
		pIntArray[nLargestIndex] = pIntArray[nIndex];
		pIntArray[nIndex] = nTemp;

		MaxHeapify(pIntArray, nSize, nLargestIndex);
	}

	return nReturnValue;
}

/*
Name: LeftChildHeap
Description: This function will get you the index of left child for the node pointed by i
Parameters: index -> index of the node whose left child's index needs to be found.
ReturnValue:	index of the left child
*/
int LeftChildHeap(int index)
{
	return 2 * index + 1;
}


/*
Name: RightChildHeap
Description: This function will get you the index of right child for the node pointed by i
Parameter: index -> index of the node whose right child needs to be found
ReturnValue: index of the right child
*/
int RightChildHeap(int index)
{
	return 2 * index + 2;
}

/*
Name: ParentHeap
Description: This function will get you the index of the parent if you give the index of child
Parameter: index -> index of the node whose parent needs to be found
ReturnValue: index of the parent
*/
int ParentHeap(int index)
{
	return index / 2;
}

/*
Name: BuildMaxHeap
Description: Given an array of integers it will be coverted to a heap array
Parameter: pIntArray -> array of integers
		   nSize -> Size of the array
ReturnValue: 0 for success else a -ve error code.
*/
int BuildMaxHeap(int* pIntArray, int nSize)
{
	int nReturnValue = 0;

	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	//Heapify will happen from the bottom up that is we start from leaves. Now leaves in a heap appear
	//only after nSize/2 index.
	for (int i = nSize / 2; i >= 0; i--)
	{
		MaxHeapify(pIntArray, nSize, i);
	}


	return nReturnValue;
}

/*
Name: HeapSort
Description: This function sorts a given array in ascending order using heap sort
Parameter: pIntArray -> This is the array which needs to be sorted
		   nSize -> Size of the array
ReturnValue: 0 for success else ERROR codes
*/
int HeapSortIntegers(int* pIntArray, int nSize)
{
	int nReturnValue = 0;
	int nTemp = 0;

	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	BuildMaxHeap(pIntArray, nSize);

	for (int i = nSize - 1, j = 1; i >= 1; i++, j++)
	{
		nTemp = pIntArray[0];
		pIntArray[0] = pIntArray[i];
		pIntArray[i] = nTemp;

		MaxHeapify(pIntArray, nSize - j, 0);

	}

	return nReturnValue;
}

/*
Name: QuickSortIntegers
Description: This function will sort an array using quicksort logic
Parameters: pIntArray -> array whose elements needs to be sorted
			nSize -> Size of the array
ReturnValue: 0 for success else error codes
*/
int QuickSortIntegers(int* pIntArray, int nSize)
{
	int nReturnValue = 0;

	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	nReturnValue = RandomizedQuickSort(pIntArray, 0, nSize - 1);

	return nReturnValue;
}

/*
Name: RandomizedQuickSort
Description: This function will do actual quicksort. It uses randomization to fasten quick sort
Parameters: pIntArray -> Array which needs to be sorted
			nlow -> Low index of array from where it should be sorted
			nhigh -> high index of array till where it sould be sorted
ReturnValue: 0 for success else error codes
*/
int RandomizedQuickSort(int* pIntArray, int nlow, int nhigh)
{
	int nReturnValue = 0;
	int nKey = -1;

	if (nlow < nhigh)
	{
		nKey = RandomizedPartition(pIntArray, nlow, nhigh);
		RandomizedQuickSort(pIntArray, nlow, nKey - 1);
		RandomizedQuickSort(pIntArray, nKey + 1, nhigh);
	}

	return nReturnValue;
}

/*
Name: RandomizedPartion
Description: This function will apply randomization and then calls partition whose work is to divide
Parameters: pIntArray -> array to be sorted
			nlow -> start index of array
			nhigh -> end index of array
ReturnValue: Returns the pivot index where partion has been done.
*/
int RandomizedPartition(int* pIntArray, int nlow, int nhigh)
{
	int nReturnValue = 0;
	
	int nDiff = nhigh - nlow;
	int nTemp = 0;

	srand(time(0));

	nDiff = rand() % nDiff;

	nTemp = pIntArray[nhigh];
	pIntArray[nhigh] = pIntArray[nlow + nDiff];
	pIntArray[nlow + nDiff] = nTemp;

	nReturnValue = PartitionQuickSort(pIntArray, nlow, nhigh);

	return nReturnValue;
}

/*
Name: PartitionQuickSort
Description: This function will get the pivot element where divid of array take place
Parameters: pIntArray -> array in which pivot element needs to be found
			nlow -> lowest index of the array
			nhigh -> highest index of the array
ReturnValue: pivot element index
*/
int PartitionQuickSort(int* pIntArray, int nlow, int nhigh)
{
	int nCompareElement = pIntArray[nhigh];
	int nTemp = 0;
	int i = nlow - 1;

	for (int j = nlow; i < nhigh; j++)
	{
		if (pIntArray[j] <= nCompareElement)
		{
			i++;
			nTemp = pIntArray[i];
			pIntArray[i] = pIntArray[j];
			pIntArray[j] = pIntArray[i];
		}
	}

	nTemp = pIntArray[i + 1];
	pIntArray[i + 1] = pIntArray[nhigh];
	pIntArray[nhigh] = nTemp;

	return i + 1;
}