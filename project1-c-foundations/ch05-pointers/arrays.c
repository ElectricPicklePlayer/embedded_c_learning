#include <stdio.h>

/*
Write reverse(int *arr, int len) that reverses an integer array in-place. You must use pointer arithmetic — no bracket indexing inside the function.
Before reversing, print the address of every element to prove contiguity
Call the function, then print the array from main using brackets
In a comment: what does "arrays decay to pointers" mean? What is lost when they decay?
Key question to answer: if you pass an array to a function, what does sizeof(arr) return inside that function? Why?
*/

int * reverse(int *arr, int len);

int main(void){

  int lijst[] = {1,2,3,4,5};
  int len = sizeof(lijst) / sizeof(int);

  printf("de grootte van de lijst: %d\n\n", len);
  
  for(int i = 0; i <5; i++) {
    int *p = &lijst[i];
    printf("%p %d\n", (void *)p, *p);
  }

  printf("\n");
  
  int * result = reverse(lijst, len);

  for(int i = 0; i <5; i++) {
    int *p = &result[i];
    printf("%p %d\n", (void *)p, *p);
  }
  
  return 0;
}

int * reverse(int *arr, int len) {
    
  for (int i=0; i<len/2; i++) {

    int t = *(arr + i);
    *(arr + i) = *(arr + len - 1 - i);
    *(arr + len - 1 - i) = t; 
  }
  
  return arr;
}
