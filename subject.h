struct sb{ //�γ���Ϣ 
	int sb_id;
	string sb_name;
	int sb_point;
};

class subject{
public:
	void add(); //���һ���γ���Ϣ 
	void del(int id); //ɾ��ָ���γ� 
	void edit(); //�޸�ָ���γ�
	void show(); //չʾָ���γ� 
	bool check(int id);//���Ҹÿγ��Ƿ���� 
	void mark(int id);//��ǿγ̴��� 
	void get();//��ȡ���пγ���Ϣ 
	void save();//һ���������� 
	void file_add();
private:
	vector<sb> sub = vector<sb> (105, {-1, "", 0});
	bool flag[105]={0};
};
void subject::file_add()//һ����������ļ� 
{
	ifstream readFile;
	
	readFile.open("�γ���Ϣ.txt", ios::in);
 
	if (readFile.is_open())
	{
		cout << "�γ���Ϣ�򿪳ɹ���" << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "������γ̺ţ����γ̺���1-100������������0�˳���ӣ�\n";
		cin >> id; 
		if (id >= 1 && id <= 100 && !check(id)) break;
		if (id == 0) goto EXIT;
		if (id < 0 && id > 100) cout << "��Ч�γ̺ţ�����������\n";
		else if (check(id)) cout << "�ÿγ̺��Ѵ��ڣ�����������\n";
		else  cout << "������������������\n";
	 } 

	while(1)
	{
		cout << "������γ���\n�γ������Ȳ�����50\n����0�˳����ѧ��\n";
		cin >> name; 
		if (name == "0") goto EXIT;
		if (name.length() >= 1 && id <= 50) break;
		else  cout << "������������������\n";
	} 
	while(1)
	{
		cout << "������γ�ѧ�֣���ѧ����1-10������������0�˳���ӣ�\n";
		cin >> point; 
		if (point == 0) goto EXIT;
		if (point >= 1 && point <= 10) break;
		else  cout << "������������������\n";
	 } 
	 cout << "����ɹ���������1����ÿγ̣�����0ȡ�����棩\n";
	 
	 cin >> s;
	 if (s == 1)
	 {
	 	mark(id); 
	 	sub[id] = {id, name, point};
	} 
	EXIT:
		cout << "�˳����\n";
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
			cout << "�γ̺ţ�" << i.sb_id << endl;
			cout << "�γ�����" << i.sb_name << endl;
			cout << "ѧ�֣�" << i.sb_point << endl;
			cout << endl; 
		}
	}
	cout << endl;
}

void subject::get()
{
	cout << "������γ̺ţ�1-100֮��\n" ;
	int id;
	cin >> id;
	if (check(id) && id >= 1 && id <= 100)
	{
		cout << "�γ̺ţ�" << sub[id].sb_id << endl;
		cout << "�γ�����" << sub[id].sb_name << endl;
		cout << "ѧ�֣�" << sub[id].sb_point << endl;
	}
	else cout << "�������� �����²�ѯ" << endl; 
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
		cout << "ɾ���ɹ���\n\n"; 
	}
	else cout << "�������� ����������" << endl;
	cout << endl; 
}

void subject::edit()
{
	cout << "�����������޸ĵ���Ϣ����ѧ�Ų��ɸ��ģ�" << endl;
	cout << "1 - �γ���" << endl;
	cout << "2 - ѧ��" << endl;
	int f; cin >> f;
	if (f == 1)
	{
		cout << "������Ҫ�޸ĵĿγ̺ţ�" << endl;
		int id; cin >> id;
		if (check(id))
		{
			string name;
			cout << "�������޸ĺ�Ŀγ���:" << endl;
			cin >> name;
			sub[id].sb_name = name;
			cout << "�޸ĳɹ���" << endl; 
		 } 
		 else
		 {
		 	 cout << "�ÿγ̲�����" << endl;
		 }
	} 
	else if (f == 2)
	{
		cout << "������Ҫ�޸Ŀγ̵Ŀγ̺ţ�" << endl;
		int id; cin >> id;
		if (check(id))
		{
			int point;
			cout << "�������޸ĺ��ѧ�֣�(1-10)" << endl;
			cin >> point;
			if (point >= 1 && point <= 10)
			{
				sub[id].sb_point = point;
				cout << "�޸ĳɹ���" << endl; 
			}
			else cout << "��������Чѧ��" << endl; 
		 } 
		 else
		 {
		 	 cout << "�ÿγ̲�����" << endl;
		 }
	}
}
void subject::save()
{
	fstream myFile;
	myFile.open("�γ���Ϣ.txt", ios::out);  // write,�����д��
	if (myFile.is_open())
	{ 
		for (auto i : sub)
		{
			if (i.sb_id != -1)
			{
//				cout << "ѧ�ţ�" << i.st_id << endl;
//				cout << "������" << i.st_name << endl;
//				cout << "�Ա�" << i.st_sex << endl;
//				cout << "���䣺" << i.st_age << endl;
//				cout << endl; 
				myFile << i.sb_id << endl << i.sb_name << endl << i.sb_point << endl << endl;
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


