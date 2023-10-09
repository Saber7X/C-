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
	void add(student s1, subject s2); //���һ��ѡ�μ�¼ 
	void del(int id1, int id2); //ɾ��ָ����¼ 
	void edit(); //�޸�ָ����¼ 
	void show(); //չʾָ����¼ 
	bool check(ch f);//���Ҹü�¼�Ƿ���� 
	void mark(ch f, int p);//���¼���� 
	void get();//��ȡ����ѡ�μ�¼ 
	void file_add();
	void save();
	
	void delete_s(int id); //��һ��ѧ����Ϣ��ɾ��ʱ������ѡ����ϢҲҪ��ɾ��
	void delete_sb(int id);//��һ���γ���Ϣ��ɾ��ʱ��ѡ�����ļ�¼ҲҪ��ɾ�� 
private:
	map<ch, int> cho;
};
void choose::file_add()//һ����������ļ� 
{
	ifstream readFile;
	
	readFile.open("ѡ����Ϣ.txt", ios::in);
 
	if (readFile.is_open())
	{
		cout << "ѡ����Ϣ�򿪳ɹ���" << endl;
		int id1, id2, p;
		while (readFile >>id1 >> id2 >> p)
		{
//			cout << id << endl << name << endl;
			mark({id1, id2}, p); 
		}
	}
	else
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "������ѧ�ţ���ѧ����1-100������������0�˳���ӣ�\n";
		cin >> id1; 
		if (id1 >= 1 && id1 <= 100 && s1.check(id1))
		{
			
		}
		else if (id1 == 0) goto EXIT;
		else if (id1 < 0 && id1 > 100) 
		{
			cout << "��Ч�γ̺ţ�����������\n";
			continue;
		}
		else  
		{
			cout << "������������������\n";
			continue;
		}
		
		cout << "������γ̺ţ����γ̺���1-100������������0�˳���ӣ�\n";
		cin >> id2; 
		if (id2 >= 1 && id2 <= 100 && s2.check(id2))
		{
			
		}
		else if (id2 == 0) goto EXIT;
		else if (id2 < 0 && id2 > 100) 
		{
			cout << "��Ч�γ̺ţ�����������\n";
			continue;
		}
		else  
		{
			cout << "������������������\n";
			continue;
		}
		if (check({id1, id2}))
		{
			cout << "��ѡ�μ�¼�Ѵ��ڣ�����������" << endl;
			continue;
		}
		else
		{
			break;
		}
	 } 
	 
	while(1)
	{
		cout << "������ɼ������ɼ���1-100������������0�˳���ӣ�\n";
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
	 	cout << "����ɹ���"  << endl << endl; 
	} 
	EXIT:
		cout << "�˳����\n";
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
	cout << "����ѧ�źͿγ̺�\n"; 
	cout << "������ѧ�ţ���1-100֮�䣩\n" ;
	int id1, id2;
	cin >> id1;
	cout << "������γ̺ţ���1-100֮�䣩\n" ;
	cin >> id2;
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
	cout << "����ѧ�źͿγ̺�\n"; 
	cout << "������ѧ�ţ���1-100֮�䣩\n" ;
	int id1, id2;
	cin >> id1;
	cout << "������γ̺ţ���1-100֮�䣩\n" ;
	cin >> id2;
	if (check({id1, id2}))
	{
		int point;
		cout << "�������޸ĺ�ĳɼ�:" << endl;
		cin >> point;
		if (point >= 1 && point <= 100)
		{
			cho[{id1, id2}] = point;
			cout << "�޸ĳɹ���" << endl << endl; 
		}
	 } 
	 else
	 {
	 	 cout << "�ü�¼������" << endl << endl;
	 }
}
void choose::save()
{
	fstream myFile;
	myFile.open("ѡ����Ϣ.txt", ios::out);  // write,�����д��
	if (myFile.is_open())
	{ 
		for (auto i : cho)
		{
			if (i.second != 0)
			{
				myFile << i.first.st_id << endl<< i.first.sb_id << endl<< i.second << endl << endl;
			}
		}
		cout << "����ɹ���" << endl; 
		myFile.close();
	}
	else
	{
		cout << "����ʧ��" << endl; 
	}
}
void choose::delete_s(int id) //��һ��ѧ����Ϣ��ɾ��ʱ������ѡ����ϢҲҪ��ɾ��
{
	for (auto i : cho)
	{
		if (i.first.st_id == id)
		{
			del(i.first.st_id, i.first.sb_id);
		}
	 } 
}
void choose::delete_sb(int id)//��һ���γ���Ϣ��ɾ��ʱ��ѡ�����ļ�¼ҲҪ��ɾ�� 
{
	for (auto i : cho)
	{
		if (i.first.sb_id == id)
		{
			del(i.first.st_id, i.first.sb_id);
		}
	 } 
}


