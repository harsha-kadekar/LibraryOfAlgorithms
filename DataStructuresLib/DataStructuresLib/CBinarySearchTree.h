#pragma once

#include<iostream>

using namespace std;

typedef struct structBinaryNode
{
	string strNameValue;
	struct structBinaryNode *pParent;
	struct structBinaryNode *pLeft;
	struct structBinaryNode *pRight;
}Node;


class CBinarySearchDictionary
{
private:
	Node *root; //*pCurrent;
	int nCount;

	int IndexOfSeparator(string strNameValue);
	Node* GetNode(string strKey);
	bool DeleteTree(Node* pNode);
	//Node* GetSuccessor(Node *pNode);
	//Node* GetPredecessor(Node *pNode);

	string preorder_traversal(Node *pNode);
	string postorder_traversal(Node *pNode);
	string inorder_traversal(Node *pNode);

public:
	bool FindKey(string strKey);
	bool InsertKeyValue(string strKey, string strValue);
	//bool DeleteKey(string strKey);
	string GetItem(string strKey);

	int GetCount()
	{
		return nCount;
	}

	CBinarySearchDictionary();
	virtual ~CBinarySearchDictionary();

	string preorder();
	string postorder();
	string inorder();

	//Node* Begin();
	//Node* End();
	//Node* Next();

};