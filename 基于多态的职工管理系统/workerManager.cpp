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
		cout << "现有员工数量：" << this->workerNum << endl;

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
}

void WorkerManager::exitMenu()
{
	cout << "BYE_BYE!!!" << endl;
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
			cout << "1->普通员工" << endl;
			cout << "2->经理" << endl;
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

		//保存添加的员工到文件中
		this->save();
	}
	else
	{
		cout << "输入信息有误！" << endl;
	}

}

//显示员工函数
void WorkerManager::showWorker()
{
	cout << "现有员工：" << endl;
	for (int i = 0; i < this->workerNum; i++)
	{
		this->workerArray[i]->showInfo();
	}
}
