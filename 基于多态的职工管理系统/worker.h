#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:

	//չʾ������Ϣ
	virtual void showInfo() = 0;

	//��ø�λ��Ϣ
	virtual string getJobName() = 0;
	
	int worker_ID;//ְ��ID
	string worker_Name;//ְ������
	int worker_JobName;//ְ����λ
};