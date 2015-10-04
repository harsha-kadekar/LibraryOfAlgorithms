#ifndef CSINGLYLIST_H
#define CSINGLYLIST_H

#include <iostream>
#include "ErrorCodes.h"

using namespace std;

class CSinglyList
{
private:
	int nLength;
	struct Node
	{
		int nData;
		struct Node* pNext;
	}*pHeadPointer,*pCurrent;
protected:
public:
	CSinglyList();
	~CSinglyList();

	int InsertItemAtFront(int nItem);
	int InsertItemAtEnd(int nItem);
	int InsertAfter(int nItem, int nReference);
	int InsertBefore(int nItem, int nReference);
	int InsertAt(int nPos, int nItem);
	int InsertAtCurrentPos(int nItem);

	int DeleteItemAtFront();
	int DeleteItemAtEnd();
	int DeleteItem(int nItem);
	int DeleteAfter(int nItem);
	int DeleteBefore(int nItem);
	int DeleteAt(int nPos);
	int DeleteAtCurretPos();

	int GetFirstElement();
	int GetLastElement();
	int GetPositionOfNode(int nItem);
	int GetCurrentElement();

	int SortList(bool bAscending);
	int Length();

	int* GetAsAnArray();

	int MoveFirst();
	int MoveLast();
	int MoveToPosition(int nPos);
	int MoveToNext();

};

#endif
