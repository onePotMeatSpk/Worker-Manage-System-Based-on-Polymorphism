#include"boss.h"

Boss::Boss(int id, string name, int jobname)
{
	this->worker_ID = id;
	this->worker_Name = name;
	this->worker_JobName = jobname;
}

Boss::~Boss()
{
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->worker_ID
		<< "\tְ��������" << this->worker_Name
		<< "\tְ����λ��" << this->getJobName() << endl;
}

string Boss::getJobName()
{
	return("�ϰ�");
}