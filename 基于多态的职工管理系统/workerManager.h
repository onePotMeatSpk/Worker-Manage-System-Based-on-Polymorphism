#pragma once
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
#define FILENAME "workerinfo.txt"


class	WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();

	//展示菜单函数
	void showMenu();

	//退出菜单函数
	void exitMenu();

	//保存文件函数
	void save();

	//获取文件中员工数量函数
	int getWorkerNum();

	//初始化员工列表函数
	void initWorkerArray();

	//添加员工函数
	void addWorker();
	
	//显示员工函数
	void showWorker();

	//员工是否存在函数(以id号查询）
	int isWorkerExist(int id);

	//员工是否存在函数(以姓名查询)
	int isWorkerExist(string name);

	//删除员工函数
	void deleteWorker();

	//修改员工函数
	void modifyWorker();

	//查找员工函数
	void searchWorker();

	//员工排序函数
	void sortWorker();

	//清空文件内容函数
	void clearFile();

public:
	//现有员工个数
	int workerNum;

	//文件是否为空标识
	bool isFileEmpty;

	//员工列表
	Worker** workerArray;
};