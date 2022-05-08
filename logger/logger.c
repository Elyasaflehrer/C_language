
#include "logger.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Cmp(char *operation, char *input );
int Cmp(char *operation, char *input );
void logger(char *name_file);
char* ChooseNameFile(char *name_file);
void GetInput(char *new_line);
int Operationes(int,int,char*,char*);
void MyRemove( char*);
int MyCount(char *);
void  MyExit();
int CreatFile(char *, char *,int read_to_head);

void appendToHead(char *file_name, char *new_line);


typedef struct{
	char *operate;
	int (*cmp)( char* , char*);
	int (*operation)(int,int,char*,char*);	
}FileManager;

typedef enum resu{
	Remove ,
	Count,
	Exit,
	EnterToHead
}result;


	
void StartLogger(char *name_file)
{		
		char new_line[100];
		int check_new_line = 0;
		int write_to_head = 1;
		int index = 0;
		int result = 5;
		FileManager logger_arr[4]= {{ "-remove\0",  &Cmp ,  &Operationes },
									{"-count\0",  &Cmp ,&Operationes },
									{"-exit\0",&Cmp ,&Operationes },
									{"b\0", &Cmp ,&Operationes }};

		/*passStruct(logger_arr);*/
		
		do{		
		write_to_head = 1;
		result = 5;
		GetInput(new_line);			
		for( index = 0; index < 4; index++)
		{
			if(logger_arr[index].cmp(logger_arr[index].operate , new_line))
			  result = index;
			if( result==3)
			{				
				write_to_head = 0;
			}
			
		}
		printf("result = %d\n",result);
					 	
	 	check_new_line = Operationes(result , write_to_head, name_file, new_line);	 

	 	/*printf("check_new_line:  %d\n",check_new_line);	
	 	printf("write_to_head:  %d\n",write_to_head);*/	
	 	}while(1);

		 	check_new_line = check_new_line ;	
	
}
/*void passStruct(struct FileManager arr[])
{
	printf(" passStruct %s",arr[0].operate);
}*/
void GetInput(char *new_line)
{	
	printf("please enter new line:\n-exit to exit, -remove to remove, -count to count the number of line, <: to enter in top of file\n");
     	fgets(new_line ,100, stdin);
     	new_line[strlen(new_line)-1] = '\0';
}
int Cmp(char *operation, char *input )
{
   unsigned int i ;
	unsigned int input_len = strlen(input);
	unsigned int operation_len = strlen(operation);
	if(input[0] == '<' &&  *operation == 'b')
		return 1;
	if(input[0] != '-' || input_len  != operation_len)
		return 0;
	for(i =1; i < operation_len; i++)
	{
		if(operation[i] !=input[i])
		return 0;
	}
	return 1;

}
int Operationes(int option,int read_to_head, char *file_name, char *new_line)
{

	enum resu result_enum = option;
	int result = 0 ;
	switch (result_enum)
	{
		case Remove:
			 MyRemove(file_name);			 		
			 exit(0);
		break;
		case Count:
			result = MyCount(file_name);
		break;

		case Exit:
			MyExit();
		break;
	
		case EnterToHead:
			result = CreatFile(file_name,new_line, read_to_head);
		break;
		default:
			result = CreatFile(file_name,new_line, read_to_head);
			break;	
	}
	return result;	
}

void MyRemove( char *file_name)
{	
	
	if(remove(file_name) == 0)
		printf("Delete successfully\n");
	else		
		printf("Unable to delete the file\n");	

}
int MyCount( char *file_name)
{
	FILE *fp;
	int count = 0;
	char c ;
	
	fp = fopen(file_name,"r");
	if(fp==NULL)
	{
		printf("Could not open the file %s\n",file_name);
		return count;
	}
	for(c=getc(fp); c!=EOF; c=getc(fp))
	{
		if(c =='\n')
		count++;
	}
	fclose(fp);
	printf("the number of line in file is %d\n",count);
	return count;
}
void MyExit()
{
	printf("exit()\n");
	exit(0);

}
int CreatFile(char *file_name, char *new_line,int read_to_head)
{		

	FILE *fp;
	printf("========CreatFile() %d\n",read_to_head);
	
	if( read_to_head == 1 )
	{
	printf(",read_to_head %d\n",read_to_head);
		fp = fopen(file_name,"a");
		fprintf(fp,"\n%s",new_line);	
		fclose(fp);
  	}
	if(read_to_head == 0)
	{		
		appendToHead(file_name, new_line);
	}
	
	
	return 0;	
}
void appendToHead(char *file_name, char *new_line)
{	

	FILE *target;
	FILE *fp;
	char c;
	char *keep_txt ="keep.txt";
	target = fopen(keep_txt, "w");
	if(!target)
		perror("fopen");	
	fp = fopen(file_name,"r+");
				printf("========read_to_head %d\n",5);
				printf("========new_line %s\n",new_line);
				fprintf(target,"%s\n",new_line);	
	if(fp==NULL)
	{	
		fclose(target);
		rename("keep_txt",file_name);
		return;
	}
				
	while(1)
	{
		c = fgetc(fp);
		if(c == EOF)
			break;
		else
		fputc(c,target);		
	}	
	fclose(fp);
	fclose(target);
	rename(keep_txt,file_name);
	
}
/*int DeletePrimerCha(int *s)
{
	char curr = *s;
	char prev ;
	while(*s)
	{
		
	}
	
}*/
