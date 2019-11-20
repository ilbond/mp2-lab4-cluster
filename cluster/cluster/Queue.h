#pragma once
//#include "TList.h"
#include <iostream>
using namespace std;


template <typename T>
class queue
{
	template <typename T>
	class Node
	{
	public:
		Node * pNext;
		T data;
		Node(T data = T())
		{
			this->data = data;

		}
		~Node() { }
	};
	int size;
	Node <T> *pFirst;
	Node<T> * pLast;
public:
	queue() :size(0), pFirst(nullptr), pLast(nullptr)
	{

	}
	~queue() {
	
		while (pFirst!= nullptr)
		{
			Node <T> *p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
		}
	}
	bool isEmpty() {
		return pFirst == nullptr;
	}
	int GetSize() { return size; }
	void push(T val) {
		if (pFirst == nullptr)
		{
			pFirst = new Node <T>(val);
			pFirst->pNext = nullptr;
			pLast = pFirst;
		}
		else {
			pLast->pNext = new Node <T>(val);
			pLast = pLast->pNext;
			pLast->pNext = nullptr;
		}
		size++;
	}
	T &GetFirst() {
		if (isEmpty()) {
			throw 1;
		}
		return pFirst->data;
	}
	T pop() {
		if (isEmpty()) {
			throw 1;
		}
		T val = pFirst->data;
		Node<T> *p = pFirst->pNext;
		delete pFirst;
		pFirst = p;
		size--;
		return val;

	}
};


