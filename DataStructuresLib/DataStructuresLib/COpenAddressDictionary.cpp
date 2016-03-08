//#include"COpenAddressDictionary.h"
//
//COpenAddDictionary::COpenAddDictionary()
//{
//	dLoadFactor = 0.7;
//	nSizeOfBucket = 10;
//	nCurrentSize = 0;
//
//	pBuckets = new char*();
//}
//
//COpenAddDictionary::COpenAddDictionary(double dLoad, int nSize)
//{
//	dLoadFactor = dLoad;
//	nSizeOfBucket = nSize;
//	nCurrentSize = 0;
//	pBuckets = new char*();
//}
//
////http://stackoverflow.com/questions/7666509/hash-function-for-string
//unsigned long COpenAddDictionary::HashFunction(char* strKey)
//{
//
//	unsigned long hash = 5381;
//	int c;
//
//	while (c = *strKey++)
//		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//
//	return hash;
//}
//
