#include <stdio.h>
#include "counter.h"

extern int count;

int main(void) {

  printf("%d\n",counter_get());
  counter_increment();
  
  printf("%d\n",counter_get());

  int *p; {
    int x = 42;
    p = &x;
  }

  printf("%d\n", *p);
  
  return 0;
}
