#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Employee: public Worker
{
public:
	Employee(int id, string name, int jobname);
	~Employee();

	//展示个人信息
	virtual void showInfo();

	//获得岗位信息
	virtual string getJobName();
};

