#include"workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "������Ա����Ϣ�ļ���û��Ա����Ϣ������" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->isFileEmpty = true;
		ifs.close();
		return;
	}

	//�ж��ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�û��Ա����Ϣ������" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->isFileEmpty = true;
		ifs.close();
		return;
	}

	//�ļ��д���Ա��ʱ����Ա����Ϣ���뵽Ա���б���
	if (!isFileEmpty)
	{
		//ȡ���ļ���Ա������
		this->workerNum = this->getWorkerNum();
		cout << "����Ա��������" << this->workerNum << endl;

		//��ʼ��Ա���б�
		this->workerArray = new Worker * [this->workerNum];
		this->initWorkerArray();

		//��ʾ����Ա��
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
	cout << "*************Ա������ϵͳ*************" << endl;
	cout << "********* Press 0: �˳�ϵͳ **********" << endl;
	cout << "********* Press 1: ���Ա�� **********" << endl;
	cout << "********* Press 2: ��ʾԱ�� **********" << endl;
	cout << "********* Press 3: ɾ��Ա�� **********" << endl;
	cout << "********* Press 4: �޸�Ա�� **********" << endl;
	cout << "**************************************" << endl;


}

void WorkerManager::exitMenu()
{
	cout << "BYE_BYE!!!" << endl;
	system("pause");
	exit(0);
}

//�����ļ�������ios::out��ʽ��
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

//��ȡ�ļ���Ա����������
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

//��ʼ��Ա���б���
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

//���Ա������
void WorkerManager::addWorker()
{
	cout << "������Ҫ��ӵ�Ա��������" << endl;
	int addNum;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����µ�Ա������
		int newSize = this->workerNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//���ɿռ��ھ�������ӵ��¿ռ�
		if (this->workerArray != NULL)
		{
			for (int i = 0; i < workerNum; i++)
			{
				newSpace[i] = this->workerArray[i];
			}
		}

		//������Ա��������
		for (int i = 0; i < addNum; i++)
		{
			//����������
			int newID;
			string newName;
			int newJobName;

			//����������
			cout << "�������" << i + 1 << "λ��Ա����ID��" << endl;
			cin >> newID;
			cout << "�������" << i + 1 << "λ��Ա�������֣�" << endl;
			cin >> newName;
			cout << "��ѡ���" << i + 1 << "λ��Ա���ĸ�λ��" << endl;
			cout << "1->�²�" << endl;
			cout << "2->�߹�" << endl;
			cout << "3->�ϰ�" << endl;
			cin >> newJobName;

			//����������
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

		//�ͷ�ԭ�пռ�
		delete[] this->workerArray;

		//��Ա���б�ָ��ָ���¿ռ�
		this->workerArray = newSpace;

		//�����µ�Ա������
		this->workerNum = this->workerNum + addNum;

		//��ʾ��Ϣ
		cout << "��ӳɹ���" << endl;

		//��ʾ����Ա��
		this->showWorker();

		//������ӵ�Ա�����ļ���
		this->save();

		this->isFileEmpty = false;
	}
	else
	{
		cout << "������Ϣ����" << endl;
	}

}

//��ʾԱ������
void WorkerManager::showWorker()
{
	if (isFileEmpty)
	{
		cout << "������Ա����Ϣ������" << endl;
	}
	else
	{
		cout << "����Ա����" << endl;
		for (int i = 0; i < this->workerNum; i++)
		{
			this->workerArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//Ա���Ƿ���ں���
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

//ɾ��Ա������
void WorkerManager::deleteWorker()
{
	if (this->isFileEmpty)
	{
		cout << "������Ա����Ϣ������" << endl;
	}
	else
	{
		int id;
		cout << "����Ҫɾ����Ա����ID:" << endl;
		cin >> id;
		int index = this->isWorkerExist(id);
		if (index == -1)
		{
			cout << "��Ա��������" << endl;
		}
		else
		{
			//ǰ�Ƹ��Ǳ�ɾԱ��
			for (int i = index; i < this->workerNum - 1; i++)
			{
				this->workerArray[i] = this->workerArray[i + 1];
			}
			this->workerNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

//�޸�Ա������
void WorkerManager::modifyWorker()
{
	//���
	if (this->isFileEmpty)
	{
		cout << "������Ա����Ϣ������" << endl;
	}
	else
	{
		int id;
		cout << "����Ҫ�޸ĵ�Ա����ID:" << endl;
		cin >> id;
		int index = this->isWorkerExist(id);

		//����б�����������id��ӦԱ��
		//�б���������id��ӦԱ��
		if (index == -1)
		{
			cout << "��Ա��������" << endl;
		}
		//�б���������id��ӦԱ������ʼ�����޸�
		else
		{
			//����һ����ָ�룬׼�������޸Ĺ������
			Worker* worker=NULL;
			int choice;

			cout << "�Ƿ��޸ĸ�λ�� 1->��   0->��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int newjobname;
				cout << "�����¸�λ: 1->�²�   2->�߹�   3->�ϰ�" << endl;
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
				//�ڳ�����Ϣ
				delete this->workerArray[index];
			}
			else
			{
				worker = this->workerArray[index];
			}

			cout << "�Ƿ��޸�ID�� 1->��   0->��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int newid;
				cout << "������ID:" << endl;
				cin >> newid;
				worker->worker_ID = newid;
			}
			
			cout << "�Ƿ��޸����֣� 1->��   0->��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				string newname;
				cout << "����������:" << endl;
				cin >> newname;
				worker->worker_Name = newname;
			}
			this->workerArray[index] = worker;
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}