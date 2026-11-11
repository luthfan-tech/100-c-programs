//Program 035 — Fibonacci Sequence Generator

#include <stdio.h>

#define MAX_SAFE_FIBONACCI_TERMS 93

int main(void) {
    int n = 0;

    printf("Enter number of Fibonacci terms to generate (1 - %d): ", MAX_SAFE_FIBONACCI_TERMS);
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Error: Input must be a positive integer greater than or equal to 1.\n");
        return 1;
    }

    if (n > MAX_SAFE_FIBONACCI_TERMS) {
        printf("Error: Term count %d exceeds 64-bit integer limit.\n", n);
        printf("Note: F(93) is the largest Fibonacci term representable in unsigned 64-bit space.\n");
        return 1;
    }

    printf("\nFirst %d term(s) of the Fibonacci sequence:\n", n);

    unsigned long long a = 0;
    unsigned long long b = 1;

    for (int i = 1; i <= n; i++) {
        /* Print current term */
        printf("%llu", a);

        /* Print comma delimiter for all but the final term */
        if (i < n) {
            printf(", ");
        }

        /* Slide window forward to calculate next term */
        unsigned long long next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
    return 0;
}

//Expected output:

/*
Enter number of Fibonacci terms to generate (1 - 93): 10

First 10 term(s) of the Fibonacci sequence:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34

Enter number of Fibonacci terms to generate (1 - 93): 94
Error: Term count 94 exceeds 64-bit integer limit.
Note: F(93) is the largest Fibonacci term representable in unsigned 64-bit space.

*/