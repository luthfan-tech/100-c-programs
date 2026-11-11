//Program 007 — Data Types and sizeof

#include <stdio.h>

int main(void) {
    char letter = 'A';
    short small_num = 100;
    int number = 19;
    float decimal = 99.1f;
    double precise_decimal = 99.99;

    printf("Size of char:        %zu byte\n", sizeof(char));
    printf("Size of short:       %zu bytes\n", sizeof(short));
    printf("Size of int:         %zu bytes\n", sizeof(int));
    printf("Size of float:       %zu bytes\n", sizeof(float));
    printf("Size of double:      %zu bytes\n", sizeof(double));

    /* You can also pass the variable directly */
    printf("\nVariable sizes in memory:\n");
    printf("Size of 'letter':    %zu byte\n", sizeof(letter));
    printf("Size of 'small_num': %zu bytes\n", sizeof(small_num));
    printf("Size of 'number':    %zu bytes\n", sizeof(number));
    printf("Size of 'decimal':   %zu bytes\n", sizeof(decimal));
    printf("Size of 'precise':   %zu bytes\n", sizeof(precise_decimal));

    return 0;
}

//Expected output (on standard 64-bit GCC):

/*
Size of char:        1 byte
Size of short:       2 bytes
Size of int:         4 bytes
Size of float:       4 bytes
Size of double:      8 bytes

Variable sizes in memory:
Size of 'letter':    1 byte
Size of 'small_num': 2 bytes
Size of 'number':    4 bytes
Size of 'decimal':   4 bytes
Size of 'precise':   8 bytes
*/