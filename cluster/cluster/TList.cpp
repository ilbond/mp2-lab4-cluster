#include "pch.h"
#include "TList.h"


template <typename T>
TList <T>::TList()
{
	size = 0;
	pFirst = nullptr;
}

template<typename T>
void TList<T>::InsertFirst(T val)
{
	Node *p = new T;
	p->data = val;
	p->pNext = pFirst;
	pFirst = p;
	size++;
}
template<typename T>
void TList<T>::InsertLast(T val)
{
	if (pFirst == nullptr)
	{
		InsertFirst(val);
	}
	else
	{
		Node <T> *p = pFirst;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		Node *pp = new T;
		pp->data = val;
		p->pNext = pp; pp->pNext = nullptr;
	}
	size++;
}

template<typename T>
void TList<T>::Insert(const T val, const int pos) // Положить на позицию
{
	if (pos > size)
		throw 1;
	if (pos == 0) {
		InsertFirst(val);
		return;
	}
	if (pos == size) {
		InsertLast(val);
		return;
	}
	int i = 0;
	Node <T>* p;
	Node <T> * Prev = pFirst; // Сохраняем предыдущий индекс
	while (i != pos - 1) // Доходим до звена с номером на 1 меньше и останавливаемся
	{
		Prev = Prev->pNext;
		i++;
	}
	p = new Node <T>(val);
	p->pNext = Prev->pNext;
	Prev->pNext = p;
	size++;
}

template<typename T>
Node<T> * TList<T>::FindElem(T val)
{
	Node *p = pFirst, *pp = nullptr;
	if (p == nullptr)
		return p;
	if (p->data == val)
		pp = p;
	while (p->pNext != nullptr) {
		p = p->pNext;
		if (p->data == val) {
			pp = p; break;
		}
	}
	return pp;
}

template<typename T>
void TList<T>::DeleteElem(int pos) //???? 
{
	if (pos >= size || pos < 0)
		throw 1;
	Node *p = pFirst, *pp = nullptr;
	if (pos == 0)
	{
		p = p->pNext;
		delete[] pFirst;
		pFirst = p;
		size--;
		return;
	}
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->pNext;
	}
	pp = p->pNext;
	if (pp->pNext != nullptr)
	{
		if (pp != pFirst)
			p->pNext = pp->pNext;
	}
	else
	{
		p->pNext = nullptr;
	}
	size--;
	delete[] pp;
}
