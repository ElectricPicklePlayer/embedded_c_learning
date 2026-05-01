#include <stdio.h>


unsigned int reg = 0xDEADBEEF;

void print_binary(unsigned int);

int main(void) {

  printf("%u\n",reg);

  printf("%#010x\n", reg);

  print_binary(reg);
    
  return 0;
}

void print_binary(unsigned int n) {

  for(int i=31; i >=0; i--) {
    printf("%d", (n >> i) & 1);

    if (i % 8 == 0 && i != 0) {
      printf(" ");
    }
  }

  printf("\n");
  return;
}
