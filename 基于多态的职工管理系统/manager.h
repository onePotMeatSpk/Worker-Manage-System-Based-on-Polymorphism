#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Manager : public Worker
{
public:
	Manager(int id, string name, int jobname);
	~Manager();

	//չʾ������Ϣ
	virtual void showInfo();

	//��ø�λ��Ϣ
	virtual string getJobName();
};
