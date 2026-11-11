//Program 039 — Sum and Count of Digits of an Integer

#include <stdio.h>

int main(void) {
    int num = 0;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Please enter a valid integer.\n");
        return 1;
    }

    int sum = 0;
    int count = 0;

    /*
     * Convert to positive 64-bit space to handle:
     * 1. Negative numbers cleanly.
     * 2. Edge case INT_MIN (-2147483648), where -INT_MIN overflows a 32-bit int.
     */
    long long temp = (long long)num;
    if (temp < 0) {
        temp = -temp;
    }

    /*
     * A do-while loop ensures that num = 0 executes exactly once,
     * correctly producing count = 1 and sum = 0.
     */
    do {
        int digit = (int)(temp % 10);
        sum += digit;
        count++;
        temp /= 10;
    } while (temp != 0);

    printf("\n--- Digit Analysis for %d ---\n", num);
    printf("Total Number of Digits: %d\n", count);
    printf("Sum of Digits:          %d\n", sum);

    return 0;
}

//Expected output:

/*
Enter an integer: 4567

--- Digit Analysis for 4567 ---
Total Number of Digits: 4
Sum of Digits:          22

Enter an integer: 0

--- Digit Analysis for 0 ---
Total Number of Digits: 1
Sum of Digits:          0

Enter an integer: -128

--- Digit Analysis for -128 ---
Total Number of Digits: 3
Sum of Digits:          11
*/