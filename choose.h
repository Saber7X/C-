struct ch{ //ѡ�� 
	int st_id; // ѧ�� 
	int sb_id; // �γ̺� 
	bool operator < (const ch &a)const
    {
        if (st_id == a.st_id)   return sb_id < a.sb_id;
        else return st_id < a.st_id;
    }
};

class choose{
public:
	void add(student s1, subject s2); //����һ��ѡ�μ�¼ 
	void del(int id1, int id2); //ɾ��ָ����¼ 
	void edit(); //�޸�ָ����¼ 
	void show(); //չʾָ����¼ 
	bool check(ch f);//���Ҹü�¼�Ƿ���� 
	void mark(ch f, int p);//���¼���� 
	void get();//��ȡ����ѡ�μ�¼ 
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
		cout << "������ѧ�ţ���ѧ����1-100������������0�˳����ӣ�\n";
		cin >> id1; 
		if (id1 >= 1 && id1 <= 100 && s1.check(id1)) break;
		if (id1 == 0) goto EXIT;
		if (id1 < 0 && id1 > 100) cout << "��Ч�γ̺ţ�����������\n";
		else  cout << "������������������\n";
	 } 

	while(1)
	{
		cout << "������γ̺ţ����γ̺���1-100������������0�˳����ӣ�\n";
		cin >> id2; 
		if (id2 >= 1 && id2 <= 100 && s2.check(id2)) break;
		if (id2 == 0) goto EXIT;
		if (id2 < 0 && id2 > 100) cout << "��Ч�γ̺ţ�����������\n";
		else  cout << "������������������\n";
	 } 
	while(1)
	{
		cout << "������ɼ������ɼ���1-100������������0�˳����ӣ�\n";
		cin >> point; 
		if (point == 0) goto EXIT;
		if (point >= 1 && point <= 100) break;
		else  cout << "������������������\n";
	 } 
	 cout << "����ɹ���������1����ü�¼������0ȡ�����棩\n";
	 
	 cin >> s;
	 if (s == 1)
	 {
	 	mark({id1, id2}, point); 
	} 
	EXIT:
		cout << "�˳�����\n";
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
			cout << "ѧ�ţ�" << i.first.st_id << endl;
			cout << "�γ̺ţ�" << i.first.sb_id << endl;
			cout << "�ɼ���" << i.second << endl;
			cout << endl; 
		}
	}
	cout << endl;
}

void choose::get()
{
	cout << "������ѧ�źͿγ̺ţ�1-100֮��\n" ;
	int id1, id2;
	cin >> id1 >> id2;
	if (cho[{id1, id2}] != 0)
	{
		cout << "ѧ�ţ�" << id1 << endl;
		cout << "�γ̺ţ�" << id2 << endl;
		cout << "�ɼ���" << cho[{id1, id2}] << endl;
	}
	else cout << "�������� �����²�ѯ" << endl; 
	cout << endl;
}

void choose::del(int id1, int id2)
{
	cho[{id1, id2}] = 0;
	cout << "ɾ���ɹ���\n\n"; 
}

void choose::edit()
{
	cout << "������Ҫ�޸ĵ�ѡ�޼�¼��" << endl;
	int id1, id2; cin >> id1 >> id2;
	if (check({id1, id2}))
	{
		int point;
		cout << "�������޸ĺ�ĳɼ�:" << endl;
		cin >> point;
		if (point >= 1 && point <= 100)
		{
			cho[{id1, id2}] = point;
			cout << "�޸ĳɹ���" << endl; 
		}
	 } 
	 else
	 {
	 	 cout << "�ü�¼������" << endl;
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

