// firstcgi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include  <stdlib.h>

int main(int argc, char* argv[])
{
    printf("Content-Type: text/html\n\n");
	printf("<html>");
	printf("<body>");
	printf("hello <a href='http://www.jd.com'> JD </a><br>\n");

    printf("Hello World!\n");
	int i = 220;
	int j = 20;
	printf("%i + %i = %i\n<br>",i,j,i+j);
    printf("ServerSoftWare:%s\n<br>",getenv("SERVER_SOFTWARE"));
    printf("http_user_agent:%s\n<br>",getenv("HTTP_USER_AGENT"));
	printf("参数:%s<br>",getenv("QUERY_STRING"));
	char name[256];
	int age;
	char* query = getenv("QUERY_STRING");
    
	int i1,i2;
	sscanf(query,"i1=%i&i2=%i",&i1,&i2);
	printf(" %i + %i = %i<br/>",i1,i2,i1+i2);
    printf("i1:%s ---- i2:%s",&i1,&i2);

   // sscanf(query,"name=%s&age=%s",name,&age);
	//printf("name 等于:%s<br>",name);
	//printf("age = %i",age);
	//printf("name 指针 等于:%s<br>",&name);
    //printf("query : %s<br>",query);
    
   // printf("query 指针 : %s<br>",&query);
	printf("</body>");
	printf("</html>");

	


	return 0;
}

