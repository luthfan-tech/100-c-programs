//Program 050 — Hollow Square with Diagonals

#include <stdio.h>

int main(void) {
    int size = 0;

    printf("Enter the size of the square (odd integer recommended >= 3): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    printf("\n--- Hollow Square with Diagonals (%d x %d) ---\n\n", size, size);

    /* Fixed N x N coordinate grid evaluation */
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            /*
             * Render asterisk if the cell satisfies ANY of the structural conditions:
             * 1. Top or bottom horizontal edge (i == 1 || i == size)
             * 2. Left or right vertical edge   (j == 1 || j == size)
             * 3. Main diagonal (\)              (i == j)
             * 4. Anti-diagonal (/)              (i + j == size + 1)
             */
            if (i == 1 || i == size ||
                j == 1 || j == size ||
                i == j ||
                j == (size - i + 1)) {
                printf("* ");
            } else {
                /* Two ASCII spaces to preserve 1:1 aspect ratio with "* " */
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("\n-----------------------------------------------\n");
    return 0;
}

//Expected output:

/*
Enter the size of the square (odd integer recommended >= 3): 7

--- Hollow Square with Diagonals (7 x 7) ---

* * * * * * * 
* *       * * 
*   *   *   * 
*     *     * 
*   *   *   * 
* *       * * 
* * * * * * * 

-----------------------------------------------
*/