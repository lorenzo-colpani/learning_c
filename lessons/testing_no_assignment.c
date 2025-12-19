#include <stdio.h>

void function_one() {
  int secret_value;
  printf("Function 1: Local variable address: %p, value: %d\n",
         (void *)&secret_value, secret_value);
}

void function_two() {
  // This variable will likely occupy the SAME memory slot as secret_value
  int noise = 99999;
  printf("Function 2: Overwriting memory at: %p with %d\n", (void *)&noise,
         noise);
}

int main() {
  int *p;

  // 1. Point p to a variable that is about to "die"
  {
    int x = 42;
    p = &x;
    printf("Main: x is %d at %p\n", *p, (void *)p);
  }

  // 2. Call other functions to "mess up" the stack
  function_one();
  function_two();

  // 3. Now check the dangling pointer
  printf("Main: Value at dangling pointer p is now: %d\n", *p);
  return 0;
}
