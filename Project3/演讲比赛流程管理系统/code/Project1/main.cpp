#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"speechManager.h"
#include<ctime>
using namespace std;

int main() {
	//���������
	srand((unsigned int)time(NULL));
	//�������������
	SpeechManager sm;
	////����12��ѡ�ִ���
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++) {
	//	cout << "ѡ�ֱ�ţ�" << it->first << " " << "������" << it->second.m_Name << " " << "������" << it->second.m_Score[0] << endl;
	//}
	int choice = 0;//���ڴ洢�û�����
	while (true) {
		sm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴���������¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");//����
			break;
		}

	}
	
	return 0;
}
