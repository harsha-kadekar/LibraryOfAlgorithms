#include"GeneralFunctionHeader.h"

/*
Name: QuickSortIntegers
Description: This function will sort an array using quicksort logic
Parameters: pIntArray -> array whose elements needs to be sorted
nSize -> Size of the array
ReturnValue: 0 for success else error codes
*/
int QuickSortIntegers(int* pIntArray, int nSize, bool bAscending)
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

	nReturnValue = RandomizedQuickSort(pIntArray, 0, nSize - 1, bAscending);

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
int RandomizedQuickSort(int* pIntArray, int nlow, int nhigh, bool bAscending)
{
	int nReturnValue = 0;
	int nKey = -1;

	if (nlow < nhigh)
	{
		nKey = RandomizedPartition(pIntArray, nlow, nhigh, bAscending);
		RandomizedQuickSort(pIntArray, nlow, nKey - 1, bAscending);
		RandomizedQuickSort(pIntArray, nKey + 1, nhigh, bAscending);
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
int RandomizedPartition(int* pIntArray, int nlow, int nhigh, bool bAscending)
{
	int nReturnValue = 0;

	int nDiff = nhigh - nlow;
	int nTemp = 0;

	srand(time(0));

	nDiff = rand() % nDiff;

	nTemp = pIntArray[nhigh];
	pIntArray[nhigh] = pIntArray[nlow + nDiff];
	pIntArray[nlow + nDiff] = nTemp;

	nReturnValue = PartitionQuickSort(pIntArray, nlow, nhigh, bAscending);

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
int PartitionQuickSort(int* pIntArray, int nlow, int nhigh, bool bAscending)
{
	int nCompareElement = pIntArray[nhigh];
	int nTemp = 0;
	int i = nlow - 1;

	for (int j = nlow; i < nhigh; j++)
	{
		if (bAscending)
		{
			if (pIntArray[j] <= nCompareElement)
			{
				i++;
				nTemp = pIntArray[i];
				pIntArray[i] = pIntArray[j];
				pIntArray[j] = pIntArray[i];
			}
		}
		else
		{
			if (pIntArray[j] > nCompareElement)
			{
				i++;
				nTemp = pIntArray[i];
				pIntArray[i] = pIntArray[j];
				pIntArray[j] = pIntArray[i];
			}

		}
	}

	nTemp = pIntArray[i + 1];
	pIntArray[i + 1] = pIntArray[nhigh];
	pIntArray[nhigh] = nTemp;

	return i + 1;
}