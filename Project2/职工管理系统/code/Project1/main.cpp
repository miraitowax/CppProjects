#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"workerManager.h"
using namespace std;
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int main() {
	////测试代码
	//Worker* worker1 = NULL;
	//worker1 = new Employee(1, "张三", 1);
	//worker1->showInfo();
	//delete worker1;

	//Worker* worker2 = NULL;
	//worker2 = new Manager(2, "李四", 2);
	//worker2->showInfo();
	//delete worker2;

	//Worker* worker3 = NULL;
	//worker3 = new Boss(3, "王五", 3);
	//worker3->showInfo();
	//delete worker3;


	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;//用来存储用户的选项
	while (true) {
		//调用展示菜单成员函数
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;//接收用户选项
		switch (choice) {
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空职工
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}

	system("pause");
	return 0;
}