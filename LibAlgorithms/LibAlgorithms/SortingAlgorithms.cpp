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