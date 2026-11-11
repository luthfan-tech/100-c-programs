//Program 037 — Prime Number Checker (Trial Division and Optimizations)

#include <stdio.h>

int main(void) {
    int number = 0;

    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1 || number <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    /* Edge case: 1 and all non-positive integers are not prime */
    if (number <= 1) {
        printf("%d is NOT a prime number (primes must be strictly greater than 1).\n", number);
        return 0;
    }

    /* Edge case: 2 is the only even prime number */
    if (number == 2) {
        printf("2 is a prime number (the only even prime).\n");
        return 0;
    }

    /* Any other even number is composite */
    if (number % 2 == 0) {
        printf("%d is NOT a prime number (it is divisible by 2).\n", number);
        return 0;
    }

    int is_prime = 1;
    int first_divisor = 0;

    /*
     * Trial division up to sqrt(number), testing odd numbers only.
     * Use long long for loop counter to prevent i * i overflowing 32-bit int.
     */
    for (long long i = 3; i * i <= (long long)number; i += 2) {
        if (number % (int)i == 0) {
            is_prime = 0;
            first_divisor = (int)i;
            break; /* Early termination */
        }
    }

    if (is_prime) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is NOT a prime number (smallest divisor > 1 is %d).\n", number, first_divisor);
    }

    return 0;
}

//Expected output:

/*
Enter a positive integer: 97
97 is a prime number.

Enter a positive integer: 1
1 is NOT a prime number (primes must be strictly greater than 1).

Enter a positive integer: 104729
104729 is a prime number.

Enter a positive integer: 49
49 is NOT a prime number (smallest divisor > 1 is 7).
*/