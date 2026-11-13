// 056 — Binary to Decimal and Decimal to Binary Conversion Functions

#include <stdio.h>

#define MAX_PACKED_DECIMAL 524287 /* (2^19 - 1): max 19 bits representable in signed 64-bit long long */

/* Function Prototypes */
long long binary_to_decimal(long long binary_num);
long long decimal_to_binary(int decimal_num);

int main(void)
{
    long long bin_input = 0;
    int dec_input = 0;

    printf("===================================================\n");
    printf("   NUMBER SYSTEM CONVERTER (BASE-2 <-> BASE-10)    \n");
    printf("===================================================\n");

    /* 1. Binary to Decimal */
    printf("Enter a non-negative binary number (0s and 1s only, max 19 digits): ");
    if (scanf("%lld", &bin_input) != 1)
    {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }

    long long dec_result = binary_to_decimal(bin_input);
    if (dec_result == -1LL)
    {
        printf("Error: '%lld' is not a valid non-negative binary number.\n", bin_input);
    }
    else
    {
        printf("Result: %lld (base-2) = %lld (base-10)\n", bin_input, dec_result);
    }

    /* 2. Decimal to Binary */
    printf("\nEnter a non-negative decimal integer (0 to %d): ", MAX_PACKED_DECIMAL);
    if (scanf("%d", &dec_input) != 1 || dec_input < 0 || dec_input > MAX_PACKED_DECIMAL)
    {
        printf("Error: Input must be an integer between 0 and %d.\n", MAX_PACKED_DECIMAL);
        return 1;
    }

    long long bin_result = decimal_to_binary(dec_input);
    printf("Result: %d (base-10) = %lld (base-2)\n", dec_input, bin_result);
    printf("===================================================\n");

    return 0;
}

/*
 * Converts a base-2 integer representation to base-10 using bitwise shifts.
 * Returns -1 if input is negative or contains digits other than 0 or 1.
 */
long long binary_to_decimal(long long binary_num)
{
    if (binary_num < 0)
    {
        return -1LL;
    }

    long long decimal_num = 0;
    int pos = 0;

    while (binary_num > 0)
    {
        int remainder = (int)(binary_num % 10);

        /* Strict base-2 digit validation */
        if (remainder != 0 && remainder != 1)
        {
            return -1LL;
        }

        if (remainder == 1)
        {
            decimal_num += (1LL << pos);
        }

        binary_num /= 10;
        pos++;
    }

    return decimal_num;
}

/*
 * Converts a non-negative base-10 integer into a decimal-packed base-2 number.
 * Precondition: 0 <= decimal_num <= MAX_PACKED_DECIMAL.
 */
long long decimal_to_binary(int decimal_num)
{
    if (decimal_num == 0)
    {
        return 0LL;
    }

    long long binary_num = 0;
    long long place = 1;

    while (decimal_num > 0)
    {
        int bit = decimal_num & 1;
        binary_num += (long long)bit * place;
        decimal_num >>= 1;
        place *= 10;
    }

    return binary_num;
}

// Expected output:

/*
===================================================
   NUMBER SYSTEM CONVERTER (BASE-2 <-> BASE-10)
===================================================
Enter a non-negative binary number (0s and 1s only, max 19 digits): 110101
Result: 110101 (base-2) = 53 (base-10)

Enter a non-negative decimal integer (0 to 524287): 53
Result: 53 (base-10) = 110101 (base-2)
===================================================
*/