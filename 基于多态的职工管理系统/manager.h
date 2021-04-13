#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Manager : public Worker
{
public:
	Manager(int id, string name, int jobname);
	~Manager();

	//展示个人信息
	virtual void showInfo();

	//获得岗位信息
	virtual string getJobName();
};
