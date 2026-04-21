#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/*
  Generic array accessor
Write void* at(void *buf, size_t elem_size, size_t idx) that returns a pointer to element idx in an untyped buffer — like a hand-rolled generic array. Internally cast to uint8_t* and use arithmetic.
Test it with an int array and a double array — same function, different elem_size
Print the raw address returned and verify it matches &arr[idx]
In a comment: why is uint8_t* the right type for byte-level pointer arithmetic?
Embedded note: DMA controllers and memory-mapped peripherals are accessed exactly this way — raw addresses, byte offsets, no types.
*/

void *at(void *buf, size_t  elem_size, size_t idx);

int main(void) {

  int idx = 1;

  int array_of_int[5] = {1 ,3, 57, 6, 333};
  double array_of_double[5] = {1.2, 3.4, 5.6, 7.8, 9.9};

  printf("the first adress of the array: %p\n",(void *) &array_of_int[0]);

  void *arit_pointer = at(array_of_int, sizeof(int), idx);

  printf("adress at idx: %p\n", arit_pointer);
  printf("controle: %p\n", (void *)&array_of_int[1]);

  printf("the first adress of the array: %p\n",(void *) &array_of_double[0]);

  arit_pointer = at(array_of_double, sizeof(double), idx);

  printf("adress at idx: %p\n", arit_pointer);
  printf("controle: %p\n", (void *)&array_of_double[1]);
  return 0;
}

void * at(void *buf, size_t elem_size, size_t idx) {

  uint8_t *at_pointer = (uint8_t *)buf + idx * elem_size;
  
  return at_pointer;
}
