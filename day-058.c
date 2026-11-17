// Program 058 — Combinations ($nCr$) and Permutations ($nPr$)

#include <stdio.h>
#include <limits.h>

/* Function Prototypes */
unsigned long long gcd(unsigned long long a, unsigned long long b);
unsigned long long falling_factorial(int n, int r, int *overflow);
unsigned long long nPr(int n, int r, int *overflow);
unsigned long long nCr(int n, int r, int *overflow);

int main(void)
{
    int n = 0;
    int r = 0;

    printf("===================================================\n");
    printf("   COMBINATORICS ENGINE: PERMUTATIONS & COMBINATIONS\n");
    printf("===================================================\n");

    printf("Enter total items (n) and selected items (r) [0 <= r <= n]: ");
    if (scanf("%d %d", &n, &r) != 2 || n < 0 || r < 0 || r > n)
    {
        printf("Error: Invalid domain. Ensure 0 <= r <= n.\n");
        return 1;
    }

    int p_overflow = 0;
    int c_overflow = 0;

    unsigned long long perm = nPr(n, r, &p_overflow);
    unsigned long long comb = nCr(n, r, &c_overflow);

    printf("\n--- Combinatorial Results for n = %d, r = %d ---\n", n, r);
    if (p_overflow)
    {
        printf("Permutations (%dP%d): Overflow (exceeds 64-bit ULLONG_MAX)\n", n, r);
    }
    else
    {
        printf("Permutations (%dP%d): %llu\n", n, r, perm);
    }

    if (c_overflow)
    {
        printf("Combinations (%dC%d): Overflow (exceeds 64-bit ULLONG_MAX)\n", n, r);
    }
    else
    {
        printf("Combinations (%dC%d): %llu\n", n, r, comb);
    }
    printf("===================================================\n");

    return 0;
}

/*
 * Iterative Euclidean GCD for stepwise fraction reduction.
 */
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    while (b != 0)
    {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/*
 * Computes n * (n - 1) * ... * (n - r + 1) with pre-multiplication overflow detection.
 */
unsigned long long falling_factorial(int n, int r, int *overflow)
{
    *overflow = 0;
    unsigned long long result = 1ULL;

    for (int i = 0; i < r; i++)
    {
        unsigned long long factor = (unsigned long long)(n - i);
        if (factor > 0 && result > ULLONG_MAX / factor)
        {
            *overflow = 1;
            return 0ULL;
        }
        result *= factor;
    }
    return result;
}

/*
 * Permutations: nPr = n! / (n - r)!
 */
unsigned long long nPr(int n, int r, int *overflow)
{
    if (n < 0 || r < 0 || r > n)
    {
        *overflow = 0;
        return 0ULL;
    }
    return falling_factorial(n, r, overflow);
}

/*
 * Combinations: nCr = n! / (r! * (n - r)!)
 * Uses symmetry reduction and stepwise GCD cross-cancellation to prevent overflow.
 */
unsigned long long nCr(int n, int r, int *overflow)
{
    *overflow = 0;
    if (n < 0 || r < 0 || r > n)
    {
        return 0ULL;
    }

    /* Symmetry property: nCr(n, r) == nCr(n, n - r) */
    if (r > n / 2)
    {
        r = n - r;
    }

    unsigned long long numerator = 1ULL;
    unsigned long long denominator = 1ULL;

    for (int i = 1; i <= r; i++)
    {
        unsigned long long mult = (unsigned long long)(n - i + 1);
        unsigned long long div = (unsigned long long)i;

        /* Cancel common factors between current multiplier and divisor */
        unsigned long long common = gcd(mult, div);
        mult /= common;
        div /= common;

        /* Cancel common factors between running numerator and current divisor */
        common = gcd(numerator, div);
        numerator /= common;
        div /= common;

        /* Cancel common factors between current multiplier and running denominator */
        common = gcd(mult, denominator);
        mult /= common;
        denominator /= common;

        if (mult > 0 && numerator > ULLONG_MAX / mult)
        {
            *overflow = 1;
            return 0ULL;
        }

        numerator *= mult;
        denominator *= div;
    }

    return numerator / denominator;
}

// Expected output:

/*
===================================================
   COMBINATORICS ENGINE: PERMUTATIONS & COMBINATIONS
===================================================
Enter total items (n) and selected items (r) [0 <= r <= n]: 25 10

--- Combinatorial Results for n = 25, r = 10 ---
Permutations (25P10): 11861676288000
Combinations (25C10): 3268760
===================================================
*/