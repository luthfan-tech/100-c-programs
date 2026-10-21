//Program 033 — Multiplication Table Generator

#include <stdio.h>

int main(void) {
    int m = 0;
    int range = 10;

    printf("Enter number (M) for multiplication table: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Error: Please enter a valid positive integer.\n");
        return 1;
    }

    printf("Enter upper range limit (e.g., 10, 20): ");
    if (scanf("%d", &range) != 1 || range <= 0) {
        printf("Error: Please enter a valid positive range.\n");
        return 1;
    }

    printf("\n=====================================\n");
    printf("     MULTIPLICATION TABLE: %d        \n", m);
    printf("=====================================\n");

    for (int i = 1; i <= range; i++) {
        /* %2d keeps counter aligned; %6d keeps results aligned */
        printf("  %d  x  %2d  =  %6d\n", m, i, m * i);
    }

    printf("=====================================\n");

    return 0;
}

//Expected output:

/*
Enter number (M) for multiplication table: 12
Enter upper range limit (e.g., 10, 20): 12

=====================================
     MULTIPLICATION TABLE: 12        
=====================================
  12  x   1  =      12
  12  x   2  =      24
  12  x   3  =      36
  12  x   4  =      48
  12  x   5  =      60
  12  x   6  =      72
  12  x   7  =      84
  12  x   8  =      96
  12  x   9  =     108
  12  x  10  =     120
  12  x  11  =     132
  12  x  12  =     144
=====================================
*/