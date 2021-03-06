#include"workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "不存在员工信息文件，没有员工信息！！！" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->isFileEmpty = true;
		ifs.close();
		return;
	}

	//判断文件是否为空
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		cout << "文件为空，没有员工信息！！！" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->isFileEmpty = true;
		ifs.close();
		return;
	}

	//文件中存在员工时，将员工信息导入到员工列表中
	if (!isFileEmpty)
	{
		//取得文件内员工数量
		this->workerNum = this->getWorkerNum();

		//初始化员工列表
		this->workerArray = new Worker * [this->workerNum];
		this->initWorkerArray();

		//显示现有员工
		this->showWorker();
	}
}

WorkerManager::~WorkerManager()
{
	if (this->workerArray != NULL)
	{
		delete[]this->workerArray;
	}
}

void WorkerManager::showMenu()
{
	cout << "**************************************" << endl;
	cout << "*************员工管理系统*************" << endl;
	cout << "********* Press 0: 退出系统 **********" << endl;
	cout << "********* Press 1: 添加员工 **********" << endl;
	cout << "********* Press 2: 显示员工 **********" << endl;
	cout << "********* Press 3: 删除员工 **********" << endl;
	cout << "********* Press 4: 修改员工 **********" << endl;
	cout << "********* Press 5: 查询员工 **********" << endl;
	cout << "********* Press 6: 排序员工 **********" << endl;
	cout << "********* Press 7: 清空文件 **********" << endl;
	cout << "**************************************" << endl;


}

void WorkerManager::exitMenu()
{
	cout << "再见再见再见!!!" << endl;

	//案件后退出
	system("pause");
	exit(0);
}

//保存文件函数（ios::out形式）
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->workerNum; i++)
	{
		ofs << this->workerArray[i]->worker_ID << " "
			<< this->workerArray[i]->worker_Name << " "
			<< this->workerArray[i]->worker_JobName << endl;
	}

	ofs.close();
}

//获取文件中员工数量函数
int WorkerManager::getWorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num=0;

	int id;
	string name;
	int jobname;

	while (ifs>>id && ifs>>name && ifs>>jobname)
	{
		num++;
	}
	ifs.close();
	return num;
}

//初始化员工列表函数
void WorkerManager::initWorkerArray()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int index = 0;

	int id;
	string name;
	int jobname;
	while(ifs>>id && ifs>>name && ifs>>jobname)
	{
		Worker* worker = NULL;
		switch (jobname)
		{
		case 1:
			worker = new Employee(id, name, jobname);
			break;
		case 2:
			worker = new Manager(id, name, jobname);
			break;
		case 3:
			worker = new Boss(id, name, jobname);
			break;
		default:
			break;
		}
		this->workerArray[index] = worker;
		index++;
	}
}

//添加员工函数
void WorkerManager::addWorker()
{
	cout << "请输入要添加的员工个数：" << endl;
	int addNum;
	cin >> addNum;

	if (addNum > 0)
	{
		//更新新的员工数量
		int newSize = this->workerNum + addNum;

		//申请新空间
		Worker** newSpace = new Worker * [newSize];

		//将旧空间内旧数据添加到新空间
		if (this->workerArray != NULL)
		{
			for (int i = 0; i < workerNum; i++)
			{
				newSpace[i] = this->workerArray[i];
			}
		}

		//输入新员工的数据
		for (int i = 0; i < addNum; i++)
		{
			//定义新数据
			int newID;
			string newName;
			int newJobName;

			//输入新数据
			cout << "请输入第" << i + 1 << "位新员工的ID：" << endl;
			cin >> newID;
			cout << "请输入第" << i + 1 << "位新员工的名字：" << endl;
			cin >> newName;
			cout << "请选择第" << i + 1 << "位新员工的岗位：" << endl;
			cout << "1->韭菜" << endl;
			cout << "2->走狗" << endl;
			cout << "3->老板" << endl;
			cin >> newJobName;

			//载入新数据
			Worker* newWorker = NULL;
			switch (newJobName)
			{
			case 1:
				newWorker = new Employee(newID, newName, newJobName);
			case 2:
				newWorker = new Manager(newID, newName, newJobName);
			case 3:
				newWorker = new Boss(newID, newName, newJobName);
			default:
				break;
			}
			newSpace[this->workerNum + i] = newWorker;
		}

		//释放原有空间
		delete[] this->workerArray;

		//将员工列表指针指向新空间
		this->workerArray = newSpace;

		//更新新的员工个数
		this->workerNum = this->workerNum + addNum;

		//提示信息
		cout << "添加成功！" << endl;

		//显示现有员工
		this->showWorker();

		//将修改过后的列表保存到文件中
		this->save();

		//修改文件过后
		this->isFileEmpty = false;
	}
	else
	{
		cout << "输入信息有误！" << endl;
	}

	//按键后清屏
	system("pause");
	system("cls");
}

//显示员工函数
void WorkerManager::showWorker()
{
	if (isFileEmpty)
	{
		cout << "不存在员工信息！！！" << endl;
	}
	else
	{
		cout << "现有员工数量：" << this->workerNum << endl;
		cout << "现有员工如下：" << endl;
		for (int i = 0; i < this->workerNum; i++)
		{
			this->workerArray[i]->showInfo();
		}
	}

	//按键后清屏
	system("pause");
	system("cls");
}

