#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include <winsock2.h>
#include "resource.h"
#include "MainDlg.h"
#pragma comment(lib,"ws2_32.lib")
/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
如鹏网（http://www.rupeng.com）大学生计算机学习社区，提供大量免费视频学习教程，提供个性化一对一学习指导
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
    //初始化Socket库
	WSAStartup(MAKEWORD(2,0),&wsaData);
    //创建一根电线
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN sa;
	sa.sin_family=AF_INET;
    //设置电线连接服务器端的端口
	sa.sin_port = htons(IPPORT_TIMESERVER);
    //123.125.50.135是ping smtp.163.com出来的，后面会讲使用gethostbyname来直接从
    //主机名得到ip地址 
	sa.sin_addr.S_un.S_addr = inet_addr("220.181.12.17");
    //为什么不用设置客户端的端口，难道不需要客户端的端口吗？
	if(connect(sock,(SOCKADDR *)&sa,sizeof(sa))==SOCKET_ERROR)
	{
	ShowError();
	return;
	}
	
	unsigned long ulTime = 0;

	//接受smtp
	TCHAR buff[256];
    ZeroMemory(buff,sizeof(buff)/sizeof(TCHAR));
	//
	recv(sock,(char *)&ulTime,sizeof(unsigned long),0);
    
	MessageBox(NULL,buff,TEXT("返回消息"),MB_OK);

	TCHAR hello[] = "QUIT\n";
	send(sock,hello,sizeof(hello)/sizeof(TCHAR),0);
	
	ZeroMemory(buff,sizeof(buff)/sizeof(TCHAR));
	recv(sock,buff,sizeof(buff)/sizeof(TCHAR),0);
	wsprintf(buff,"%i",ulTime);
	MessageBox(NULL,buff,TEXT("返回消息"),MB_OK);




//做事情。把大象放冰箱ss总共分几步 
closesocket(sock);
WSACleanup();



}

void ShowError()
{
TCHAR* lpMsgBuf;
FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER| //自动分配消息缓冲区
FORMAT_MESSAGE_FROM_SYSTEM, //从系统获取信息
NULL,GetLastError(), //获取错误信息标识
MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),//使用系统缺省语言
(LPTSTR)&lpMsgBuf, //消息缓冲区
0,
NULL);
MessageBox(NULL,lpMsgBuf,"",MB_ICONERROR); 
}


void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}