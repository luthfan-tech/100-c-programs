//Program 025 — Quadratic Equation Roots Solver

#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    printf("Enter coefficients a, b, and c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }

    if (a == 0.0) {
        printf("Error: Coefficient 'a' cannot be 0 for a quadratic equation.\n");
        return 1;
    }

    double discriminant = (b * b) - (4.0 * a * c);

    printf("\nDiscriminant (D) = %.2f\n", discriminant);

    if (discriminant > 0.0) {
        double sqrt_d = sqrt(discriminant);
        double root1 = (-b + sqrt_d) / (2.0 * a);
        double root2 = (-b - sqrt_d) / (2.0 * a);

        printf("Roots are real and distinct:\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    } else if (discriminant == 0.0) {
        double root = -b / (2.0 * a);
        if (root == -0.0) {
            root = 0.0;
        }

        printf("Roots are real and equal:\n");
        printf("Root 1 = Root 2 = %.2f\n", root);
    } else {
        double real_part = -b / (2.0 * a);
        if (real_part == -0.0) {
            real_part = 0.0;
        }
        double imag_part = sqrt(-discriminant) / (2.0 * fabs(a));

        printf("Roots are complex conjugates:\n");
        printf("Root 1 = %.2f + %.2fi\n", real_part, imag_part);
        printf("Root 2 = %.2f - %.2fi\n", real_part, imag_part);
    }

    return 0;
}

//Example Input/Output:

/*
Enter coefficients a, b, and c: 1 -5 6

Discriminant (D) = 1.00
Roots are real and distinct:
Root 1 = 3.00
Root 2 = 2.00

Enter coefficients a, b, and c: 1 2 5

Discriminant (D) = -16.00
Roots are complex conjugates:
Root 1 = -1.00 + 2.00i
Root 2 = -1.00 - 2.00i
*/