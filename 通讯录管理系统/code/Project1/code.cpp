#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//联系人结构体
struct Person {
	string m_Name;//性别
	int m_Sex;//性别
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//住址
};

//通讯录结构体
struct Addressbooks {
	//通讯录中保存联系人数组
	struct Person personArray[MAX];
	//通讯录当前记录的人员个数
	int m_Size;
};

//菜单界面显示
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空联系人 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "************************" << endl;
}

//1. 添加联系人
void addPerson(Addressbooks* abs) {
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
	}
	else {
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新出入！" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加联系人成功\n" << endl;

		system("pause");
		system("cls");//清屏
	}
}

//2. 显示联系人
void showPerson(Addressbooks* abs) {
	//判断通讯录中人数是否为空，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "联系方式：" << abs->personArray[i].m_Phone << "\t";
			cout << "家庭住址：" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//3. 删除联系人
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExit(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;//找到，返回下标编号
		}
	}
	return -1;//遍历结束未找到，返回-1
}
//删除联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	//ret != -1 查到了
	//ret == -1 未查到
	if (ret != -1) {
		//数据前移
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//更新通讯录中的人员数
		abs->m_Size--;
		cout << "删除成功\n";
	}
	else {
		cout << "查无此人\n";
	}
	system("pause");
	system("cls");
}

//4. 查找指定联系人信息
void findPerson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否存在在通讯录中
	int ret = isExit(abs,name);
	if (ret != -1) {//找到
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "联系方式：" << abs->personArray[ret].m_Phone << "\t";
		cout << "家庭住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {//未找到
		cout << "查无此人\n" << endl;
	}
	system("pause");
	system("cls");
}

//5. 修改指定联系人信息
void modifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 ---女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//地址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else {
		cout << "查无此人\n" << endl;
	}
	system("pause");
	system("cls");
}

//6. 清空联系人函数
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	//将当前记录的联系人数量置为0，做逻辑清空操作
	cout << "通讯录已清空\n" << endl;
	system("pause");
	system("cls");
}

int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	//用户选择输入
	int select = 0;
	while (true) {//重复选择选项
		//菜单的调用
		showMenu();
		cin >> select;
		switch (select) {
		case 1://添加联系人
			addPerson(&abs);//利用地址传递，可以修饰实参
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用\n";
			system("pause");//请按任意键继续
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
