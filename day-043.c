//Program 043 — Equilateral Pyramid and Inverted Pyramid Star Patterns

#include <stdio.h>

int main(void) {
    int rows = 0;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    /* Pattern 1: Upright Equilateral Pyramid */
    printf("\n--- Upright Equilateral Pyramid ---\n");
    for (int i = 1; i <= rows; i++) {
        /* Phase 1: Leading spaces (rows - i) */
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        /* Phase 2: Odd star sequence (2 * i - 1) */
        for (int star = 1; star <= (2 * i - 1); star++) {
            printf("*");
        }

        printf("\n");
    }

    /* Pattern 2: Inverted Equilateral Pyramid */
    printf("\n--- Inverted Equilateral Pyramid ---\n");
    for (int i = rows; i >= 1; i--) {
        /* Phase 1: Leading spaces (rows - i) */
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        /* Phase 2: Odd star sequence (2 * i - 1) */
        for (int star = 1; star <= (2 * i - 1); star++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

//Expected output:

/*
Enter number of rows: 5

--- Upright Equilateral Pyramid ---
    *
   ***
  *****
 *******
*********

--- Inverted Equilateral Pyramid ---
*********
 *******
  *****
   ***
    *

*/