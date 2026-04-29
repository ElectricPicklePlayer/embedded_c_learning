#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*
malloc one large block (1024 bytes) upfront. Write arena_alloc(size_t n) that hands out chunks by bumping an internal pointer. Write arena_reset() that resets the bump pointer. free the whole block once at the end.
Track remaining bytes — return NULL if out of space
In a comment: why do embedded systems prefer arena/pool allocators over malloc?
Embedded note: many MCU environments ban dynamic allocation entirely. Arena allocators are a common alternative used in production firmware.
*/
#define LARGE 1024

char *arena;
char *bump_pointer;
size_t remaining_space = LARGE;

void *arena_alloc(size_t n);
void arena_reset(void);

int main(void) {
  arena = malloc(LARGE);
  bump_pointer = arena;

  printf("arena pointer: %p\n bump pointer is %p\n", (void *)arena, (void *)bump_pointer);
  printf("oglum bak git %zu\n", remaining_space);
  arena_alloc(8);

  printf("arena pointer: %p\n bump pointer is %p\n", (void *)arena, (void *)bump_pointer);
  printf("oglum bak git %zu\n", remaining_space);

  free(arena);
  return 0;
}

void *arena_alloc(size_t n) {
  if (n <= remaining_space) {
    char *pointer = bump_pointer;
    bump_pointer += (int)n;
    remaining_space -= n;
    return pointer;
  }
  else {
    fprintf(stderr, "Error: not enough remaining space \n");
    return NULL;
  }
}

void arena_reset(void) {
  bump_pointer = arena;
  remaining_space = LARGE;
}
