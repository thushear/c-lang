// win32demo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    
	//MessageBox(NULL,TEXT("�������"),TEXT("�ʺ�"),MB_ICONHAND);
	//MessageBox(NULL,TEXT("�������"),TEXT("�ʺ�"),MB_ICONQUESTION);
	int ret =  MessageBox(NULL,TEXT("�������"),TEXT("�ʺ�"),MB_YESNO|MB_ICONQUESTION);
	if(IDYES == ret){
	   MessageBox(NULL,TEXT("���ǳ���"),TEXT("������"),MB_OK);
	}else{
		MessageBox(NULL,TEXT("����û����"),TEXT("������"),MB_OK);
	}
	return 0;
}



