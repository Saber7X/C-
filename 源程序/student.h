#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
struct st{ //ѧ������ 
	int st_id; //ѧ�� ��1-100�� 
	string st_name; //���� 
	string st_sex; //�Ա��С�Ů�� 
	int st_age; //���䣨1-100�� 
};

class student{
public:
	void add(); //���һ��ѧ����Ϣ 
	int del(int id); //ɾ��ָ��ѧ�� 
	void edit(); //�޸�ָ��ѧ�� 
	void show(); //չʾָ��ѧ�� 
	bool check(int id);//���Ҹ�ѧ���Ƿ���� 
	void mark(int id);//���ѧ������ 
	void get();//��ȡ����ѧ��ѧ�� 
	void save();//һ���������� 
	void file_add();//һ����������ļ� 
	friend void delete_s(int id); //��һ��ѧ����Ϣ��ɾ��ʱ������ѡ����ϢҲҪ��ɾ��
private:
	vector<st> stu = vector<st> (105, {-1, "", "", 0}); //ѧ�š��������Ա����䣬�±���ѧ�� 
	bool flag[105]={0}; //��Ǹ�ѧ���Ƿ���� 
};

void student::file_add()//һ����������ļ� 
{
	ifstream readFile;
	readFile.open("ѧ������.txt", ios::in);
 
	if (readFile.is_open())
	{
		cout << "ѧ����������ɹ���" << endl;
		int id;
		string name, sex;
		int age;
		while (readFile >>id >> name >> sex >> age)
		{
//			cout << id << endl << name << endl;
			mark(id); 
	 		stu[id] = {id, name, sex, age};
		}
	}
	else
	{
		cout << "ѧ����������ʧ�ܣ�" << endl;
	}

	readFile.close();
}
void student::add()
{
	int id;
	string name;
	string sex;
	int age;
	int s=0;
	while(1)
	{
		cout << "������ѧ��ѧ�ţ���ѧ����1-100������������0�˳���ӣ�\n";
		cin >> id; 
		if (id >= 1 && id <= 100 && !check(id)) break;
		if (id == 0) goto EXIT;
		if (id < 0 && id > 100) cout << "��Чѧ�ţ����������룺\n";
		else if (check(id)) cout << "��ѧ���Ѵ��ڣ����������룺\n";
		else cout << "�����������������룺\n";
	 } 

	while(1)
	{
		cout << "������ѧ�����������������Ȳ�����20������0�˳���ӣ�\n";
		cin >> name; 
		if (name == "0") goto EXIT;
		if (name.length() >= 1 && id <= 20) break;
		else  cout << "������������������\n";
	} 
	while(1)
	{
		cout << "������ѧ���Ա𣨡��С���Ů��������0�˳����ѧ����\n";
		cin >> sex; 
		if (sex == "0") goto EXIT;
		if (sex == "��" || sex == "Ů") break;
		else  cout << "������������������\n";
	} 	
	while(1)
	{
		cout << "������ѧ�����䣺��������1-100������������0�˳���ӣ�\n";
		cin >> age; 
		if (age == 0) goto EXIT;
		if (age >= 1 && age <= 100) break;
		else  cout << "������������������\n";
	 } 
	 cout << "����ɹ���\n����1�����ѧ��������0ȡ������\n";
	 
	 cin >> s;
	 if (s == 1)
	 {
	 	mark(id); 
	 	stu[id] = {id, name, sex, age};
	 	cout << "����ɹ���" << endl; 
//	 	cout <<  check(id) << endl;
	} 
	EXIT:
		cout << "�˳����\n";
	cout << endl;
}

bool student::check(int id)
{
	return flag[id] == 1;
}

void student::mark(int id)
{
	flag[id] = 1;
}

void student::show()
{
	cout << endl; 
	for (auto i : stu)
	{
		if (i.st_id != -1)
		{
			cout << "ѧ�ţ�" << i.st_id << endl;
			cout << "������" << i.st_name << endl;
			cout << "�Ա�" << i.st_sex << endl;
			cout << "���䣺" << i.st_age << endl;
			cout << endl; 
		}
	}
	cout << endl;
}

