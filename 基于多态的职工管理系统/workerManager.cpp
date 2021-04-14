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
			cout << "1->��ͨԱ��" << endl;
			cout << "2->����" << endl;
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
	}
	else
	{
		cout << "������Ϣ����" << endl;
	}

}

//��ʾԱ������
void WorkerManager::showWorker()
{
	cout << "����Ա����" << endl;
	for (int i = 0; i < this->workerNum; i++)
	{
		this->workerArray[i]->showInfo();
	}
}
