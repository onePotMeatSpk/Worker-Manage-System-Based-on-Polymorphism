#include"employee.h"

Employee::Employee(int id, string name, int jobname)
{
	this->worker_ID = id;
	this->worker_Name = name;
	this->worker_JobName = jobname;
}

Employee::~Employee()
{
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->worker_ID
		 << "\tְ��������" << this->worker_Name
		 << "\tְ����λ��" << this->getJobName() << endl;
}

string Employee::getJobName()
{
	return("�²�");
}