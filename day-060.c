// Program 060 — Number Properties & Classification Engine

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/* --- Low-Level Helper Prototypes --- */
int count_digits(long long n);
int sum_digits(long long n);
long long int_pow(long long base, int exp);
long long factorial_digit(int d);
long long reverse_number(long long n);
long long sum_proper_divisors(long long n);

/* --- Classification Predicate Prototypes --- */
bool is_even(long long n);
bool is_prime(long long n);
bool is_palindrome(long long n);
bool is_armstrong(long long n);
bool is_strong(long long n);
int aliquot_classification(long long n);

/* --- UI & Stream Helper Prototypes --- */
void analyze_number(long long n);
void clear_input_buffer(void);

int main(void)
{
    long long num = 0;
    char choice = 'n';

    printf("===================================================\n");
    printf("     NUMBER PROPERTIES & CLASSIFICATION ENGINE     \n");
    printf("===================================================\n");

    do
    {
        printf("\nEnter an integer to classify: ");
        if (scanf("%lld", &num) != 1)
        {
            printf("Error: Invalid input. Please enter a valid 64-bit integer.\n");
            clear_input_buffer();
            choice = 'y';
            continue;
        }

        analyze_number(num);

        printf("\nWould you like to analyze another number? (y/n): ");
        clear_input_buffer();
        if (scanf(" %c", &choice) != 1)
        {
            break;
        }
        clear_input_buffer();

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting Classification Engine. Goodbye!\n");
    return 0;
}

/* --- Low-Level Helper Definitions --- */

int count_digits(long long n)
{
    if (n == LLONG_MIN)
    {
        return 19; /* -9223372036854775808 has 19 decimal digits */
    }
    if (n < 0)
    {
        n = -n;
    }
    if (n == 0)
    {
        return 1;
    }

    int count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

int sum_digits(long long n)
{
    int sum = 0;
    while (n != 0)
    {
        int digit = (int)(n % 10);
        sum += (digit < 0) ? -digit : digit;
        n /= 10;
    }
    return sum;
}

long long int_pow(long long base, int exp)
{
    long long result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

long long factorial_digit(int d)
{
    long long fact = 1;
    for (int i = 2; i <= d; i++)
    {
        fact *= i;
    }
    return fact;
}

long long reverse_number(long long n)
{
    long long reversed = 0;
    while (n > 0)
    {
        reversed = (reversed * 10) + (n % 10);
        n /= 10;
    }
    return reversed;
}

/*
 * Computes the sum of proper divisors (< n) in O(sqrt(N)) time.
 */
long long sum_proper_divisors(long long n)
{
    if (n <= 1)
    {
        return 0;
    }

    long long sum = 1; /* 1 is a proper divisor for all n > 1 */
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }
    return sum;
}

/* --- Number Classification Definitions --- */

bool is_even(long long n)
{
    return !(n & 1LL);
}

/*
 * Primality test using the 6k +/- 1 wheel optimization in O(sqrt(N)) time.
 */
bool is_prime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

bool is_palindrome(long long n)
{
    if (n < 0)
        return false;
    return n == reverse_number(n);
}

bool is_armstrong(long long n)
{
    if (n < 0)
        return false;
    int digits = count_digits(n);
    long long temp = n;
    long long sum = 0;

    while (temp > 0)
    {
        int digit = (int)(temp % 10);
        sum += int_pow(digit, digits);
        temp /= 10;
    }
    return sum == n;
}

/*
 * Checks if n equals the sum of factorials of its digits (e.g., 145 = 1! + 4! + 5!).
 */
bool is_strong(long long n)
{
    if (n <= 0)
        return false;
    long long temp = n;
    long long sum = 0;

    while (temp > 0)
    {
        int digit = (int)(temp % 10);
        sum += factorial_digit(digit);
        if (sum > n)
        {
            return false; /* Early exit once sum exceeds target */
        }
        temp /= 10;
    }
    return sum == n;
}

/*
 * Classifies positive integers as Deficient (-1), Perfect (0), or Abundant (1).
 */
int aliquot_classification(long long n)
{
    if (n <= 0)
        return -2;
    long long div_sum = sum_proper_divisors(n);
    if (div_sum < n)
        return -1;
    if (div_sum == n)
        return 0;
    return 1;
}

/* --- Reporting & UI Definitions --- */

void analyze_number(long long n)
{
    printf("\n===================================================\n");
    printf("   DIAGNOSTIC PROFILE FOR: %lld\n", n);
    printf("===================================================\n");

    /* 1. Basic Arithmetic Metrics */
    printf("Sign           : %s\n", (n > 0) ? "Positive" : (n < 0) ? "Negative"
                                                                   : "Zero");
    printf("Parity         : %s\n", is_even(n) ? "Even" : "Odd");
    printf("Digit Count    : %d\n", count_digits(n));
    printf("Digit Sum      : %d\n", sum_digits(n));

    /* 2. Primality */
    if (n <= 1)
    {
        printf("Primality      : Neither Prime nor Composite\n");
    }
    else
    {
        printf("Primality      : %s\n", is_prime(n) ? "Prime" : "Composite");
    }

    /* 3. Aliquot / Divisor Classification */
    if (n > 0)
    {
        int aliquot = aliquot_classification(n);
        long long div_sum = sum_proper_divisors(n);
        printf("Divisor Type   : ");
        if (aliquot == 0)
        {
            printf("Perfect Number (Proper divisor sum = %lld)\n", div_sum);
        }
        else if (aliquot == 1)
        {
            printf("Abundant Number (Proper divisor sum = %lld > %lld)\n", div_sum, n);
        }
        else
        {
            printf("Deficient Number (Proper divisor sum = %lld < %lld)\n", div_sum, n);
        }
    }
    else
    {
        printf("Divisor Type   : N/A (Requires positive integer)\n");
    }

    /* 4. Special Digit Properties */
    printf("Palindrome     : %s\n", is_palindrome(n) ? "Yes" : "No");
    printf("Armstrong      : %s\n", is_armstrong(n) ? "Yes" : "No");
    printf("Strong Number  : %s\n", is_strong(n) ? "Yes" : "No");
    printf("===================================================\n");
}

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* Discard remaining characters */
    }
}

// Expected output:

/*
===================================================
     NUMBER PROPERTIES & CLASSIFICATION ENGINE
===================================================

Enter an integer to classify: 28

===================================================
   DIAGNOSTIC PROFILE FOR: 28
===================================================
Sign           : Positive
Parity         : Even
Digit Count    : 2
Digit Sum      : 10
Primality      : Composite
Divisor Type   : Perfect Number (Proper divisor sum = 28)
Palindrome     : No
Armstrong      : No
Strong Number  : No
===================================================

Would you like to analyze another number? (y/n): y

Enter an integer to classify: 145

===================================================
   DIAGNOSTIC PROFILE FOR: 145
===================================================
Sign           : Positive
Parity         : Odd
Digit Count    : 3
Digit Sum      : 10
Primality      : Composite
Divisor Type   : Deficient Number (Proper divisor sum = 35 < 145)
Palindrome     : No
Armstrong      : No
Strong Number  : Yes
===================================================

Would you like to analyze another number? (y/n): n
Exiting Classification Engine. Goodbye!
*/