#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"
#define SUCCESS 0;
#define FAILS 1;
int GruwthCapacity(vector_d* vector,  double size);
struct vector_d
{
	void* start;
	size_t occupied;
	size_t capacity;	
	size_t element;/*elememt represent by size*/
};


int Shrink( vector_d* vector)
{
	void* new_start; 
	if(vector->capacity == 0)
	{	
		printf("Invalid free space\n");
		return FAILS;
	}
	if(!(new_start = realloc( vector->start, vector->occupied*vector->element )))
	{
		return FAILS;
	} 
	vector->start = new_start;
	vector->capacity = 0;
	return SUCCESS;
}


size_t GetCapacity(struct vector_d* vector)
{
	return vector->capacity;
}
size_t  GetOccupied(struct vector_d* vector )
{
	return vector->occupied;
}

int Destroyed( vector_d* vector)
{	
	if(vector -> start)
	{
		free(vector->start);
			vector->start = NULL;
		free(vector);
			vector = NULL;	
			return SUCCESS;
	}
	return  FAILS;
}

struct vector_d* Create(size_t size, size_t size_element)
{
	vector_d *vector;
	if( size_element == 0)
	{
	 printf("Illegal size element\n");	
	 return NULL;
	}
	if(!(vector = malloc(sizeof(vector_d))))
	{
		printf("ERROR\n");	
		return NULL;
	}	
	if(!(vector->start = malloc( size_element*size)))
	{
		free(vector);
		vector = NULL;
		printf("ERROR\n");	 
		return NULL;
	}
		
	vector->occupied = 0;
	vector->capacity = size;
	vector->element =  size_element;
	return vector;
}

int PushBack(vector_d* vector, void *value)
{	
	char *p_start = NULL;
	if( vector->capacity == 0 )
	{
		if(!GruwthCapacity(vector, (vector->capacity+vector->element)*1.5))
		{
			printf("Not Enough Space");
			return FAILS ;
		}
	}
	p_start = (char*)vector->start;
	p_start = (p_start + (vector->occupied*vector->element));
	memcpy(p_start , value ,vector->element);
	vector->capacity -= 1;
	vector->occupied += 1;
	return SUCCESS;	
}
void *PopBack(struct vector_d* vector)
{
	void *elem_pop;
	if(vector->occupied == 0)
	{
		return NULL;
	}
	elem_pop = Access(vector,vector->occupied-1 );
	if(elem_pop)
	{
		vector->occupied--;
		vector->capacity++;
	}
	return elem_pop;
	
}
void* Access(vector_d* vector, size_t index)
{
	char *elem_in_vector;
	void *p_index;
	if(vector->occupied-1 < index)
	{
		printf("Invalid index\n");
		return NULL;
	}
	elem_in_vector = 	(char*)vector->start + index*vector->element;
	p_index = calloc(vector->element, 1);
	if(!p_index)
	{
		return NULL;
	}	
	memcpy(p_index, elem_in_vector ,vector->element );
	return p_index;
}

int GruwthCapacity(vector_d* vector, double size)
{
	void *new_start;
	if((new_start = realloc(vector->start, size*vector->element)))
	{
		vector->start = new_start;
		vector->capacity =  size - vector -> occupied;
		return SUCCESS;
	}
		return FAILS;
}

int Reserve(vector_d* vector, size_t size)
{

	return GruwthCapacity(vector, size);
	/*void *new_start;
	
	if((new_start = realloc(vector->start, size*vector->element)))
	{
		vector->start = new_start;
		vector->capacity =  size - vector -> occupied;
		return SUCCESS;
	}
		return FAILS;*/
}
