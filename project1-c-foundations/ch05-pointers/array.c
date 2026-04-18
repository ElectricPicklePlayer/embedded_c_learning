#include <stdio.h>

int main(void) {

  int i;

  float array[4];

  array[0] = 1.2;
  array[1] = 1.3;
  array[2] = 1.4;
  array[3] = 1.5;

  for (i = 0; i < 4; i++) {
    printf("%f\n", array[i]);
  }

  return 0;
}
