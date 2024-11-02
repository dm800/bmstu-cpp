#pragma once
#include "Node.h"
#include <iostream>
#include <optional>
#include <exception>

template <class T>
class LinkedList
{
	int size;
	Node<T>* head;
public:
	LinkedList()
	{
		size = 0;
		head = nullptr;
	}
	LinkedList(T* items, int count)
	{
		
		for (int i = 0; i < count;i++)
		{
			Append(items[i]);
		}
	}
	LinkedList(const LinkedList <T>& list)
	{
		Node<T>* temp = list.head;
		while (temp != nullptr)
		{
			Append(temp->GetData());
			temp = temp->GetNext();
		}
	}
	void Prepend(T item)
	{
		Node<T>* temp = new Node(item);
		temp->SetNext(head);
		head = temp;
		size += 1;
	}
	T GetFirst()
	{
		if (head == nullptr)
			throw std::out_of_range("Index out of range");
		return head->GetData();

	}
	T GetLast()
	{
		if (head == nullptr)
			throw std::out_of_range("Index out of range");
		Node<T>* temp = head;
		while (temp->GetNext() != nullptr)
		{
			temp = temp->GetNext();
		}
		return temp->GetData();
	}
	void Append(T item)
	{
		Node<T>* node = new Node(item);
		if (head == nullptr)
			head = node;
		else
		{
			Node<T>* temp = head;
			while (temp->GetNext() != nullptr)
			{
				temp = temp->GetNext();
			}
			temp->SetNext(node);
		}
		size += 1;
	}
	T Get(int index)
	{
		if (index < 0 || index>=size)
			throw std::out_of_range("Index out of range");
		Node<T>* temp = head;
		for (int i = 0; i < index;i++)
		{
			temp = temp->GetNext();
		}
		
		return temp->GetData();
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		if (startIndex < 0 ||
			endIndex < 0 ||
			startIndex >= size ||
			endIndex >= size)
			throw std::out_of_range("Index out of range");
		if (endIndex < startIndex)
		{
			int t = endIndex;
			endIndex = startIndex;
			startIndex = t;
		}
		LinkedList<T>* result = new LinkedList<T>();
		Node<T>* temp = head;
		for (int i = 0; i < startIndex;i++)
			temp = temp->GetNext();
		for (int i = startIndex; i < endIndex;i++)
		{
			result->Append(temp->GetData());
			temp = temp->GetNext();
		}
		return result;

	}
	void InsertAt(T item, int index)
	{
		Node<T>* node=new Node<T>(item);
		if (index<0 || index>=size)
			throw std::out_of_range("Index out of range");
		if (index == 0)
			Prepend(item);
		else
		{
			Node<T>* temp = head;
			for (int i = 0; i < index - 1;i++)
				temp = temp->GetNext();
			node->SetNext(temp->GetNext());
			temp->SetNext(node);
			size += 1;
		}
	}
	LinkedList<T>* Concat(LinkedList<T>* list)
	{
		LinkedList<T>* result = new LinkedList<T>();
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			result->Append(temp->GetData());
			temp = temp->GetNext();
		}
		temp = list->head;
		//while (temp != nullptr)
		{
			result->Append(temp->GetData());
			temp = temp->GetNext();
		}
		return result;
	}
	int GetLenght()
	{
		return size;
	}
};

