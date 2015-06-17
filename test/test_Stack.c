#include "unity.h"
#include "Stack.h"
#include <malloc.h>
#include <stdio.h>

void setUp(void){}

void tearDown(void){}

/**
 *
 *     head------->NULL
 *                 
 *     tail------->NULL
 *                
 *
 */

void xtest_stackCreated_function_should_not_return_NULL_with_two_pointers_pointing_to_NULL(void)
{
	Stack *stack = malloc(sizeof(Stack));
  stack = stackCreate();
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL(NULL, stack -> head);
  TEST_ASSERT_EQUAL(NULL, stack -> tail);
}


/**
 *
 *     |-----------|
 *     |     1     |-------->NULL
 *     |-----------|
 *                
 *
 */

void xtest_stackElementCreated_function(void){
  StackElement *stackElement = malloc(sizeof(StackElement));
  stackElement = stackElementCreate(1);
  
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_EQUAL(NULL, stackElement -> next);
  TEST_ASSERT_EQUAL(1, stackElement -> data);
}

/**
 *
 *     head-------> |-----------|
 *                  |     1     |-------->NULL
 *     tail-------> |-----------|
 *                
 *
 */
void xtest_stackAdd_given_empty_stack_then_add_1_should_add_element_1_to_the_stack(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_EQUAL_PTR(stackElement, stack -> head);
  TEST_ASSERT_EQUAL_PTR(stackElement, stack -> tail);
  TEST_ASSERT_EQUAL(1, stack -> tail -> data);
  TEST_ASSERT_EQUAL(NULL, stack -> head -> next);
  TEST_ASSERT_EQUAL(NULL, stack -> tail -> next);
  TEST_ASSERT_EQUAL(1, stack -> length);
}

/**
 *
 *
 *     head-------> |-----------|         |-----------|
 *                  |     1     |-------> |     2     |------>NULL
 *                  |-----------|         |-----------|
 *                                             ^
 *                                             | 
 *     tail------------------------------------
 *   
 */

void xtest_stackAdd_given_empty_stack_then_add_1_and_2_should_add_elements_1_and_2_to_the_stack(void){
Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_EQUAL(1, stack -> head -> data);
  TEST_ASSERT_NOT_NULL(stack -> head -> next);
  TEST_ASSERT_EQUAL_PTR(stackElement, stack -> tail);
  TEST_ASSERT_EQUAL(2, stack -> tail -> data);
  TEST_ASSERT_EQUAL(2, stack -> length);
}

void xtest_stack_given_empty_stack_then_add_1_should_add_element_1_to_the_stack_and_remove_it_and_return_empty_stack(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  StackElement *removedElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  removedElement = stackRemove(stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL(NULL, stack -> head);
  TEST_ASSERT_EQUAL(NULL, stack -> tail);
  TEST_ASSERT_EQUAL(1, removedElement -> data);
  TEST_ASSERT_EQUAL(NULL, removedElement -> next);
  TEST_ASSERT_EQUAL(0, stack -> length);
  
  }
  
 void test_stack_add_1_and_2_to_the_stack_and_remove_first_element(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  StackElement *removedElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);

  // printf("stack -> head -> ->next-> value = %d\n", stack -> head -> next-> data);
  removedElement = stackRemove(stack);
  
  // printf("stack -> head -> value = %d\n", stack -> head -> data);

  
  TEST_ASSERT_EQUAL(2, stack -> head ->data);
  
  
  }