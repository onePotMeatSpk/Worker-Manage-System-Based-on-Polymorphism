#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	//创建WorkerManager管理类，后面的所有操作都由该类提供接口
	WorkerManager wm;

	//创建choice选择变量，通过该变量选择要进行的功能
	int choice = 0;
	while (true)
	{
		//显示主界面
		wm.showMenu();

		//进行功能选择
		cout <<"Please Inuput Your Choice:"<< endl;
		cin >> choice;
		switch (choice)
		{
		//选择为0：退出系统
		case 0:
			wm.exitMenu();
			break;
		//选择为1：添加员工
		case 1:
			wm.addWorker();
			break;
		//选择为2：显示员工信息
		case 2:
			wm.showWorker();
			break;
		//选择为3：删除员工
		case 3:
			wm.deleteWorker();
			break;
		//选择为4：修改员工信息
		case 4:
			wm.modifyWorker();
			break;
		//选择为5：查询员工
		case 5:
			wm.searchWorker();
			break;
		//选择为6：对员工进行排序(依照ID号)
		case 6:
			wm.sortWorker();
			break;
		//选择为7：清空文件内容
		case 7:
			wm.clearFile();
			break;
		default:
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}