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

/*
Name:	BinarySearchIntegers
Description:	This funciton will search given sorted array to find the position of the key element using binary search algorithm
Parameters:	pIntArray -> sorted array in which we need to find the nkey
			nSize -> This is the size of the array
			nKey -> This is the element whose position has to be found out in array
ReturnValue: -1 if not found else position that is positive numbers. Other negative numbers means error.
*/
int BinarySearchIntegers(int* pIntArray, int nSize, int nKey)
{
	int nReturnValue = -1;
	int nMid = -1;
	int nLow = 0;
	int nHigh = nSize - 1;
	//bool bFound = false;

	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	if (nSize > 1)
	{
		while (nLow < nHigh)
		{
			nMid = ( nHigh - nLow) / 2;
			if (pIntArray[nMid] == nKey)
			{
				//bFound == true;
				nReturnValue = nMid;
				break;
			}
			else if (pIntArray[nMid] < nKey)
			{
				nLow = nMid + 1;
			}
			else
			{
				nHigh = nMid - 1;
			}
		}
	}
	else
	{
		if (pIntArray[0] == nKey)
			nReturnValue = 0;
			//bFound = true;
	}

	return nReturnValue;
}