#pragma once

template <class T>
class CQueue
{
public:
	CQueue(int nSize);
	~CQueue();

	int GetErrorStatus()
	{
		return m_nErrorStatus;
	}

	int Enqueue(T item);

	T Dequeue();

	int GetRearIndexOfQueue()
	{
		return m_nRear;
	}

	int GetFrontIndexOfQueue()
	{
		return m_nFront;
	}

private:
	int m_nSizeOfQueue;
	int m_nErrorStatus;
	T *m_pStorage;
	int m_nFront;
	int m_nRear;
};

template<class T>
CQueue::CQueue(int nSize)
{
	m_nSizeOfQueue = nSize;
	m_nErrorStatus = 0;
	m_nFront = -1;
	m_nRear = -1;

	m_pStorage = new T(nSize);
}

template<class T>
int CQueue::Enqueue(T item)
{
	if ((m_nRear + 1) % m_nSizeOfQueue == m_nFront)
	{
		//Queue is full
		m_nErrorStatus = -1;
	}
	else
	{
		m_nRear = (m_nRear + 1) % m_nSizeOfQueue;
		m_pStorage[m_nRear] = item;
		m_nErrorStatus = 0;
	}

	return m_nErrorStatus;
}

template<class T>
T CQueue::Dequeue()
{
	T temp;

	if (m_nRear == m_nFront)
	{
		//Queue is empty
		m_nErrorStatus = -2;
	}
	else
	{
		temp = m_pStorage[m_nFront];
		m_nFront = (m_nFront + 1) % m_nSizeOfQueue;
		m_nErrorStatus = 0;
	}

	return temp;
}

template<class T>
CQueue::~CQueue()
{
	if (m_pStorage != 0)
		delete[] m_pStorage;

	m_pStorage = 0;
	m_nRear = -1;
	m_nFront = -1;
	m_nErrorStatus = 0;
	m_nSizeOfQueue = 0;

}