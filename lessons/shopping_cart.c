#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  int quantity_of_items_to_add;

  printf("How many items will you add to the basket? \n");
  scanf(" %d", &quantity_of_items_to_add);
  getchar();

  int *quantities = malloc(quantity_of_items_to_add * sizeof(int));
  float *prices = malloc(quantity_of_items_to_add * sizeof(float));
  char **names = malloc(quantity_of_items_to_add * sizeof(char *));
  char temp_buffer[1000] = "";
  double total = 0.0;
  int size_of_string = 0;
  printf("\n");

  for (int i = 0; i < quantity_of_items_to_add; i++) {
    printf("This is item %d\n", i);
    printf("What is the item you want to add: \n");
    fgets(temp_buffer, sizeof(temp_buffer), stdin);

    size_of_string = strlen(temp_buffer);
    temp_buffer[size_of_string - 1] = '\0';

    names[i] = malloc((size_of_string + 1) * sizeof(char));
    if (names[i] == NULL) {
      printf("Memory allocation failed!\n");
      return 1;
    }
    strcpy(names[i], temp_buffer);

    printf("What is the price of the item: \n");
    scanf("%f", &prices[i]);

    printf("How many items of this product would you like to buy: \n");
    scanf("%d", &quantities[i]);
    getchar();

    printf("\n");

    total += prices[i] * quantities[i];
  }

  for (int i = 0; i < quantity_of_items_to_add; i++) {
    printf("You have bought %03d %s. The total for this item is: $%.2f. \n",
           quantities[i], names[i], quantities[i] * prices[i]);

    // free up memory free(quantitities[i]);
    free(names[i]);
  }
  printf("The total is: $%.2lf \n", total);
  free(names);
  free(prices);
  free(quantities);
}
