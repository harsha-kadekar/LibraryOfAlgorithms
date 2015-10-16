#include "CSinglyList.h"
#include "GeneralFunctionHeader.h"

/*
This is the constructor of the singly linked list
*/
CSinglyList::CSinglyList()
{
	nLength = 0;
	pCurrent = 0;
	pHeader = 0;
}

/*
This is the destructor of the singly linked list
*/
CSinglyList::~CSinglyList()
{

}

/*
This function will insert a new item at the start of the singly linked list
*/
int CSinglyList::InsertItemAtFront(int nItem)
{
	int nReturnValue = 0;
	Node *pNode = 0;
	
		pNode = new Node();
		if (pNode == 0)
		{
			nReturnValue = ERR_MEMORYALLOCATIONFAILED;
		}
		else
		{
			pNode->nData = nItem;
			pNode->pNext = 0;

			if (0 == nLength)
			{
				pHeader = pNode;
				pCurrent = pNode;
				nLength++;
			}
			else
			{
				if (pHeader == 0 || pCurrent == 0)
				{
					nReturnValue = ERR_INVALIDPOINTERREFERENCE;
					delete pNode;
					pNode = 0;
				}
				else
				{
					pNode->pNext = pHeader;
					pCurrent = pNode;
					pHeader = pNode;
					nLength++;
				}

			}
		}

	return nReturnValue;
}

/*
This function will give the number of nodes present in the list
*/
int CSinglyList::Length()
{
	return nLength;
}

/*
This function adds nItem at the end of list
*/
int CSinglyList::InsertItemAtEnd(int nItem)
{
	int nReturnValue = 0;
	Node* pNode = 0;

	pNode = new Node();
	if (pNode == 0)
	{
		nReturnValue = ERR_MEMORYALLOCATIONFAILED;
	}
	else
	{
		if (nLength = 0)
		{
			pNode->nData = nItem;
			pNode->pNext = 0;
			pHeader = pNode;
			pCurrent = pHeader;
			nLength++;
		}
		else
		{
			pNode->nData = nItem;
			pNode->pNext = 0;
			MoveLast();
			pCurrent->pNext = pNode;
			pCurrent = pNode;
			nLength++;

		}

	}

	return nReturnValue;
}

/*
This function adds the new item at the current position pointed by pCurrent pointer
*/
int CSinglyList::InsertAtCurrentPos(int nItem)
{
	int nReturnValue = 0;
	Node* pNode = 0;

	pNode = new Node();
	if (pNode == 0)
	{
		nReturnValue = ERR_MEMORYALLOCATIONFAILED;
	}
	else
	{
		pNode->nData = nItem;
		pNode->pNext = 0;

		if (pCurrent != 0)
		{
			pNode->pNext = pCurrent->pNext;
			pCurrent->pNext = pNode;
			pCurrent = pNode;
			nLength++;
		}
		else
		{
			if (nLength == 0)
			{
				pCurrent = pNode;
				pHeader = pCurrent;
				nLength++;
			}
			else
			{
				nReturnValue = ERR_INVALIDPOINTERREFERENCE;
				delete pNode;
				pNode = 0;

			}
		}
	}

	return nReturnValue;
}

/*
This function will insert the new item after the node containing nReference
*/
int CSinglyList::InsertAfter(int nItem, int nReference)
{
	int nReturnValue = 0;
	Node* pNode = 0;

	nReturnValue = MoveToPosition(GetPositionOfNode(nReference));
	if (0 == nReturnValue )
	{
		pNode = new Node();
		if (0 == pNode)
		{
			nReturnValue = ERR_MEMORYALLOCATIONFAILED;
		}
		else
		{
			pNode->pNext = 0;
			pNode->nData = nItem;

			pNode->pNext = pCurrent->pNext;
			pCurrent->pNext = pNode;
			pCurrent = pNode;
			nLength++;
		}

	}


	return nReturnValue;
}


/*
This function will insert the new item at a particular position
*/
int CSinglyList::InsertAt(int nPos, int nItem)
{
	int nReturnValue = 0;
	Node* pNode = 0;

	if (nPos == 0)
	{
		nReturnValue = InsertItemAtFront(nItem);
	}
	else
	{
		nReturnValue = MoveToPosition(nPos - 1);
		if (0 == nReturnValue)
		{
			pNode = new Node();
			if (0 == pNode)
			{
				nReturnValue = ERR_MEMORYALLOCATIONFAILED;
			}
			else
			{
				pNode->nData = nItem;
				pNode->pNext = pCurrent->pNext;
				pCurrent->pNext = pNode;
				pCurrent = pNode;
				nLength++;
			}

		}
	}

	return nReturnValue;
}

