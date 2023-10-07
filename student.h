#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
struct st{ //学生姓名 
	int st_id;
	string st_name;
	string st_sex;
	int st_age;
};

class student{
public:
	void add(); //添加一个学生信息 
	void del(int id); //删除指定学生 
	void edit(); //修改指定学生 
	void show(); //展示指定学生 
	bool check(int id);//查找该学生是否存在 
	void mark(int id);//标记学生存在 
	void get();//获取所有学生学号 
	void save();//一键保存数据 
	void file_add();//一键添加所有文件 
private:
	vector<st> stu = vector<st> (105, {-1, "", "", 0});
	bool flag[105]={0};
};



void student::file_add()//一键添加所有文件 
{
	ifstream readFile;
	readFile.open("学生名单.txt", ios::in);
 
	if (readFile.is_open())
	{
		cout << "学生名单打开成功！" << endl;
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
		cout << "学生名单打开失败！" << endl;
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
		cout << "请输入学生学号：（学号是1-100的整数，输入0退出添加）\n";
		cin >> id; 
		if (id >= 1 && id <= 100 && !check(id)) break;
		if (id == 0) goto EXIT;
		if (id < 0 && id > 100) cout << "无效学号，请重新输入\n";
		else if (check(id)) cout << "该学号已存在，请重新输入\n";
		else  cout << "输入有误，请重新输入\n";
	 } 

	while(1)
	{
		cout << "请输入学生姓名\n姓名长度不超过20\n输入0退出添加学生\n";
		cin >> name; 
		if (name == "0") goto EXIT;
		if (name.length() >= 1 && id <= 20) break;
		else  cout << "输入有误，请重新输入\n";
	} 
	while(1)
	{
		cout << "请输入学生性别\n请输入“男”或“女”\n输入0退出添加学生\n";
		cin >> sex; 
		if (sex == "0") goto EXIT;
		if (sex == "男" || sex == "女") break;
		else  cout << "输入有误，请重新输入\n";
	} 	

	while(1)
	{
		cout << "请输入学生年龄：（年龄是1-100的整数，输入0退出添加）\n";
		cin >> age; 
		if (age == 0) goto EXIT;
		if (age >= 1 && age <= 100) break;
		else  cout << "输入有误，请重新输入\n";
	 } 
	 cout << "输入成功！（输入1保存该学生，输入0取消保存）\n";
	 
	 cin >> s;
	 if (s == 1)
	 {
	 	mark(id); 
	 	stu[id] = {id, name, sex, age};
//	 	cout <<  check(id) << endl;
	} 
	EXIT:
		cout << "退出添加\n";
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
			cout << "学号：" << i.st_id << endl;
			cout << "姓名：" << i.st_name << endl;
			cout << "性别：" << i.st_sex << endl;
			cout << "年龄：" << i.st_age << endl;
			cout << endl; 
		}
	}
	cout << endl;
}

void student::get()
{
	cout << "请输入学号，1-100之间\n" ;
	int id;
	cin >> id;
	if (check(id) && id >= 1 && id <= 100)
	{
		cout << "学号：" << stu[id].st_id << endl;
		cout << "姓名：" << stu[id].st_name << endl;
		cout << "性别：" << stu[id].st_sex << endl;
		cout << "年龄：" << stu[id].st_age << endl; 
	}
	else cout << "输入有误， 请重新查询" << endl; 
	cout << endl;
}

void student::del(int id)
{
	cout << "请输入学号，1-100之间" ;
	if (check(id) && id >= 1 && id <= 100)
	{
		stu[id].st_id = -1;
		stu[id].st_name = "";
		stu[id].st_sex = "";
		stu[id].st_age = -1; 
		flag[id] = -1;
		cout << "删除成功！\n\n"; 
	}
	else cout << "输入有误， 请重新输入" << endl;
	cout << endl; 
}

void student::save()
{
	fstream myFile;
	myFile.open("学生名单.txt", ios::out);  // write,清空再写入
	if (myFile.is_open())
	{ 
		for (auto i : stu)
		{
			if (i.st_id != -1)
			{
//				cout << "学号：" << i.st_id << endl;
//				cout << "姓名：" << i.st_name << endl;
//				cout << "性别：" << i.st_sex << endl;
//				cout << "年龄：" << i.st_age << endl;
//				cout << endl; 
				myFile << i.st_id << endl << i.st_name << endl << i.st_sex << endl << i.st_age << endl << endl;
			}
		}	
		cout << "保存成功" << endl; 
		myFile.close();
	}
	else
	{
		cout << "保存失败" << endl; 
	}
}

void student::edit()
{
	cout << "请输入您想修改的信息：（学号不可更改）" << endl;
	cout << "1 - 姓名" << endl;
	cout << "2 - 性别" << endl;
	cout << "3 - 年龄" << endl;
	int f; cin >> f;
	if (f == 1)
	{
		cout << "请输入要求改学生的学号：" << endl;
		int id; cin >> id;
		if (check(id))
		{
			string name;
			cout << "请输入修改后的名字:" << endl;
			cin >> name;
			stu[id].st_name = name;
			cout << "修改成功！" << endl; 
		 } 
		 else
		 {
		 	 cout << "该生不存在" << endl;
		 }
	} 
	else if (f == 2)
	{
		cout << "请输入要求改学生的学号：" << endl;
		int id; cin >> id;
		if (check(id))
		{
			string sex;
			cout << "请输入修改后的性别:（男/女）" << endl;
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				stu[id].st_sex = sex;
				cout << "修改成功！" << endl; 
			}
			else cout << "输入有误" << endl; 
			
		 } 
		 else
		 {
		 	 cout << "该生不存在" << endl;
		 }
	}
	else if (f == 3)
	{
		cout << "请输入要求改学生的学号：" << endl;
		int id; cin >> id;
		if (check(id))
		{
			int age;
			cout << "请输入修改后的年龄:(1-100)" << endl;
			cin >> age;
			if (age >= 1 && age <= 100)
			{
				stu[id].st_age = age;
				cout << "修改成功！" << endl; 
			}
			else cout << "请输入有效年龄" << endl; 
		 } 
		 else
		 {
		 	 cout << "该生不存在" << endl;
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


