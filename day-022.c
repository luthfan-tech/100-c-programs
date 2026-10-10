//Program 022 — Largest of Two and Three Numbers

#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;
    int c = 0;

    printf("Enter three integers (separated by spaces): ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Error: Invalid integer input. Please provide three numbers.\n");
        return 1;
    }

    /* 1. Compare the first two numbers */
    printf("\n--- Comparison of First Two (a vs b) ---\n");
    if (a > b) {
        printf("%d is greater than %d\n", a, b);
    } else if (b > a) {
        printf("%d is greater than %d\n", b, a);
    } else {
        printf("%d is equal to %d\n", a, b);
    }

    /* 2. Find maximum of three using the running-maximum pattern */
    printf("\n--- Maximum of All Three ---\n");
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    if (a == b && b == c) {
        printf("All three numbers are equal: %d\n", a);
    } else {
        printf("The largest value among (%d, %d, %d) is: %d\n", a, b, c, max);
    }

    return 0;
}

//Expected output:

/*
Enter three integers (separated by spaces): 14 42 27

--- Comparison of First Two (a vs b) ---
42 is greater than 14

--- Maximum of All Three ---
The largest value among (14, 42, 27) is: 42
*/