int CSinglyList::InsertBefore(int nItem, int nReference)
{
	int nReturnValue = 0;
	int nPos = -1;
	
	nPos = GetPositionOfNode(nReference);
	
	if (nPos == 0 || nPos == -1 || nPos == 1)
	{
		nReturnValue = InsertItemAtFront(nItem);
	}
	else
	{
		nReturnValue = InsertAt(nPos - 1, nItem);
	}

	return nReturnValue;
}

int CSinglyList::MoveFirst()
{
	int nReturnValue = 0;

	pCurrent = pHeader;

	return nReturnValue;
}

int CSinglyList::MoveLast()
{
	int nReturnValue = 0;

	pCurrent = pHeader;

	while (pCurrent->pNext != NULL)
		pCurrent = pCurrent->pNext;

	return nReturnValue;
}

int CSinglyList::DeleteAfter(int nItem)
{
	int nReturnValue = 0;
	Node* pDelNode = NULL;

	pCurrent = pHeader;

	while (pCurrent != NULL && pCurrent->nData != nItem)
		pCurrent = pCurrent->pNext;

	if (pCurrent != NULL)
	{
		pDelNode = pCurrent->pNext;
		if (pDelNode != NULL)
			pCurrent->pNext = pDelNode->pNext;
		else
			pCurrent->pNext = NULL;

		delete pDelNode;
		pDelNode = NULL;
		nLength--;
	}

	return nReturnValue;
}

Node* CSinglyList::GetNodeatPos(int nPos)
{
	Node* pNode = NULL;
	int nIndex = 0;

	pNode = pHeader;
	while (pNode != NULL && nIndex < nPos )
		pNode = pNode->pNext;

	return pNode;
}

int CSinglyList::DeleteAt(int nPos)
{
	int nReturnValue;
	Node* pDelNode = NULL;

	if (nPos == 0)
		nReturnValue = DeleteItemAtFront();
	else if (nPos == Length() - 1)
		nReturnValue = DeleteItemAtEnd();
	else
	{
		pCurrent = GetNodeatPos(nPos - 1);

		if (pCurrent != NULL)
		{
			pDelNode = pCurrent->pNext;
			if (pDelNode != NULL)
				pCurrent = pDelNode->pNext;
			else
				pCurrent->pNext = NULL;

			delete pDelNode;
			pDelNode = NULL;
			nLength--;
		}
	}

	return nReturnValue;
}

int CSinglyList::DeleteAtCurretPos()
{
	int nReturnValue = 0;
	Node *pDelNode = NULL;
	Node *pPrevNode = NULL;

	if (pCurrent != NULL)
	{
		if (pCurrent == pHeader)
		{
			pHeader = pCurrent->pNext;
			pDelNode = pCurrent;
			pCurrent = pHeader;

			delete pDelNode;
			pDelNode = NULL;
			nLength--;
		}
		else
		{
			pPrevNode = pHeader;
			while (pPrevNode->pNext != pCurrent)
				pPrevNode = pPrevNode->pNext;

			pPrevNode->pNext = pCurrent->pNext;

			pDelNode = pCurrent;
			pCurrent = pPrevNode;

			delete pDelNode;
			pDelNode = NULL;
			nLength--;

		}
	}

	return nReturnValue;
}

int CSinglyList::DeleteBefore(int nItem)
{
	int nReturnValue = 0;
	Node *pDelNode = NULL, *pPrevNode = NULL;
	int nPos = -1;

	nPos = GetPositionOfNode(nItem);

	if (nPos != 0 && nPos != -1)
	{
		if (nPos == 1)
		{
			nReturnValue = DeleteItemAtFront();
		}
		else
		{
			pDelNode = GetNodeatPos(nPos - 1);
			if (pPrevNode != NULL)
			{
				pPrevNode = pHeader;
				while (pPrevNode->pNext != pDelNode)
					pPrevNode = pPrevNode->pNext;

				pPrevNode->pNext = pDelNode->pNext;
				pCurrent = pPrevNode;

				delete pDelNode;
				pDelNode = NULL;
				nLength--;

			}
		}
	}

	return nReturnValue;
}

