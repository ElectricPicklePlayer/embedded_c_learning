#include <stdio.h>

void swap(int *a, int *b);

int main(void) {

  int a = 2;
  int b = 4;
  
  swap(&a,&b);
  
  printf("SWAP! a is nu %d en b is nu %d\n", a, b);
  
  return 0;
}

void swap(int *a, int *b) {

  int temp = *a;
  *a = *b;
  *b = temp;
}
