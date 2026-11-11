//Program 018 — Type Casting and Conversion (Implicit vs Explicit)

#include <stdio.h>

int main(void) {
    int total_marks = 0;
    int num_subjects = 0;

    printf("Enter total marks: ");
    if (scanf("%d", &total_marks) != 1) {
        printf("Error: Invalid marks input.\n");
        return 1;
    }

    printf("Enter number of subjects: ");
    if (scanf("%d", &num_subjects) != 1 || num_subjects <= 0) {
        printf("Error: Number of subjects must be greater than zero.\n");
        return 1;
    }

    /* 1. Implicit truncation vs explicit casting */
    int int_div = total_marks / num_subjects;
    double float_div = (double)total_marks / num_subjects;
    double diff = float_div - (double)int_div;

    printf("\n--- Division Comparison ---\n");
    printf("Without cast (int division):    %d\n", int_div);
    printf("With cast (floating-point):     %.2f\n", float_div);
    printf("Truncated loss:                 %.2f\n", diff);

    /* 2. Decimal Truncation */
    double original_decimal = 0.0;
    printf("\n--- Decimal Truncation ---\n");
    printf("Enter a decimal value (e.g., 12.87): ");
    if (scanf("%lf", &original_decimal) != 1) {
        printf("Error: Invalid decimal input.\n");
        return 1;
    }

    int truncated_int = (int)original_decimal;
    int rounded_int = (int)(original_decimal + 0.5); /* rounding for positive decimals */

    printf("Original double:                %.2f\n", original_decimal);
    printf("Casted to int (truncated):      %d\n", truncated_int);
    printf("Nearest integer (rounded):      %d\n", rounded_int);

    /* 3. ASCII Casting */
    int ascii_code = 0;
    printf("\n--- ASCII Casting ---\n");
    printf("Enter an integer code (65-90 for A-Z): ");
    if (scanf("%d", &ascii_code) != 1) {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    char ascii_char = (char)ascii_code;
    printf("Code %d explicitly cast to char: '%c'\n", ascii_code, ascii_char);

    return 0;
}

//Expected output:

/*
Enter total marks: 473
Enter number of subjects: 5

--- Division Comparison ---
Without cast (int division):    94
With cast (floating-point):     94.60
Truncated loss:                 0.60

--- Decimal Truncation ---
Enter a decimal value (e.g., 12.87): 12.87
Original double:                12.87
Casted to int (truncated):      12
Nearest integer (rounded):      13

--- ASCII Casting ---
Enter an integer code (65-90 for A-Z): 80
Code 80 explicitly cast to char: 'P'

*/