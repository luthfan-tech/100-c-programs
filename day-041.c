//041: Right-Angled Triangle Star Pattern and Inverted Triangle

#include <stdio.h>

int main(void) {
    int rows = 0;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    /* Pattern 1: Upright Right-Angled Triangle */
    printf("\n--- Upright Right-Angled Triangle ---\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    /* Pattern 2: Inverted Right-Angled Triangle */
    printf("\n--- Inverted Right-Angled Triangle ---\n");
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

//Expected output:

/*
Enter number of rows: 5

--- Upright Right-Angled Triangle ---
* 
* * 
* * * 
* * * * 
* * * * * 

--- Inverted Right-Angled Triangle ---
* * * * * 
* * * * 
* * * 
* * 
*
*/