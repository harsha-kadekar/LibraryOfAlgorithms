#include "CBinarySearchTree.h"

CBinarySearchDictionary::CBinarySearchDictionary()
{
	nCount = 0;
	root = NULL;
}

int CBinarySearchDictionary::IndexOfSeparator(string strNameValue)
{
	int nIndex = -1;
	
	for (int i = 0; i < strNameValue.length(); i++)
	{
		if (strNameValue[i] == ':')
		{
			if (i + 2 < strNameValue.length())
			{
				if (strNameValue[i + 1] == '-' && strNameValue[i + 2] == ':')
				{
					nIndex = i;
					break;
				}
			}
			else
			{
				//Basically you could not find the separator in the string
				break;
			}
		}

	}
	

	return nIndex;
}

Node* CBinarySearchDictionary::GetNode(string strKey)
{
	Node *ptrCurrent = root;
	Node *pNode = NULL;

	string strTemp = "", strKeyTest = "";
	int nCompValue = 0;

	while (ptrCurrent != NULL)
	{
		strTemp = ptrCurrent->strNameValue;

		strKeyTest = strTemp.substr(0, IndexOfSeparator(strTemp));

		nCompValue = strKey.compare(strKeyTest);

		if (0 == nCompValue)
		{
			pNode = ptrCurrent;
			break;
		}
		else if (nCompValue > 0)
		{
			ptrCurrent = ptrCurrent->pRight;
		}
		else
		{
			ptrCurrent = ptrCurrent->pLeft;
		}


	}

	return pNode;
}

bool CBinarySearchDictionary::FindKey(string strKey)
{
	bool bReturnValue = false;
	Node *ptrCurrent = root;

	//ptrCurrent = Begin();
	ptrCurrent = GetNode(strKey);

	if (ptrCurrent != NULL)
	{
		bReturnValue = true;
	}

	return bReturnValue;

}

string CBinarySearchDictionary::GetItem(string strKey)
{
	string strValue = "";

	string strTemp = "";

	Node *ptrCurrent = GetNode(strKey);
	
	if (ptrCurrent != NULL)
	{
		strValue = ptrCurrent->strNameValue.substr(IndexOfSeparator(ptrCurrent->strNameValue) + 3);
	}

	return strValue;
}

bool CBinarySearchDictionary::InsertKeyValue(string strKey, string strValue)
{
	string strNameValue = strKey + ":-:" + strValue;
	Node *ptrTemp = NULL, *ptrPrev = NULL;
	string strTemp = "";

	Node *pNode = new Node();

	pNode->pLeft = NULL;
	pNode->pParent = NULL;
	pNode->pRight = NULL;
	pNode->strNameValue = strNameValue;

	ptrTemp = root;

	if (ptrTemp == NULL)
	{
		root = pNode;
		nCount++;
	}
	else
	{
		while (ptrTemp != NULL)
		{
			strTemp = ptrTemp->strNameValue.substr(0, IndexOfSeparator(ptrTemp->strNameValue));

			int nCompValue = strKey.compare(strTemp);

			if (nCompValue == 0)
			{
				ptrTemp->strNameValue = pNode->strNameValue;
				delete pNode;
				break;
			}
			else if (nCompValue > 0)
			{
				if(ptrTemp->pRight != NULL)
					ptrTemp = ptrTemp->pRight;
				else
				{
					ptrTemp->pRight = pNode;
					pNode->pParent = ptrTemp;
					nCount++;
					break;
				}

			}
			else
			{
				if (ptrTemp->pLeft != NULL)
				{
					ptrTemp = ptrTemp->pLeft;
				}
				else
				{
					ptrTemp->pLeft = pNode;
					pNode->pParent = ptrTemp;
					nCount++;
					break;
				}

			}

		}
	}

	return true;

}

bool CBinarySearchDictionary::DeleteTree(Node *pRoot)
{
	if (pRoot != NULL)
	{
		DeleteTree(pRoot->pLeft);
		DeleteTree(pRoot->pRight);

		delete pRoot;
		nCount--;
	}

	return true;
}

CBinarySearchDictionary::~CBinarySearchDictionary()
{
	DeleteTree(root);
}

string CBinarySearchDictionary::preorder_traversal(Node *pNode)
{
	string strValue = "";
	string strLeft = "";
	string strRight = "";

	if (pNode != NULL)
	{
		strLeft = preorder_traversal(pNode->pLeft);
		strRight = preorder_traversal(pNode->pRight);

		strValue = pNode->strNameValue + "\t" + strLeft + "\t" + strRight;
	}
	

	return strValue;
}

string CBinarySearchDictionary::preorder()
{
	return preorder_traversal(root);
}

string CBinarySearchDictionary::postorder_traversal(Node *pNode)
{
	string strValue = "";
	string strLeft = "";
	string strRight = "";

	if (pNode != NULL)
	{
		strLeft = postorder_traversal(pNode->pLeft);
		strRight = postorder_traversal(pNode->pRight);

		strValue = strLeft + "\t" + strRight + "\t" + pNode->strNameValue;
	}

	return strValue;
}

string CBinarySearchDictionary::postorder()
{
	return postorder_traversal(root);
}

string CBinarySearchDictionary::inorder_traversal(Node *pNode)
{
	string strValue = "";
	string strLeft = "";
	string strRight = "";

	if (pNode != NULL)
	{
		strLeft = inorder_traversal(pNode->pLeft);
		strRight = inorder_traversal(pNode->pRight);

		strValue = strLeft + "\t" + pNode->strNameValue + "\t" + strRight;
	}

	return strValue;
}

string CBinarySearchDictionary::inorder()
{
	return inorder_traversal(root);
}
