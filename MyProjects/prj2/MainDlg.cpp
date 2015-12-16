#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

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
			//GetDlgItemText  ��һ�������Ǵ��ڵľ�� �ڶ���������Ҫȡ�õ����ݵĿռ��id
			//�������������ַ���ָ��  ���ĸ�������ָ��ָ������Ĵ�С
			 
			//char name[256];
			TCHAR  name[256];
			GetDlgItemText(hwnd,IDC_EDIT1,name,sizeof(name));
			TCHAR name2[256];
			GetDlgItemText(hwnd,IDC_EDIT1,name2,sizeof(name2));
			//sprintf(�ַ���ָ�� )
			TCHAR msg[256];
			//sprintf(msg,"%s���",name);
			wsprintf(msg,"%s���",name);
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