#ifndef SEARCHINGALGORITHMS_H
#define SEARCHINGALGORITHMS_H

#include "ErrorCodes.h"

#ifdef __cplusplus
extern "C" {
#endif

	_declspec(dllimport) int LinearSearchIntegers(int* pIntArray, int nSize, int nKey);
	_declspec(dllimport) int BinarySearchIntegers(int* pIntArray, int nSize, int nKey);

#ifdef __cplusplus
}
#endif

#endif
