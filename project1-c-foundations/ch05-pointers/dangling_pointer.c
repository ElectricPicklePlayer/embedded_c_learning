#include <stdio.h>

// Dangling pointer trap
// Write a function that returns a pointer to a local int variable. Store the returned pointer in main and dereference it.
// Compile and run it — record what you see (garbage, crash, or "works")
// In a comment, explain why this is undefined behaviour even if it appears to work
// Draw a small ASCII diagram of the stack at the moment of dereference

int * dangle(void);

int main(void) {
  int *d = dangle();

  printf("%p\n", d);

  printf("%d\n", *d);

  return 0;
}

int * dangle(void) {
  int i = 10;
  int *p = &i;

  printf("%d\n", *p);
  return p;
}
