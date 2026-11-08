//Program 051 — Custom Mathematical Functions Library

#include <stdio.h>
#include <limits.h>

/* Function Prototypes (Interface Declarations) */
long long int_power(int base, int exp);
long long custom_abs(long long n);
int is_even(long long n);
long long max2(long long a, long long b);
long long max3(long long a, long long b, long long c);

int main(void) {
    int base = 0;
    int exp = 0;
    long long num_c = 0;

    printf("===========================================\n");
    printf("   CUSTOM MATHEMATICAL FUNCTIONS LIBRARY   \n");
    printf("===========================================\n");

    printf("Enter base (integer) and exponent (>= 0): ");
    if (scanf("%d %d", &base, &exp) != 2 || exp < 0) {
        printf("Error: Invalid base or exponent. Exponent must be non-negative.\n");
        return 1;
    }

    printf("Enter an integer (C) for absolute/parity checks: ");
    if (scanf("%lld", &num_c) != 1) {
        printf("Error: Non-numeric input encountered.\n");
        return 1;
    }

    /* Execution and Reporting */
    printf("\n--- Computation Results ---\n");
    printf("1. Power (%d^%d):            %lld\n", base, exp, int_power(base, exp));
    printf("2. Absolute Value |%lld|:    %lld\n", num_c, custom_abs(num_c));
    printf("3. Parity of %lld:           %s\n", num_c, is_even(num_c) ? "Even" : "Odd");
    printf("4. Max of (%d, %d):          %lld\n", base, exp, max2(base, exp));
    printf("5. Max of (%d, %d, %lld):    %lld\n", base, exp, num_c, max3(base, exp, num_c));
    printf("---------------------------\n");

    return 0;
}

/*
 * Computes base^exp iteratively using exact integer multiplication.
 * Precondition: exp >= 0.
 */
long long int_power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

/*
 * Returns the absolute magnitude of n.
 * Guards against two's complement LLONG_MIN negation overflow.
 */
long long custom_abs(long long n) {
    if (n == LLONG_MIN) {
        /* In two's complement, -LLONG_MIN overflows 64-bit signed space */
        return LLONG_MAX;
    }
    return (n < 0) ? -n : n;
}

/*
 * Evaluates parity using bitwise masking.
 * Any integer whose least significant bit (LSB) is 0 is evenly divisible by 2.
 */
int is_even(long long n) {
    return !(n & 1LL);
}

/*
 * Returns the maximum of two values using the ternary operator.
 */
long long max2(long long a, long long b) {
    return (a > b) ? a : b;
}

/*
 * Returns the maximum of three values via functional composition of max2.
 */
long long max3(long long a, long long b, long long c) {
    return max2(max2(a, b), c);
}

//Expected output:

/*
===========================================
   CUSTOM MATHEMATICAL FUNCTIONS LIBRARY   
===========================================
Enter base (integer) and exponent (>= 0): 2 10
Enter an integer (C) for absolute/parity checks: -42

--- Computation Results ---
1. Power (2^10):            1024
2. Absolute Value |-42|:    42
3. Parity of -42:           Even
4. Max of (2, 10):          10
5. Max of (2, 10, -42):     10
---------------------------
*/