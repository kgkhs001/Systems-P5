/** short program to demonstrate use of stack
 *
 * @author Blake Nelson
 * @editor Krishna Garg
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define MAX_CHARS 1000
//#define DEBUG_TEST
/** main function to demonstrate use of stack
 *
 */
 
int main (int argc, char *argv[]) {
  //make sure that a number is inputted
  if(argc < 2){
  	printf("You must input an integer value indicating the size of the stack. Exiting...\n");
  	return 1;
  }
  
 
  char *buffer[MAX_CHARS];
  size_t buffer_size = MAX_CHARS;
  size_t characters;
  
  Stack *the_stack;
  int elements = atoi(argv[1]);
  char *test_data[elements];
  
  // Create a stack to hold our test data
  the_stack = create(elements);
  
  
    
  // Push some test data onto the stack
  for(int j = 0; j < elements; j++){
  	characters = getline(buffer, &buffer_size, stdin);
  	if(characters == -1){	//shows that the input was the EOF
  		break;		//breaks the loop then
  	}
  	char * copy = malloc(characters * sizeof(char * ));
  	test_data[j] = *buffer;
  	strncpy(copy, test_data[j], characters - 1);
  	copy[characters] = '\0';
  	push(the_stack, copy);
  }
  
  
  // Now pop the elements off the stack   
  while (!isempty(the_stack)) {
    char *element = (char *) pop(the_stack);
    printf("%s\n", element);
  }
  
  
  destroy(the_stack);
  return 0;
}
  
