#pragma once

#include <iostream>
using namespace std;

//Звено списка
template <typename T>
struct Node
{
	Node * pNext;
	T data;
	Node(T data = T(), Node * pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
	~Node() { }
};

//Односвязый список
template <typename T>
class TList
{
private:
	int size;
	Node <T> * pFirst;
public:
	TList();
	~TList() { delete[] head; }
	void InsertLast(T val); // Вставка в конец
	void InsertFirst(T val); // Вставка в начало
	void Insert(T val, int pos); // Вставка на позицию
	void DeleteElem(int pos); // Удаление n-ого элемента
	int len() { return size; } // Узнать длину
	Node <T> * FindElem(T); // Поиск элемента

};

