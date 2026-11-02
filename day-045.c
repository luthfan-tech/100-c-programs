//Program 045 — Floyd's Triangle and 0-1 Alternate Triangle

#include <stdio.h>

void print_floyds_triangle(int rows);
void print_zero_one_triangle(int rows);
static void flush_stdin(void);

int main(void) {
    int choice = 0;
    int rows = 0;

    while (1) {
        printf("\n=========================================\n");
        printf("         NUMERIC PATTERN GENERATOR       \n");
        printf("=========================================\n");
        printf("1. Floyd's Triangle (Sequential Natural Numbers)\n");
        printf("2. 0-1 Alternating Triangle (Checkerboard Parity)\n");
        printf("3. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter selection (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nError: Non-numeric input encountered. Please enter a valid number.\n");
            flush_stdin();
            continue;
        }

        if (choice == 3) {
            printf("\nExiting pattern generator. Clean shutdown.\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("\nError: Invalid selection '%d'. Please choose between 1 and 3.\n", choice);
            continue;
        }

        printf("Enter the number of rows: ");
        if (scanf("%d", &rows) != 1 || rows <= 0) {
            printf("\nError: Row count must be a positive integer greater than 0.\n");
            flush_stdin();
            continue;
        }

        printf("\n--- Generated Pattern (Rows = %d) ---\n\n", rows);
        switch (choice) {
            case 1:
                print_floyds_triangle(rows);
                break;
            case 2:
                print_zero_one_triangle(rows);
                break;
        }
        printf("\n-------------------------------------\n");
    }

    return 0;
}

/*
 * Floyd's Triangle:
 * Uses a single persistent accumulator variable across all inner iterations.
 */
void print_floyds_triangle(int rows) {
    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%-4d ", num);
            num++;
        }
        printf("\n");
    }
}

/*
 * 0-1 Alternate Triangle:
 * Evaluates coordinate parity: if row + col is even, cell is 1; else 0.
 */
void print_zero_one_triangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            if ((i + j) % 2 == 0) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

/* Helper to flush remaining garbage characters from stdin on parse failure */
static void flush_stdin(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* Discard input buffer */
    }
}

//Expected output:

/*
=========================================
         NUMERIC PATTERN GENERATOR       
=========================================
1. Floyd's Triangle (Sequential Natural Numbers)
2. 0-1 Alternating Triangle (Checkerboard Parity)
3. Exit
-----------------------------------------
Enter selection (1-3): 1
Enter the number of rows: 4

--- Generated Pattern (Rows = 4) ---

1    
2    3    
4    5    6    
7    8    9    10   

-------------------------------------

=========================================
         NUMERIC PATTERN GENERATOR       
=========================================
1. Floyd's Triangle (Sequential Natural Numbers)
2. 0-1 Alternating Triangle (Checkerboard Parity)
3. Exit
-----------------------------------------
Enter selection (1-3): 2
Enter the number of rows: 5

--- Generated Pattern (Rows = 5) ---

1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1 

-------------------------------------
*/