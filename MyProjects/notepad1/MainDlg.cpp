#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include <commdlg.h>
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
        case ID_MENUOPEN:
		{
			FILE * fp = fopen("c:/1.txt","r");
		    char line[256];
			fgets(line,sizeof(line),fp);
            fclose(fp);
			SetDlgItemText(hwnd,IDC_EDIT1,TEXT(line));
			SetDlgItemText(hwnd,IDC_RICHEDIT1,TEXT(line));

			
		}
        break;
		case IDC_BUTTON1:
			{

				OPENFILENAME ofn;
			char szfile[MAX_PATH];
			ZeroMemory(&ofn,sizeof(ofn));
			ofn.lStructSize= sizeof(ofn);	
			ofn.lpstrFile = szfile;
			ofn.lpstrFile[0] = TEXT('\0');
			ofn.nMaxFile = sizeof(szfile);
			ofn.lpstrFilter =  TEXT("ALL\0*.*\0TEXT\0*.txt\o");
			ofn.nFilterIndex = 2;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.hwndOwner = hwnd;
			ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST;
			if(GetOpenFileName(&ofn)){
			  //MessageBox(NULL,szfile,"",MB_OK);
			FILE * fp = fopen(szfile,"r");
		    char line[256];
			fgets(line,sizeof(line),fp);
            fclose(fp);
			SetDlgItemText(hwnd,IDC_EDIT1,TEXT(line));
			SetDlgItemText(hwnd,IDC_RICHEDIT1,TEXT(line));	
			}

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