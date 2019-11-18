#pragma once
#include "TList.h"

template <typename T>
class queue
{
	Node <T> *pFirst;
public:
	queue() :pFirst(nullptr) {}
	~queue() {
		while (pFirst != nullptr) {
			Node *p = pFirst;
			pFirst = p->pNext;
			delete p;
		}
	}
	bool isEmpty() {
		return pFirst == nullptr;
	}
	void push(T val) {
		Node *p = new Node;
		p->data = val;
		Node *pp = pFirst;
		while (pp->pNext != nullptr) {
			pp = pp->pNext;
		}
		pp->pNext = p;
	}
	T GetFirst() {
		return pFirst;
	}
	T pop() {
		if (isEmpty) {
			throw 1;
		}
		T val = pFirst->data;
		Node *p = pFirst->pNext;
		delete pFirst;
		pFirst = p;
		return val;

	}
};


