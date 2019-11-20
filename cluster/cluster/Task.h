
#pragma once
#include "Queue.h"
#include <string>
#include <vector>
#include <ctime>
class Task
{
	string id;
	int qtyCores;
	int qtyProc;
	int qtyTacts;
public:
	vector <int> numProc;

	Task() {
		string id = "";
		qtyProc = 1+rand() % 10;
		qtyCores = 1+rand() % 16;
		qtyTacts = 1+ rand() % 10;
	}
	void SetqProc(int a) { qtyProc = a; }
	void SetqCores(int a) { qtyCores = a; }
	void TaskTact() {
		if (0 == qtyTacts)
			return;
		qtyTacts--;
	}
	bool isDone() {
		if (0 > qtyTacts)
			throw 1;
		if (0 == qtyTacts)
			return 1;
		return 0;
	}
	string getID() { return id; }
	int getProc() { return qtyProc; }
	int getCores() { return qtyCores; }
	int getTacts() { return qtyTacts; }
	~Task() {}
};

