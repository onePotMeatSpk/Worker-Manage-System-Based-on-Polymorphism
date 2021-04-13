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

	//���Ա������
	void addWorker();

public:
	//����Ա������
	int workerNum;

	//�ļ��Ƿ�Ϊ�ձ�ʶ
	bool isFileEmpty;

	//Ա���б�
	Worker** workerArray;
};