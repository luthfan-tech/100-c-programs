//Program 004: Variables and Format Specifiers

#include <stdio.h>

int main(void) {
    int age = 19;
    float height = 5.9f;
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Height: %.1f\n", height);
    printf("Grade: %c\n", grade);

    return 0;
}

//Expected output:
/*Age: 19
Height: 5.9
Grade: 'A'*/