#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include <winsock2.h>
#include "resource.h"
#include "MainDlg.h"
#pragma comment(lib,"ws2_32.lib")
/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
*/
BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
    }

    return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
		{
		    
			SocketTest();
		}
        break;
        default:
		break;
    }
}


void SocketTest()
{ 
      WSADATA wsaData;
    //��ʼ��Socket��
	WSAStartup(MAKEWORD(2,0),&wsaData);
    //����һ������
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN sa;
	sa.sin_family=AF_INET;
    //���õ������ӷ������˵Ķ˿�
	sa.sin_port = htons(IPPORT_TIMESERVER);
    //123.125.50.135��ping smtp.163.com�����ģ�����ὲʹ��gethostbyname��ֱ�Ӵ�
    //�������õ�ip��ַ 
	sa.sin_addr.S_un.S_addr = inet_addr("220.181.12.17");
    //Ϊʲô�������ÿͻ��˵Ķ˿ڣ��ѵ�����Ҫ�ͻ��˵Ķ˿���
	if(connect(sock,(SOCKADDR *)&sa,sizeof(sa))==SOCKET_ERROR)
	{
	ShowError();
	return;
	}
	
	unsigned long ulTime = 0;

	//����smtp
	TCHAR buff[256];
    ZeroMemory(buff,sizeof(buff)/sizeof(TCHAR));
	//
	recv(sock,(char *)&ulTime,sizeof(unsigned long),0);
    
	MessageBox(NULL,buff,TEXT("������Ϣ"),MB_OK);

	TCHAR hello[] = "QUIT\n";
	send(sock,hello,sizeof(hello)/sizeof(TCHAR),0);
	
	ZeroMemory(buff,sizeof(buff)/sizeof(TCHAR));
	recv(sock,buff,sizeof(buff)/sizeof(TCHAR),0);
	wsprintf(buff,"%i",ulTime);
	MessageBox(NULL,buff,TEXT("������Ϣ"),MB_OK);




//�����顣�Ѵ���ű���ss�ܹ��ּ��� 
closesocket(sock);
WSACleanup();



}

void ShowError()
{
TCHAR* lpMsgBuf;
FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER| //�Զ�������Ϣ������
FORMAT_MESSAGE_FROM_SYSTEM, //��ϵͳ��ȡ��Ϣ
NULL,GetLastError(), //��ȡ������Ϣ��ʶ
MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),//ʹ��ϵͳȱʡ����
(LPTSTR)&lpMsgBuf, //��Ϣ������
0,
NULL);
MessageBox(NULL,lpMsgBuf,"",MB_ICONERROR); 
}


void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}