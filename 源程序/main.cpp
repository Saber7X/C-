#include <windows.h>
#include <bits/stdc++.h>
#include "student.h"
#include "subject.h"
#include "choose.h"
using namespace std;

student s;
subject sb; 
choose chs;

int main()
{
	while (1)
	{
		cout << "��ӭʹ��ѧ���ɼ�����ϵͳ!!!" << endl; 
		cout << "����ѡ����Ҫִ�еĲ���" << endl; 
		cout << "1 - �����ʼ����" << endl;
		cout << "2 - ��ʾ��¼" << endl; 
		cout << "3 - �����¼" << endl; 
		cout << "4 - ɾ����¼" << endl; 
		cout << "5 - ��ѯ��¼" << endl; 
		cout << "6 - �༭��¼" << endl; 
		cout << "7 - ȥ��" << endl; 
		cout << "8 - ��������" << endl; 
		cout << "0 - �˳�" << endl; 
			
		int chose; cin >> chose;
		
		if (chose == 0) 
		{
			cout << "�˳�����" << endl; 
			break;
		 } 
		 else if (chose == 1)
		 {
		 	s.file_add(); 
		 	sb.file_add();
		 	chs.file_add();
		 	cout << endl; 
		 }
		 else if (chose == 2)
		 {
		 	cout << "����ѡ����Ҫչʾ������" << endl; 
			cout << "1 - ѧ����Ϣ" << endl;
			cout << "2 - �γ���Ϣ" << endl; 
			cout << "3 - ѡ����Ϣ" << endl; 
			int f; cin >> f;
			if (f == 1) s.show(); 
			else if (f == 2) sb.show();
			else if (f == 3) chs.show();
		 }
		 else if (chose == 3)
		 {
		 	cout << "����ѡ����Ҫ��ӵ�����" << endl; 
			cout << "1 - ѧ����Ϣ" << endl;
			cout << "2 - �γ���Ϣ" << endl; 
			cout << "3 - ѡ����Ϣ" << endl; 
			int f; cin >> f;
			if (f == 1) s.add();
			else if (f == 2) sb.add();
			else if (f == 3) chs.add(s, sb);
		 }
		 else if (chose == 4)
		 {
		 	cout << "����ѡ����Ҫɾ������Ϣ" << endl; 
			cout << "1 - ѧ����Ϣ" << endl;
			cout << "2 - �γ���Ϣ" << endl; 
			cout << "3 - ѡ����Ϣ" << endl; 
			int f; cin >> f;
			if (f == 1) 
			{
				cout << "������Ҫɾ����ѧ��ѧ�ţ�" << endl; 
			 	int id;
			 	cin >> id;
			 	int xx = s.del(id);
			 	if (xx == 1)
			 	{
			 		chs.delete_s(id);
				}
			}
			else if (f == 2)
			{
				cout << "������Ҫɾ���Ŀγ̺ţ�" << endl; 
			 	int id;
			 	cin >> id;
			 	int xx = sb.del(id);
			 	if (xx == 1)
			 	{
			 		chs.delete_sb(id);
				}
			}
			else if (f == 3)
			{
				cout << "��������ɾ��ѡ�μ�¼��ѧ�źͿγ̺�\n������ѧ�ţ�" << endl; 
			 	int id1, id2;
			 	cin >> id1;
			 	cout << "������γ̺ţ�\n";
			 	cin >> id2;
			 	chs.del(id1, id2);
			}
		 }
		 else if (chose == 5)
		 {
		 	cout << "����ѡ����Ҫ��ѯ����Ϣ" << endl; 
			cout << "1 - ѧ����Ϣ" << endl;
			cout << "2 - �γ���Ϣ" << endl; 
			cout << "3 - ѡ����Ϣ" << endl; 
			int f; cin >> f;
			if (f == 1) s.get();
			else if (f == 2) sb.get();
			else if (f == 3) chs.get();
		 }
		 else if (chose == 6)
		 {
		 	cout << "����ѡ����Ҫ�༭����Ϣ" << endl; 
			cout << "1 - ѧ����Ϣ" << endl;
			cout << "2 - �γ���Ϣ" << endl; 
			cout << "3 - ѡ����Ϣ" << endl; 
			int f; cin >> f;
			if (f == 1) s.edit();
			else if (f == 2) sb.edit();
			else if (f == 3) chs.edit();
		 }
		 else if (chose == 7)
		 {
		 	cout << "����ʱ��ȷ����ѧ�š������γ̺š�Ϊ�����������ظ�\n\n";
		 }
		 else if (chose == 8)
		 {
		 	s.save();
		 	sb.save();
		 	chs.save();
		 }
		 else
		 {
		 	cout << "������Ч" << endl << endl;
		  } 
	}
	return 0;
}
