struct sb{ //课程信息 
	int sb_id;
	string sb_name;
	int sb_point;
};

class subject{
public:
	void add(); //添加一个课程信息 
	void del(int id); //删除指定课程 
	void edit(); //修改指定课程
	void show(); //展示指定课程 
	bool check(int id);//查找该课程是否存在 
	void mark(int id);//标记课程存在 
	void get();//获取所有课程信息 
	void save();//一键保存数据 
	void file_add();
private:
	vector<sb> sub = vector<sb> (105, {-1, "", 0});
	bool flag[105]={0};
};
void subject::file_add()//一键添加所有文件 
{
	ifstream readFile;
	
	readFile.open("课程信息.txt", ios::in);
 
	if (readFile.is_open())
	{
		cout << "课程信息打开成功！" << endl;
		int p, id;
		string name;
		while (readFile >> id >> name >> p)
		{
//			cout << id << endl << name << endl;
			mark(id); 
	 		sub[id] = {id, name, p};
		}
	}
	else
	{
		cout << "文件打开失败！" << endl;
	}
 
	readFile.close();
	
}
void subject::add()
{
	int id;
	string name;
	int point;
	int s=0;
	while(1)
	{
		cout << "请输入课程号：（课程号是1-100的整数，输入0退出添加）\n";
		cin >> id; 
		if (id >= 1 && id <= 100 && !check(id)) break;
		if (id == 0) goto EXIT;
		if (id < 0 && id > 100) cout << "无效课程号，请重新输入\n";
		else if (check(id)) cout << "该课程号已存在，请重新输入\n";
		else  cout << "输入有误，请重新输入\n";
	 } 

	while(1)
	{
		cout << "请输入课程名\n课程名长度不超过50\n输入0退出添加学生\n";
		cin >> name; 
		if (name == "0") goto EXIT;
		if (name.length() >= 1 && id <= 50) break;
		else  cout << "输入有误，请重新输入\n";
	} 
	while(1)
	{
		cout << "请输入课程学分：（学分是1-10的整数，输入0退出添加）\n";
		cin >> point; 
		if (point == 0) goto EXIT;
		if (point >= 1 && point <= 10) break;
		else  cout << "输入有误，请重新输入\n";
	 } 
	 cout << "输入成功！（输入1保存该课程，输入0取消保存）\n";
	 
	 cin >> s;
	 if (s == 1)
	 {
	 	mark(id); 
	 	sub[id] = {id, name, point};
	} 
	EXIT:
		cout << "退出添加\n";
	cout << endl;
}

bool subject::check(int id)
{
	return flag[id] == 1;
}

void subject::mark(int id)
{
	flag[id] = 1;
}

void subject::show()
{
	cout << endl; 
	for (auto i : sub)
	{
		if (i.sb_id != -1)
		{
			cout << "课程号：" << i.sb_id << endl;
			cout << "课程名：" << i.sb_name << endl;
			cout << "学分：" << i.sb_point << endl;
			cout << endl; 
		}
	}
	cout << endl;
}

void subject::get()
{
	cout << "请输入课程号，1-100之间\n" ;
	int id;
	cin >> id;
	if (check(id) && id >= 1 && id <= 100)
	{
		cout << "课程号：" << sub[id].sb_id << endl;
		cout << "课程名：" << sub[id].sb_name << endl;
		cout << "学分：" << sub[id].sb_point << endl;
	}
	else cout << "输入有误， 请重新查询" << endl; 
	cout << endl;
}

void subject::del(int id)
{
	if (check(id) && id >= 1 && id <= 100)
	{
		sub[id].sb_id = -1;
		sub[id].sb_name = "";
		sub[id].sb_point = 0;
		flag[id] = 0;
		cout << "删除成功！\n\n"; 
	}
	else cout << "输入有误， 请重新输入" << endl;
	cout << endl; 
}

void subject::edit()
{
	cout << "请输入您想修改的信息：（学号不可更改）" << endl;
	cout << "1 - 课程名" << endl;
	cout << "2 - 学分" << endl;
	int f; cin >> f;
	if (f == 1)
	{
		cout << "请输入要修改的课程号：" << endl;
		int id; cin >> id;
		if (check(id))
		{
			string name;
			cout << "请输入修改后的课程名:" << endl;
			cin >> name;
			sub[id].sb_name = name;
			cout << "修改成功！" << endl; 
		 } 
		 else
		 {
		 	 cout << "该课程不存在" << endl;
		 }
	} 
	else if (f == 2)
	{
		cout << "请输入要修改课程的课程号：" << endl;
		int id; cin >> id;
		if (check(id))
		{
			int point;
			cout << "请输入修改后的学分：(1-10)" << endl;
			cin >> point;
			if (point >= 1 && point <= 10)
			{
				sub[id].sb_point = point;
				cout << "修改成功！" << endl; 
			}
			else cout << "请输入有效学分" << endl; 
		 } 
		 else
		 {
		 	 cout << "该课程不存在" << endl;
		 }
	}
}
void subject::save()
{
	fstream myFile;
	myFile.open("课程信息.txt", ios::out);  // write,清空再写入
	if (myFile.is_open())
	{ 
		for (auto i : sub)
		{
			if (i.sb_id != -1)
			{
//				cout << "学号：" << i.st_id << endl;
//				cout << "姓名：" << i.st_name << endl;
//				cout << "性别：" << i.st_sex << endl;
//				cout << "年龄：" << i.st_age << endl;
//				cout << endl; 
				myFile << i.sb_id << endl << i.sb_name << endl << i.sb_point << endl << endl;
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


