#include <windows.h>
#include <bits/stdc++.h>
#include "student.h"
#include "subject.h"
#include "choose.h"
using namespace std;

student s;
subject sb; 
choose chs;
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */ 
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}



void s_delete(int id)
{
	
}

int main()
{
	
	while (1)
	{
		cout << "��ӭʹ��ѧ���ɼ�����ϵͳ!!!" << endl; 
		cout << "����ѡ����Ҫִ�еĲ���" << endl; 
		cout << "1 - �����ʼ����" << endl;
		cout << "2 - ��ʾ��Ϣ" << endl; 
		cout << "3 - �����¼" << endl; 
		cout << "4 - ɾ����¼" << endl; 
		cout << "5 - ��ѯ��Ϣ" << endl; 
		cout << "6 - �༭��¼" << endl; 
		cout << "7 - ȥ��" << endl; 
		cout << "8 - ������������" << endl; 
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
		 	cout << "�������ݳɹ�" << endl;	
		 }
		 else if (chose == 2)
		 {
		 	cout << "����ѡ����Ҫִ�еĲ���" << endl; 
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
		 	cout << "����ѡ����Ҫִ�еĲ���" << endl; 
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
		 	cout << "����ѡ����Ҫִ�еĲ���" << endl; 
			cout << "1 - ѧ����Ϣ" << endl;
			cout << "2 - �γ���Ϣ" << endl; 
			cout << "3 - ѡ����Ϣ" << endl; 
			int f; cin >> f;
			if (f == 1) 
			{
				cout << "��������ɾ����ѧ��ѧ�ţ�" << endl; 
			 	int id;
			 	cin >> id;
			 	s.del(id);
			}
			else if (f == 2)
			{
				cout << "��������ɾ���Ŀγ̺ţ�" << endl; 
			 	int id;
			 	cin >> id;
			 	sb.del(id);
			}
			else if (f == 3)
			{
				cout << "��������ɾ��ѡ�μ�¼��ѧ�źͿγ̺ţ�������ѧ�ţ�" << endl; 
			 	int id1, id2;
			 	cin >> id1;
			 	cout << "������γ̺ţ�\n";
			 	cin >> id2;
			 	chs.del(id1, id2);
			}
		 }
		 else if (chose == 5)
		 {
		 	cout << "����ѡ����Ҫִ�еĲ���" << endl; 
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
		 	cout << "����ѡ����Ҫִ�еĲ���" << endl; 
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
		 	cout << "����ʱ��ȷ����ѧ�š������γ̺š�Ϊ�����������ظ�\n";
		 }
		 else if (chose == 8)
		 {
		 	s.save();
		 	sb.save();
		 	chs.save();
		 }
	}
	return 0;
}
