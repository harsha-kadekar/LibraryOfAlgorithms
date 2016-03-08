//#pragma once
//
//class COpenAddDictionary
//{
//private:
//	double dLoadFactor;
//	int nSizeOfBucket;
//	int nCurrentSize;
//	char **pBuckets;
//
//	unsigned long HashFunction(char* str);
//protected:
//public:
//	double GetLoadFactor();
//	int SizeOfBucket();
//	int CountOfElements();
//	bool isKeyPresent(char *strKey);
//	bool isKeyPresent(int nKey);
//	bool isKeyPresent(double dKey);
//	bool isKeyPresent(char chKey);
//	char* GetValue(char* strKey);
//	char* GetValue(int nKey);
//	char* GetValue(double dkey);
//	char* GetValue(char chKey);
//	int SetValue(char* strKey, char* strValue);
//	int SetValue(int nKey, int nValue);
//	int SetValue(int nKey, char* strValue);
//	int SetValue(int nKey, double dValue);
//	int SetValue(int nKey, char chValue);
//	int SetValue(double dKey, double dValue);
//	int SetValue(double dKey, char* strValue);
//	int SetValue(char* strKey, double dValue);
//	int RebuildHashTable(int nNewSizeOfBucket);
//
//	COpenAddDictionary();
//	COpenAddDictionary(double dLoadFactor, int nSize);
//	~COpenAddDictionary();
//
//};
