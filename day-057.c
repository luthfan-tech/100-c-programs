// Program 057 — Modular Euclidean GCD and LCM FunctionsProgram 057 — Modular Euclidean GCD and LCM Functions

#include <stdio.h>
#include <limits.h>

/* Function Prototypes */
long long safe_abs(long long n);
long long gcd_recursive(long long a, long long b);
long long gcd_iterative(long long a, long long b);
long long lcm(long long a, long long b);

int main(void)
{
    long long num1 = 0;
    long long num2 = 0;

    printf("===================================================\n");
    printf("   MODULAR EUCLIDEAN GCD & LCM (RECURSIVE/ITER)    \n");
    printf("===================================================\n");

    printf("Enter two integers (a and b): ");
    if (scanf("%lld %lld", &num1, &num2) != 2)
    {
        printf("Error: Please enter two valid integers.\n");
        return 1;
    }

    if (num1 == LLONG_MIN || num2 == LLONG_MIN)
    {
        printf("Error: LLONG_MIN cannot be safely negated in two's complement.\n");
        return 1;
    }

    long long g_rec = gcd_recursive(num1, num2);
    long long g_iter = gcd_iterative(num1, num2);
    long long l_val = lcm(num1, num2);

    printf("\n--- Calculation Results ---\n");
    printf("Inputs:              %lld, %lld\n", num1, num2);
    printf("GCD (Recursive):     %lld\n", g_rec);
    printf("GCD (Iterative):     %lld\n", g_iter);
    printf("LCM (Composed):      %lld\n", l_val);
    printf("===================================================\n");

    return 0;
}

/*
 * Computes absolute magnitude without requiring <stdlib.h>.
 */
long long safe_abs(long long n)
{
    return (n < 0) ? -n : n;
}

/*
 * Tail-Recursive Euclidean GCD:
 * Time Complexity: O(log(min(|a|, |b|)))
 */
long long gcd_recursive(long long a, long long b)
{
    a = safe_abs(a);
    b = safe_abs(b);

    if (b == 0)
    {
        return a;
    }
    return gcd_recursive(b, a % b);
}

/*
 * Iterative Euclidean GCD:
 * O(1) auxiliary stack space, immune to stack depth limits.
 */
long long gcd_iterative(long long a, long long b)
{
    a = safe_abs(a);
    b = safe_abs(b);

    while (b != 0)
    {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

/*
 * Composed LCM Function:
 * Handles zero edge cases and divides before multiplying to prevent overflow.
 */
long long lcm(long long a, long long b)
{
    if (a == 0 || b == 0)
    {
        return 0LL;
    }

    long long abs_a = safe_abs(a);
    long long abs_b = safe_abs(b);
    long long divisor = gcd_iterative(abs_a, abs_b);

    return (abs_a / divisor) * abs_b;
}

// Expected output:

/*
===================================================
   MODULAR EUCLIDEAN GCD & LCM (RECURSIVE/ITER)
===================================================
Enter two integers (a and b): -48 18

--- Calculation Results ---
Inputs:              -48, 18
GCD (Recursive):     6
GCD (Iterative):     6
LCM (Composed):      144
===================================================
*/