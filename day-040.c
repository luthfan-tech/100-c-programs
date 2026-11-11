//Program 040 — Armstrong (Narcissistic) Number Checker.

#include <stdio.h>

int main(void) {
    int num = 0;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Error: Please enter a valid non-negative integer.\n");
        return 1;
    }

    /* Pass 1: Count the total number of digits (n) */
    int count = 0;
    int temp = num;

    do {
        count++;
        temp /= 10;
    } while (temp != 0);

    /* Pass 2: Extract each digit and compute digit^count via exact integer math */
    long long sum = 0;
    temp = num;

    while (temp != 0) {
        int digit = temp % 10;

        /* Integer power computation: digit^count */
        long long power = 1;
        for (int i = 0; i < count; i++) {
            power *= digit;
        }

        sum += power;
        temp /= 10;
    }

    /* Pass 3: Verification */
    printf("\n--- Analysis for %d ---\n", num);
    printf("Number of digits (n): %d\n", count);
    printf("Sum of digits^%d:      %lld\n", count, sum);

    if (sum == (long long)num) {
        printf("Result: %d is an Armstrong (Narcissistic) number.\n", num);
    } else {
        printf("Result: %d is NOT an Armstrong number.\n", num);
    }

    return 0;
}

//Example Input/Output:

/*
Enter a non-negative integer: 153

--- Analysis for 153 ---
Number of digits (n): 3
Sum of digits^3:      153
Result: 153 is an Armstrong (Narcissistic) number.

Enter a non-negative integer: 1634

--- Analysis for 1634 ---
Number of digits (n): 4
Sum of digits^4:      1634
Result: 1634 is an Armstrong (Narcissistic) number.

Enter a non-negative integer: 250

--- Analysis for 250 ---
Number of digits (n): 3
Sum of digits^3:      141
Result: 250 is NOT an Armstrong number.
*/