#include <stdio.h>


unsigned int reg = 0xDEADBEEF;

int main(void) {

  printf("%u\n",reg);

  printf("%#010x\n", reg);
  
  return 0;
}
