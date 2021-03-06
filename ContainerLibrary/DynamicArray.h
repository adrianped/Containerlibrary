#pragma once
#include <memory.h>

template<typename T>
class DynamicArray
{
public:
	DynamicArray(int initialSize)
	{
		m_pStorage = new T[initialSize];
		m_nCapacity = initialSize;
		m_nUsed = 0;
	}

	~DynamicArray()
	{
		delete[] Storage;
	}

	void PushBack(T newElement)
	{
		Resize();
		m_pStorage[m_nUsed] = newElement;
		m_nUsed += 1;
	}

	void PushFront(T newElement)
	{
		Insert(newElement, 0);
	}

	void Insert(T newElement, int Index)
	{
		for (int i = m_nUsed; i < Index; --i)
		{
			m_pStorage[i] = m_pStorage[i - 1];
		}
		m_pStorage[Index] = newElement;
	}

	T PopBack()
	{
		m_nUsed -= 1;
		return m_pStorage[m_nUsed]
	}

	T PopFront()
	{
		return Remove(0);
	}

	T Remove(int Index)
	{
		T Temp;
		Temp = m_pStorage[Index];
		m_pStorage[Index] = m_pStorage[m_nUsed - 1];
		m_nUsed -= 1;

		return Temp;
	}

	void clear()
	{
		m_nUsed = 0;
	}

	void Shrink()
	{
		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
			nCapacity = 1;

		T* newData = new T[nCapacity];
		memcpy(newData, m_pData, sizeof(T) * nCapacity);
		delete m_pData;
		m_pData = newData;
		m_nCapacity = nCapacity;
	}

	void GetSize()
	{
		return m_nUsed;
	}

	void GetCapacity()
	{
		return m_nCapacity;
	}

private:

	void Resize() 
	{
		if (m_nUsed == m_nCapacity)
		{
			int newData = new T[m_nCapacity * 2];
			memcpy(newData, m_pStorage, m_nCapacity * sizeof(T));
			delete m_pStorage;
			m_pStorage = newData;
			m_nCapacity *= 2;
		}
	}

	T* m_pStorage;
	int m_nCapacity;
	int m_nUsed;
	
};

