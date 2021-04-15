#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout <<"Please Inuput Your Choice:"<< endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitMenu();
			break;
		case 1:
			wm.addWorker();
			break;
		case 2:
			wm.showWorker();
			break;
		case 3:
			wm.deleteWorker();
			break;
		case 4:
			wm.modifyWorker();
			break;
		default:
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}