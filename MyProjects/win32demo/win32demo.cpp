// win32demo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    
	//MessageBox(NULL,TEXT("世界你好"),TEXT("问好"),MB_ICONHAND);
	//MessageBox(NULL,TEXT("世界你好"),TEXT("问好"),MB_ICONQUESTION);
	int ret =  MessageBox(NULL,TEXT("世界你好"),TEXT("问好"),MB_YESNO|MB_ICONQUESTION);
	if(IDYES == ret){
	   MessageBox(NULL,TEXT("你是超过"),TEXT("成人了"),MB_OK);
	}else{
		MessageBox(NULL,TEXT("你是没超过"),TEXT("成人了"),MB_OK);
	}
	return 0;
}



