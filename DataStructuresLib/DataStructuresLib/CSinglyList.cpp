#include "CSinglyList.h"

/*
This is the constructor of the singly linked list
*/
CSinglyList::CSinglyList()
{
	nLength = 0;
	pCurrent = 0;
	pHeadPointer = 0;
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
				pHeadPointer = pNode;
				pCurrent = pNode;
				nLength++;
			}
			else
			{
				if (pHeadPointer == 0 || pCurrent == 0)
				{
					nReturnValue = ERR_INVALIDPOINTERREFERENCE;
					delete pNode;
					pNode = 0;
				}
				else
				{
					pNode->pNext = pHeadPointer;
					pCurrent = pNode;
					pHeadPointer = pNode;
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
			pHeadPointer = pNode;
			pCurrent = pHeadPointer;
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
				pHeadPointer = pCurrent;
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


	return nReturnValue;
}

int CSinglyList::MoveFirst()
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::MoveLast()
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::DeleteAfter(int nItem)
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::DeleteAt(int nPos)
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::DeleteAtCurretPos()
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::DeleteBefore(int nItem)
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::DeleteItem(int nItem)
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::DeleteItemAtEnd()
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::DeleteItemAtFront()
{
	int nReturnValue;

	return nReturnValue;
}

int* CSinglyList::GetAsAnArray()
{
	int* pArray = 0;

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
	if (pHeadPointer != 0)
	{
		MoveFirst();
		return pHeadPointer->nData;
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

	return nPos;
}

int CSinglyList::SortList(bool bAscending)
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::MoveToNext()
{
	int nReturnValue;

	return nReturnValue;
}

int CSinglyList::MoveToPosition(int nPos)
{
	int nReturnValue;

	return nReturnValue;
}
