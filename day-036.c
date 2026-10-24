//Program 036 — Reverse an Integer and Check for Palindrome

#include <stdio.h>

int main(void) {
    int original = 0;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &original) != 1 || original < 0) {
        printf("Error: Please enter a valid non-negative integer.\n");
        return 1;
    }

    /* Use long long for reversed to safely absorb 32-bit reversal overflows */
    long long reversed = 0;
    int temp = original;

    while (temp != 0) {
        int remainder = temp % 10;
        reversed = (reversed * 10) + remainder;
        temp /= 10;
    }

    printf("\nOriginal Number: %d\n", original);
    printf("Reversed Number: %lld\n", reversed);

    if (reversed == (long long)original) {
        printf("Status: Palindrome (reads the same forward and backward)\n");
    } else {
        printf("Status: Not a Palindrome\n");
    }

    return 0;
}

//Expected output:

/*
Enter a non-negative integer: 12321

Original Number: 12321
Reversed Number: 12321
Status: Palindrome (reads the same forward and backward)

Enter a non-negative integer: 1200

Original Number: 1200
Reversed Number: 21
Status: Not a Palindrome
*/