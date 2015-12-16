#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "LoginDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
*/
BOOL WINAPI Login_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Login_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Login_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Login_OnClose);
    }

    return FALSE;
}

BOOL Login_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	LoginData* ld = (LoginData*)lParam;
    //TCHAR* buff = (TCHAR*)lParam;
	//itoa(lParam,c,10);
	//wsprintf("%i",c,lParam);
	MessageBox(hwnd,ld->username,TEXT(""),MB_OK);
    return TRUE;
}

void Login_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
		{
			  
		}
        break;
        default:
		break;
    }
}

void Login_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}