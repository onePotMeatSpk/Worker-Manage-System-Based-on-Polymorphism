#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"


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

	//Ա���б�
	Worker** workerArray;
};