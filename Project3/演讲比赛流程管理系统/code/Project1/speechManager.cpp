#define _CRT_SECURE_NO_WARNINGS 1
#include"speechManager.h"

//���캯��
SpeechManager::SpeechManager() {
	//��ʼ������������
	this->initSpeech();
	//����12��ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();
}
//�˵�����
void SpeechManager::show_Menu() {
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
	cout << "************* 1. ��ʼ�ݽ�����  *************" << endl;
	cout << "************* 2. �鿴�����¼   ************" << endl;
	cout << "************* 3. ��ձ�����¼  *************" << endl;
	cout << "************* 0. �˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//�˳�ϵͳ
void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//��ʼ������������
void SpeechManager::initSpeech() {
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVectory.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_Index = 1;
	//����¼���������
	this->m_Record.clear();
}
//����12��ѡ��
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		//���ֵ÷־���Ϊ0
		for (int j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}
		//����ѡ�ֱ�� ���ҷ��뵽v1������
		this->v1.push_back(i + 10001);
		//ѡ�ֱ���Լ���Ӧѡ�� ���뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
//��ʼ���� �����������̿��ƺ���
void SpeechManager::startSpeech() {
	//��һ�ֿ�ʼ����
	//1. ��ǩ
	this->speechDraw();
	//2. ����
	this->speechContest();
	//3. ��ʾ�������
	this->showScore();
	//�ڶ��ֿ�ʼ����
	this->m_Index++;
	//1. ��ǩ
	this->speechDraw();
	//2. ����
	this->speechContest();
	//3. ��ʾ���ս��
	this->showScore();
	//4. ����������ļ���
	this->saveRecord();
	//���ñ��� ��ȡ��¼
	//��ʼ������������
	this->initSpeech();
	//����12��ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();
	cout << "����������" << endl;
	system("pause");
	system("cls");
}
//��ǩ
void SpeechManager::speechDraw() {
	cout << "�� <<" << this->m_Index << ">> ��ѡ�����ڳ�ǩ" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "��ǩ����ݽ�˳�����£�" << endl;
	if (this->m_Index == 1) {
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		//��һ�ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------------------" << endl;
	system("pause");
	cout << endl;
}
//��ʼ����
void SpeechManager::speechContest() {
	cout << "-------------��" << this->m_Index << "�ֱ�����ʼ---------------" << endl;
	//׼����ʱ�������С��ɼ�
	multimap<double, int, greater<double>>groupScore;
	int num = 0;//��¼��Ա�ĸ��� 6��һ��
	vector<int>v_Src;//����ѡ������
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;//60~100
			d.push_back(score);
			//cout << score << " ";
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();//ƽ����
		////��ӡƽ����
		//cout << "��ţ�" << *it << " " << "������" << this->m_Speaker[*it].m_Name << " " << "ƽ���֣�" << avg << endl;
		//��ƽ���ַ��뵽map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//��������ݷ�����ʱС��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷� value�Ǿ���ѡ�ֱ��
		//ÿ����ȡ��ǰ����
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С������������£�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "��ţ�" << it->second << " " << "������" << this->m_Speaker[(*it).second].m_Name << " " << "�ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			//ȡ��ǰ���� 
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++,count++) {
				if (this->m_Index == 1) {
					v2.push_back((*it).second);
				}
				else {
					vVectory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "-------------��" << this->m_Index << "�ֱ������---------------" << endl;
	system("pause");
}
//��ʾ�÷�
void SpeechManager::showScore() {
	cout << "-------------��" << this->m_Index << "�ֱȽ���ѡ�֣�---------------" << endl;
	vector<int>v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVectory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ�ţ�" << *it << " " << "������" << this->m_Speaker[*it].m_Name << " " << "�÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}
//�������
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�
	//��ÿ��ѡ�ֵ�����д�뵽�ļ���
	for (vector<int>::iterator it = vVectory.begin(); it != vVectory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	//�ر��ļ�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	//�����ļ���״̬
	this->fileIsEmpty = false;
}
//��ȡ��¼
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);//���ļ�
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ��Ż���

	string data;
	int index = 0;
	while (ifs >> data) {
		//cout << data << endl;
		vector<string>v;//���6��string�ַ���
		int pos = -1;
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				//û���ҵ�
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
	//	cout << it->first << " " << "�ھ���ţ�" << it->second[0] << " " << "����:" << it->second[1] << endl;
	//}
}
//��ʾ�����¼
void SpeechManager::showRecord() {
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ����ļ�������" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++) {
			cout << "��" << i + 1 << "��" << " "
				<< "�ھ���ţ�" << this->m_Record[i][0] << "�÷֣�" << this->m_Record[i][1] << " "
				<< "�Ǿ���ţ�" << this->m_Record[i][2] << "�÷֣�" << this->m_Record[i][3] << " "
				<< "������ţ�" << this->m_Record[i][3] << "�÷֣�" << this->m_Record[i][4] << endl;
		}
	}
	system("pause");
	system("cls");
}
//��ռ�¼
void SpeechManager::clearRecord() {
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������������
		this->initSpeech();
		//����12��ѡ��
		this->createSpeaker();
		//���������¼
		this->loadRecord();
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//��������
SpeechManager::~SpeechManager() {

}