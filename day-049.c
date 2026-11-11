//Program 049 — Butterfly Star Pattern

#include <stdio.h>

int main(void) {
    int n = 0;

    printf("Enter number of rows (half-height): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    printf("\n--- Butterfly Star Pattern ---\n\n");

    /* Phase 1: Upper Wings & Center Convergence */
    for (int i = 1; i <= n; i++) {
        /* Left wing */
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        /* Center cavity */
        for (int j = 1; j <= 2 * (n - i); j++) {
            printf(" ");
        }

        /* Right wing */
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    /* Phase 2: Lower Wings (starts at n - 1 to prevent middle row duplication) */
    for (int i = n - 1; i >= 1; i--) {
        /* Left wing */
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        /* Center cavity */
        for (int j = 1; j <= 2 * (n - i); j++) {
            printf(" ");
        }

        /* Right wing */
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

//Expected output:

/*


Enter number of rows (half-height): 5

--- Butterfly Star Pattern ---

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *


*/