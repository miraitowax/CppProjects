#define _CRT_SECURE_NO_WARNINGS 1
#include"employee.h"
#include<iostream>
using namespace std;

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
string Employee::getDeptName() {
	return string("Ա��");
}
void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< " \tְ��������" << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
}