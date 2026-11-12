// Program 055 — Sum of Natural Numbers and Reverse Number via Recursion

#include <stdio.h>

#define MAX_SAFE_STACK_DEPTH 10000

/* Function Prototypes */
unsigned long long sum_natural_recursive(int n);
long long reverse_number(long long n);
static long long reverse_helper(long long n, long long rev);

int main(void)
{
    int n = 0;
    long long target_num = 0;

    printf("===================================================\n");
    printf("   RECURSIVE PATTERNS: SUMMATION & DIGIT REVERSAL  \n");
    printf("===================================================\n");

    /* Part 1: Recursive Sum of Natural Numbers */
    printf("Enter a non-negative integer N (0 - %d): ", MAX_SAFE_STACK_DEPTH);
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Error: Please enter a valid non-negative integer.\n");
        return 1;
    }

    if (n > MAX_SAFE_STACK_DEPTH)
    {
        printf("Error: N exceeds safe interactive stack depth (%d) to prevent Stack Overflow.\n",
               MAX_SAFE_STACK_DEPTH);
        return 1;
    }

    printf("\n--- 1. Linear Accumulative Recursion ---\n");
    printf("Sum of first %d natural numbers: %llu\n", n, sum_natural_recursive(n));

    /* Part 2: Tail-Recursive Integer Reversal */
    printf("\nEnter an integer to reverse (positive or negative): ");
    if (scanf("%lld", &target_num) != 1)
    {
        printf("Error: Please enter a valid integer.\n");
        return 1;
    }

    long long reversed = reverse_number(target_num);
    printf("\n--- 2. Tail-Recursive Accumulator Pattern ---\n");
    printf("Original Number: %lld\n", target_num);
    printf("Reversed Number: %lld\n", reversed);
    printf("Palindrome Check: %s\n", (target_num >= 0 && target_num == reversed) ? "Yes" : "No");
    printf("===================================================\n");

    return 0;
}

/*
 * Computes 1 + 2 + ... + n using linear head recursion.
 * Aggregation happens during stack unwinding.
 */
unsigned long long sum_natural_recursive(int n)
{
    if (n == 0)
    {
        return 0ULL;
    }
    return (unsigned long long)n + sum_natural_recursive(n - 1);
}

/*
 * Public Wrapper: Preserves sign and initializes the tail-recursive accumulator.
 */
long long reverse_number(long long n)
{
    int is_negative = 0;
    if (n < 0)
    {
        is_negative = 1;
        n = -n;
    }

    long long result = reverse_helper(n, 0LL);
    return is_negative ? -result : result;
}

/*
 * Tail-Recursive Helper: Carries accumulated reversed digits downward.
 * Allows compilers to apply Tail-Call Optimization (TCO).
 */
static long long reverse_helper(long long n, long long rev)
{
    if (n == 0)
    {
        return rev;
    }
    return reverse_helper(n / 10, (rev * 10) + (n % 10));
}

// Expected output:

/*
===================================================
   RECURSIVE PATTERNS: SUMMATION & DIGIT REVERSAL
===================================================
Enter a non-negative integer N (0 - 10000): 100

--- 1. Linear Accumulative Recursion ---
Sum of first 100 natural numbers: 5050

Enter an integer to reverse (positive or negative): -48291

--- 2. Tail-Recursive Accumulator Pattern ---
Original Number: -48291
Reversed Number: -19284
Palindrome Check: No
===================================================
*/