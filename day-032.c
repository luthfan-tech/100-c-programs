//Program 032 — Sum of First N Natural Numbers and Formula Verification

#include <stdio.h>

int main(void) {
    int n = 0;

    printf("Enter a positive integer (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    /* 1. Iterative Accumulator Approach: O(N) Time */
    long long iterative_sum = 0;
    for (int i = 1; i <= n; i++) {
        iterative_sum += i;
    }

    /* 2. Gauss Closed-Form Approach: O(1) Time */
    /* Cast to long long first to prevent 32-bit integer overflow during n * (n + 1) */
    long long gauss_sum = (long long)n * (n + 1) / 2;

    /* 3. Output Results and Assert Equality */
    printf("\n--- Summation Results ---\n");
    printf("Iterative Loop Sum: %lld\n", iterative_sum);
    printf("Gauss Formula Sum:  %lld\n", gauss_sum);

    if (iterative_sum == gauss_sum) {
        printf("Verification: PASS (Both methods yield identical results)\n");
    } else {
        printf("Verification: FAIL (Mismatch detected)\n");
        return 1;
    }

    return 0;
}

//Expected output:

/*
Enter a positive integer (N): 100000

--- Summation Results ---
Iterative Loop Sum: 5000050000
Gauss Formula Sum:  5000050000
Verification: PASS (Both methods yield identical results)
*/