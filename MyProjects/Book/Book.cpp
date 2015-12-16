// Book.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
//#include <mysql.h>

/*显示菜单*/
void showmenu()
{
	
    //system("cls");
    printf("\n\n\n\n\n");
    printf("\t╔═══════════════════════════╗\n");
    printf("\t║            Welcome To Lemon Books System             ║\n");
    printf("\t╠═══════════════════════════╣\n");
    printf("\t║\t 1 - 显示所有图书信息                           ║\n");
    printf("\t║\t 2 - 添加图书信息                               ║\n");
    printf("\t║\t 3 - 修改图书信息                               ║\n");
    printf("\t║\t 4 - 删除图书信息                               ║\n");
    printf("\t║\t 5 - 查询图书信息                               ║\n");
    printf("\t║\t 6 - 退出                                       ║\n");
    printf("\t╚═══════════════════════════╝\n");
    printf("\n              ENTER YOUR CHOICE(1-6):");
    
}

int main(int argc, char* argv[])
{

	//showmenu();   /*显示菜单*/ 
	//指针
	int i1 = 555;
	int i2 = 666;
	int *p = &i1;
	printf("%d,%d\n",&i1,&i2);
	p--;
	int i3 = *p;
	printf("%d\n",i3);
	p--;
    printf("%d\n",*p);
    p-=9999;
	printf("%d\n",*p);
	return 0;
}

