//Program 016: Swapping Two Numbers (With and Without a Third Variable)

#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;

    printf("Enter two integers (a and b): ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    printf("\nInitial values:          a = %d, b = %d\n", a, b);

    /* Method 1: Using a temporary third variable (Recommended) */
    int temp = a;
    a = b;
    b = temp;
    printf("After swap (with temp): a = %d, b = %d\n", a, b);

    /* Method 2: Bitwise XOR swap (No extra variable, no overflow risk) */
    /* Swapping back to original order */
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swap back (via XOR):  a = %d, b = %d\n", a, b);

    return 0;
}

//Expected output:

/*
Enter two integers (a and b): 42 99

Initial values:             a = 42, b = 99
After swap (with temp):     a = 99, b = 42
After swap back (via XOR):  a = 42, b = 99

*/
