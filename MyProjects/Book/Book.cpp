// Book.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
//#include <mysql.h>

/*��ʾ�˵�*/
void showmenu()
{
	
    //system("cls");
    printf("\n\n\n\n\n");
    printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("\t�U            Welcome To Lemon Books System             �U\n");
    printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
    printf("\t�U\t 1 - ��ʾ����ͼ����Ϣ                           �U\n");
    printf("\t�U\t 2 - ���ͼ����Ϣ                               �U\n");
    printf("\t�U\t 3 - �޸�ͼ����Ϣ                               �U\n");
    printf("\t�U\t 4 - ɾ��ͼ����Ϣ                               �U\n");
    printf("\t�U\t 5 - ��ѯͼ����Ϣ                               �U\n");
    printf("\t�U\t 6 - �˳�                                       �U\n");
    printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
    printf("\n              ENTER YOUR CHOICE(1-6):");
    
}

int main(int argc, char* argv[])
{

	//showmenu();   /*��ʾ�˵�*/ 
	//ָ��
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

