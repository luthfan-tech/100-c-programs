//038 — GCD and LCM (Euclidean Algorithm)

#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;

    printf("Enter two positive integers: ");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Error: Please enter two valid positive integers greater than 0.\n");
        return 1;
    }

    /* Preserve original values for LCM calculation */
    int num1 = a;
    int num2 = b;

    /*
     * Euclidean Algorithm (O(log(min(a, b))) time complexity):
     * Repeatedly replace (a, b) with (b, a % b) until b becomes 0.
     */
    while (num2 != 0) {
        int remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }

    int gcd = num1;

    /*
     * LCM calculation:
     * Divide first to avoid intermediate integer overflow: (a / gcd) * b
     */
    long long lcm = ((long long)a / gcd) * b;

    printf("\n--- Calculation Summary ---\n");
    printf("Inputs:                      %d, %d\n", a, b);
    printf("Greatest Common Divisor:     %d\n", gcd);
    printf("Least Common Multiple (LCM): %lld\n", lcm);

    return 0;
}

//Expected output:

/*
Enter two positive integers: 48 18

--- Calculation Summary ---
Inputs:                      48, 18
Greatest Common Divisor:     6
Least Common Multiple (LCM): 144

Enter two positive integers: 1000000007 1000000009

--- Calculation Summary ---
Inputs:                      1000000007, 1000000009
Greatest Common Divisor:     1
Least Common Multiple (LCM): 1000000016000000063
*/