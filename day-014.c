//for Program 014 — Area and Circumference of a Circle (User Input)

#include <stdio.h>

#define PI 3.14159265358979323846

int main(void) {
    double radius = 0.0;

    printf("Enter the radius of the circle: ");
    if (scanf("%lf", &radius) != 1) {
        printf("Error: Invalid input. Please enter a valid number.\n");
        return 1;
    }

    if (radius <= 0.0) {
        printf("Error: Radius must be greater than zero.\n");
        return 1;
    }

    double diameter = 2.0 * radius;
    double circumference = 2.0 * PI * radius;
    double area = PI * radius * radius;

    printf("Diameter:      %.2f\n", diameter);
    printf("Circumference: %.2f\n", circumference);
    printf("Area:          %.2f\n", area);

    return 0;
}

//Expected output:

/*
Enter the radius of the circle: 5.5
Diameter:      11.00
Circumference: 34.56
Area:          95.03
*/