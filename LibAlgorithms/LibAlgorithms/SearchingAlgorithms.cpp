/*
This file has functions which is implemeting several of the searching algorithms
*/

#include "SearchingAlgorithms.h"

/*
Name: LinearSearchIntegers
Description: This function does a linear search of array pIntArray to find the key. If found will return the index. Else -1
Parameters:	pIntArray: Integer Array which needs to be searched
			nSize: Size of the array which needs to be searched
			nKey:	Key value which needs to be searched in array
ReturnValue: -1 if not found, else index of the array where key's first appearnce.
*/
int LinearSearchIntegers(int* pIntArray, int nSize, int nKey)
{
	int nReturnPosition = -1;

	if (0 == pIntArray)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	for (int i = 0; i < nSize; i++)
	{
		if (pIntArray[i] == nKey)
		{
			nReturnPosition = i;
			break;
		}
	}

	return nReturnPosition;
}