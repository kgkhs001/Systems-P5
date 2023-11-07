/** Functions to support Stack implementation. Each stack element is a 
 * pointer to void. This allows any type of object to be stored on the stack
 *
 * @author Blake Nelson
 * @editor Krishna Garg
 */
#include<stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/** Function to create a stack with defined size. The returned Stack structure
 * must be passed to each stack operation to identify the stack and its
 * state.
 *
 * @return pointer to Stack structure or NULL on error
 */
Stack * create ( int size_of_stack ) {
  Stack * stack = NULL;
  // Allocate memory for the structure identifying stack and its state
  // Check for failed allocation and return NULL if failure
  stack = (Stack *) calloc (1, sizeof(Stack));

  // Valid stack was allocated, initialize attributes
  // Note: because we called calloc, fields initialized to 0
  
  //allocate memory to the elements field of the stack
  stack->elements = (void *) calloc (size_of_stack, sizeof(void *));
  if (stack->elements == NULL) {
    fprintf (stderr, "create: failed to allocate elements array memory\n");
    free (stack);
    return NULL;
  }
  
  //set all the elements to null to start
  // first set the pString array to NULL pointers using pointers
  stack->ptr = stack->elements;
  for (int index = 0; index < size_of_stack; index++, stack->ptr++) {
    *stack->ptr = (char *) NULL;
  }
  
  //initialize the base and top to the same and beginnning of the place in memory
  stack->base = &stack->elements[0];
  stack->top = &stack->elements[0];
  stack->ptr = (void **) NULL;

  // No elements stored in the array yet
  stack->num_elements = 0;
  stack->max_elements = size_of_stack; //initialize the max number of elements to the number that was passed in
  return stack;
}

/** Function to destroy a stack and return memory resources to heap. Note: the
 * memory for the stack struct used to track configuration of the stack is
 * returned to heap, the memory (void pointer to) elements which might currently
 * exist in the stack are not released back to the stack. 
 *
 * Note:  It is the responsibility of the user of the stack to manage elements.
 * Note2: It is the responsibility of the user of the stack to manage the 
 *        pointer to the stack struct. (The stack struct is returned to the 
 *        memory heap, but the calling code still has a pointer to the, now 
 *        freed, stack struct. That pointer should be set to NULL upon return
 *        from this function.)
 *
 * @param stack is a pointer to the stack struct. Invalid upon function return.
 * @return none.
 */
void destroy (Stack *stack) {
  free (stack->elements);
  free (stack);
  
  return;
}

/** Function to return whether the stack is empty. If empty returns non-zero.
 *
 * @param stack is a pointet to the stack
 * @return non-zero (true) if empty or zero (false) if not empty
 */
int isempty(Stack *stack) {
  // If there are elements in the stack it can't be empty
  return(numelements(stack) == 0);
}

/** Function to return the number of elements currently in the stack
 *
 * @param stack is a pointer to the stack
 * @return the number of elements currently in the stack
 */
int numelements(Stack *stack) {
  return stack->num_elements;
}

/** Function to return the max number of elements the stack can hold
 *
 * @param stack is a pointer to the stack
 * @return the maximum number of elements the stack can hold
 */
int maxelements (Stack *stack) {
  // Note: we assume stack is not larger than we  can represent by signed int
  return (int) (sizeof(stack->elements));
}

/** Function to support peeking at the current top of stack. This function
 * will return the top element of the stack without removing it from the stack.
 * the state of the stack will not be changed by this function.
 *
 * @param stack is a pointer to the stack
 * @return the element on top of stack or null if the stack is empty
 */
void * peek (Stack *stack) {
  // If stack is empty, there's nothing to return
  if (stack->num_elements == 0) {
    return (void *) NULL;
  }

  // Stack is not empty. the top pointer pointers to next empty slot, so
  // top element is at preceding address
  void **top_element;
  top_element = stack->top;
  top_element--;
  return (*top_element);
}

/** Function to pop the top stack element and return to caller. This will
 * remove the top element and modify the state of the stack.
 *
 * top of stack pointer is modified (moved)
 * top element of stack is removed from the stack
 * top slot (where the element was) is set to NULL for ease of debugging
 * number of elements in stack is decremented by one
 *
 * @param stack is a pointer to the stack
 * @return the top element from the stack or null if the stack is empty
 */
void * pop (Stack *stack) {
  // If stack is empty, there's nothing to return
  if (stack->num_elements == 0) {
    return (void *) NULL;
  }

  // Stack is not empty. the top pointer pointers to next empty slot, so
  // top element is at preceding address
  void *top_element;
  stack->top--;
  top_element = *(stack->top);
  *(stack->top) = (void *) NULL;
  stack->num_elements--;
  //printf("element popped successfully\n");
  return (top_element);
}

/** Function to push element onto stack. A pointer to the top element of the
 * stack is returned upon success. If the stack is full, the element will not be
 * pushed onto the stack and NULL will be returned.
 *
 * new element is inserted into stack at current top (pointer to by top)
 * top of stack pointer is modified (moved to next position)
 * number of elements in stack is incremented by one
 *
 * @param stack is a pointer to the stack
 * @param element is a pointer to the element to pus onto stack (which is itself
 *        a pointer to void)
 * @return a pointer to the element pushed onto the stack or NULL on failure
 */
 void * push (Stack *stack, void *element) {
  // If stack is full, we can't push another element
  size_t maxelements = stack->max_elements;
 
  if (maxelements == (stack->top - stack->base)) {
    return (void *) NULL;
  }

  // There is room on the stack
  // Push element and adjust top pointer & number of elements
  *(stack->top) = element;
  stack->top++;
  stack->num_elements++;
  return element;
}





/** Function to pop the top stack element and return to caller. This will
 * remove the bottom element and modify the state of the stack.
 *
 * bottom of stack pointer is modified (moved)
 * bottom element of stack is removed from the stack
 * bottom slot (where the element was) is set to NULL for ease of debugging
 * number of elements in stack is decremented by one
 *
 * @param stack is a pointer to the stack
 * @return the top element from the stack or null if the stack is empty
 */
void * pop_ord (Stack *stack, int size) {
  // Stack is not empty. the top pointer pointers to next empty slot, so
  // top element is at preceding address
  void *base_element;
  base_element = *(stack->base);
  *(stack->base) = (void *) NULL;
  stack->base++;
  stack->num_elements--;
  return (base_element);
}

/**Function to reverse a string
* Takes in a string and pops all the characters to a stack. 
* prints the top of the stack to stdout
* pops the top of the stack
* @param string is a string that is inputted
* @return
**/

void reverse(char * string){
	int len = strlen(string);
	Stack *chars;
	chars = create(len);
	for(int i = 0; i < len; i++){
		char *element;
		element = string[i];
		push(chars, element);
	}
	while(len !=0){
	  printf("%c", (char) peek(chars));
	  pop(chars);
	  len--;
	}
}










