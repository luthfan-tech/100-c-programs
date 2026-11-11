//Program 042 — Mirrored (Right-Aligned) Right Triangle Star Pattern

#include <stdio.h>

int main(void) {
    int rows = 0;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    printf("\n--- Mirrored Right-Angled Triangle (Dense) ---\n");
    for (int i = 1; i <= rows; i++) {
        /* Phase 1: Print (rows - i) leading spaces */
        for (int s = 1; s <= rows - i; s++) {
            printf(" ");
        }

        /* Phase 2: Print i stars */
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("\n--- Mirrored Right-Angled Triangle (Spaced Grid) ---\n");
    for (int i = 1; i <= rows; i++) {
        /* Phase 1: Print (rows - i) double-spaces */
        for (int s = 1; s <= rows - i; s++) {
            printf("  ");
        }

        /* Phase 2: Print i spaced stars */
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}


//Expected output

/*
Enter number of rows: 5

--- Mirrored Right-Angled Triangle (Dense) ---
    *
   **
  ***
 ****
*****

--- Mirrored Right-Angled Triangle (Spaced Grid) ---
        * 
      * * 
    * * * 
  * * * * 
* * * * * 

*/