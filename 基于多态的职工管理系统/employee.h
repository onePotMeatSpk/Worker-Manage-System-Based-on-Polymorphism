#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Employee: public Worker
{
public:
	Employee(int id, string name, int jobname);
	~Employee();

	//չʾ������Ϣ
	virtual void showInfo();

	//��ø�λ��Ϣ
	virtual string getJobName();
};

