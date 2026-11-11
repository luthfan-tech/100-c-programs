// Program 054 — Factorial and Fibonacci via Recursion

#include <stdio.h>

#define MAX_SAFE_FACTORIAL 20
#define MAX_SAFE_RECURSIVE_FIB 30

/* Function Prototypes */
unsigned long long factorial_recursive(int n);
unsigned long long fibonacci_recursive(int n);

int main(void)
{
    int n = 0;

    printf("===================================================\n");
    printf("   RECURSION MECHANICS: FACTORIAL & FIBONACCI      \n");
    printf("===================================================\n");

    printf("Enter a non-negative integer (0 to %d): ", MAX_SAFE_RECURSIVE_FIB);
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Error: Please enter a valid non-negative integer.\n");
        return 1;
    }

    /* 1. Factorial Demonstration */
    printf("\n--- 1. Recursive Factorial ---\n");
    if (n > MAX_SAFE_FACTORIAL)
    {
        printf("Notice: %d! exceeds 64-bit integer limits (max n = %d).\n", n, MAX_SAFE_FACTORIAL);
    }
    else
    {
        printf("%d! = %llu (Stack depth: %d frames)\n", n, factorial_recursive(n), n == 0 ? 1 : n);
    }

    /* 2. Fibonacci Series Demonstration */
    printf("\n--- 2. Recursive Fibonacci Series ---\n");
    if (n > MAX_SAFE_RECURSIVE_FIB)
    {
        printf("Warning: Generating %d terms naively via recursion would cause severe CPU lag.\n", n);
        printf("Tree complexity O(2^N) caps practical interactive execution at N = %d.\n", MAX_SAFE_RECURSIVE_FIB);
    }
    else
    {
        printf("First %d terms of Fibonacci sequence:\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%llu", fibonacci_recursive(i));
            if (i < n - 1)
            {
                printf(", ");
            }
        }
        printf("\n");
    }

    printf("===================================================\n");
    return 0;
}

/*
 * Linear Recursive Factorial:
 * O(N) time complexity, O(N) auxiliary stack memory frames.
 */
unsigned long long factorial_recursive(int n)
{
    /* Base case: terminates recursion and unwinds call stack */
    if (n <= 1)
    {
        return 1ULL;
    }

    /* Recursive case */
    return (unsigned long long)n * factorial_recursive(n - 1);
}

/*
 * Branching Naive Recursive Fibonacci:
 * O(2^N) exponential time complexity due to redundant subproblem recomputation.
 */
unsigned long long fibonacci_recursive(int n)
{
    /* Base cases */
    if (n == 0)
        return 0ULL;
    if (n == 1)
        return 1ULL;

    /* Recursive case: binary call tree */
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Expected output:

/*
===================================================
   RECURSION MECHANICS: FACTORIAL & FIBONACCI
===================================================
Enter a non-negative integer (0 to 30): 10

--- 1. Recursive Factorial ---
10! = 3628800 (Stack depth: 10 frames)

--- 2. Recursive Fibonacci Series ---
First 10 terms of Fibonacci sequence:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34
===================================================
*/