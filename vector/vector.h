#ifndef _VECTOR_H
#define _VECTOR_H
#include <stddef.h>
#include <stdlib.h>



typedef struct vector_d vector_d;
size_t print(struct vector_d *);

/* create new vector  */
vector_d *Create(size_t size , size_t  size_element);/* V CreateVector(size_t size , size_t type) */
/* Add item to end  */
int PushBack(struct vector_d*, void* value);/* V  */
/* Pop last item from end  end remove it*/
void *PopBack(struct vector_d*);/*end remove it */
/*Alocated memory  */
int Reserve(struct vector_d*, size_t size);/* V */
/*Free empty cells */
int Shrink(struct vector_d*);/* not finish */
/*Kill vector */
int Destroyed(struct vector_d*);/* V  */
/*Get value of specific index */
void* Access(struct vector_d*, size_t index);/*AccessElement read only */
/* Get size of use cells*/
size_t  GetOccupied(struct vector_d*);/* V */
/* Get size of vector*/
size_t GetCapacity(struct vector_d*);/* V how many space free,  capacity+occupied = total*/

#endif

