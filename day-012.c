//Program 012 — Simple Calculator (Add/Sub/Mul/Div)

#include <stdio.h>

int main(void) {
    double num1 = 0.0;
    double num2 = 0.0;
    char op = ' ';

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("Error: Invalid number input.\n");
        return 1;
    }

    printf("Enter an operator (+, -, *, /): ");
    if (scanf(" %c", &op) != 1) {
        printf("Error: Failed to read operator.\n");
        return 1;
    }

    if (op == '+') {
        printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
    } else if (op == '-') {
        printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
    } else if (op == '*') {
        printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
    } else if (op == '/') {
        if (num2 != 0.0) {
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
    } else {
        printf("Error: Invalid operator '%c'. Please use +, -, *, or /.\n", op);
    }

    return 0;
}

//Expected output:

/*
Enter two numbers: 15.5 2.5
Enter an operator (+, -, *, /): /
15.50 / 2.50 = 6.20
*/