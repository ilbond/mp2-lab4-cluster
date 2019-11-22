#pragma once
#include "Task.h"
class Processor
{
	int allCores;
	int freeCores;
	int nTasks;

public:
	Processor() {
		//srand(time(0));
		allCores = 1 + rand() % 15;
		freeCores = allCores;
		nTasks = 0;
	}
	void SetallCores(int a) {
		allCores = a;
		freeCores = allCores;
	}
	int GetnTasks() { return nTasks; }
	int GetallCores() { return allCores; }
	int GetfreeCores() { return freeCores; }
	bool CanAddTaskInProc(Task task) {
		if (task.getCores() > this->freeCores)
			return 0;
		return 1;
	}
	bool isEmpty() {
		if (freeCores == allCores)
			return 1;
		return 0;
	}
	void AddTask(Task & task) {
		freeCores -= task.getCores();
		nTasks++;
	}
	void FinishTask(Task &task) {
		freeCores += task.getCores();
		nTasks--;
	}
	~Processor() {

	}
};

