//Program 044 — Solid and Hollow Diamond Star Patterns

#include <stdio.h>

int main(void) {
    int rows = 0;

    printf("Enter number of rows (half-height): ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    /* Pattern 1: Solid Diamond */
    printf("\n--- Solid Diamond Pattern ---\n");

    /* Upper Half (including center row) */
    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++) {
            printf("*");
        }
        printf("\n");
    }

    /* Lower Half (starts at rows - 1 to avoid center duplication) */
    for (int i = rows - 1; i >= 1; i--) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++) {
            printf("*");
        }
        printf("\n");
    }

    /* Pattern 2: Hollow Diamond */
    printf("\n--- Hollow Diamond Pattern ---\n");

    /* Upper Half */
    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++) {
            if (star == 1 || star == (2 * i - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    /* Lower Half */
    for (int i = rows - 1; i >= 1; i--) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++) {
            if (star == 1 || star == (2 * i - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

//Expected output:

/*
Enter number of rows (half-height): 5

--- Solid Diamond Pattern ---
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *

--- Hollow Diamond Pattern ---
    *
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    *
*/