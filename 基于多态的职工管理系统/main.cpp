#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	//����WorkerManager�����࣬��������в������ɸ����ṩ�ӿ�
	WorkerManager wm;

	//����choiceѡ�������ͨ���ñ���ѡ��Ҫ���еĹ���
	int choice = 0;
	while (true)
	{
		//��ʾ������
		wm.showMenu();

		//���й���ѡ��
		cout <<"Please Inuput Your Choice:"<< endl;
		cin >> choice;
		switch (choice)
		{
		//ѡ��Ϊ0���˳�ϵͳ
		case 0:
			wm.exitMenu();
			break;
		//ѡ��Ϊ1�����Ա��
		case 1:
			wm.addWorker();
			break;
		//ѡ��Ϊ2����ʾԱ����Ϣ
		case 2:
			wm.showWorker();
			break;
		//ѡ��Ϊ3��ɾ��Ա��
		case 3:
			wm.deleteWorker();
			break;
		//ѡ��Ϊ4���޸�Ա����Ϣ
		case 4:
			wm.modifyWorker();
			break;
		//ѡ��Ϊ5����ѯԱ��
		case 5:
			wm.searchWorker();
			break;
		//ѡ��Ϊ6����Ա����������(����ID��)
		case 6:
			wm.sortWorker();
			break;
		//ѡ��Ϊ7������ļ�����
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