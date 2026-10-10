//Program 021 — Even or Odd Checker

#include <stdio.h>

int main(void) {
    int num = 0;

    printf("Enter an integer (positive, negative, or zero): ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    /* Method 1: Modulo arithmetic check */
    if (num % 2 == 0) {
        printf("[Modulo]  %d is Even\n", num);
    } else {
        printf("[Modulo]  %d is Odd\n", num);
    }

    /* Method 2: Bitwise LSB mask check (parentheses required) */
    if ((num & 1) == 0) {
        printf("[Bitwise] %d has LSB = 0 (Even)\n", num);
    } else {
        printf("[Bitwise] %d has LSB = 1 (Odd)\n", num);
    }

    return 0;
}

//Expected output:

/*
Enter an integer (positive, negative, or zero): -7
[Modulo]  -7 is Odd
[Bitwise] -7 has LSB = 1 (Odd)
*/