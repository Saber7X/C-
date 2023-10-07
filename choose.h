struct ch{ //选课 
	int st_id; // 学号 
	int sb_id; // 课程号 
	bool operator < (const ch &a)const
    {
        if (st_id == a.st_id)   return sb_id < a.sb_id;
        else return st_id < a.st_id;
    }
};

class choose{
public:
	void add(student s1, subject s2); //添加一个选课记录 
	void del(int id1, int id2); //删除指定记录 
	void edit(); //修改指定记录 
	void show(); //展示指定记录 
	bool check(ch f);//查找该记录是否存在 
	void mark(ch f, int p);//标记录存在 
	void get();//获取所有选课记录 
	friend void student::file_add();
private:
	map<ch, int> cho;
};

void choose::add(student s1, subject s2)
{
	int id1, id2;
	int point;
	int s=0;
	while(1)
	{
		cout << "请输入学号：（学号是1-100的整数，输入0退出添加）\n";
		cin >> id1; 
		if (id1 >= 1 && id1 <= 100 && s1.check(id1)) break;
		if (id1 == 0) goto EXIT;
		if (id1 < 0 && id1 > 100) cout << "无效课程号，请重新输入\n";
		else  cout << "输入有误，请重新输入\n";
	 } 

	while(1)
	{
		cout << "请输入课程号：（课程号是1-100的整数，输入0退出添加）\n";
		cin >> id2; 
		if (id2 >= 1 && id2 <= 100 && s2.check(id2)) break;
		if (id2 == 0) goto EXIT;
		if (id2 < 0 && id2 > 100) cout << "无效课程号，请重新输入\n";
		else  cout << "输入有误，请重新输入\n";
	 } 
	while(1)
	{
		cout << "请输入成绩：（成绩是1-100的整数，输入0退出添加）\n";
		cin >> point; 
		if (point == 0) goto EXIT;
		if (point >= 1 && point <= 100) break;
		else  cout << "输入有误，请重新输入\n";
	 } 
	 cout << "输入成功！（输入1保存该记录，输入0取消保存）\n";
	 
	 cin >> s;
	 if (s == 1)
	 {
	 	mark({id1, id2}, point); 
	} 
	EXIT:
		cout << "退出添加\n";
	cout << endl;
}

bool choose::check(ch f)
{
	int x = cho[f];
	return x != 0;
}

void choose::mark(ch f, int p)
{
	cho[f] = p;
}

void choose::show()
{
	cout << endl; 
	for (auto i : cho)
	{
		if (i.second != 0)
		{
			cout << "学号：" << i.first.st_id << endl;
			cout << "课程号：" << i.first.sb_id << endl;
			cout << "成绩：" << i.second << endl;
			cout << endl; 
		}
	}
	cout << endl;
}

void choose::get()
{
	cout << "请输入学号和课程号，1-100之间\n" ;
	int id1, id2;
	cin >> id1 >> id2;
	if (cho[{id1, id2}] != 0)
	{
		cout << "学号：" << id1 << endl;
		cout << "课程号：" << id2 << endl;
		cout << "成绩：" << cho[{id1, id2}] << endl;
	}
	else cout << "输入有误， 请重新查询" << endl; 
	cout << endl;
}

void choose::del(int id1, int id2)
{
	cho[{id1, id2}] = 0;
	cout << "删除成功！\n\n"; 
}

void choose::edit()
{
	cout << "请输入要修改的选修记录：" << endl;
	int id1, id2; cin >> id1 >> id2;
	if (check({id1, id2}))
	{
		int point;
		cout << "请输入修改后的成绩:" << endl;
		cin >> point;
		if (point >= 1 && point <= 100)
		{
			cho[{id1, id2}] = point;
			cout << "修改成功！" << endl; 
		}
	 } 
	 else
	 {
	 	 cout << "该记录不存在" << endl;
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


