#pragma once
#include "DynamicArray.h"
#include "Sequence.h"
template <class T> class ArraySequence :public Sequence<T>//, public IEnumerable<T>
{
	int index=0;
	DynamicArray<T>* _array;
public:


	ArraySequence (T* items, int count)
	{
		_array= new DynamicArray<T>(items, count);
	}
	ArraySequence ()
	{
		_array = new DynamicArray<T>(0);
	}
	ArraySequence (const ArraySequence  <T>& list )
	{
		int n = list._array->getCount();
		T* temp = new T[n];
		for (int i = 0; i < n;i++)
			temp[i] = list._array->Get(i);
		_array= new DynamicArray<T>(temp, n);
	}
	T GetFirst() override
	{
		try
		{
			if (_array->getCount() <= 0)
				throw 1;
			return _array->Get(0);
		}
		catch (int e)
		{
			std::cout << "index out of Range ";
		}
	}
	T GetLast()override
	{
		try
		{
			if (_array->getCount() <= 0)
				throw 1;
			return _array->Get(_array->getSize()-1);
		}
		catch (int e)
		{
			std::cout << "index out of Range ";
		}
	}
	T Get(int index)override
	{
		try
		{
			if (_array->getCount() <= 0 || index>=_array->getCount())
				throw 1;
			return _array->Get(index);
		}
		catch (int e)
		{
			std::cout << "index out of Range ";
		}
	}

	Sequence <T>* GetSubsequence(int startIndex, int endIndex) override
	{
		try
		{
			if (startIndex < 0 ||
				endIndex < 0 ||
				startIndex >= _array->getCount()||
				endIndex >= _array->getCount())
				throw 1;
			if (endIndex < startIndex)
			{
				int t = endIndex;
				endIndex = startIndex;
				startIndex=t;
			}
			int n = endIndex - startIndex;
			T* temp = new T[n];
			for (int i = startIndex;i < endIndex;i++)
				temp[i - startIndex] = _array->Get(i);
			
			return new ArraySequence <T> (temp, n);
		}
		catch (int e)
		{
			std::cout << "index out of Range ";
		}
	}
	int GetLength()override
	{
		return _array->getCount();
	}
	Sequence<T>* Append(T item) override {
		if (_array->getCount() == _array->getSize())
		{
			_array->Resize((int)(_array->getSize() * 1.5));
		}
		++_array->count;
		_array->Set(_array->getCount() - 1, item);
		return this;
	}
	Sequence<T>* Prepend(T item) override {
		if (_array->getCount() == _array->getSize())
		{
			_array->Resize((int)(_array->getSize() * 1.5));
		}
		for (int i = _array->getCount() - 1; i > 0;i--) {
			_array->Set(i, _array->Get(i - 1));
		}
		_array->Set(0, item);
		return this;
	}
	Sequence<T>* InsertAt(T item, int index)override
	{
		try
		{
			if (index <= 0 || index >= _array->getCount())
				throw 1;
			if (_array->getCount() == _array->getSize())
			{
				_array->Resize((int)(_array->getSize() * 1.5));
			}
			
			for(int i = _array->getCount() - 1;i>index;i--)
				_array->Set(i, _array->Get(i -1));
			_array->Set(index, item);
			return this;
		}
		catch (int e)
		{
			std::cout << "index out of Range ";
		}
	}
	Sequence <T>* Concat(Sequence <T>* list)override
	{
		int n = GetLength()+  list->GetLength();
		T* temp = new T[n];
		for (int i = 0; i < n;i++)
		{
			if (i < GetLength())
				temp[i] = _array->Get(i);
			else
				temp[i] = list->Get(i- GetLength());
		}
	 
		return new ArraySequence <T>(temp, n);
	}
	~ArraySequence () {
		delete _array;
	}
	ArraySequence <T>& operator=(const ArraySequence <T>& list) {
		if (this != &list) {
			delete _array;
			CopyFrom(list);
		}
		return *this;
	}
	T& operator[](int index) const {
		return (*_array)[index];
	}


	/*

	*/
	
	T GetCurrent()
	{
		return _array->Get(index);
	}
	bool MoveNext()
	{
		index++;
		return index < _array->getCount();
	}
	void Reset()
	{
		index = -1;
	}
};

