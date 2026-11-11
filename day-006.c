//Program 006: Constants and #define

#include <stdio.h>

#define PI 3.14159f

int main(void) {
    const float radius = 5.0f;
    const int max_attempts = 3;

    float area = PI * radius * radius;
    float circumference = 2.0f * PI * radius;

    printf("Radius: %.2f\n", radius);
    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);
    printf("Configured Max Attempts: %d\n", max_attempts);

    return 0;
}

//Expected output:
/*
Radius: 5.00
Area: 78.54
Circumference: 31.42
Configured Max Attempts: 3
*/