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
		printf("2. Searching Algorithms\n");
		printf("3. General Algorithms\n");
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
			case 2:
			{
				TestSearchingFunctions();
				break;
			}
			case 3:
			{
				TestGeneralAlgorithms();
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

int TestSearchingFunctions()
{
	int nReturnValue = 0;
	int nChoice = -1;
	int nKey = -1;
	int nSize = 0;
	int* pIntArray = 0;

	while (nChoice != 0)
	{
		printf("\n****************************SEARCHING TESTING MODULE************************************\n");
		printf("Menu:\n");
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("0. Exit\n");
		printf("\n**************************************************************************************\n");

		scanf_s("%d", &nChoice);

		switch (nChoice)
		{
			case 0:
			{
				printf("Exiting Searching module\n");
				break;
			}
			case 1:
			{
				nSize = 0;
				printf("\n\nLINEAR SEARCH TESTING:\n\n");
				while (nSize <= 0)
				{
					printf("Enter the length of array\n");
					scanf_s("%d", &nSize);

				}

				pIntArray = (int*)malloc(nSize*sizeof(int));
				if (pIntArray == 0)
				{
					printf("ERROR::Memory could not be allocated to the array. Cannot proceed further\n");
				}
				else
				{
					printf("Please enter the integers to store in array. SIZE = %d\n", nSize);
					for (int i = 0; i < nSize; i++)
					{
						scanf_s("%d", &pIntArray[i]);
					}

					printf("Done adding to array. Redisplaying to confirm\n");
					for (int i = 0; i < nSize; i++)
						printf("%d\n", pIntArray[i]);

					printf("\nPlease enter the key which needs to be searched in array\n");
					scanf_s("%d", &nKey);

					printf("\nRedisplaying the key to confirm\n%d\n", nKey);

					printf("\n------------------------------------------------------------------------------\n");

					HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
					if (0 == hLibMod)
					{
						printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

						free(pIntArray);
					}
					else
					{
						GeneralSearchFunc LinearSearch = 0;

						LinearSearch = (GeneralSearchFunc)GetProcAddress(hLibMod, "LinearSearchIntegers");

						if (0 == LinearSearch)
						{
							printf("ERROR::Could Not get the address of the fuction LinearSearchIntegers\n");

							FreeLibrary(hLibMod);
							hLibMod = 0;

							free(pIntArray);

						}
						else
						{
							nReturnValue = LinearSearch(pIntArray, nSize, nKey);
							if (nReturnValue < -1)
							{
								printf("\nERROR occured during searching. Returned Value is %d\n", nReturnValue);
								FreeLibrary(hLibMod);
								free(pIntArray);
							}
							else
							{

								printf("\nFound at index %d. Array:\n", nReturnValue);
								for (int i = 0; i < nSize; i++)
									printf("%d\n", pIntArray[i]);

								printf("\nFound at index %d.\n", nReturnValue);

								printf("\n----------------------------------------------------------------------\n");

								nReturnValue = 0;

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
				printf("\n\nBINARY SEARCH TESTING:\n\n");
				while (nSize <= 0)
				{
					printf("Enter the length of array\n");
					scanf_s("%d", &nSize);

				}

				pIntArray = (int*)malloc(nSize*sizeof(int));
				if (pIntArray == 0)
				{
					printf("ERROR::Memory could not be allocated to the array. Cannot proceed further\n");
				}
				else
				{
					printf("Please enter the integers to store in array. Remember its binary search so array should be sorted. SIZE = %d\n", nSize);
					for (int i = 0; i < nSize; i++)
					{
						scanf_s("%d", &pIntArray[i]);
					}

					printf("Done adding to array. Redisplaying to confirm\n");
					for (int i = 0; i < nSize; i++)
						printf("%d\n", pIntArray[i]);

					printf("\nPlease enter the key which needs to be searched in array\n");
					scanf_s("%d", &nKey);

					printf("\nRedisplaying the key to confirm\n%d\n", nKey);

					printf("\n------------------------------------------------------------------------------\n");

					HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
					if (0 == hLibMod)
					{
						printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

						free(pIntArray);
					}
					else
					{
						GeneralSearchFunc BinarySearch = 0;

						BinarySearch = (GeneralSearchFunc)GetProcAddress(hLibMod, "BinarySearchIntegers");

						if (0 == BinarySearch)
						{
							printf("ERROR::Could Not get the address of the fuction BinarySearchIntegers\n");

							FreeLibrary(hLibMod);
							hLibMod = 0;

							free(pIntArray);

						}
						else
						{
							nReturnValue = BinarySearch(pIntArray, nSize, nKey);
							if (nReturnValue < -1)
							{
								printf("\nERROR occured during searching. Returned Value is %d\n", nReturnValue);
								FreeLibrary(hLibMod);
								free(pIntArray);
							}
							else
							{

								printf("\nFound at index %d. Array:\n", nReturnValue);
								for (int i = 0; i < nSize; i++)
									printf("%d\n", pIntArray[i]);

								printf("\nFound at index %d.\n", nReturnValue);

								printf("\n----------------------------------------------------------------------\n");

								nReturnValue = 0;

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
		printf("3. Selection Sort\n");
		printf("4. Bubble Sort\n");
		printf("5. Compare Sorting algorithms\n");
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
			case 3:
			{
				nSize = 0;
				printf("\n\nSELECTION SORT TESTING:\n\n");
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
						GeneralSortFunc SelectionSort = 0;

						SelectionSort = (GeneralSortFunc)GetProcAddress(hLibMod, "SelectionSortIntegers");

						if (0 == SelectionSort)
						{
							printf("ERROR::Could Not get the address of the fuction SelectionSortIntegers\n");

							FreeLibrary(hLibMod);
							hLibMod = 0;

							free(pIntArray);

						}
						else
						{
							nReturnValue = SelectionSort(pIntArray, nSize);
							if (0 != nReturnValue)
							{
								printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
								FreeLibrary(hLibMod);
								free(pIntArray);
							}
							else
							{
								printf("\nArray after sorting using Selection sort:\n");
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
			case 4:
			{
				nSize = 0;
				printf("\n\BUBBLE SORT TESTING:\n\n");
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
						GeneralSortFunc BubbleSort = 0;

						BubbleSort = (GeneralSortFunc)GetProcAddress(hLibMod, "BubbleSortIntegers");

						if (0 == BubbleSort)
						{
							printf("ERROR::Could Not get the address of the fuction BubbleSortIntegers\n");

							FreeLibrary(hLibMod);
							hLibMod = 0;

							free(pIntArray);

						}
						else
						{
							nReturnValue = BubbleSort(pIntArray, nSize);
							if (0 != nReturnValue)
							{
								printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
								FreeLibrary(hLibMod);
								free(pIntArray);
							}
							else
							{
								printf("\nArray after sorting using Bubble sort:\n");
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
			case 5:
			{
				printf("\nComparing different sorting algorithms time wise\n");
				nSize = 0;
				while (nSize <= 0)
				{
					printf("\nEnter the size of the array which needs to sorted\n");
					scanf_s("%d", &nSize);
				}

				pIntArray = (int*)malloc(sizeof(int)*nSize);
				if (pIntArray == 0)
				{
					printf("\nError could allocate memory\n");

				}
				else
				{
					int *pInt2 = 0;
					

					pInt2 = (int*)malloc(sizeof(int)*nSize);
					if (pInt2 == 0)
					{
						printf("\nError could not allocate memory\n");
					}
					else
					{
						srand(time(NULL));
						for (int i = 0; i < nSize; i++)
						{
							pIntArray[i] = rand() % 100;
							pInt2[i] = pIntArray[i];
						}

						DWORD t1 = 0, t2 = 0;

						HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
						if (0 == hLibMod)
						{
							printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

							free(pIntArray);
						}
						else
						{
							GeneralSortFunc sort = 0;

							sort = (GeneralSortFunc)GetProcAddress(hLibMod, "BubbleSortIntegers");

							if (0 == sort)
							{
								printf("ERROR::Could Not get the address of the fuction BubbleSortIntegers\n");

								/*FreeLibrary(hLibMod);
								hLibMod = 0;

								free(pIntArray);

								free(pInt2);*/

							}
							else
							{
								t1 = GetTickCount();
								nReturnValue = sort(pInt2, nSize);
								t2 = GetTickCount();
								printf("\nBubble sort: %dms\n", t2 - t1);
								if (0 != nReturnValue)
								{
									printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
									FreeLibrary(hLibMod);
									free(pIntArray);
								}
								
							}

							for (int i = 0; i < nSize; i++)
							{
								pInt2[i] = pIntArray[i];
							}

							sort = (GeneralSortFunc)GetProcAddress(hLibMod, "InsertionSortIntegers");

							if (0 == sort)
							{
								printf("ERROR::Could Not get the address of the fuction InsertionSortIntegers\n");

								//FreeLibrary(hLibMod);
								//hLibMod = 0;

								/*free(pIntArray);

								free(pInt2);*/

							}
							else
							{
								t1 = GetTickCount();
								nReturnValue = sort(pInt2, nSize);
								t2 = GetTickCount();
								printf("\nInsertion Sort: %dms\n", t2 - t1);
								if (0 != nReturnValue)
								{
									printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
									//FreeLibrary(hLibMod);
									//free(pIntArray);
								}

							}

							for (int i = 0; i < nSize; i++)
							{
								pInt2[i] = pIntArray[i];
							}

							sort = (GeneralSortFunc)GetProcAddress(hLibMod, "MergeSortIntegers");

							if (0 == sort)
							{
								printf("ERROR::Could Not get the address of the fuction MergeSortIntegers\n");

								//FreeLibrary(hLibMod);
								//hLibMod = 0;

								//free(pIntArray);

								//free(pInt2);

							}
							else
							{
								t1 = GetTickCount();
								nReturnValue = sort(pIntArray, nSize);
								t2 = GetTickCount();
								printf("\nMerge Sort: %dms\n", t2 - t1);
								if (0 != nReturnValue)
								{
									printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
									/*FreeLibrary(hLibMod);
									free(pIntArray);*/
								}

							}

							for (int i = 0; i < nSize; i++)
							{
								pInt2[i] = pIntArray[i];
							}
							sort = (GeneralSortFunc)GetProcAddress(hLibMod, "SelectionSortIntegers");

							if (0 == sort)
							{
								printf("ERROR::Could Not get the address of the fuction SelectionSortIntegers\n");

								//FreeLibrary(hLibMod);
								//hLibMod = 0;

								//free(pIntArray);

								//free(pInt2);

							}
							else
							{
								t1 = GetTickCount();
								nReturnValue = sort(pIntArray, nSize);
								t2 = GetTickCount();
								printf("\nSelection Sort: %dms\n", t2 - t1);
								if (0 != nReturnValue)
								{
									printf("\nERROR occured during sorting. Returned Value is %d\n", nReturnValue);
									//FreeLibrary(hLibMod);
									//free(pIntArray);
								}

							}
						}

						free(pInt2);
						pInt2 = 0;
						free(pIntArray);
						pIntArray = 0;

						FreeLibrary(hLibMod);
						hLibMod = 0;

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

int TestGeneralAlgorithms()
{
	int nReturnValue = 0;

	int nChoice = -1;
	int nKey = -1;
	int nSize = 0;
	int* pIntArray = 0;

	int Am = -1;
	int An = -1;
	int Bm = -1;
	int Bn = -1;
	int *Cm = 0;
	int *Cn = 0;

	int **pMatrixA = 0, **pMatrixB = 0, **pMatrixC = 0;

	while (nChoice != 0)
	{
		printf("\n****************************GENERAL ALGOS TESTING MODULE************************************\n");
		printf("Menu:\n");
		printf("1. Multiplication of Matrix (Basic)\n");
		printf("2. Find Sub Array having maximum Sum\n");
		printf("3. Addition of Binary numbers\n");
		printf("4. Strassens Matrix Multiplication Algorithm\n");
		printf("5. Random Strassen and Basic Matrix multiplication testing\n");
		printf("6. Generate Random numbers\n");
		printf("7. Test whether matrix multiplication works!!!!\n");
		printf("0. Exit\n");
		printf("\n**************************************************************************************\n");

		scanf_s("%d", &nChoice);

		switch (nChoice)
		{
		case 0:
		{
			printf("Exiting General Algorihms module\n");
			break;
		}
		case 1:
		{
			bool bErrorFound = false;
			nSize = 0;
			printf("\n\nMatrix Multiplication TESTING:\n\n");
			printf("\nMatrix A details\n");
			while (Am <= 0)
			{
				printf("\nEnter the rows of Matrix A\n");
				scanf_s("%d", &Am);
			}

			while (An <= 0)
			{
				printf("\nEnter the columns of Matrix A\n");
				scanf_s("%d", &An);
			}

			pMatrixA = (int**)malloc(Am*sizeof(int*));
			if (pMatrixA == 0)
			{
				printf("\nERROR::Not abe to alocate memeory. Returning\n");
				bErrorFound = true;
			}
			else
			{

				for (int i = 0; i < Am; i++)
				{
					pMatrixA[i] = (int*)malloc(An*sizeof(int));
					if (0 == pMatrixA[i])
					{
						printf("\nERROR::Not able to allocate memory. Returning\n");
						bErrorFound = true;
						break;
					}
				}

				if (bErrorFound)
				{
					for (int i = 0; i < Am; i++)
					{
						if (0 != pMatrixA[i])
						{
							free(pMatrixA[i]);
							pMatrixA[i] = 0;
						}
						else
						{
							break;
						}
					}

				}

				printf("\nEnter the values of Matrix A <<ROW wise - Enter 1st row then 2nd row like that>>\n");

				for (int i = 0; i < Am; i++)
				{
					printf("\nENTER %d ROW\n", i);
					for (int j = 0; j < An; j++)
					{
						printf("\nENTER %d COLUMN i.e. A[%d][%d] item\n", j, i, j);
						scanf_s("%d", &pMatrixA[i][j]);
					}
				}

				printf("\nRedisplaying Matrix A\n");
				for (int i = 0; i < Am; i++)
				{
					for (int j = 0; j < An; j++)
					{
						printf("%d\t", pMatrixA[i][j]);
					}
					printf("\n");
				}

				printf("\nMatrix B details\n");
				while (Bm <= 0)
				{
					printf("\nEnter the rows of Matrix B\n");
					scanf_s("%d", &Bm);
				}

				while (Bn <= 0)
				{
					printf("\nEnter the columns of Matrix B\n");
					scanf_s("%d", &Bn);
				}

				pMatrixB = (int**)malloc(Bm*sizeof(int*));
				if (pMatrixB == 0)
				{
					//ERROR handle it
				}

				for (int i = 0; i < Bm; i++)
				{
					pMatrixB[i] = (int*)malloc(Bn*sizeof(int));
					if (0 == pMatrixB[i])
					{
						//EROR handle it
					}
				}

				printf("\nEnter the values of Matrix B <<ROW wise - Enter 1st row then 2nd row like that>>\n");

				for (int i = 0; i < Bm; i++)
				{
					printf("\nENTER %d ROW\n", i);
					for (int j = 0; j < Bn; j++)
					{
						printf("\nENTER %d COLUMN i.e. B[%d][%d] item\n", j, i, j);
						scanf_s("%d", &pMatrixB[i][j]);
					}
				}


				printf("\nRedisplaying Matrix B\n");
				for (int i = 0; i < Bm; i++)
				{
					for (int j = 0; j < Bn; j++)
					{
						printf("%d\t", pMatrixB[i][j]);
					}
					printf("\n");
				}

				HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
				if (0 == hLibMod)
				{
					printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

					//HANDLE THE ERROR
				}
				else
				{


					MatrixMultiplicationBasic MatrixMultiplication = 0;

					MatrixMultiplication = (MatrixMultiplicationBasic)GetProcAddress(hLibMod, "MatrixMultiplicationBasic");

					if (0 == MatrixMultiplication)
					{
						printf("ERROR::Could Not get the address of the function MatrixMultiplicationBasic\n");

						FreeLibrary(hLibMod);
						hLibMod = 0;

						//HANLDE THE ERROR

					}
					else
					{
						pMatrixC = (int**)malloc(sizeof(int*)*Am);
						if (0 == pMatrixC)
						{
							//ERROR HANDLE
						}

						for (int i = 0; i < Am; i++)
						{
							pMatrixC[i] = (int*)malloc(sizeof(int)*Bn);
						}

						//Sleep(30000);

						nReturnValue = MatrixMultiplication(pMatrixA, Am, An, pMatrixB, Bm, Bn, pMatrixC);
						printf("\nDisplaying the Result\n");
						for (int i = 0; i < Am; i++)
						{
							for (int j = 0; j < Bn; j++)
							{
								printf("%d\t", pMatrixC[i][j]);
							}
							printf("\n");
						}

						for (int i = 0; i < Am; i++)
						{
							free(pMatrixC[i]);
							pMatrixC[i] = 0;
						}

						for (int i = 0; i < Am; i++)
						{
							free(pMatrixA[i]);
							pMatrixA[i] = 0;
						}

						free(pMatrixA);
						pMatrixA = 0;

						for (int i = 0; i < Bm; i++)
						{
							free(pMatrixB[i]);
							pMatrixB[i] = 0;
						}

						free(pMatrixB);
						pMatrixB = 0;

						FreeLibrary(hLibMod);
						hLibMod = 0;

					}
				}

			}
		
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			nSize = 0;

			printf("\nTESTING STRASSEN MULTIPLICATION\n");
			while (nSize <= 0)
			{
				printf("\nEnter the Size of the Matrices(Remember it is a square matrix)\n");
				scanf_s("%d",&nSize);
			}

			pMatrixA = (int**)malloc(nSize*(sizeof(int*)));
			if (pMatrixA == 0)
			{
				//Error handle it
			}
			else
			{
				for (int i = 0; i < nSize; i++)
				{
					pMatrixA[i] = (int*)malloc(sizeof(int)*nSize);
					if (0 == pMatrixA[i])
					{
						//Error handle it
					}
					else
					{
						for (int j = 0; j < nSize; j++)
						{
							pMatrixA[i][j] = 0;
						}
					}

				}

				pMatrixB = (int**)malloc(nSize*sizeof(int*));
				if (0 == pMatrixB)
				{
					//Error handle it
				}
				else
				{
					for (int i = 0; i < nSize; i++)
					{
						pMatrixB[i] = (int*)malloc(sizeof(int)*nSize);
						if (pMatrixB[i] == 0)
						{
							//Error handle it
						}
						else
						{
							for (int j = 0; j < nSize; j++)
							{
								pMatrixB[i][j] = 0;
							}
						}
					}

					pMatrixC = (int**)malloc(nSize*sizeof(int*));
					if (0 == pMatrixC)
					{
						//Error handle it
					}
					else
					{
						for (int i = 0; i < nSize; i++)
						{
							pMatrixC[i] = (int*)malloc(nSize*sizeof(int));
							if (0 == pMatrixC[i])
							{
								//Error handle it
							}
							else
							{
								for (int j = 0; j < nSize; j++)
								{
									pMatrixC[i][j] = 0;
								}
							}
						}

						printf("\nEnter the elements of matrix A\n");
						for (int i = 0; i < nSize; i++)
						{
							for (int j = 0; j < nSize; j++)
							{
								printf("\nEnter the A[%d][%d]\n", i, j);
								scanf_s("%d", &pMatrixA[i][j]);
							}
						}

						printf("\nRedisplaying the elements of matrix A\n");
						for (int i = 0; i < nSize; i++)
						{
							for (int j = 0; j < nSize; j++)
							{
								printf("%d\t", pMatrixA[i][j]);
							}
							printf("\n");
						}

						printf("\nEnter the elements of matrix B\n");
						for (int i = 0; i < nSize; i++)
						{
							for (int j = 0; j < nSize; j++)
							{
								printf("\nEnter the B[%d][%d]\n", i, j);
								scanf_s("%d", &pMatrixB[i][j]);
							}
						}

						printf("\nRedisplaying the elements of matrix B\n");
						for (int i = 0; i < nSize; i++)
						{
							for (int j = 0; j < nSize; j++)
							{
								printf("%d\t", pMatrixB[i][j]);
							}
							printf("\n");
						}

						HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
						if (0 == hLibMod)
						{
							printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

							//HANDLE THE ERROR
						}
						else
						{
							//printf("\nHook it up\n");
							//Sleep(30000);

							MatrixMultiplicationStrassen MatrixMultiplication = 0;

							MatrixMultiplication = (MatrixMultiplicationStrassen)GetProcAddress(hLibMod, "MatrixMultiplicationStrassen");

							if (0 == MatrixMultiplication)
							{
								printf("ERROR::Could Not get the address of the function MatrixMultiplicationBasic\n");

								FreeLibrary(hLibMod);
								hLibMod = 0;

								//HANLDE THE ERROR

							}
							else
							{
								nReturnValue = MatrixMultiplication(pMatrixA, pMatrixB, nSize, pMatrixC);
								if (nReturnValue != 0)
								{
									//Error handle it
								}
								else
								{
									printf("\nResultant matrix after multiplication:\n");
									for (int i = 0; i < nSize; i++)
									{
										for (int j = 0; j < nSize; j++)
										{
											printf("%d\t", pMatrixC[i][j]);
										}
										printf("\n");
									}

									printf("\n----------------------------------------------------------------------\n");
								}
							}
						}
						FreeLibrary(hLibMod);
						hLibMod = 0;
					}
				}
			}

			if (pMatrixA != 0)
			{
				for (int i = 0; i < nSize; i++)
				{
					if (pMatrixA[i] != 0)
					{
						free(pMatrixA[i]);
						pMatrixA[i] = 0;
					}
					
				}

				free(pMatrixA);
				pMatrixA = 0;
			}

			if (pMatrixB != 0)
			{
				for (int i = 0; i < nSize; i++)
				{
					if (pMatrixB[i] != 0)
					{
						free(pMatrixB[i]);
						pMatrixB[i] = 0;
					}

				}

				free(pMatrixB);
				pMatrixB = 0;
			}

			if (pMatrixC != 0)
			{
				for (int i = 0; i < nSize; i++)
				{
					if (pMatrixC[i] != 0)
					{
						free(pMatrixC[i]);
						pMatrixC[i] = 0;
					}

				}

				free(pMatrixC);
				pMatrixC = 0;
			}

			break;
		}
		case 5:
		{
			nSize = 0;
			while (nSize <= 0)
			{
				printf("\nEnter the size of square matrix to be generated\n");
				scanf_s("%d", &nSize);
			}

			//For generating random square matrix used following code -> Modified: http://stackoverflow.com/questions/13589248/generating-random-matrix-in-c
			pMatrixA = (int**)malloc(sizeof(int*)*nSize);
			if (0 == pMatrixA)
			{
				//Error handle it
			}
			else
			{
				for (int i = 0; i < nSize; i++)
				{
					pMatrixA[i] = (int*)malloc(sizeof(int)*nSize);
					if (pMatrixA[i] == 0)
					{
						//Error handle it
					}
					else
					{
						for (int j = 0; j < nSize; j++)
						{
							pMatrixA[i][j] = 0;
						}
					}
				}

				pMatrixB = (int**)malloc(sizeof(int*)*nSize);
				if (pMatrixB == 0)
				{
					//Error handle it
				}
				else
				{
					for (int i = 0; i < nSize; i++)
					{
						pMatrixB[i] = (int*)malloc(sizeof(int)*nSize);
						if (pMatrixB[i] == 0)
						{
							//Error handle it
						}
						else
						{
							for (int j = 0; j < nSize; j++)
							{
								pMatrixB[i][j] = 0;
							}
						}
					}

					int** pMatrixC2 = (int**)malloc(sizeof(int*)*nSize);
					if (pMatrixC2 == 0)
					{
						//Error handle it
					}
					else
					{
						for (int i = 0; i < nSize; i++)
						{
							pMatrixC2[i] = (int*)malloc(sizeof(int)*nSize);
							if (pMatrixC2[i] == 0)
							{
								//Error handle it
							}
							else
							{
								for (int j = 0; j < nSize; j++)
									pMatrixC2[i][j] = 0;
							}
						}
					}
					pMatrixC = (int**)malloc(sizeof(int*)*nSize);
					if (pMatrixC == 0)
					{
						//Error handle it
					}
					else
					{
						for (int i = 0; i < nSize; i++)
						{
							pMatrixC[i] = (int*)malloc(sizeof(int)*nSize);
							if (pMatrixC[i] == 0)
							{
								//Error handle it
							}
							else
							{
								for (int j = 0; j < nSize; j++)
								{
									pMatrixC[i][j] = 0;
								}
							}	
						}

						//Random matrix
						srand(time(NULL));
						for (int i  = 0; i<nSize; i++)
							for (int j = 0; j<nSize; j++)
								pMatrixA[i][j] = rand()%100;

						for (int i = 0; i<nSize; i++)
							for (int j = 0; j<nSize; j++)
								pMatrixB[i][j] = rand() % 100;


						//Load library
						HMODULE hLibMod = LoadLibrary(L"LibAlgorithms.dll");
						if (0 == hLibMod)
						{
							printf("\nERROR:: COULD NOT LOAD LIBRARY LibAlgorithms.dll\n");

							//HANDLE THE ERROR
						}
						else
						{
							//First is Basic Matrix
							MatrixMultiplicationBasic MatrixMulti1;

							MatrixMulti1 = (MatrixMultiplicationBasic)GetProcAddress(hLibMod, "MatrixMultiplicationBasic");
							DWORD t1 = 0, t2 = 0, t3 = 0, t4 = 0;

							t1 = GetTickCount();
							nReturnValue = MatrixMulti1(pMatrixA, nSize, nSize, pMatrixB, nSize, nSize, pMatrixC);

							t2 = GetTickCount();

							printf("\n\nBRUTE FORCE MATRIX MULTIPLICATION: %dms\n\n", t2 - t1);

							if (nReturnValue != 0)
							{
								printf("\nError while executing function - strassen %d\n", nReturnValue);
							}

							/*for (int i = 0; i < nSize; i++)
							{
								for (int j = 0; j < nSize; j++)
								{
									pMatrixC[i][j] = 0;
								}
							}*/

							//Second is Strassen
							nReturnValue = 0;
							MatrixMultiplicationStrassen MatrixMult2;

							MatrixMult2 = (MatrixMultiplicationStrassen)GetProcAddress(hLibMod, "MatrixMultiplicationStrassen");

							//printf("\nHook it up\n");
							//Sleep(30000);

							t3 = GetTickCount();

							nReturnValue = MatrixMult2(pMatrixA, pMatrixB, nSize, pMatrixC2);

							t4 = GetTickCount();

							if (nReturnValue != 0)
							{
								printf("\nError while executing function - strassen %d\n", nReturnValue);
							}

							
							printf("\n\nSTRASSEN MATRIX MULTIPLICATION: %dms\n\n", t4 - t3);

							bool bNotMatching = false;
							for (int i = 0; i < nSize; i++)
							{
								for (int j = 0; j < nSize; j++)
								{
									if (pMatrixC[i][j] != pMatrixC2[i][j])
									{
										printf("\nMatrix Multiplication is not matching\n");
										bNotMatching = true;
										break;
									}
								}
								if (bNotMatching)
									break;
							}

							FreeLibrary(hLibMod);
							//free(hLibMod);
							hLibMod = NULL;

							for (int i = 0; i < nSize; i++)
							{
								free(pMatrixA[i]);
								pMatrixA[i] = 0;
							}
							free(pMatrixA);
							pMatrixA = 0;
							
							for (int i = 0; i < nSize; i++)
							{
								free(pMatrixB[i]);
								pMatrixB[i] = 0;
							}
							free(pMatrixB);
							pMatrixB = 0;

							for (int i = 0; i < nSize; i++)
							{
								free(pMatrixC[i]);
								pMatrixC[i] = 0;
							}
							free(pMatrixC);
							pMatrixC = 0;

						}
					}
				}
			}


			
			break;
		}
		case 6:
		{
			nSize = 0;
			printf("\nGenerating random numbers\n");
			while(nSize <= 0)
			{
				printf("\nEnter the number of random numbers to be generated\n");
				scanf_s("%d", &nSize);
			}

			srand(time(NULL));
			for (int i = 0; i < nSize; i++)
			{
				printf("%d\n", rand()%100);
			}
			
			break;
		}
		case 7:
		{
			nSize = 0;
			printf("\nTesting the equality of different approches for matrix multiplication\n");
			while (nSize < 0)
			{
				printf("\nEnter the number size of matrix\n");
				scanf_s("%d", &nSize);
			}


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






