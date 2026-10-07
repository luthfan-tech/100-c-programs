//Program 019 — Sum and Reverse of a 3-Digit Number

#include <stdio.h>

int main(void) {
    int number = 0;

    printf("Enter a 3-digit integer (100 - 999): ");
    if (scanf("%d", &number) != 1 || number < 100 || number > 999) {
        printf("Error: Please enter a valid 3-digit positive integer.\n");
        return 1;
    }

    int original = number;

    /* Direct positional decomposition */
    int units = number % 10;
    int tens = (number / 10) % 10;
    int hundreds = number / 100;

    int sum_of_digits = hundreds + tens + units;
    int reversed_number = (units * 100) + (tens * 10) + hundreds;

    printf("\n--- Digit Breakdown ---\n");
    printf("Hundreds digit:  %d\n", hundreds);
    printf("Tens digit:      %d\n", tens);
    printf("Units digit:     %d\n", units);

    printf("\n--- Results ---\n");
    printf("Original number: %d\n", original);
    printf("Sum of digits:   %d\n", sum_of_digits);
    printf("Reversed number: %d\n", reversed_number);

    return 0;
}

//Expected output:

/*
Enter a 3-digit integer (100 - 999): 742

--- Digit Breakdown ---
Hundreds digit:  7
Tens digit:      4
Units digit:     2

--- Results ---
Original number: 742
Sum of digits:   13
Reversed number: 247
*/