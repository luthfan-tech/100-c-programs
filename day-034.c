//Program 034 — Factorial of a Number (and Overflow Limits)

#include <stdio.h>

int main(void) {
    unsigned long long n = 0;
    unsigned long long factorial = 1;

    printf("Enter a non-negative integer (0 to 20): ");
    if (scanf("%llu", &n) != 1) {
        printf("Error: Non-numeric input encountered.\n");
        return 1;
    }

    /* 64-bit unsigned limit guard */
    if (n > 20) {
        printf("Error: %llu! exceeds the 64-bit unsigned integer capacity (max N = 20).\n", n);
        printf("Note: 20! is ~2.43 x 10^18; 21! overflows ULLONG_MAX (~1.84 x 10^19).\n");
        return 1;
    }

    /* Handles both n = 0 (0! = 1) and n > 0 naturally */
    for (unsigned long long i = 1; i <= n; ++i) {
        factorial *= i;
    }

    printf("\nCalculation:\n");
    printf("%llu! = %llu\n", n, factorial);

    return 0;
}

//Expected Output:

/*
Enter a non-negative integer (0 to 20): 0

Calculation:
0! = 1

Enter a non-negative integer (0 to 20): 20

Calculation:
20! = 2432902008176640000

Enter a non-negative integer (0 to 20): 21
Error: 21! exceeds the 64-bit unsigned integer capacity (max N = 20).
Note: 20! is ~2.43 x 10^18; 21! overflows ULLONG_MAX (~1.84 x 10^19).
*/