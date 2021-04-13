#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:

	//展示个人信息
	virtual void showInfo() = 0;

	//获得岗位信息
	virtual string getJobName() = 0;
	
	int worker_ID;//职工ID
	string worker_Name;//职工名字
	int worker_JobName;//职工岗位
};