//Program 009 — Boolean Simulation using Integers

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a = 15;
    int b = 20;

    int is_less = (a < b);
    int is_greater = (a > b);
    int is_equal = (a == b);
    int is_not_equal = (a != b);

    /* Printing raw integer values (0 or 1) and textual representation */
    printf("Comparison (%d and %d):\n", a, b);
    printf("Is a < b?  Value: %d -> %s\n", is_less, is_less ? "true" : "false");
    printf("Is a > b?  Value: %d -> %s\n", is_greater, is_greater ? "true" : "false");
    printf("Is a == b? Value: %d -> %s\n", is_equal, is_equal ? "true" : "false");
    printf("Is a != b? Value: %d -> %s\n", is_not_equal, is_not_equal ? "true" : "false");

    /* Using <stdbool.h> */
    bool flag = true;
    printf("\nUsing stdbool.h: flag = %d (%s)\n", flag, flag ? "true" : "false");

    return 0;
}

//Expected Output:

/*
Comparison (15 and 20):
Is a < b?  Value: 1 -> true
Is a > b?  Value: 0 -> false
Is a == b? Value: 0 -> false
Is a != b? Value: 1 -> true

Using stdbool.h: flag = 1 (true)
*/