//Program 015 — Temperature Converter (Celsius $\leftrightarrow$ Fahrenheit)

#include <stdio.h>

int main(void) {
    double temp = 0.0;
    char unit = ' ';

    printf("Enter temperature with unit (e.g., 100 C or 212 F): ");
    if (scanf("%lf %c", &temp, &unit) != 2) {
        printf("Error: Invalid input format. Expected a number followed by C or F.\n");
        return 1;
    }

    if (unit == 'C' || unit == 'c') {
        if (temp < -273.15) {
            printf("Error: Temperature below absolute zero (-273.15 C) is not possible.\n");
            return 1;
        }
        double fahrenheit = (temp * 9.0 / 5.0) + 32.0;
        printf("%.2f C = %.2f F\n", temp, fahrenheit);
    } else if (unit == 'F' || unit == 'f') {
        if (temp < -459.67) {
            printf("Error: Temperature below absolute zero (-459.67 F) is not possible.\n");
            return 1;
        }
        double celsius = (temp - 32.0) * 5.0 / 9.0;
        printf("%.2f F = %.2f C\n", temp, celsius);
    } else {
        printf("Error: Unknown unit '%c'. Please use 'C' or 'F'.\n", unit);
        return 1;
    }

    return 0;
}

//Expected output:

/*
Enter temperature with unit (e.g., 100 C or 212 F): 37 C
37.00 C = 98.60 F
*/