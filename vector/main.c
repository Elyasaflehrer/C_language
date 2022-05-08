#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "vector.h"

int main()
{	
	
	vector_d *vector1 = Create(20,4); 
	size_t capacity = GetCapacity(vector1);
	size_t occupied = GetOccupied(vector1 );
	int *access;
	int *pop_back;
	int a = 1 ;
	int b = 2 ;
	int c = 3 ;
	int d = 4 ;
	int e = 5 ;
	
	
	printf("====== test Capacity ========\n");
	printf("Capacity %lu\n",capacity);
	
	
	printf("\n====== test Occupied ========\n");
	printf("occupied %lu\n",occupied);
	
	
		
		printf("\n====== test Push ========\n");
		PushBack(vector1 , &a);
		PushBack(vector1 , &b);
		PushBack(vector1 , &c);
		PushBack(vector1 , &d);
		PushBack(vector1 , &e);
		printf("occupied  after push %lu\n",GetOccupied(vector1));
		printf("capacity  after push %lu\n",GetCapacity(vector1));
		
		printf("\n====== test Reserv ========\n");
		Reserve(vector1, 40);
		printf("capacity after reserv %lu\n",GetCapacity(vector1));
		printf("occupied after reserv %lu\n",GetOccupied(vector1));
		
		
		printf("\n====== test Shrink ========\n");
		Shrink( vector1);
		printf("capacity after Shrink %lu\n",GetCapacity(vector1));
		printf("occupied after Shrink %lu\n",GetOccupied(vector1));
		
		printf("\n====== test Access ========\n");
		
		 access = (int*)Access(vector1, 6);
		 if(access!=NULL)
		printf("Access %d\n", *access);
		else
			printf("access = NULL\n");		
		free(access);
		
		printf("\n====== test PopBack ========\n");
		Shrink( vector1);
		
		pop_back = (int*)PopBack(vector1);
		printf("PopBack %d\n", *pop_back);
		printf("try to get last index after pop \n");
		free(pop_back);
		 access = (int*)Access(vector1, 6);
		if(access!=NULL)
		printf("Access %d\n", *access);
		else
			printf("access = NULL\n");
			free(access);
		pop_back = (int*)PopBack(vector1);
		printf("PopBack %d\n", *pop_back);
		free(pop_back);
		printf("====== test Destroyed ========\n");
		Destroyed(vector1);
	
		
	return 0;
}


/*typedef enum type
{

	CHAR = 1,
	INT = 4,
	DOUBLE = 8
	CHAR,
	SHORT_INT,
	INT,
	LONG_INT,
	LONG_LONG_INT,
	FLOAT,
	LONG_DOUBLE,
	UNSIGNED_CHAR,
	SIGNED_CHAR,
	UNSIGNED_SHORT_INT,
	UNSIGNED_INT,
	UNSIGNED_LONG_INT,
	UNSIGNED_LONG_LONG_INT,
	DOUBLE
};*/
