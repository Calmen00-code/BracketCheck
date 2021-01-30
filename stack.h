#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

LinkedList *createStack();
void push( LinkedList *, void * );
void *top( LinkedList * );
void *pop( LinkedList * );
void freeStack( LinkedList * );

#endif
