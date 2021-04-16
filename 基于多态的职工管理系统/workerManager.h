#pragma once
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
#define FILENAME "workerinfo.txt"


class	WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//��������
	~WorkerManager();

	//չʾ�˵�����
	void showMenu();

	//�˳��˵�����
	void exitMenu();

	//�����ļ�����
	void save();

	//��ȡ�ļ���Ա����������
	int getWorkerNum();

	//��ʼ��Ա���б���
	void initWorkerArray();

	//���Ա������
	void addWorker();
	
	//��ʾԱ������
	void showWorker();

	//Ա���Ƿ���ں���(��id�Ų�ѯ��
	int isWorkerExist(int id);

	//Ա���Ƿ���ں���(��������ѯ)
	int isWorkerExist(string name);

	//ɾ��Ա������
	void deleteWorker();

	//�޸�Ա������
	void modifyWorker();

	//����Ա������
	void searchWorker();

	//Ա��������
	void sortWorker();

	//����ļ����ݺ���
	void clearFile();

public:
	//����Ա������
	int workerNum;

	//�ļ��Ƿ�Ϊ�ձ�ʶ
	bool isFileEmpty;

	//Ա���б�
	Worker** workerArray;
};