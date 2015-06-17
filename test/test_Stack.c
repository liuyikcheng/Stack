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
 **/

void xtest_stackCreated_function_should_not_return_NULL_with_two_pointers_pointing_to_NULL(void)
{
	Stack *stack = malloc(sizeof(Stack));
  stack = stackCreate();
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL(NULL, stack -> head);
  TEST_ASSERT_EQUAL(NULL, stack -> tail);
  TEST_ASSERT_EQUAL(0, stack -> length);
}


/**
 *
 *     |-----------|
 *     |     1     |-------->NULL
 *     |-----------|
 *                
 *
 **/

void test_stackElementCreated_function(void){
  StackElement *stackElement = malloc(sizeof(StackElement));
  stackElement = stackElementCreate(1);
  
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_EQUAL(NULL, stackElement -> next);
  TEST_ASSERT_EQUAL(1, stackElement -> data);
}

/**
 *
 *        head------------>                           head-------> |-----------|
 *                                 ===========>                    |     1     |-------->NULL
 *        tail------------>                           tail-------> |-----------|
 *                
 *
 **/
void test_stackAdd_given_empty_stack_then_add_1_should_add_element_1_to_the_stack(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_NOT_NULL(stack -> head);
  TEST_ASSERT_NOT_NULL(stack -> tail);
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
 *                                                               
 *     head-------> |-----------|                               head-------> |-----------|         |-----------|
 *                  |     1     |-------->NULL    ========>                  |     2     |-------> |     1     |------>NULL
 *     tail-------> |-----------|                                            |-----------|         |-----------|                                                                            
 *                                                                                                      ^
 *                                                                                                      | 
 *                                                               tail-----------------------------------
 *   
 **/

void test_stackAdd_given_empty_stack_then_add_1_and_2_should_add_elements_1_and_2_to_the_stack(void){
Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_NOT_NULL(stack -> head);
  TEST_ASSERT_NOT_NULL(stack -> tail);
  TEST_ASSERT_EQUAL(2, stack -> head -> data);
  TEST_ASSERT_NOT_NULL(stack -> head -> next);
  TEST_ASSERT_EQUAL_PTR(stackElement, stack -> head);
  TEST_ASSERT_EQUAL(1, stack -> tail -> data);
  TEST_ASSERT_EQUAL(2, stack -> length);
}

/**
 *
 *
 *                                                               head--------->|-------|       |-------|       |-------|
 *       head-------> |-------|       |-------|                                |   3   |-----> |   2   |-----> |   1   |------>NULL
 *                    |   2   |-----> |   1   |------>NULL  ======>            |-------|       |-------|       |-------|
 *                    |-------|       |-------|                                                                     ^   
 *                                        ^                                                                         |
 *                                        |                                 tail------------------------------------
 *         tail---------------------------
 *   
 **/
void test_stackAdd_given_empty_stack_then_add_1_and_2_and_3_should_add_elements_1_and_2_and_3_to_the_stack(void){
Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(3);
  stackAdd(stack,stackElement);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_NOT_NULL(stack -> head);
  TEST_ASSERT_NOT_NULL(stack -> tail);
  TEST_ASSERT_EQUAL(3, stack -> head -> data);
  TEST_ASSERT_NOT_NULL(stack -> head -> next);
  TEST_ASSERT_EQUAL_PTR(stackElement, stack -> head);
  TEST_ASSERT_EQUAL(1, stack -> tail -> data);
  TEST_ASSERT_EQUAL(3, stack -> length);
}

/**
 *
 *
 *                                                               
 *     head-------> |-----------|                               head------->NULL 
 *                  |     1     |-------->NULL    ========>                  
 *     tail-------> |-----------|                               tail------->NULL                                                                                         
 *                                                                           
 *                                                                            
 *   
 **/
void test_stack_given_empty_stack_then_add_1_should_add_element_1_to_the_stack_and_remove_it_and_return_empty_stack(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  StackElement *removedElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  removedElement = stackRemove(stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_EQUAL(removedElement,stack -> head);
  TEST_ASSERT_EQUAL(NULL, stack -> head);
  TEST_ASSERT_EQUAL(NULL, stack -> tail);
  TEST_ASSERT_EQUAL(0, stack -> length);
  
  }
  
  
  
/**
 *
 *
 *                                                                        head---------> |-------|
 *       head-------> |-------|       |-------|                                          |   1   |------>NULL
 *                    |   2   |-----> |   1   |------>NULL  ======>                      |-------|
 *                    |-------|       |-------|                                               ^   
 *                                        ^                                                   |
 *                                        |                                 tail--------------
 *         tail---------------------------
 *   
 **/
 void test_stack_given_empty_stack_then_add_1_and_2_should_add_element_1_and_2_to_the_stack_and_remove_element_2(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  StackElement *removedElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);
  removedElement = stackRemove(stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_NOT_NULL(stack -> head);
  TEST_ASSERT_NOT_NULL(stack -> tail);
  TEST_ASSERT_EQUAL(1, stack -> head ->data);
  TEST_ASSERT_EQUAL(1, stack -> tail ->data);
  TEST_ASSERT_EQUAL(1, stack -> length);
  TEST_ASSERT_NOT_EQUAL(removedElement,stack -> head);
  }
  
  
  
  
/**
 *
 *
 *                                                                                       head---------> |-------|       |-------|
 *       head-------> |-------|      |-------|       |-------|                                          |   2   |-----> |   1   |------>NULL
 *                    |   3   |----> |   2   |-----> |   1   |------>NULL  ======>                      |-------|       |-------|
 *                    |-------|      |-------|       |-------|                                                             ^   
 *                                                      ^                                                                  |
 *                                                      |                                                tail--------------
 *         tail------------------------------------------
 *   
 **/
 void test_stack_given_empty_stack_then_add_1_and_2_and_3_should_add_element_1_and_2_and_3_to_the_stack_and_remove_element_3(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  StackElement *removedElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(3);
  stackAdd(stack,stackElement);
  removedElement = stackRemove(stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_NOT_NULL(stack -> head);
  TEST_ASSERT_NOT_NULL(stack -> tail);
  TEST_ASSERT_EQUAL(2, stack -> head ->data);
  TEST_ASSERT_EQUAL(1, stack -> tail ->data);
  TEST_ASSERT_EQUAL(2, stack -> length);
  TEST_ASSERT_NOT_EQUAL(removedElement,stack -> head);
  }
  
/**
 *
 *
 *                                                                                       head---------> |-------|
 *       head-------> |-------|      |-------|       |-------|                                          |   1   |------>NULL
 *                    |   3   |----> |   2   |-----> |   1   |------>NULL  ======>                      |-------|
 *                    |-------|      |-------|       |-------|                                               ^   
 *                                                      ^                                                   |
 *                                                      |                                 tail--------------
 *         tail------------------------------------------
 *   
 **/
 void test_stack_given_empty_stack_then_add_1_and_2_and_3_should_add_element_1_and_2_and_3_to_the_stack_and_remove_element_2_and_3(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  StackElement *removedElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(3);
  stackAdd(stack,stackElement);
  removedElement = stackRemove(stack);
  removedElement = stackRemove(stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NOT_NULL(stackElement);
  TEST_ASSERT_NOT_NULL(stack -> head);
  TEST_ASSERT_NOT_NULL(stack -> tail);
  TEST_ASSERT_EQUAL(1, stack -> head ->data);
  TEST_ASSERT_EQUAL(1, stack -> tail ->data);
  TEST_ASSERT_EQUAL(1, stack -> length);
  TEST_ASSERT_NOT_EQUAL(removedElement,stack -> head);
  }
  
  
  /**
 *
 *
 *                                                                                       head--------->NULL 
 *       head-------> |-------|      |-------|       |-------|                                          
 *                    |   3   |----> |   2   |-----> |   1   |------>NULL  ======>       tail--------->NULL
 *                    |-------|      |-------|       |-------|                                                
 *                                                      ^                                                   
 *                                                      |                                
 *         tail------------------------------------------
 *   
 **/
  
  void test_stack_given_empty_stack_then_add_1_and_2_and_3_should_add_element_1_and_2_and_3_to_the_stack_and_remove_all_element(void){
  Stack *stack = malloc(sizeof(Stack));
  StackElement *stackElement = malloc(sizeof(StackElement));
  StackElement *removedElement = malloc(sizeof(StackElement));
  
  stack = stackCreate();
  stackElement = stackElementCreate(1);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(2);
  stackAdd(stack,stackElement);
  stackElement = stackElementCreate(3);
  stackAdd(stack,stackElement);
  removedElement = stackRemove(stack);
  removedElement = stackRemove(stack);
  removedElement = stackRemove(stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL(NULL, stack -> head);
  TEST_ASSERT_EQUAL(NULL, stack -> tail);
  TEST_ASSERT_EQUAL(0, stack -> length);
  TEST_ASSERT_NOT_EQUAL(removedElement,stack -> head);
  }