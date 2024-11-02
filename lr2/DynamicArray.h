#pragma once
#include <iostream>

template <class T> class DynamicArray
{
private:
	T* arr;
	int size;


	void Copy(const DynamicArray& Array) {
		arr = new T[Array.size];
		size = Array.size;
		count = Array.count;
		for (int i = 0; i < size; i++) {
			arr[i] = Array.arr[i];
		}
	}
public:
	int count;

	DynamicArray() {
		arr = nullptr;
		size = 0;
		count = 0;
	}
	DynamicArray(int size)
	{
		arr = new T[size];
		this->size = size;
		this->count = 0;
	}
	DynamicArray(T* items, int size)
	{
		arr = new T[size];
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = items[i];
		}
		this->count = size;
	}
	DynamicArray(const DynamicArray& Array)
	{
		Copy(Array);
	}
	DynamicArray& operator=(const DynamicArray& Array)
	{
		if (this != &Array)
		{
			delete[] arr;
			Copy(Array);
		}
		return *this;
	}

	~DynamicArray()
	{
		delete[] arr;
	}
	int getSize()
	{
		return size;
	}
	int getCount()
	{
		return count;
	}
	void Set(int index, T value)
	{

		if (index < 0 || index >= size)
			throw std::out_of_range("Index is out of range");
		arr[index] = value;
	}




	T Get(int index)
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("Index is out of range");
		return arr[index];
	}
	T operator[](int index)
	{
		return Get(index);
	}
	void Resize(int newSize)
	{
		if (newSize < 0)
			throw std::out_of_range("Size of array must be more then 0");
		T* buffer = new T[newSize];
		for (int i = 0; i < newSize && i < size;i++)
			buffer[i] = arr[i];
		size = newSize;
		arr = buffer;
	}
};



