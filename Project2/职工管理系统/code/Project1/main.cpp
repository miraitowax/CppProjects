#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"workerManager.h"
using namespace std;
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int main() {
	////���Դ���
	//Worker* worker1 = NULL;
	//worker1 = new Employee(1, "����", 1);
	//worker1->showInfo();
	//delete worker1;

	//Worker* worker2 = NULL;
	//worker2 = new Manager(2, "����", 2);
	//worker2->showInfo();
	//delete worker2;

	//Worker* worker3 = NULL;
	//worker3 = new Boss(3, "����", 3);
	//worker3->showInfo();
	//delete worker3;


	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;//�����洢�û���ѡ��
	while (true) {
		//����չʾ�˵���Ա����
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;//�����û�ѡ��
		switch (choice) {
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://���ְ��
			wm.Clean_File();
			break;
		default:
			system("cls");//����
			break;
		}
	}

	system("pause");
	return 0;
}