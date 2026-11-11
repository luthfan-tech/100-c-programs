// Program 052 — Prime and Armstrong Range Finder Using Helper Functions

#include <stdio.h>

/* Function Prototypes (Pure Predicates & Helpers) */
int count_digits(int n);
long long int_power(int base, int exp);
int is_prime(int n);
int is_armstrong(int n);

int main(void)
{
    int start = 0;
    int end = 0;

    printf("===========================================\n");
    printf("   PRIME & ARMSTRONG RANGE FINDER          \n");
    printf("===========================================\n");

    printf("Enter lower limit: ");
    if (scanf("%d", &start) != 1)
    {
        printf("Error: Invalid lower limit entered.\n");
        return 1;
    }

    printf("Enter upper limit: ");
    if (scanf("%d", &end) != 1)
    {
        printf("Error: Invalid upper limit entered.\n");
        return 1;
    }

    if (start > end)
    {
        printf("Notice: Lower limit (%d) is greater than upper limit (%d). Swapping limits.\n", start, end);
        int temp = start;
        start = end;
        end = temp;
    }

    /* Range Scan 1: Prime Numbers */
    printf("\n--- Prime Numbers in Range [%d, %d] ---\n", start, end);
    int prime_count = 0;
    for (int i = start; i <= end; i++)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
            prime_count++;
        }
    }
    if (prime_count == 0)
    {
        printf("None found.");
    }
    printf("\n(Total primes: %d)\n", prime_count);

    /* Range Scan 2: Armstrong Numbers */
    printf("\n--- Armstrong Numbers in Range [%d, %d] ---\n", start, end);
    int armstrong_count = 0;
    for (int i = start; i <= end; i++)
    {
        if (is_armstrong(i))
        {
            printf("%d ", i);
            armstrong_count++;
        }
    }
    if (armstrong_count == 0)
    {
        printf("None found.");
    }
    printf("\n(Total Armstrong numbers: %d)\n", armstrong_count);

    printf("\n===========================================\n");
    return 0;
}

/*
 * Returns the total number of decimal digits in n.
 * Uses do-while so 0 is accurately counted as 1 digit.
 */
int count_digits(int n)
{
    long long temp = (long long)n;
    if (temp < 0)
    {
        temp = -temp;
    }

    int count = 0;
    do
    {
        count++;
        temp /= 10;
    } while (temp != 0);

    return count;
}

/*
 * Computes base^exp iteratively using exact integer math.
 */
long long int_power(int base, int exp)
{
    long long res = 1;
    for (int i = 0; i < exp; i++)
    {
        res *= base;
    }
    return res;
}

/*
 * Checks primality in O(sqrt(N)) time using integer bounds (no math.h).
 * Returns 1 if prime, 0 otherwise.
 */
int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    for (long long i = 3; i * i <= (long long)n; i += 2)
    {
        if (n % (int)i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/*
 * Checks if n equals the sum of its digits raised to the power of digit count.
 * Returns 1 if Armstrong, 0 otherwise.
 */
int is_armstrong(int n)
{
    if (n < 0)
        return 0;

    int digits = count_digits(n);
    long long sum = 0;
    int temp = n;

    while (temp != 0)
    {
        int rem = temp % 10;
        sum += int_power(rem, digits);
        temp /= 10;
    }

    return (sum == (long long)n);
}

// Expected output

/*
===========================================
   PRIME & ARMSTRONG RANGE FINDER
===========================================
Enter lower limit: 1
Enter upper limit: 500

--- Prime Numbers in Range [1, 500] ---
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499
(Total primes: 95)

--- Armstrong Numbers in Range [1, 500] ---
1 2 3 4 5 6 7 8 9 153 370 371 407
(Total Armstrong numbers: 13)

===========================================
*/