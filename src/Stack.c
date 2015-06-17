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
  if(stack -> head == NULL || stack -> tail == NULL)
    stack -> head = stack -> tail = elem;
  
  else{
    stack -> tail -> next = elem;
    stack -> tail = elem;
  }
  stack -> length++;
  printf("ad Stack length = %d\n", stack -> length);
}

StackElement *stackRemove(Stack *stack){
  StackElement *removedElement = malloc(sizeof(StackElement));
  StackElement *stackElement = malloc(sizeof(StackElement));
  
  removedElement = stack -> head ;
  removedElement -> next = NULL;
  
  // stackElement = stack -> head;
  // stack -> head =  stack -> head -> next;
  // printf("removedElement -> value = %d\n", removedElement -> data);
  if(stack -> head -> next == NULL){
    stack -> head = NULL;
    stack -> tail = NULL;
  }
  else{
    stack -> head = stack -> head -> next; 
  }
  
  free(removedElement);
  // printf("stack -> head -> value = %d", stack -> head -> next-> data);
  
  // free(stackElement);
  // printf("stack -> head -> value = %d\n", stack -> head -> data);
  // printf("stack -> head -> value = %d\n", stack -> head -> data);
  stack -> length--;
  return removedElement;
}