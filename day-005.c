//Program 005 — Basic Arithmetic (Hardcoded)

#include <stdio.h>

int main(void) {
    int num1 = 20;
    int num2 = 6;

    printf("Addition: %d + %d = %d\n", num1, num2, num1 + num2);
    printf("Subtraction: %d - %d = %d\n", num1, num2, num1 - num2);
    printf("Multiplication: %d * %d = %d\n", num1, num2, num1 * num2);
    printf("Division: %d / %d = %d\n", num1, num2, num1 / num2);
    printf("Modulus: %d %% %d = %d\n", num1, num2, num1 % num2);

    return 0;
}

//Expected output:

/*
 Addition: 20 + 6 = 26
Subtraction: 20 - 6 = 14
Multiplication: 20 * 6 = 120
Division: 20 / 6 = 3
Modulus: 20 % 6 = 2
*/