//Program 023 — Leap Year Checker

#include <stdio.h>

int main(void) {
    int year = 0;

    printf("Enter a year (greater than 0): ");
    if (scanf("%d", &year) != 1 || year <= 0) {
        printf("Error: Please enter a valid positive integer for the year.\n");
        return 1;
    }

    if (year % 400 == 0) {
        printf("%d is a leap year (divisible by 400).\n", year);
    } else if (year % 100 == 0) {
        printf("%d is not a leap year (century year not divisible by 400).\n", year);
    } else if (year % 4 == 0) {
        printf("%d is a leap year (divisible by 4 and not a century year).\n", year);
    } else {
        printf("%d is not a leap year (not divisible by 4).\n", year);
    }

    return 0;
}

//Expected output:

/*
Enter a year (greater than 0): 1900
1900 is not a leap year (century year not divisible by 400).

Enter a year (greater than 0): 2000
2000 is a leap year (divisible by 400).

Enter a year (greater than 0): 2024
2024 is a leap year (divisible by 4 and not a century year).
*/