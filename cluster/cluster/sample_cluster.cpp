// cluster.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Cluster.h"

int main()

{
	setlocale(LC_ALL, "Russian");
	Cluster cluster;
	int n,m;
	cout << "Введите количество тактов: ";
	cin >> n;
	cout << endl;
	cluster.SetTactsNumber(n);
	cout << "Введите скорость выполнения такта(мс): ";
	cin >> m;
	cout << endl;
	cluster.SetSpeedTact(m);
	cluster.Work();
}

