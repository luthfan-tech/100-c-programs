//Program 048 — Hourglass Star Pattern

#include <stdio.h>

int main(void) {
    int rows = 0;

    printf("Enter number of rows for the half-height: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    /* Variant 1: Spaced Equilateral Hourglass */
    printf("\n--- Spaced Equilateral Hourglass ---\n");

    /* Top Half: Inverted pyramid down to 1 */
    for (int i = rows; i >= 1; i--) {
        for (int space = 0; space < rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= i; star++) {
            printf("* ");
        }
        printf("\n");
    }

    /* Bottom Half: Upright pyramid starting at 2 to avoid duplicating the neck */
    for (int i = 2; i <= rows; i++) {
        for (int space = 0; space < rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= i; star++) {
            printf("* ");
        }
        printf("\n");
    }

    /* Variant 2: Dense Odd-Count Hourglass */
    printf("\n--- Dense Odd-Count Hourglass ---\n");

    /* Top Half: (2 * i - 1) stars */
    for (int i = rows; i >= 1; i--) {
        for (int space = 0; space < rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++) {
            printf("*");
        }
        printf("\n");
    }

    /* Bottom Half: (2 * i - 1) stars starting from row 2 */
    for (int i = 2; i <= rows; i++) {
        for (int space = 0; space < rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

//Expected output:

/*
Enter number of rows for the half-height: 5

--- Spaced Equilateral Hourglass ---
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
   * * 
  * * * 
 * * * * 
* * * * * 

--- Dense Odd-Count Hourglass ---
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********
*/