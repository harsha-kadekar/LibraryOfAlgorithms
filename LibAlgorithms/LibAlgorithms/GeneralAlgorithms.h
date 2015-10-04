#ifndef GENERALALGORITHMS_H
#define GENERALALGORITHMS_H

#include "ErrorCodes.h"
#include <stdlib.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

	_declspec(dllimport) int AddingTwoBinaryNumbers(int* pFirstNumber, int* pSecondNumber, int nSize, int* pResultant);
	_declspec(dllimport) int FindMaximumSubArray(int* pIntArray, int nSize, int* plow, int* phigh, int* psum);
	_declspec(dllimport) int MatrixMultiplicationBasic(int** pMatrixA, int Am, int An, int** pMatrixB, int Bm, int Bn, int** pMatrixC);
	_declspec(dllimport) int MatrixMultiplicationStrassen(int** pMatrixA, int** pMatrixB, int nSize, int** pMatrixC);
	_declspec(dllimport) int FindMaxSubArrayBruteForce(int* pIntArray, int nSize, int* pLowRes, int* pHighRes, int *pSumRes);
	_declspec(dllimport) int FindMaxSubArrayLinear(int* pIntArray, int nSize, int *pLow, int*pHigh, int* pSum);

#ifdef __cplusplus
}
#endif

int FindMaxSubArrayRec(int* pIntArray, int nLow, int nHigh, int* pLowRes, int* pHighRes, int* pSumRes);
int FindMaxCrossingSubArray(int* pIntArray, int nLow, int nMid, int nHigh, int* pLowRes, int* pHighRes, int* pSumRes);
int StrassenImplementation(int** pMatrixA, int AmStart, int AnStart, int** pMatrixB, int BmStart, int BnStart, int nSize, int** pMatrixC);
int AddTwoSquareMatrix(int** pMatrixA, int nAmStart, int nAnStart, int** pMatrixB, int nBmStart, int nBnStart, int nSize, int** pResult);
int SubtractTwoSquareMatrix(int** pMatrixA, int nAmStart, int nAnStart, int** pMatrixB, int nBmStart, int nBnStart, int nSize, int** pResult);
int FreeUpMemory(int** pS1, int **pS2, int **pS3, int **pS4, int** pS5, int** pS6, int **pS7, int** pS8, int** pS9, int** pS10, int** pP1, int** pP2, int** pP3, int** pP4, int** pP5, int** pP6, int** pP7, int nSize);



#endif
