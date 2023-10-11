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
		cout << "欢迎使用学生成绩管理系统!!!" << endl; 
		cout << "请输选择您要执行的操作" << endl; 
		cout << "1 - 导入初始数据" << endl;
		cout << "2 - 显示记录" << endl; 
		cout << "3 - 输入记录" << endl; 
		cout << "4 - 删除记录" << endl; 
		cout << "5 - 查询记录" << endl; 
		cout << "6 - 编辑记录" << endl; 
		cout << "7 - 去重" << endl; 
		cout << "8 - 保存数据" << endl; 
		cout << "0 - 退出" << endl; 
			
		int chose; cin >> chose;
		
		if (chose == 0) 
		{
			cout << "退出程序" << endl; 
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
		 	cout << "请输选择您要展示的数据" << endl; 
			cout << "1 - 学生信息" << endl;
			cout << "2 - 课程信息" << endl; 
			cout << "3 - 选课信息" << endl; 
			int f; cin >> f;
			if (f == 1) s.show(); 
			else if (f == 2) sb.show();
			else if (f == 3) chs.show();
		 }
		 else if (chose == 3)
		 {
		 	cout << "请输选择您要添加的数据" << endl; 
			cout << "1 - 学生信息" << endl;
			cout << "2 - 课程信息" << endl; 
			cout << "3 - 选课信息" << endl; 
			int f; cin >> f;
			if (f == 1) s.add();
			else if (f == 2) sb.add();
			else if (f == 3) chs.add(s, sb);
		 }
		 else if (chose == 4)
		 {
		 	cout << "请输选择您要删除的信息" << endl; 
			cout << "1 - 学生信息" << endl;
			cout << "2 - 课程信息" << endl; 
			cout << "3 - 选课信息" << endl; 
			int f; cin >> f;
			if (f == 1) 
			{
				cout << "输入您要删除的学生学号：" << endl; 
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
				cout << "输入您要删除的课程号：" << endl; 
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
				cout << "输入您想删除选课记录的学号和课程号\n请输入学号：" << endl; 
			 	int id1, id2;
			 	cin >> id1;
			 	cout << "请输入课程号：\n";
			 	cin >> id2;
			 	chs.del(id1, id2);
			}
		 }
		 else if (chose == 5)
		 {
		 	cout << "请输选择您要查询的信息" << endl; 
			cout << "1 - 学生信息" << endl;
			cout << "2 - 课程信息" << endl; 
			cout << "3 - 选课信息" << endl; 
			int f; cin >> f;
			if (f == 1) s.get();
			else if (f == 2) sb.get();
			else if (f == 3) chs.get();
		 }
		 else if (chose == 6)
		 {
		 	cout << "请输选择您要编辑的信息" << endl; 
			cout << "1 - 学生信息" << endl;
			cout << "2 - 课程信息" << endl; 
			cout << "3 - 选课信息" << endl; 
			int f; cin >> f;
			if (f == 1) s.edit();
			else if (f == 2) sb.edit();
			else if (f == 3) chs.edit();
		 }
		 else if (chose == 7)
		 {
		 	cout << "输入时已确保“学号”、“课程号”为主键，不会重复\n\n";
		 }
		 else if (chose == 8)
		 {
		 	s.save();
		 	sb.save();
		 	chs.save();
		 }
		 else
		 {
		 	cout << "输入无效" << endl << endl;
		  } 
	}
	return 0;
}
