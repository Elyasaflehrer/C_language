#ifndef STACK_H
#define STACK_H
#include <stddef.h>
typedef struct stack stack_d;


/*Creat new stack*/
stack_d* Create(size_t size, size_t elementsize);/*V*/

/*Delete stack*/
int Destroy(stack_d* ptr);/*V*/

/*Get Last value and remove */
void* Pop(stack_d* ptr);/*V*/

/*Set new value on top*/ 
int Push(stack_d* ptr, const void* value);/*V*/

/*Get last value */
void* Peek(const stack_d* ptr);

/*Get size of stack*/
size_t Size(const stack_d* ptr);/*V*/

/*Check if stack empty*/
int IsEmpty(const stack_d* ptr);/*V*/

/*Get used cells stack*/
size_t Capacity(const stack_d* ptr);/*V*/



#endif
