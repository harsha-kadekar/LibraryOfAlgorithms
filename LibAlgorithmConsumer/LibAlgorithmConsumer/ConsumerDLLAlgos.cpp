/*
This file contains functions which will consumer LibAlgorithms.dll exported functions. This is used as testing tool.
*/

#include "ConsumerDLLAlgos.h"

int main(int argc, char** argv)
{
	int nReturnValue = 0;
	int nChoice = -1;

	while (nChoice != 0)
	{
		printf("\n***************WELCOME TO TEST MODULE*******************\n");
		printf("Menu:\n");
		printf("1. Sorting Algorihms\n");
		printf("0. Exit\n");
		printf("Please enter your choice\n");
		printf("\n********************************************************\n");

		scanf_s("%d", &nChoice);

		switch (nChoice)
		{
			case 1:
			{
				TestSortingFunctions();
				break;
			}
			case 0:
			{
				printf("Exiting the program. Thank you!!!!\n");
				break;
			}
			default:
			{
				printf("Invalid option. Please enter a valid option\n");
				break;
			}
		}
	}

	return nReturnValue;
}

int TestSortingFunctions()
{
	int nReturnValue = 0;
	int nChoice = -1;

	int nSize = 0;
	int* pIntArray = 0;

	while (nChoice != 0)
	{
		printf("\n****************************SORTING TESTING MODULE************************************\n");
		printf("Menu:\n");
		printf("1. Insertion Sort\n");
		printf("2. Merge Sort\n");
		printf("0. Exit\n");
		printf("\n**************************************************************************************\n");

		scanf_s("%d", &nChoice);

		switch (nChoice)
		{
			case 0:
			{
				printf("Exiting Sorting module\n");
				break;
			}
			case 1:
			{
				nSize = 0;
				printf("\n\nINSERTION SORT TESTING:\n\n");
				while (nSize <= 0)
				{
					printf("Enter the number of integers to be sorted\n");
					scanf_s("%d", &nSize);
					
				}

				pIntArray = (int*)malloc(nSize*sizeof(int));
				if(pIntArray == 0)
				{
					printf("ERROR::Memory could not be allocated to the array. Cannot proceed further\n");
				}
				else
				{
					printf("Please enter the integers which needs to be sorted. SIZE = %d\n", nSize);
					for (int i = 0; i < nSize; i++)
					{
						scanf_s("%d", &pIntArray[i]);
					}

					printf("Done adding to array. Redisplaying to confirm\n");
					for (int i = 0; i < nSize; i++)
						printf("%d\n", pIntArray[i]);

					printf("\n------------------------------------------------------------------------------\n");

					HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
					if (0 == hLibMod)
					{
						printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

						free(pIntArray);
					}
					else
					{
						GeneralSortFunc InsertionSort = 0;

						InsertionSort = (GeneralSortFunc)GetProcAddress(hLibMod, "InsertionSortIntegers");

						if (0 == InsertionSort)
						{
							printf("ERROR::Could Not get the address of the fuction InsertionSortIntegers\n");

							FreeLibrary(hLibMod);
							hLibMod = 0;

							free(pIntArray);

						}
						else
						{
							nReturnValue = InsertionSort(pIntArray, nSize);
							if (0 != nReturnValue)
							{
								printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
								FreeLibrary(hLibMod);
								free(pIntArray);
							}
							else
							{
								printf("\nArray after sorting using insertion sort:\n");
								for (int i = 0; i < nSize; i++)
									printf("%d\n", pIntArray[i]);

								printf("\n----------------------------------------------------------------------\n");

								FreeLibrary(hLibMod);
								free(pIntArray);
							}
						}
					}


				}

				break;
			}
			case 2:
			{
				nSize = 0;
				printf("\n\nMERGE SORT TESTING:\n\n");
				while (nSize <= 0)
				{
					printf("Enter the number of integers to be sorted\n");
					scanf_s("%d", &nSize);

				}

				pIntArray = (int*)malloc(nSize*sizeof(int));
				if (pIntArray == 0)
				{
					printf("ERROR::Memory could not be allocated to the array. Cannot proceed further\n");
				}
				else
				{
					printf("Please enter the integers which needs to be sorted. SIZE = %d\n", nSize);
					for (int i = 0; i < nSize; i++)
					{
						scanf_s("%d", &pIntArray[i]);
					}

					printf("Done adding to array. Redisplaying to confirm\n");
					for (int i = 0; i < nSize; i++)
						printf("%d\n", pIntArray[i]);

					printf("\n------------------------------------------------------------------------------\n");

					HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
					if (0 == hLibMod)
					{
						printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

						free(pIntArray);
					}
					else
					{
						GeneralSortFunc MergeSort = 0;

						MergeSort = (GeneralSortFunc)GetProcAddress(hLibMod, "MergeSortIntegers");

						if (0 == MergeSort)
						{
							printf("ERROR::Could Not get the address of the fuction InsertionSortIntegers\n");

							FreeLibrary(hLibMod);
							hLibMod = 0;

							free(pIntArray);

						}
						else
						{
							nReturnValue = MergeSort(pIntArray, nSize);
							if (0 != nReturnValue)
							{
								printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
								FreeLibrary(hLibMod);
								free(pIntArray);
							}
							else
							{
								printf("\nArray after sorting using Merge sort:\n");
								for (int i = 0; i < nSize; i++)
									printf("%d\n", pIntArray[i]);

								printf("\n----------------------------------------------------------------------\n");

								FreeLibrary(hLibMod);
								free(pIntArray);
							}
						}
					}


				}
				break;
			}
			default:
			{
				printf("\n\nInvalid option selected. Please select a valid option\n");
				break;
			}
		}

	}
	return nReturnValue;
}






