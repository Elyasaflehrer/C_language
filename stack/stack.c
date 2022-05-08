#include <string.h>
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define FAEIL 0;
#define SUCCESS 1;
static int IlligalStack(const stack_d* stack);
static size_t GetElementSize(const stack_d*);
struct stack{
		char* data;
		size_t capacity;
		size_t size;
		size_t element_size;	
};
static size_t GetElementSize(const stack_d* stack)
{
	return stack->element_size;
}

static int IlligalStack(const stack_d* stack)
{
	assert(stack != NULL && "stack  NULL ");
		return  SUCCESS;	
}

void* Pop( stack_d* stack)
{
	void *p_data;
	p_data = Peek(stack);
	if(p_data != NULL)
		stack->capacity = stack->capacity + 1 ;
  	return p_data;
}


void* Peek(const stack_d* stack)
{
	char *p_data;
	IlligalStack(stack);
	
	assert(!IsEmpty(stack) && "in function Peek, Empty stack");
	
	return  (stack->data + ((stack->size - stack-> capacity)-1)*GetElementSize(stack));
}

int Push(stack_d* stack, const void* value)
{
	char *p_data = NULL;
	size_t index_to_push = 0;
	size_t keep_capacity = stack->capacity;
	size_t keep_size = stack->size;
	size_t keep_element_size = stack->element_size;
	IlligalStack(stack);
		
	if(stack->capacity == 0)
	{
		printf("Stack is full\n	");
		return FAEIL;
	}	
	p_data = stack->data;
	index_to_push = (stack->size - stack->capacity)* stack->element_size;
	p_data = p_data + index_to_push;
	memcpy(p_data, value, stack->element_size );
	stack->capacity = keep_capacity -1;
	stack->size = keep_size;
	stack->element_size = keep_element_size;
	return SUCCESS;	
}

int Destroy(stack_d* stack)
{
	IlligalStack(stack);
	
	free(stack);
	stack = NULL;
	return SUCCESS;
}

size_t Size(const stack_d* stack)
{
	
	IlligalStack(stack);
	return (stack -> size);
	
}

int IsEmpty(const stack_d* stack)
{
	IlligalStack(stack);
		return FAEIL;	
		
	return (stack -> capacity == stack -> size)?1:0;	
}

size_t Capacity(const stack_d* stack)
{
		IlligalStack(stack);		
		return stack -> capacity;
}

stack_d* Create(size_t size, size_t elem_size)
{
	stack_d *stack;
	if(elem_size == 0)
	{
		printf("Illigal element = 0");
		return NULL;
	}
	if(!(stack = malloc(sizeof(stack_d) + elem_size*size )))
	{
		return NULL;
	}
	stack->data = (char*)stack + sizeof(stack_d);
	stack->size = size;
	stack->capacity = size;
	stack->element_size = elem_size;
	
	return stack;
}