int CSinglyList::DeleteItem(int nItem)
{
	int nReturnValue = 0;
	Node *pPrevNode = NULL, *pDelNode = NULL;
	int nPos = GetPositionOfNode(nItem);

	if (nPos == 0)
		nReturnValue = DeleteItemAtFront();
	else if (nPos == nLength - 1)
		nReturnValue = DeleteItemAtEnd();
	else
	{
		pPrevNode = GetNodeatPos(nPos - 1);
		pDelNode = pPrevNode->pNext;
		pPrevNode->pNext = pDelNode->pNext;
		pCurrent = pPrevNode;

		delete pDelNode;
		pDelNode = NULL;
		nLength--;
	}

	return nReturnValue;
}

int CSinglyList::DeleteItemAtEnd()
{
	int nReturnValue = 0;
	Node* pPrevNode = NULL, *pDelNode = NULL;

	if (pHeader != NULL)
	{
		pCurrent = pHeader;

		while (pCurrent->pNext != NULL)
		{
			pPrevNode = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		pDelNode = pCurrent;
		pCurrent = pPrevNode;

		delete pDelNode;
		pDelNode = NULL;

		nLength--;
	}

	return nReturnValue;
}

int CSinglyList::DeleteItemAtFront()
{
	int nReturnValue = 0;
	Node *pDelNode = NULL;

	if (pHeader != NULL)
	{
		pDelNode = pHeader;
		pHeader = pDelNode->pNext;
		pCurrent = pHeader;

		delete pDelNode;
		pDelNode = NULL;

		nLength--;
	}

	return nReturnValue;
}

int* CSinglyList::GetAsAnArray()
{
	int* pArray = 0;
	Node *pTraverse = NULL;
	int i = 0;
	if (nLength > 0)
	{
		pArray = (int*)malloc(sizeof(int)*nLength);
		if (pArray != NULL)
		{
			pTraverse = pHeader;
			while (pTraverse != NULL)
			{
				pArray[i++] = pTraverse->nData;
				pTraverse = pTraverse->pNext;
			}
		}
	}
	return pArray;
}

int CSinglyList::GetCurrentElement()
{
	if (pCurrent != 0)
	{
		return pCurrent->nData;
	}
	else
	{
		return ERR_LISTISEMPTY;
	}
}

int CSinglyList::GetFirstElement()
{
	if (pHeader != 0)
	{
		MoveFirst();
		return pHeader->nData;
	}
	else
	{
		return ERR_LISTISEMPTY;
	}
}

int CSinglyList::GetLastElement()
{
	if (pCurrent != 0)
	{
		MoveLast();
		return pCurrent->nData;
	}
	else
	{
		return ERR_LISTISEMPTY;
	}
}

int CSinglyList::GetPositionOfNode(int nItem)
{
	int nPos = -1;
	Node *pTraverse = NULL;

	if (pHeader != NULL)
	{
		nPos++;
		pTraverse = pHeader;

		while (pTraverse != NULL && pTraverse->nData != nItem )
		{
			pTraverse = pTraverse->pNext;
			nPos++;
		}

		if (pTraverse == NULL)
			nPos = -1;
		else if (pTraverse->nData != nItem)
			nPos = -1;
	}

	return nPos;
}

int CSinglyList::SortList(bool bAscending)
{
	int nReturnValue = 0;
	int *pArray = NULL;
	int i = 0;
	Node *pTraverse = NULL;

	if (pHeader != NULL && nLength > 1)
	{
		pArray = GetAsAnArray();

			nReturnValue = QuickSortIntegers(pArray, nLength, bAscending);

			pTraverse = pHeader;

			while (pTraverse != NULL)
			{
				pTraverse->nData = pArray[i++];
				pTraverse = pTraverse->pNext;
			}

			delete pArray;
			pArray = NULL;

		

	}

	return nReturnValue;
}

int CSinglyList::MoveToNext()
{
	int nReturnValue = 0;

	if (pCurrent != NULL)
		pCurrent = pCurrent->pNext;

	return nReturnValue;
}

int CSinglyList::MoveToPosition(int nPos)
{
	int nReturnValue = 0;

	pCurrent = GetNodeatPos(nPos);

	return nReturnValue;
}
