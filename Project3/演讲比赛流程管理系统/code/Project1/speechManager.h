#pragma once
#include<iostream>
#include<vector>
#include"speaker.h"
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>
using namespace std;

//����ݽ�������
class SpeechManager {
public:
	//���캯��
	SpeechManager();
	//�˵�����
	void show_Menu();
	//�˳�ϵͳ
	void exitSystem();
	//��������
	~SpeechManager();
	//����12��ѡ��
	void createSpeaker();
	//��ʼ���� �����������̿��ƺ���
	void startSpeech();
	//��ǩ
	void speechDraw();
	//��ʼ����
	void speechContest();
	//��ʾ�÷�
	void showScore();
	//�������
	void saveRecord();
	//��ȡ��¼
	void loadRecord();
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//��������¼������
	map<int, vector<string>>m_Record;
	//��ʾ�����¼
	void showRecord();
	//��ռ�¼
	void clearRecord();
	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;
	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;
	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVectory;
	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;
	//��ű�������
	int m_Index;
	//��ʼ������������
	void initSpeech();
};