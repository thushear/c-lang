#ifndef _LOGIN_H
#define _LOGIN_H

#include <windows.h>

struct LoginData
{
  TCHAR* username;
  TCHAR* password;
};


BOOL WINAPI Login_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL Login_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void Login_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void Login_OnClose(HWND hwnd);

#endif