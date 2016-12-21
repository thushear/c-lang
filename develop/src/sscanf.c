/*
 * sscanf.c
 *
 *  Created on: 2015Äê11ÔÂ26ÈÕ
 *      Author: kongming
 */

#include <stdio.h>
#include <stdlib.h>
#define  BUFFER_SIZE  1024  // buffer size
int main(void) {

	unsigned int a , b ,sum;
	char buffer[BUFFER_SIZE] ;

	printf("************welcome************\n");
	printf("*****enter a and b and get sum\n");
	printf("*******quit please input #******\n");
	printf("***************************\n");

	while(fgets(buffer,BUFFER_SIZE,stdin)!=NULL && buffer[0]!='#'){

		if(sscanf(buffer,"%d %d",&a,&b)!=2){
			printf("skip");
			continue;
		}

		sum = a + b;
		printf("%d and %d sum is %d ",a,b,sum);
	}




	return EXIT_SUCCESS;
}



