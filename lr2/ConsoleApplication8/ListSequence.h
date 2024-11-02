#pragma once
#include "Sequence.h"
#include "LinkedList.h"
#include <iostream>
#include <optional>
#include <exception>

template <class T>
class ListSequence :public Sequence<T>
{
	LinkedList<T> list;
public :
	ListSequence() {}
	ListSequence(T* items, int count):list(items, count)
	{
	}
	ListSequence(LinkedList<T> list) {
		this->list = list;
	}
	T GetFirst() override
	{
		if (list.GetLenght()==0)
			throw std::out_of_range("Index is out of range");
		return list.GetFirst();
	}
	T GetLast() override{
		if (list.GetLenght() == 0)
			throw std::out_of_range("Index is out of range");
		return list.GetLast();
	}
	T Get(int index) override
	{
		return list.Get(index);
	}
	Sequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		LinkedList <T>* temp = list.GetSubList(startIndex, endIndex);
		T* buffer = new T[temp->GetLenght()];
		for (int i = 0; i <temp->GetLenght();i++)
			buffer[i] = temp->Get(i);

		return new ListSequence<T>(buffer, temp->GetLenght());
	}
	int GetLength() override
	{
		return list.GetLenght();
	}
	Sequence<T>* Append(T item) override
	{
		list.Append(item);
		return this;
	}
	Sequence<T>* Prepend(T item) override
	{
		list.Prepend(item);
		return this;
	}
	Sequence<T>* InsertAt(T item, int index)  override
	 {
		 list.InsertAt(item,index);
		 return this;
	 }
	Sequence<T>* Concat(Sequence<T>* list) override
	 {
		 T* temp = new T[list->GetLength()+GetLength()];
		 for (int i = 0; i < GetLength();i++)
			 temp[i] = Get(i);


		 for (int i = GetLength(); i < GetLength()+ list->GetLength();i++)
			 temp[i] = list->Get(i- GetLength());
		 

		 return new ListSequence<T>(temp, list->GetLength() + GetLength());
	 }

};

