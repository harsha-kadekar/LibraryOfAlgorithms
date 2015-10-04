/*
This file has general algorithms like adding two n bit binary numbers like that
*/

#include "GeneralAlgorithms.h"

/*
Name: AddingTwoBinaryNumbers
Description: This function given two binary numbers in the format of integer array, adds them and gives back the result in binary number.
Parameters:	pFirstNumber -> This is the first n bit  number
			pSecondNumber -> This is the second n bit number
			nSize -> The size of the binary numbers.
			pResultant -> Its size will be n+1 and it will hold the final sum of the two n bit binary numbers.
ReturnValue: 0 for success else error code.
*/
int AddingTwoBinaryNumbers(int* pFirstNumber, int* pSecondNumber, int nSize, int* pResultant)
{
	int nReturnValue = 0;
	int nSum = 0;
	int nCarry = 0;
	bool bFoundInvalidChar = false;

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	if (pFirstNumber == 0 || pSecondNumber == 0 || pResultant == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	for (int i = 0; i < nSize; i++)
	{
		if (pFirstNumber[i] == 0 && pSecondNumber[i] == 0)
		{
			if (nCarry == 0)
			{
				nSum = 0;
				nCarry = 0;
			}
			else
			{
				nSum = 1;
				nCarry = 0;
			}
			
		}
		else if ((pFirstNumber[i] == 1 && pSecondNumber[i] == 0) || (pFirstNumber[i] == 0 && pSecondNumber[i] == 1))
		{
			if (nCarry == 0)
			{
				nSum = 1;
				nCarry = 0;
			}
			else
			{
				nSum = 0;
				nCarry = 1;
			}
		}
		else if (pFirstNumber[i] == 1 && pSecondNumber[i] == 1)
		{
			if (nCarry == 0)
			{
				nSum = 0;
				nCarry = 1;
			}
			else
			{
				nSum = 1;
				nCarry = 1;
			}
		}
		else
		{
			bFoundInvalidChar = true;
			break;
		}

		pResultant[i] = nSum;

	}

	if (bFoundInvalidChar)
		return ERR_INVALIDCHAR;

	pResultant[nSize] = nCarry;

	return nReturnValue;
}

/*
Name: FindMaximumSubArray
Description: This function will give the subArray within a given array whose sum of its elements is maximum. Follows divide and conquer
Parameters: pIntArray -> Actual array in which we need to find subarray
			nSize -> Size of the array
			plow -> Start index of the maximum sub array
			phigh -> End index of the maximum sub array
			psum -> sum of the maximum sub array
ReturnValue: 0 for success, else error code. Results will be in plow, phigh and psum
*/
int FindMaximumSubArray(int* pIntArray, int nSize, int* plow, int* phigh, int* psum)
{
	int nReturnValue = 0;

	//plow = 0, phigh = 0, psum = 0;

	if (nSize <= 0)
		return ERR_INVALIDARRAYSIZE;

	if (0 == pIntArray)
		return ERR_NULLINPUTARRAY;

	if (0 == plow || 0 == phigh || 0 == psum)
	{
		return ERR_INVALIDINPUT;
	}

	//C is always call by value. By using we are just simulating call by reference. When yu 
	//pass pointer it has copied that pointer into its local variable. You can do manipulation to the values pointed
	//by the address pointed by the pointer. Suppose you allocate new pointer then you lost connection to old pointer in this function.
	//So whatever you do will not be reflected in the parent function.
	/*plow = (int*)malloc(sizeof(int));
	if (0 == plow)
		return ERR_DYNAMICMEMNOTALLOC;

	phigh = (int*)malloc(sizeof(int));
	if (0 == phigh)
	{
		if (0 != plow)
		{
			free(plow);
			plow = 0;
		}

		return ERR_DYNAMICMEMNOTALLOC;
	}

	psum = (int*)malloc(sizeof(int));
	if (0 == psum)
	{
		if (0 != plow)
		{
			free(plow);
			plow = 0;
		}

		if (0 != phigh)
		{
			free(phigh);
			phigh = 0;
		}

		return ERR_DYNAMICMEMNOTALLOC;
	}*/

	//Call actual function.
	*plow = -1;
	*phigh = -1;

	nReturnValue = FindMaxSubArrayRec(pIntArray, 0, nSize - 1, plow, phigh, psum);

	return nReturnValue;
}

/*
Name: FindMaxSubArrayLinear
Description: FInd the maximum Sub array in a such a way that it should be non recursive and linear.
Parameter: pIntArray - Array in which we need to find the maximum sub array
		   nSize - Size of the array
		   pLow - Start index of sub array
		   pHigh - End index of sub array
		   pSum - Sum of the sub array 
ReturnValue: 0 for success else Error codes.
*/
int FindMaxSubArrayLinear(int* pIntArray, int nSize, int *pLow, int*pHigh, int* pSum)
{
	int nReturnValue = 0;
	bool bResetCurrentValue = false;
	int nCurrentSum = 0;
	int nTempSum = 0;
	int nResetStart = 0;


	if (pIntArray == 0)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	if (pLow == 0 || pHigh == 0 || pSum == 0)
	{
		return ERR_INVALIDINPUT;
	}

	nCurrentSum = *pSum = pIntArray[0];

	*pLow = *pHigh = 0;

	for (int i = 1; i < nSize; i++)
	{
		nTempSum = nCurrentSum + pIntArray[i];
		if (nTempSum > 0)
		{
			nCurrentSum = nTempSum;

			if (nCurrentSum > 0 && bResetCurrentValue)
			{
				nResetStart = i;
				bResetCurrentValue = false;
			}

			if (nCurrentSum > *pSum)
			{
				*pSum = nCurrentSum;
				*pHigh = i;
				*pLow = nResetStart;
				
			}



			
		}
		else
		{
			nCurrentSum = 0;
			bResetCurrentValue = true;
		}
	}

	return nReturnValue;
}

/*
Name: FindMaxSubArrayBruteForce
Description: This will find the sub array in pIntArray such that the subarrays sum is maximum among other possible sub arrays
Parameter: pIntArray -> This is the array in which we need to find the maximum sub array
		   nlow -> starting index of the array
		   nhigh -> end of the array
		   pLowRes -> start of the sub array
		   pHighRes -> end of the sub array
		   pSumRes -> sum of the sub array
ReturnValue: 0 for success else Error codes
*/
int FindMaxSubArrayBruteForce(int* pIntArray,int nSize, int* pLowRes, int* pHighRes, int *pSumRes)
{
	int nReturnValue = 0;
	int nTempSum = 0;

	if (0 == pIntArray)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	if (pLowRes == 0 || pHighRes == 0 || pSumRes == 0)
	{
		return ERR_INVALIDINPUT;
	}

	*pLowRes = *pHighRes = *pSumRes = 0;

	for (int i = 0; i < nSize; i++)
	{
		nTempSum = pIntArray[i];
		for (int j = i + 1; j < nSize; j++)
		{
			nTempSum += pIntArray[j];
			if (nTempSum > *pSumRes)
			{
				*pLowRes = i;
				*pHighRes = j;
				*pSumRes = nTempSum;
			}
		}
	}

	return nReturnValue;
}

/*
Name: FindMaxSubArrayRec
Desciption: This is a recursive function which will try to find the maximum sub array from the given sub array.
Parameter: pIntArray -> Actual array in which sub array needs to be found
		   nLow -> low index of array from where sub array needs to be found
		   nHigh -> high index of array till which we can find the sub array.
		   pLowRes -> Found maximum sub arrays low index
		   pHighRes -> Found maximum sub arrays high index
		   pSumRes -> Found maximum sub arrays sum
ReturnValue: 0 for success else error codes.
*/
int FindMaxSubArrayRec(int* pIntArray, int nLow, int nHigh, int* pLowRes, int* pHighRes, int* pSumRes)
{
	int nReturnValue = 0;
	int nMid = -1;
	int nLeftLow = -1;
	int nRightLow = -1;
	int nCrossLow = -1;
	int nLeftHigh = -1;
	int nRightHigh = -1;
	int nCrossHigh = -1;
	int nLeftSum = 0;
	int nRightSum = 0;
	int nCrossSum = 0;

	if (nLow == nHigh)
	{
		*pLowRes = nLow;
		*pHighRes = nHigh;
		*pSumRes = pIntArray[nLow];

		return nReturnValue;
	}
	else
	{
		nMid = (nHigh + nLow) / 2;
		nReturnValue = FindMaxSubArrayRec(pIntArray, nLow, nMid, pLowRes, pHighRes, pSumRes);

		nLeftLow = *pLowRes;
		nLeftHigh = *pHighRes;
		nLeftSum = *pSumRes;

		nReturnValue = FindMaxSubArrayRec(pIntArray, nMid + 1, nHigh, pLowRes, pHighRes, pSumRes);

		nRightHigh = *pHighRes;
		nRightLow = *pLowRes;
		nRightSum = *pSumRes;

		nReturnValue = FindMaxCrossingSubArray(pIntArray, nLow, nMid, nHigh, pLowRes, pHighRes, pSumRes);

		nCrossHigh = *pLowRes;
		nCrossLow = *pLowRes;
		nCrossSum = *pSumRes;

		if (nLeftSum >= nRightSum && nLeftSum >= nCrossSum)
		{
			*pLowRes = nLeftLow;
			*pHighRes = nLeftHigh;
			*pSumRes = nLeftSum;
		}
		else if (nRightSum >= nLeftSum && nRightSum >= nCrossSum)
		{
			*pLowRes = nRightLow;
			*pHighRes = nRightHigh;
			*pSumRes = nRightSum;
		}
		else
		{
			*pLowRes = nCrossLow;
			*pHighRes = nCrossHigh;
			*pSumRes = nCrossSum;

		}
			

	}

	return nReturnValue = 0;
}


/*
Name: FindMaxCrossingSubArray
Description: Given two divided sub array of single array this function will give you the maximum subarray including the point of division
Parameter: pIntArray -> Actual array whose sub arrays indices are given
		   nLow -> Lowest index of the left sub array
		   nHigh -> Highest index of the right sub array
		   nMid -> This is the mid term. This will be highest index of left sub array and nMid+1 will be lowest index of right sub array
		   pLowRes -> low index of the found max sub array
		   pHighRes -> High index of the found max sub array
		   pSumRes -> Sum of the found max sub array
*/
int FindMaxCrossingSubArray(int* pIntArray, int nLow, int nMid, int nHigh, int* pLowRes, int* pHighRes, int* pSumRes)
{
	int nReturnValue = 0;
	int nleftSum = INT_MIN;
	int nRightSum = INT_MIN;
	int nMaxLeft = -1;
	int nMaxRight = -1;
	int nSum = 0;

	for (int i = nMid; i >= 0; i--)
	{
		nSum += pIntArray[i];
		if (nSum > nleftSum)
		{
			nleftSum = nSum;
			nMaxLeft = i;
		}
	}

	nSum = 0;
	for (int i = nMid + 1; i <= nHigh; i++)
	{
		nSum += pIntArray[i];
		if (nSum > nRightSum)
		{
			nRightSum = nSum;
			nMaxRight = i;
		}
	}

	*pLowRes = nMaxLeft;
	*pHighRes = nMaxRight;
	*pSumRes = nleftSum + nRightSum;

	return nReturnValue;
}

/*
Name: MatrixMultiplicationBasic
Description: This function will do matrix multiplication of two mxn Matrices. It uses the normal way. For strassens way of multiplication
			 you need to use a different algorithm.
Parameters: pMatrixA -> First matrix
			Am -> Rows of first matrix
			An -> Columns of the first matrix
			pMatrixB -> Second Matrix
			Bm -> Rows of second matrix
			Bn -> Columns of second matrix
			pMatrixC -> Resultant Matrix
ReturnValue: 0 for success else error codes
*/
int MatrixMultiplicationBasic(int** pMatrixA, int Am, int An, int** pMatrixB, int Bm, int Bn, int** pMatrixC)
{
	int nReturnValue = 0;
	
	if (0 == pMatrixA || 0 == pMatrixB || 0 == pMatrixC)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (Am <= 0 || An <= 0 || Bm <= 0 || Bn <= 0)
	{
		return ERR_INVALIDARRAYSIZE;
	}

	if (An != Bm)
	{
		return ERR_INVALIDINPUT;
	}

	

	for (int i = 0; i < Am; i++)
	{
		for (int j = 0; j < Bn; j++)
		{
			pMatrixC[i][j] = 0;
			for (int k = 0; k < An; k++)
			{
				pMatrixC[i][j] += pMatrixA[i][k] * pMatrixB[k][j];
			}
		}
	}

	return nReturnValue;
}

/*
Name: MatrixMultiplicationStrassen
Description: This function will do the matrix multiplication using strassen algorithm
Parameters: pMatrixA -> First matrix
			pMatrixB -> Second Matrix
			nSize -> Size of the square matrix
			pMatrixC -> Resultant Matrix
ReturnValue: 0 for success else error code
*/
int MatrixMultiplicationStrassen(int** pMatrixA, int** pMatrixB, int nSize, int** pMatrixC)
{
	int nReturnValue = 0;

	if (0 == pMatrixA || 0 == pMatrixB || 0 == pMatrixC)
	{
		return ERR_NULLINPUTARRAY;
	}

	if (nSize <= 0)
	{
		return ERR_INVALIDINPUT;
	}

	nReturnValue = StrassenImplementation(pMatrixA, 0, 0, pMatrixB, 0, 0, nSize, pMatrixC);

	return nReturnValue;
}



/*
Name: StrassenImplemenationa
Description: This function actually implements the strassens algorithm and does multiplication
Parameter: pMatrixA -> This is Matrix A
			AmStart -> Row Start index of MatrixA
			AnStart -> Column Start index of MatrixA
			pMatrixB -> This is Matrix B
			BmStart -> Row Start index of Matrix B
			BnStart -> Column Start index of Matrix B
			nSize -> Size of the square matrix
			pMatrixC -> This is resultant Matrix
ReturnValue: 0 for success else error code
*/
int StrassenImplementation(int** pMatrixA, int AmStart, int AnStart, int** pMatrixB, int BmStart, int BnStart, int nSize, int** pMatrixC)
{
	int nReturnValue = 0;

	int **pS1 = 0, **pS2 = 0, **pS3 = 0, **pS4 = 0, **pS5 = 0, **pS6 = 0, **pS7 = 0, **pS8 = 0, **pS9 = 0, **pS10 = 0;
	int **pP1 = 0, **pP2 = 0, **pP3 = 0, **pP4 = 0, **pP5 = 0, **pP6 = 0, **pP7 = 0;
	int **pTempA = 0, **pTempB = 0;

	/*if (nSize == 1)
	{
		pMatrixC[0][0] = pMatrixA[AmStart][AnStart] * pMatrixB[BmStart][BnStart];
	}*/
	if (nSize == 32)
	{
		//CrossOver
		pTempA = (int**)malloc(sizeof(int*)*nSize);
		if (pTempA == 0)
		{
			return ERR_DYNAMICMEMNOTALLOC;
		}
		else
		{
			for (int i = 0; i < nSize; i++)
			{
				pTempA[i] = (int*)malloc(sizeof(int)*nSize);
				if (pTempA[i] == 0)
				{
					return ERR_DYNAMICMEMNOTALLOC;
				}
				else
				{
					for (int j = 0; j < nSize; j++)
					{
						pTempA[i][j] = 0;
					}
				}
			}

			pTempB = (int**)malloc(sizeof(int*)*nSize);
			if (pTempB == 0)
			{
				return ERR_DYNAMICMEMNOTALLOC;
			}
			else
			{
				for (int i = 0; i < nSize; i++)
				{
					pTempB[i] = (int*)malloc(sizeof(int)*nSize);
					if (pTempB[i] == 0)
					{
						return ERR_DYNAMICMEMNOTALLOC;
					}
					else
					{
						for (int j = 0; j < nSize; j++)
						{
							pTempB[i][j] = 0;
						}
					}


				}

				for (int i = 0; i < nSize; i++)
				{
					for (int j = 0; j < nSize; j++)
					{
						pTempA[i][j] = pMatrixA[i+AmStart][j+AnStart];
					}
				}

				for (int i = 0; i < nSize; i++)
				{
					for (int j = 0; j < nSize; j++)
					{
						pTempB[i][j] = pMatrixB[i+BmStart][j+BnStart];
					}
				}

				nReturnValue = MatrixMultiplicationBasic(pTempA, nSize, nSize, pTempB, nSize, nSize, pMatrixC);

				if (pTempA != 0)
				{
					for (int i = 0; i < nSize; i++)
					{
						if (pTempA[i] != 0)
							free(pTempA[i]);
						pTempA[i] = 0;
					}
					free(pTempA);
					pTempA = 0;
				}

				if (pTempB != 0)
				{
					for (int i = 0; i < nSize; i++)
					{
						if (pTempB[i] != 0)
							free(pTempB[i]);
						pTempB[i] = 0;
					}
					free(pTempB);
					pTempB = 0;
				}

			}

		}
		

		
	}
	else if (nSize == 1)
	{
		pMatrixC[0][0] = pMatrixA[AmStart][AnStart] * pMatrixB[BmStart][BnStart];
	}
	else
	{
		pS1 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS1 == 0)
		{
			//Error
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS1[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS1[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		SubtractTwoSquareMatrix(pMatrixB, BmStart, BnStart + nSize/2, pMatrixB, BmStart + nSize / 2, BnStart + nSize / 2, nSize / 2, pS1);

		pS2 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS2 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS2[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS2[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}
		
		AddTwoSquareMatrix(pMatrixA, AmStart, AnStart, pMatrixA, AmStart, AnStart + nSize/2, nSize / 2, pS2);

		pS3 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS3 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS3[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS3[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		AddTwoSquareMatrix(pMatrixA, AmStart + nSize/ 2, AnStart, pMatrixA, AmStart + nSize/ 2, AnStart + nSize/ 2, nSize / 2, pS3);

		pS4 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS4 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS4[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS4[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		SubtractTwoSquareMatrix(pMatrixB, BmStart + nSize/ 2, BnStart, pMatrixB, BmStart, BnStart, nSize / 2, pS4);

		pS5 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS5 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS5[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS5[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		AddTwoSquareMatrix(pMatrixA, AmStart, AnStart, pMatrixA, AmStart + nSize/2, AnStart + nSize/2, nSize/2, pS5);

		pS6 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS6 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS6[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS6[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		AddTwoSquareMatrix(pMatrixB, BmStart, BnStart, pMatrixB, BmStart + nSize/2, BnStart + nSize/ 2, nSize / 2, pS6);

		pS7 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS7 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS7[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS7[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		SubtractTwoSquareMatrix(pMatrixA, AmStart, AnStart + nSize/ 2, pMatrixA, AmStart +nSize/ 2, AnStart+nSize/ 2, nSize / 2, pS7);

		pS8 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS8 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS8[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS8[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		AddTwoSquareMatrix(pMatrixB, BmStart+nSize/2, BnStart, pMatrixB, BmStart+nSize/2, BmStart+nSize/2, nSize/2, pS8);

		pS9 = (int**)malloc(sizeof(int*)*(nSize/2));
		if (pS9 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS9[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS9[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		SubtractTwoSquareMatrix(pMatrixA, AmStart, AnStart, pMatrixA, AmStart + nSize/ 2, AnStart, nSize / 2, pS9);

		pS10 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pS10 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pS10[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pS10[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		AddTwoSquareMatrix(pMatrixB, BmStart, BnStart, pMatrixB, BmStart, BnStart +nSize/ 2, nSize / 2, pS10);

		pP1 = (int**)malloc(sizeof(int*)*nSize/2);
		if(pP1 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pP1[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pP1[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		nReturnValue = StrassenImplementation(pMatrixA, AmStart, AnStart, pS1, 0, 0, nSize/2, pP1);
		if (0 != nReturnValue)
		{
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			return nReturnValue;
		}



		pP2 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pP2 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pP2[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pP2[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		nReturnValue = StrassenImplementation(pS2, 0, 0, pMatrixB, BmStart + nSize/ 2, BnStart +nSize/ 2, nSize / 2, pP2);
		if (0 != nReturnValue)
		{
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			return nReturnValue;
		}

		pP3 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pP3 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pP3[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pP3[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		nReturnValue = StrassenImplementation(pS3, 0, 0, pMatrixB, BmStart, BnStart, nSize / 2, pP3);
		if (0 != nReturnValue)
		{
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			return nReturnValue;
		}

		pP4 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pP4 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pP4[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pP4[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		nReturnValue = StrassenImplementation(pMatrixA, AmStart + nSize / 2, AnStart + nSize / 2, pS4, 0, 0, nSize / 2, pP4);
		if (0 != nReturnValue)
		{
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			return nReturnValue;
		}

		pP5 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pP5 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pP5[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pP5[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		nReturnValue = StrassenImplementation(pS5, 0, 0, pS6, 0, 0, nSize / 2, pP5);
		if (0 != nReturnValue)
		{
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			return nReturnValue;
		}

		pP6 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pP6 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;
		}

		for (int i = 0; i < nSize/2; i++)
		{
			pP6[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pP6[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		nReturnValue = StrassenImplementation(pS7, 0, 0, pS8, 0, 0, nSize / 2, pP6);
		if (0 != nReturnValue)
		{
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			return nReturnValue;
		}

		pP7 = (int**)malloc(sizeof(int*)*nSize/2);
		if (pP7 == 0)
		{
			//Error
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			nReturnValue = ERR_DYNAMICMEMNOTALLOC;
			return nReturnValue;

		}

		for (int i = 0; i < nSize/2; i++)
		{
			pP7[i] = (int*)malloc((nSize/2)*sizeof(int));
			if (pP7[i] == 0)
			{
				//Error
				FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
				nReturnValue = ERR_DYNAMICMEMNOTALLOC;
				return nReturnValue;
			}
		}

		nReturnValue = StrassenImplementation(pS9, 0, 0, pS10, 0, 0, nSize / 2, pP7);
		if (0 != nReturnValue)
		{
			FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize/2);
			return nReturnValue;
		}

		for (int i = 0; i < nSize; i++)
		{
			for (int j = 0; j < nSize; j++)
			{
				pMatrixC[i][j] = 0;
			}
		}

		for (int i = 0; i < nSize/2; i++)
		{
			for (int j = 0; j < nSize/2; j++)
			{
				pMatrixC[i][j] += pP5[i][j] + pP4[i][j] - pP2[i][j] + pP6[i][j];
			}
		}

		for (int i = 0, m = 0; i < nSize/2 && m < nSize / 2; i++, m++)
		{

			for (int j = nSize / 2, n = 0; j < nSize && n < nSize / 2; j++, n++)
			{
				pMatrixC[i][j] += pP1[m][n] + pP2[m][n];
			}
		}

		for (int i = nSize/2, m = 0; i < nSize && m < nSize / 2; i++, m++)
		{

			for (int j = 0 , n = 0; j < nSize/2 && n < nSize / 2; j++, n++)
			{
				pMatrixC[i][j] += pP3[m][n] + pP4[m][n];
			}
		}

		for (int i = nSize / 2, m = 0; i < nSize && m < nSize/2; i++, m++)
		{
			
			for (int j = nSize / 2, n = 0; j < nSize && n < nSize/2; j++, n++)
			{
				pMatrixC[i][j] += pP5[m][n] + pP1[m][n] - pP3[m][n] - pP7[m][n];
			}
		}

		FreeUpMemory(pS1, pS2, pS3, pS4, pS5, pS6, pS7, pS8, pS9, pS10, pP1, pP2, pP3, pP4, pP5, pP6, pP7, nSize / 2);
		
	}
	
	return nReturnValue;
}

/*
Name: AddTwoSquareMatrix
Description: This will add two square matrices.
Parameter: pMatrixA -> First Matrix
pMatrixB -> Second Matrix
pResultant -> Resultant Matrix will be stored here after subtraction
nAmStart -> Start index of the row of Matrix A
nAnStart -> Start index of the column of Matrix A
nBmStart -> Start index of the row of Matrix B
nBnStart -> Start index of the column of Matrix B
nSize -> Size of the square matrices
ReturnValue: 0 for success else error.
*/
int AddTwoSquareMatrix(int** pMatrixA, int nAmStart, int nAnStart, int** pMatrixB, int nBmStart, int nBnStart, int nSize, int** pResult)
{
	int nReturnValue = 0;

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			pResult[i][j] = pMatrixA[nAmStart + i][nAnStart + j] + pMatrixB[nBmStart + i][nBnStart + j];
		}
	}


	return nReturnValue;
}

/*
Name: SubtractTwoSquareMatrix
Description: This will subtract two square matrices.
Parameter: pMatrixA -> First Matrix
		   pMatrixB -> Second Matrix
		   pResultant -> Resultant Matrix will be stored here after subtraction
		   nAmStart -> Start index of the row of Matrix A
		   nAnStart -> Start index of the column of Matrix A
		   nBmStart -> Start index of the row of Matrix B
		   nBnStart -> Start index of the column of Matrix B
		   nSize -> Size of the square matrices
ReturnValue: 0 for success else error.
*/
int SubtractTwoSquareMatrix(int** pMatrixA, int nAmStart, int nAnStart, int** pMatrixB, int nBmStart, int nBnStart, int nSize, int** pResult)
{
	int nReturnValue = 0;

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			pResult[i][j] = pMatrixA[nAmStart + i][nAnStart + j] - pMatrixB[nBmStart + i][nBnStart + j];
		}
	}


	return nReturnValue;
}

/*
Name: FreeUpMemory
Description: This function will freeup memory of the matrices which were created by StrassenImplimentation funciton
Parameters: pS1,pS2,pS3,pS4,pS5,pS6,pS7,pS8,pS9,pS10,pP1,pP2,pP3,pP4,pP5,pP6,pP7 -> square matrices which needs to be freeed
			nSize -> Size of the square matrix
ReturnValue: 0 for success else error code.
*/
int FreeUpMemory(int** pS1, int **pS2, int **pS3, int **pS4, int** pS5, int** pS6, int **pS7, int** pS8, int** pS9, int** pS10, int** pP1, int** pP2, int** pP3, int** pP4, int** pP5, int** pP6, int** pP7, int nSize)
{
	int nReturnValue = 0;

	if (0 != pS1)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS1[i])
			{
				free(pS1[i]);
			}
			pS1[i] = 0;
		}
		free(pS1);
		pS1 = 0;
	}

	if (0 != pS2)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS2[i])
			{
				free(pS2[i]);
			}
			pS2[i] = 0;
		}
		free(pS2);
		pS2 = 0;
	}

	if (0 != pS3)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS3[i])
			{
				free(pS3[i]);
			}
			pS3[i] = 0;
		}
		free(pS3);
		pS3 = 0;
	}

	if (0 != pS4)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS4[i])
			{
				free(pS4[i]);
			}
			pS4[i] = 0;
		}
		free(pS4);
		pS4 = 0;
	}

	if (0 != pS5)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS5[i])
			{
				free(pS5[i]);
			}
			pS5[i] = 0;
		}
		free(pS5);
		pS5 = 0;
	}

	if (0 != pS6)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS6[i])
			{
				free(pS6[i]);
			}
			pS6[i] = 0;
		}
		free(pS6);
		pS6 = 0;
	}

	if (0 != pS7)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS7[i])
			{
				free(pS7[i]);
			}
			pS7[i] = 0;
		}
		free(pS7);
		pS7 = 0;
	}

	if (0 != pS8)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS8[i])
			{
				free(pS8[i]);
			}
			pS8[i] = 0;
		}
		free(pS8);
		pS8 = 0;
	}

	if (0 != pS9)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS9[i])
			{
				free(pS9[i]);
			}
			pS9[i] = 0;
		}
		free(pS9);
		pS9 = 0;
	}

	if (0 != pS10)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pS10[i])
			{
				free(pS10[i]);
			}
			pS10[i] = 0;
		}
		free(pS10);
		pS10 = 0;
	}

	if (0 != pP1)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pP1[i])
			{
				free(pP1[i]);
			}
			pP1[i] = 0;
		}
		free(pP1);
		pP1 = 0;
	}

	if (0 != pP2)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pP2[i])
			{
				free(pP2[i]);
			}
			pP2[i] = 0;
		}
		free(pP2);
		pP2 = 0;
	}

	if (0 != pP3)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pP3[i])
			{
				free(pP3[i]);
			}
			pP3[i] = 0;
		}
		free(pP3);
		pP3 = 0;
	}

	if (0 != pP4)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pP4[i])
			{
				free(pP4[i]);
			}
			pP4[i] = 0;
		}
		free(pP4);
		pP4 = 0;
	}

	if (0 != pP5)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pP5[i])
			{
				free(pP5[i]);
			}
			pP5[i] = 0;
		}
		free(pP5);
		pP5 = 0;
	}

	if (0 != pP6)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pP6[i])
			{
				free(pP6[i]);
			}
			pP6[i] = 0;
		}
		free(pP6);
		pP6 = 0;
	}

	if (0 != pP7)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (0 != pP7[i])
			{
				free(pP7[i]);
			}
			pP7[i] = 0;
		}
		free(pP7);
		pP7 = 0;
	}



	return nReturnValue;
}