#pragma once
template <class T>
class Node
{
	T data;
	Node* next;
	//Node* prev;
public:
	Node(T data)
	{
		this->data = data;
		next = nullptr;
	}


	Node* GetNext()
	{
		return next;
	}
	/*Node* GetPrev()
	{
		return prev;
	}*/
	T GetData()
	{
		return data;
	}
	void SetNext(Node* next)
	{
		this->next = next;
	}
	/*void SetPrev(Node prev)
	{
		this->prev = prev;
	}*/
};

