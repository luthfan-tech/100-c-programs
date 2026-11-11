//Program 017 — Simple and Compound Interest Calculator

#include <stdio.h>
#include <math.h>

int main(void) {
    double principal = 0.0;
    double rate = 0.0;
    double time = 0.0;
    int n = 1;

    printf("Enter principal amount: ");
    if (scanf("%lf", &principal) != 1 || principal <= 0.0) {
        printf("Error: Principal must be a positive number.\n");
        return 1;
    }

    printf("Enter annual interest rate (in %%): ");
    if (scanf("%lf", &rate) != 1 || rate <= 0.0) {
        printf("Error: Rate must be a positive number.\n");
        return 1;
    }

    printf("Enter time (in years): ");
    if (scanf("%lf", &time) != 1 || time <= 0.0) {
        printf("Error: Time must be a positive number.\n");
        return 1;
    }

    printf("Enter compounding frequency per year (e.g., 1=annual, 4=quarterly, 12=monthly): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Compounding frequency must be an integer greater than zero.\n");
        return 1;
    }

    /* Simple Interest */
    double si = (principal * rate * time) / 100.0;
    double total_simple = principal + si;

    /* Compound Interest: A = P * (1 + r/n)^(n*t) */
    double r_decimal = rate / 100.0;
    double total_compound = principal * pow(1.0 + (r_decimal / (double)n), (double)n * time);
    double ci = total_compound - principal;

    printf("\n--- Results ---\n");
    printf("Simple Interest:          %.2f\n", si);
    printf("Total (Simple):           %.2f\n", total_simple);
    printf("Compound Interest:        %.2f\n", ci);
    printf("Total (Compound):         %.2f\n", total_compound);
    printf("Compound vs Simple Gain:  +%.2f\n", total_compound - total_simple);

    return 0;
}

//Expected output:

/*
Enter principal amount: 10000
Enter annual interest rate (in %): 8.5
Enter time (in years): 3
Enter compounding frequency per year (e.g., 1=annual, 4=quarterly, 12=monthly): 4

--- Results ---
Simple Interest:          2550.00
Total (Simple):           12550.00
Compound Interest:        2870.19
Total (Compound):         12870.19
Compound vs Simple Gain:  +320.19

*/