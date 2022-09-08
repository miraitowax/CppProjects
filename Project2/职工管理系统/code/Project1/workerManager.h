#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流文件
using namespace std;//使用标准的命名空间
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager {
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	//统计文件中人数
	int getEmpNum();
	//初始化员工
	void init_Emp();
	//显示职工函数
	void Show_Emp();
	//删除职工
	void Del_Emp();
	//判断职工是否存在，若存在则返回职工在数组中的位置，不存在返回-1
	int IsExit(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序员工
	void Sort_Emp();
	//清空文件
	void Clean_File();
	//析构函数
	~WorkerManager();
};