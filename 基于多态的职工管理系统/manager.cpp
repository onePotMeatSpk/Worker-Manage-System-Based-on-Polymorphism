#include"Manager.h"

Manager::Manager(int id, string name, int jobname)
{
	this->worker_ID = id;
	this->worker_Name = name;
	this->worker_JobName = jobname;
}

Manager::~Manager()
{
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->worker_ID
		<< "\tְ��������" << this->worker_Name
		<< "\tְ����λ��" << this->getJobName() << endl;
}

string Manager::getJobName()
{
	return("Manager");
}