#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

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
			//GetDlgItemText  第一个参数是窗口的句柄 第二个参数是要取得的内容的空间的id
			//第三个参数是字符串指针  第四个参数是指针指向区域的大小
			 
			//char name[256];
			TCHAR  name[256];
			GetDlgItemText(hwnd,IDC_EDIT1,name,sizeof(name));
			TCHAR name2[256];
			GetDlgItemText(hwnd,IDC_EDIT1,name2,sizeof(name2));
			//sprintf(字符串指针 )
			TCHAR msg[256];
			//sprintf(msg,"%s你好",name);
			wsprintf(msg,"%s你好",name);
			MessageBox(hwnd,name,msg,MB_OK);
		}
        break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}