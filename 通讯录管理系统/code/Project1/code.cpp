#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//��ϵ�˽ṹ��
struct Person {
	string m_Name;//�Ա�
	int m_Sex;//�Ա�
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//סַ
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	//ͨѶ¼�б�����ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼��ǰ��¼����Ա����
	int m_Size;
};

//�˵�������ʾ
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}

//1. �����ϵ��
void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else {
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�������������³��룡" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "�����ϵ�˳ɹ�\n" << endl;

		system("pause");
		system("cls");//����
	}
}

//2. ��ʾ��ϵ��
void showPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ�գ����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "��ϵ��ʽ��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ͥסַ��" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//3. ɾ����ϵ��
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExit(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;//�ҵ��������±���
		}
	}
	return -1;//��������δ�ҵ�������-1
}
//ɾ����ϵ��
void deletePerson(Addressbooks* abs) {
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	//ret != -1 �鵽��
	//ret == -1 δ�鵽
	if (ret != -1) {
		//����ǰ��
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//����ͨѶ¼�е���Ա��
		abs->m_Size--;
		cout << "ɾ���ɹ�\n";
	}
	else {
		cout << "���޴���\n";
	}
	system("pause");
	system("cls");
}

//4. ����ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ������ͨѶ¼��
	int ret = isExit(abs,name);
	if (ret != -1) {//�ҵ�
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "��ϵ��ʽ��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ͥסַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {//δ�ҵ�
		cout << "���޴���\n" << endl;
	}
	system("pause");
	system("cls");
}

//5. �޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 ---Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//��ַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else {
		cout << "���޴���\n" << endl;
	}
	system("pause");
	system("cls");
}

//6. �����ϵ�˺���
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	//����ǰ��¼����ϵ��������Ϊ0�����߼���ղ���
	cout << "ͨѶ¼�����\n" << endl;
	system("pause");
	system("cls");
}

int main() {
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	//�û�ѡ������
	int select = 0;
	while (true) {//�ظ�ѡ��ѡ��
		//�˵��ĵ���
		showMenu();
		cin >> select;
		switch (select) {
		case 1://�����ϵ��
			addPerson(&abs);//���õ�ַ���ݣ���������ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��\n";
			system("pause");//�밴���������
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