//员工是否存在函数(以id号查询）
int WorkerManager::isWorkerExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->workerNum; i++)
	{
		if(this->workerArray[i]->worker_ID==id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//员工是否存在函数(以姓名查询)
int WorkerManager::isWorkerExist(string name)
{
	int index = -1;
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->workerArray[i]->worker_Name == name)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除员工函数
void WorkerManager::deleteWorker()
{
	if (this->isFileEmpty)
	{
		cout << "不存在员工信息！！！" << endl;
	}
	else
	{
		int id;
		cout << "输入要删除的员工的ID:" << endl;
		cin >> id;
		int index = this->isWorkerExist(id);
		if (index == -1)
		{
			cout << "该员工不存在" << endl;
		}
		else
		{
			//前移覆盖被删员工
			for (int i = index; i < this->workerNum - 1; i++)
			{
				this->workerArray[i] = this->workerArray[i + 1];
			}
			this->workerNum--;

			//将修改过后的列表保存到文件中
			this->save();

			cout << "删除成功" << endl;
		}
	}

	//按键后清屏
	system("pause");
	system("cls");
}

//修改员工函数
void WorkerManager::modifyWorker()
{
	//检查
	if (this->isFileEmpty)
	{
		cout << "不存在员工信息！！！" << endl;
	}
	else
	{
		int id;
		cout << "输入要修改的员工的ID:" << endl;
		cin >> id;
		int index = this->isWorkerExist(id);

		//检查列表中有无输入id对应员工
		//列表中无输入id对应员工
		if (index == -1)
		{
			cout << "该员工不存在" << endl;
		}
		//列表中有输入id对应员工，开始进行修改
		else
		{
			//创建一个新指针，准备接收修改过后的新
			Worker* worker=NULL;
			int choice;

			cout << "是否修改岗位？ 1->是   0->否" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int newjobname;
				cout << "输入新岗位: 1->韭菜   2->走狗   3->老板" << endl;
				cin >> newjobname;
				switch (newjobname)
				{
				case 1:
					worker = new Employee(this->workerArray[index]->worker_ID, this->workerArray[index]->worker_Name, newjobname);
					break;
				case 2:
					worker = new Manager(this->workerArray[index]->worker_ID, this->workerArray[index]->worker_Name, newjobname);
					break;
				case 3:
					worker = new Boss(this->workerArray[index]->worker_ID, this->workerArray[index]->worker_Name, newjobname);
					break;
				default:
					break;
				}
				//腾出旧信息
				delete this->workerArray[index];
			}
			else
			{
				worker = this->workerArray[index];
			}

			cout << "是否修改ID？ 1->是   0->否" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int newid;
				cout << "输入新ID:" << endl;
				cin >> newid;
				worker->worker_ID = newid;
			}
			
			cout << "是否修改名字？ 1->是   0->否" << endl;
			cin >> choice;
			if (choice == 1)
			{
				string newname;
				cout << "输入新名字:" << endl;
				cin >> newname;
				worker->worker_Name = newname;
			}
			this->workerArray[index] = worker;

			//将修改过后的列表保存到文件中
			this->save();

			cout << "修改成功" << endl;
		}
	}

	//按键后清屏
	system("pause");
	system("cls");
}

//查找员工函数
void WorkerManager::searchWorker()
{
	if (this->isFileEmpty)
	{
		cout << "没有员工！！！" << endl;

	}
	else
	{
		int choice = 0;
		do
		{
			cout << "请选择通过什么方式查找： 1->ID   2->姓名" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int id;
				cout << "请输入要查询的ID：" << endl;
				cin >> id;
				int index = this->isWorkerExist(id);
				if (index == -1)
				{
					cout << "无此员工" << endl;
				}
				else
				{
					this->workerArray[index]->showInfo();
				}
				break;
			}
			else if (choice == 2)
			{
				string name;
				cout << "请输入要查询的姓名：" << endl;
				cin >> name;
				int index = this->isWorkerExist(name);
				if (index == -1)
				{
					cout << "无此员工" << endl;
				}
				else
				{
					this->workerArray[index]->showInfo();
				}
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}
		} while (choice != 1 && choice != 2);
	}
	
	//按键后清屏
	system("pause");
	system("cls");
}

//员工排序函数
void WorkerManager::sortWorker()
{
	if (isFileEmpty)
	{
		cout << "没有员工！！！" << endl;
	}
	else
	{
		//定义一个中转指针
		Worker* tempworker = NULL;

		//冒泡排序
		for (int i = this->workerNum; i > 0 ; i--)
		{
			for (int j = 0; j < i - 1 ; j++)
			{
				if (this->workerArray[j]->worker_ID > this->workerArray[j + 1]->worker_ID)
				{
					tempworker = this->workerArray[j];
					this->workerArray[j] = this->workerArray[j + 1];
					this->workerArray[j + 1] = tempworker;
				}
			}
		}

		//将修改过后的列表保存到文件中
		this->save();
	}

	//按键后清屏
	system("pause");
	system("cls");
}

//清空文件内容函数
void WorkerManager::clearFile()
{
	//创建输出流
	ofstream ofs;
	
	//利用ios::trunc将文件中内容清空
	ofs.open(FILENAME, ios::trunc);
	ofs.close();

	//清空员工列表
	if (this->workerArray != NULL)
	{
		//首先在员工列表数组中，将每个员工指针所指向的堆区数据释放
		for (int i = 0; i < this->workerNum; i++)
		{
			if (this->workerArray[i] != NULL)
			{
				delete this->workerArray[i];
			}
		}

		//然后将员工列表数组指针指向的堆区数据释放
		delete[] this->workerArray;

		//将员工列表数组指针置零，以防野指针
		this->workerArray = NULL;

		//将员工数量置零
		this->workerNum = 0;

		//将文件状态置为空
		this->isFileEmpty = true;
	}

	//按键后清屏
	system("pause");
	system("cls");
}