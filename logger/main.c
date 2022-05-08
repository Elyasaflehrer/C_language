#include "logger.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{

	char name_file[30];
	
	if(argc==1)
	{
		printf("please enter the name of file\n");
		exit(0);
	}
	
	strcpy(name_file,argv[1]);
	StartLogger(argv[1]);

	return 0;
}
