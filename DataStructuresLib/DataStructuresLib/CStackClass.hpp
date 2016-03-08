#pragma once

template <class T> CStack
{
public:
	CStack(int nSize);
	~CStack();

	int Push(T item);
	T Pop();
	int GetErrorStatus();
	int TopOfStack();

private:
	int m_nTop;
	int m_nErrorStatus;
	T *m_pStorage;
	int m_nSizeOfStack;
};


template <class T>
CStack::CStack(int nSize)
{
	m_nSizeOfStack = nSize;
	m_nTop = -1;
	m_nErrorStatus = 0;
	m_pStorage = new T(nSize);
}

template <class T>
CStack::~CStack()
{
	if (m_pStorage != 0)
		delete[] m_pStorage;

	m_pStorage = 0;
	m_nErrorStatus = 0;
	m_nSizeOfStack = 0;
	m_nTop = -1;
}

template <class T>
int CStack::Push(T item)
{
	if (m_nTop == m_nSizeOfStack - 1)
	{
		m_nErrorStatus = -2; //Stack Overflow
	}
	else
	{
		m_nStorage[++m_nTop] = item;
		m_nErrorStatus = 0;
	}

	return m_nErrorStatus;

}

template <class T>
T CStack::Pop()
{
	T temp;

	if (m_nTop == -1)
	{
		m_nErrorStatus = -1; //Stack Underflow
	}
	else
	{
		temp = m_pStorage[m_nTop--];
	}

	return temp;
}

template <class T>
int GetErrorStatus()
{
	return m_nErrorStatus;
}


template <class T>
int TopOfStack()
{
	return m_nTop;
}