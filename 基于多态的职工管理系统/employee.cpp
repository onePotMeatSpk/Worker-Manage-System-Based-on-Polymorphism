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
	cout << "职工编号：" << this->worker_ID
		 << "\t职工姓名：" << this->worker_Name
		 << "\t职工岗位：" << this->getJobName() << endl;
}

string Employee::getJobName()
{
	return("韭菜");
}