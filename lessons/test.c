#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int RANDOM_NUMBER = 42;
int main() {
  srand(time(NULL));

  double randomNum = ((rand() % 10) + 1) / 100.0;

  double input_value = 0;

  // This is the main function where execution starts
  printf("Choose a number. There will be added a random noise: \n");
  scanf("%lf", &input_value);

  printf("The new number is: %lg \n", input_value + randomNum);

  return 0;
}
