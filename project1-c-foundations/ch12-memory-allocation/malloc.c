#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  // Allocate space for 10 ints.

  int *array_ints = malloc(sizeof(int) * 10);

  if (array_ints == NULL) {
    fprintf(stderr, "tering malloc NULL\n");
    return 1;
  }
  
  // Assign them values 0-45.
  
  for(int i = 0; i < 10; i++) {
    *(array_ints + i) = i * 5; 
  }
  
  // Print those values.

  for(int i = 0; i < 10; i++) {
    printf("%d\n", *(array_ints + i));
  } 

  // free the allocated memory.

  free(array_ints);

  return 0;
} 
