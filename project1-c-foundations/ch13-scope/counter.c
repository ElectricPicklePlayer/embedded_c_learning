#include <stdio.h>
#include "counter.h"

int count = 0;

void counter_increment(void) {
  count++;
}

int counter_get(void){

  return count;
}
