#include "stdafx.h"
#include "windows.h"
#include "windowsx.h"
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

VOID CALLBACK MyTimerProc(HWND hwnd,UINT message,UINT iTimerID,DWORD dateTime){

	  SYSTEMTIME stLocal;
	  GetLocalTime(&stLocal);
	  TCHAR strTime[256];
	  wsprintf(strTime,"%i��%i��%i�� %i:%i:%i",stLocal.wYear,stLocal.wMonth,stLocal.wDay,stLocal.wHour,stLocal.wMinute,stLocal.wSecond);
	  SetDlgItemText(hwnd,IDC_EDITTIME,strTime);
} 


BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{   

	    SetTimer(hwnd,0,2000,MyTimerProc);

		HWND hwndcombo = GetDlgItem(hwnd,IDC_COMBOOP);
			//ComboBox_AddString(hwndcombo,TEXT("+"));
			//ComboBox_AddString(hwndcombo,TEXT("-"));
			ComboBox_InsertString(hwndcombo,-1,TEXT("+"));
			ComboBox_InsertString(hwndcombo,-1,TEXT("-"));
			ComboBox_InsertString(hwndcombo,-1,TEXT("*"));
			ComboBox_InsertString(hwndcombo,-1,TEXT("/"));
	
    return TRUE;
}

BOOL  isInt(TCHAR* str){
	int i = atoi(str);
	TCHAR strtemp[256];
	wsprintf(strtemp,"%i",i);
	if(strcmp(str,strtemp)!=0){
	  return false;
	}
	return true;

}


void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
		{ 

            //
		    

			//��һ��������С����
			TCHAR str1[256];
			TCHAR str2[256];
			GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
			GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
			//c��׼���� atoi a:ascii to  i:int 
			int i1 = atoi(str1);
			int i2 = atoi(str2);
            if(!isInt(str1)){
			  MessageBox(hwnd,TEXT("��һ���������ǺϷ�����"),TEXT("error"),MB_OK|MB_ICONERROR);
			  return;
			}

			  if(!isInt(str2)){
			  MessageBox(hwnd,TEXT("�ڶ����������ǺϷ�����"),TEXT("error"),MB_OK|MB_ICONERROR);
			  return;
			}
			  HWND comboHwnd = GetDlgItem(hwnd,IDC_COMBOOP);
			int curIndex = ComboBox_GetCurSel(comboHwnd);
			int i3;
			switch(curIndex){
		    	case 0:
					{
                       i3 = i1 + i2;
					}
					break;
				case 1:
					{
					   i3 = i1 - i2;
					}		 
					break;
				case 2:
					{
						i3 = i1*i2;
					}
					break;
				case 3:{
					     i3 = i1/i2;
					   }
					break;
			}

		

			TCHAR str3[256];
			//wsprintf(str3,"%i",i3);
			//itoa  �����������ǽ���  
			itoa(i3,str3,10);
			SetDlgItemText(hwnd,IDC_EDIT3,str3);
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