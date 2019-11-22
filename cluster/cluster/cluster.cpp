#include "pch.h"
#include "Cluster.h"


Cluster::Cluster()
{
	srand(time(0));
	nProc = 4 + rand() % 60;
	proc.resize(nProc);
	sumcap = 0;
}

bool Cluster::ValidTask(Task t){
	if (t.getProc() > nProc) {
		return 0;
	}
	for (int i = 0; i < nProc; i++) {
		if (proc[i].GetallCores() < t.getCores())
			return 0;
	}
	return 1;
}

bool Cluster::CanPutTask() {
	int count = 0;
	for (int i = 0; i < nProc; i++) {
		if (proc[i].CanAddTaskInProc(q.GetFirst())) {
			count++;
		}
	}
	if (count >= q.GetFirst().getProc()) {
		return 1;
	}
	else {
		return 0;
	}
}

void Cluster::StartCluster() {
	srand(time(0));
	double tmp = 1;
	while (tmp > 0.2)
	{
		Task t;
		q.push(t);
		tmp = 0.01 * (1 + rand() % 100);
	}

}

void Cluster::TaskIn() {
	StartCluster();
	while (!(q.isEmpty())) {
		if (!(CanPutTask())) {
			if (!(ValidTask(q.GetFirst())))
				invalid.push_back(q.pop());
			else break;
			return;
		}
		int count = 0;
		for (int i = 0; i < nProc; i++) {
			if (proc[i].CanAddTaskInProc(q.GetFirst())) {
				count++;
				proc[i].AddTask(q.GetFirst());
				q.GetFirst().numProc.push_back(i);
			}
			if (count == q.GetFirst().getProc()) {
				active.push_back(q.pop());
				break;
			}
		}
	}
}

void Cluster::NextTact() {
	for (int i = 0; i < active.size(); i++)
	{
		active[i].TaskTact();
		if (active[i].isDone()) {
			for (int j = 0; j < active[i].numProc.size(); j++) {
				proc[active[i].numProc[j]].FinishTask(active[i]);
			}
			finished.push_back(active[i]);
			active.erase(active.begin() + i);
		}
	}
	sumcap += Capacity();
	Tact++;
}

double Cluster::Capacity() {
	double sum1 = 0, sum2 = 0, res;
	for (int i = 0; i < nProc; i++) {
		sum1 += (proc[i].GetallCores() - proc[i].GetfreeCores());
		sum2 += proc[i].GetallCores();
	}
	res = (sum1 / sum2) * 100;
	return res;
}

void Cluster::PrintProcess() {
	system("cls");
	setlocale(LC_ALL, "Russian");
	cout << "Номер такта: " << Tact << endl;
	cout << endl;
	cout << "Кол-во задач на процессорах:" << endl;
	for (int i = 0; i < nProc; i++)
	{
		cout << i + 1 << ": " << proc[i].GetnTasks() << " задач" << endl;
		cout << "Kол-во ядер -  " << proc[i].GetallCores() << ", кол-во свободных - " << proc[i].GetfreeCores() << endl;
	}
	cout << endl;
	cout << "Число задач в очереди: " << q.GetSize() << endl;
	cout << "Число выполняющихся задач: " << active.size() << endl;
	cout << "Число выполненных задач: " << finished.size() << endl;
	cout << "Число невыполняемых задач: " << invalid.size() << endl;
	cout << endl;
	double average = this->Capacity();
	cout << "3агруженность кластера: " << average << "%" << endl;
	cout << endl;
	Sleep(SpeedTact);
}

void Cluster::Work() {
	for (int i = 0; i < endTact; i++) {
		TaskIn();
		NextTact();
		PrintProcess();
	}
	cout << "\tCредняя загруженность за всё время:" << sumcap / endTact << "%" << endl;
}

Cluster::~Cluster()
{
}
