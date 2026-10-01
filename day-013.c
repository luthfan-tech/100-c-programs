//Program 013 — Area and Perimeter of a Rectangle

#include <stdio.h>

int main(void) {
    double length = 0.0;
    double width = 0.0;

    printf("Enter the length of the rectangle: ");
    if (scanf("%lf", &length) != 1) {
        printf("Error: Invalid input for length.\n");
        return 1;
    }

    printf("Enter the width of the rectangle: ");
    if (scanf("%lf", &width) != 1) {
        printf("Error: Invalid input for width.\n");
        return 1;
    }

    /* Validate physical geometric constraints */
    if (length <= 0.0 || width <= 0.0) {
        printf("Error: Dimensions must be positive numbers greater than zero.\n");
        return 1;
    }

    double area = length * width;
    double perimeter = 2.0 * (length + width);

    printf("Area of the rectangle: %.2f\n", area);
    printf("Perimeter of the rectangle: %.2f\n", perimeter);

    if (length == width) {
        printf("Note: This rectangle is a square.\n");
    }

    return 0;
}

//Expected output:

/*
Enter the length of the rectangle: 8.5
Enter the width of the rectangle: 4.0
Area of the rectangle: 34.00
Perimeter of the rectangle: 25.00
*/