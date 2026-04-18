#include <stdio.h>
#include <string.h>

int main(void){
  char name[20];
  int n = 20;
  
  printf("Hi, what is your name?\n");
  fgets(name, n, stdin);

  name[strcspn(name, "\n")] = '\0';
  printf("Hello %s!\n", name);
  return 0;
}
