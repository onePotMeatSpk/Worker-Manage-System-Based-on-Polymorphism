#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Boss : public Worker
{
public:
	Boss(int id, string name, int jobname);
	~Boss();

	//展示个人信息
	virtual void showInfo();

	//获得岗位信息
	virtual string getJobName();
};