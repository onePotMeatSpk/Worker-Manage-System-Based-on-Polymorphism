#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"


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

	//添加员工函数
	void addWorker();

public:
	//现有员工个数
	int workerNum;

	//员工列表
	Worker** workerArray;
};