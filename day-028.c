//Program 028 — Simple Menu-Driven Calculator (Using switch-case)

#include <stdio.h>

int main(void) {
    double num1 = 0.0;
    double num2 = 0.0;
    char op = '\0';

    printf("Enter first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }

    printf("Enter operator (+, -, *, /): ");
    if (scanf(" %c", &op) != 1) {
        printf("Error: Failed to read operator.\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }

    switch (op) {
        case '+':
            printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;

        case '-':
            printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;

        case '*':
            printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;

        case '/':
            if (num2 == 0.0) {
                printf("\nError: Division by zero is undefined.\n");
                return 1;
            }
            printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            break;

        default:
            printf("\nError: Unknown operator '%c'. Supported operators are +, -, *, /\n", op);
            return 1;
    }

    return 0;
}

//Expected output:

/*
Enter first number: 18.5
Enter operator (+, -, *, /): *
Enter second number: 2

Result: 18.50 * 2.00 = 37.00

Enter first number: 42
Enter operator (+, -, *, /): /
Enter second number: 0

Error: Division by zero is undefined.
*/