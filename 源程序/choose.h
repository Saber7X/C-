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
	void file_add();
	void save();
	
	void delete_s(int id); //当一个学生信息被删除时，他的选课信息也要被删除
	void delete_sb(int id);//当一个课程信息被删除时，选了它的记录也要被删除 
private:
	map<ch, int> cho;
};
void choose::file_add()//一键添加所有文件 
{
	ifstream readFile;
	
	readFile.open("选课信息.txt", ios::in);
 
	if (readFile.is_open())
	{
		cout << "选课信息打开成功！" << endl;
		int id1, id2, p;
		while (readFile >>id1 >> id2 >> p)
		{
//			cout << id << endl << name << endl;
			mark({id1, id2}, p); 
		}
	}
	else
	{
		cout << "文件打开失败！" << endl;
	}
 
	readFile.close();
}
void choose::add(student s1, subject s2)
{
	int id1, id2;
	int point;
	int s=0;
	while(1)
	{
		cout << "请输入学号：（学号是1-100的整数，输入0退出添加）\n";
		cin >> id1; 
		if (id1 >= 1 && id1 <= 100 && s1.check(id1))
		{
			
		}
		else if (id1 == 0) goto EXIT;
		else if (id1 < 0 && id1 > 100) 
		{
			cout << "无效课程号，请重新输入\n";
			continue;
		}
		else  
		{
			cout << "输入有误，请重新输入\n";
			continue;
		}
		
		cout << "请输入课程号：（课程号是1-100的整数，输入0退出添加）\n";
		cin >> id2; 
		if (id2 >= 1 && id2 <= 100 && s2.check(id2))
		{
			
		}
		else if (id2 == 0) goto EXIT;
		else if (id2 < 0 && id2 > 100) 
		{
			cout << "无效课程号，请重新输入\n";
			continue;
		}
		else  
		{
			cout << "输入有误，请重新输入\n";
			continue;
		}
		if (check({id1, id2}))
		{
			cout << "该选课记录已存在，请重新输入" << endl;
			continue;
		}
		else
		{
			break;
		}
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
	 	cout << "保存成功！"  << endl << endl; 
	} 
	EXIT:
		cout << "退出添加\n";
	cout << endl;
}

bool choose::check(ch f)
{
	int x = cho[f];
	if (x == 0) return false;
	else return true;
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
	cout << "输入学号和课程号\n"; 
	cout << "请输入学号：（1-100之间）\n" ;
	int id1, id2;
	cin >> id1;
	cout << "请输入课程号：（1-100之间）\n" ;
	cin >> id2;
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
	cout << "输入学号和课程号\n"; 
	cout << "请输入学号：（1-100之间）\n" ;
	int id1, id2;
	cin >> id1;
	cout << "请输入课程号：（1-100之间）\n" ;
	cin >> id2;
	if (check({id1, id2}))
	{
		int point;
		cout << "请输入修改后的成绩:" << endl;
		cin >> point;
		if (point >= 1 && point <= 100)
		{
			cho[{id1, id2}] = point;
			cout << "修改成功！" << endl << endl; 
		}
	 } 
	 else
	 {
	 	 cout << "该记录不存在" << endl << endl;
	 }
}
void choose::save()
{
	fstream myFile;
	myFile.open("选课信息.txt", ios::out);  // write,清空再写入
	if (myFile.is_open())
	{ 
		for (auto i : cho)
		{
			if (i.second != 0)
			{
				myFile << i.first.st_id << endl<< i.first.sb_id << endl<< i.second << endl << endl;
			}
		}
		cout << "保存成功！" << endl; 
		myFile.close();
	}
	else
	{
		cout << "保存失败" << endl; 
	}
}
void choose::delete_s(int id) //当一个学生信息被删除时，他的选课信息也要被删除
{
	for (auto i : cho)
	{
		if (i.first.st_id == id)
		{
			del(i.first.st_id, i.first.sb_id);
		}
	 } 
}
void choose::delete_sb(int id)//当一个课程信息被删除时，选了它的记录也要被删除 
{
	for (auto i : cho)
	{
		if (i.first.sb_id == id)
		{
			del(i.first.st_id, i.first.sb_id);
		}
	 } 
}


