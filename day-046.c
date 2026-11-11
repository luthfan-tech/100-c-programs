//Program 046 — Pascal's Triangle (Without Factorial Overflow)

#include <stdio.h>

#define MAX_TERMINAL_ROWS 15

void print_pascal_triangle(int num_rows);

int main(void) {
    int rows = 0;

    printf("Enter number of rows (1 - %d): ", MAX_TERMINAL_ROWS);
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Error: Please enter a valid positive integer.\n");
        return 1;
    }

    if (rows > MAX_TERMINAL_ROWS) {
        printf("Notice: Rows capped at %d to prevent horizontal terminal line-wrapping.\n", MAX_TERMINAL_ROWS);
        rows = MAX_TERMINAL_ROWS;
    }

    printf("\n--- Pascal's Triangle (%d Rows) ---\n\n", rows);
    print_pascal_triangle(rows);
    printf("\n------------------------------------\n");

    return 0;
}

void print_pascal_triangle(int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        /*
         * Each number is printed with width %6lld.
         * To keep the apex and child elements balanced on a 6-space pitch,
         * indent each preceding row by 3 spaces (half the width of %6d).
         */
        for (int space = 0; space < (num_rows - i - 1); space++) {
            printf("   ");
        }

        long long val = 1; /* C(i, 0) is always 1 */
        for (int j = 0; j <= i; j++) {
            printf("%6lld", val);

            /*
             * Iterative Binomial Recurrence:
             * C(i, j + 1) = C(i, j) * (i - j) / (j + 1)
             * Must multiply before dividing to preserve exact integer math.
             */
            val = val * (i - j) / (j + 1);
        }

        printf("\n");
    }
}

//Expected output:

/*
Enter number of rows (1 - 15): 6

--- Pascal's Triangle (6 Rows) ---

                    1
                 1     1
              1     2     1
           1     3     3     1
        1     4     6     4     1
     1     5    10    10     5     1

------------------------------------
*/