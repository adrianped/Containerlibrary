#pragma once
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

	void PushBack(int newElement)
	{
		if (m_nUsed == m_nCapacity)
		{
			int newData = new T[m_nCapacity * 2];
			
		}
	}

	void PushFront()
	{
		
	}

	void Insert()
	{

	}

	void PopBack()
	{

	}

	void PopFront()
	{

	}

	void Remove()
	{

	}

	void clear()
	{

	}

	void Shrink()
	{

	}

	void GetSize()
	{

	}

	void GetCapacity()
	{

	}

private:

	void Resize;

	T* m_pStorage;
	int m_nCapacity;
	int m_nUsed;
	
};

