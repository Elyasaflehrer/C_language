#include "stack.h"
#include <stdio.h>
#undef NDEBUG
#include <assert.h>


int main()
{

	
	stack_d *stack2;
	/*stack_d *stack1;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	size_t capacity;*/
	int x = 1;
	int y = 2;
	int z = 3;
	stack2 = Create(2,5);
	Push(stack2,&x);
	Push(stack2,&y);
	Push(stack2,&z);
	printf("Pop() y %d\n" , *(int*)Pop(stack2));
	printf("Pop() x %d\n" , *(int*)Pop(stack2));
	Destroy(stack2);
	/*
	printf("======test null stack=====\n");
	printf("\n=============test stack define===========\n");
	stack1 = Create(2,5);
	printf("Capacity %lu\n" , Capacity(stack1));
	printf("\n====test Push====\n");
	printf("Size %lu\n" , Size(stack1));
	Push(stack1,&a);
	Push(stack1,&b);
	Push(stack1,&c);
	Push(stack1,&d);
	capacity= Capacity(stack1);
	printf("Capacity  %lu\n" , capacity);
	printf("\n=test stack full=\n");	
	printf("\n====test Peek====\n");	
	printf("Peek() %c\n" , *((char*)Peek(stack1)));
	printf("\n====test Pop====\n");	
	printf("Capacity  %lu\n" , Capacity(stack1));
	printf("Pop() d %c\n" , *(char*)Pop(stack1));
	printf("Pop() c %c\n" , *(char*)Pop(stack1));
	printf("Capacity  %lu\n" , Capacity(stack1));
	Push(stack1,&c);
	Push(stack1,&d);
	printf("Capacity  %lu\n" , Capacity(stack1));
	printf("Pop() b %c\n" , *(char*)Pop(stack1));
	printf("Pop() b %c\n" , *(char*)Pop(stack1));
	Destroy(stack1);*/
	
	return 0;
}

