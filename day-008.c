//Program 008 — Character Output and ASCII Values

#include <stdio.h>

int main(void) {
    char letter = 'A';
    int code = 97;

    printf("The character is: %c\n", letter);
    printf("The ASCII value of '%c' is: %d\n", letter, letter);
    printf("The character for ASCII value %d is: %c\n", code, code);

    /* Character arithmetic demonstration */
    char next_letter = letter + 1;
    printf("'%c' + 1 = '%c' (ASCII %d)\n", letter, next_letter, next_letter);

    return 0;
}

//Expected output:

/*
The character is: A
The ASCII value of 'A' is: 65
The character for ASCII value 97 is: a
'A' + 1 = 'B' (ASCII 66)
*/