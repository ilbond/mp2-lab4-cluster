#pragma once
#include "Queue.h"
#include "Task.h"
#include "Processor.h"
#include "vector"
#include <cstdio>
#include <ctime>
#include "windows.h"
class Cluster
{
	queue<Task> q;
	int nProc;
	vector<Processor> proc;
	vector<Task> active;
	vector<Task> finished;
	vector<Task> invalid;
	int Tact;
	int endTact = 10;
	double sumcap;
	int SpeedTact;
public:
	Cluster();
	void SetTactsNumber(int a) {
		if (a <= 0) {
			throw 1;
		}
		endTact = a;
	}
	void SetSpeedTact(int a) {
		SpeedTact = a;
	}
	bool ValidTask(Task t);
	bool CanPutTask();
	void StartCluster();
	void TaskIn();
	void NextTact();
	double Capacity();
	void PrintProcess();	
	void Work();
	~Cluster();
};

