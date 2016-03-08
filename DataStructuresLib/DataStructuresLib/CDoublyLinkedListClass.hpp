#pragma once

template<class T>
struct structDNode
{
	T data;
	struct DNode *pNext;
	struct DNode *pBefore;
};

typedef struct structDNode<class T> DNode;


template<class T>
class CDoublyLinkedList
{
public:
	CDoublyLinkedList();
	~CDoublyLinkedList();

	int InsertAtFront(T item);
	int InsertAtEnd(T item);
	int InsertAtPosition(T item, int nPosition);
	int InsertAfter(T item_toinsert, T item_after);
	int InsertBefore(T item_toinsert, T item_before);

	int FindItem(T item);

	int GetCount();

	T RemoveAtFront();
	T RemoveAtEnd();
	T RemoveAtPosition(int nPosition);
	T RemoveAfter(T item_after);
	T RemoveBefore(T item_before);

	int GetErrorStatus();

private:
	int nCount;
	int nErrorStatus;
	DNode *pHead;
};


template<class T>
CDoublyLinkedList::CDoublyLinkedList()
{
	nCount = 0;
	nErrorStatus = 0;
	pHead = 0;
}

template<class T>
CDoublyLinkedList::~CDoublyLinkedList()
{
	if (pHead != 0)
	{
		while (pHead != 0)
		{
			DNode* pCurrent = pHead;
			pHead = pHead->pNext;
			delete pCurrent;
		}

	}
}

template<class T>
int CDoublyLinkedList::InsertAtFront(T item)
{
	int nReturnValue = 0;
	if (pHead != NULL)
	{
		DNode* pTempNode = new DNode();
		pTempNode->Data = item;
		pTempNode->pNext = pHead->pNext;
		pTempNode->pBefore = NULL;
	}
	return nReturnValue;
}

