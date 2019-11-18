#pragma once

#include <iostream>
using namespace std;

//����� ������
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

//���������� ������
template <typename T>
class TList
{
private:
	int size;
	Node <T> * pFirst;
public:
	TList();
	~TList() { delete[] head; }
	void InsertLast(T val); // ������� � �����
	void InsertFirst(T val); // ������� � ������
	void Insert(T val, int pos); // ������� �� �������
	void DeleteElem(int pos); // �������� n-��� ��������
	int len() { return size; } // ������ �����
	Node <T> * FindElem(T); // ����� ��������

};

