#include "Stack.h"
#include <stdio.h>
#include <malloc.h>


Stack *stackCreate(){
  Stack *stack = malloc(sizeof(Stack));
  stack -> head = NULL;
  stack -> tail = NULL;
  stack -> length = 0;
  return stack;
}

StackElement *stackElementCreate(int data){
  StackElement *stackElement = malloc(sizeof(StackElement));
  stackElement -> next = NULL;
  stackElement -> data = data;
  return stackElement;
}

void stackAdd(Stack *stack, StackElement *elem){
  StackElement *prevElement = malloc(sizeof(StackElement));
  prevElement = stack -> head;
  
  if(stack -> head == NULL || stack -> tail == NULL)
    stack -> head = stack -> tail = elem;
  else{
    stack -> head = elem;
    stack -> head ->next = prevElement;
  }
  
  stack -> length++;
}

StackElement *stackRemove(Stack *stack){
  StackElement *removedElement = malloc(sizeof(StackElement));
  removedElement = stack -> head ;
  
  if(stack -> head -> next == NULL){
    stack -> head = NULL;
    stack -> tail = NULL;
  }
  else{
    stack -> head = stack -> head -> next; 
  }
  
  free(removedElement);

  stack -> length--;
  return removedElement;
}