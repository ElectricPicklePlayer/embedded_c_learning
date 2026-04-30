## Exercise 1: Hidden counter module

Create two files: counter.c and main.c. In counter.c, declare a static int count = 0 at file scope. Expose only void counter_increment(void) and int counter_get(void). In main.c, use only those two functions.

Try to access count directly from main.c — it must fail to compile
Add a static local variable inside counter_increment that tracks call count — show it persists across calls
In a comment: what is the difference between static at file scope vs inside a function?


**Embedded note:** static at file scope is how you hide peripheral state inside a HAL module. The outside world sees only your API, not the internal register state.