void student::get()
{
	cout << "������ѧ�ţ�1-100֮��\n" ;
	int id;
	cin >> id;
	if (check(id) && id >= 1 && id <= 100)
	{
		cout << "ѧ�ţ�" << stu[id].st_id << endl;
		cout << "������" << stu[id].st_name << endl;
		cout << "�Ա�" << stu[id].st_sex << endl;
		cout << "���䣺" << stu[id].st_age << endl; 
	}
	else cout << "�������� �����²�ѯ" << endl; 
	cout << endl;
}

int student::del(int id)
{
	if (check(id) && id >= 1 && id <= 100)
	{
		stu[id].st_id = -1;
		stu[id].st_name = "";
		stu[id].st_sex = "";
		stu[id].st_age = -1; 
		flag[id] = -1;
		cout << "ɾ���ɹ���\n\n"; 
		return 1;
	}
	else cout << "�������� ����������" << endl;
	cout << endl; 
	return 0;
}

void student::save()
{
	fstream myFile;
	myFile.open("ѧ������.txt", ios::out);  // write,�����д��
	if (myFile.is_open())
	{ 
		for (auto i : stu)
		{
			if (i.st_id != -1)
			{
//				cout << "ѧ�ţ�" << i.st_id << endl;
//				cout << "������" << i.st_name << endl;
//				cout << "�Ա�" << i.st_sex << endl;
//				cout << "���䣺" << i.st_age << endl;
//				cout << endl; 
				myFile << i.st_id << endl << i.st_name << endl << i.st_sex << endl << i.st_age << endl << endl;
			}
		}	
		cout << "����ɹ�" << endl; 
		myFile.close();
	}
	else
	{
		cout << "����ʧ��" << endl; 
	}
}

void student::edit()
{
	cout << "��������Ҫ�޸ĵ���Ϣ����ѧ�Ų��ɸ��ģ�" << endl;
	cout << "1 - ����" << endl;
	cout << "2 - �Ա�" << endl;
	cout << "3 - ����" << endl;
	int f; cin >> f;
	if (f == 1)
	{
		cout << "������Ҫ�޸�ѧ����ѧ�ţ�" << endl;
		int id; cin >> id;
		if (check(id))
		{
			string name;
			cout << "�������޸ĺ������:" << endl;
			cin >> name;
			stu[id].st_name = name;
			cout << "�޸ĳɹ���" << endl; 
		 } 
		 else
		 {
		 	 cout << "����������" << endl;
		 }
	} 
	else if (f == 2)
	{
		cout << "������Ҫ�޸�ѧ����ѧ�ţ�" << endl;
		int id; cin >> id;
		if (check(id))
		{
			string sex;
			cout << "�������޸ĺ���Ա�:����/Ů��" << endl;
			cin >> sex;
			if (sex == "��" || sex == "Ů")
			{
				stu[id].st_sex = sex;
				cout << "�޸ĳɹ���" << endl; 
			}
			else cout << "��������" << endl; 
			
		 } 
		 else
		 {
		 	 cout << "����������" << endl;
		 }
	}
	else if (f == 3)
	{
		cout << "�������޸�ѧ����ѧ�ţ�" << endl;
		int id; cin >> id;
		if (check(id))
		{
			int age;
			cout << "�������޸ĺ������:(1-100)" << endl;
			cin >> age;
			if (age >= 1 && age <= 100)
			{
				stu[id].st_age = age;
				cout << "�޸ĳɹ���" << endl; 
			}
			else cout << "��������Ч����" << endl; 
		 } 
		 else
		 {
		 	 cout << "����������" << endl;
		 }
	}
}
//vector<int> student::get()
//{
//	vector <int> num;
//	for (int i = 1; i <= 100; i ++ )
//	{
//		if (check(i)) num.push_back(i);
//	}
//	return num;
// } 
//	


