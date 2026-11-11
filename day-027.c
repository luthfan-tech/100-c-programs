//Program 027 — Triangle Validity and Classification

#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;
    int c = 0;

    printf("Enter the lengths of the three sides: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
        printf("Error: Side lengths must be positive integers.\n");
        return 1;
    }

    /* 1. Triangle Inequality Theorem: sum of any two sides > third side */
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Invalid: The sides (%d, %d, %d) cannot form a closed triangle.\n", a, b, c);
        return 0;
    }

    printf("Valid triangle confirmed.\n");

    /* 2. Side-length classification */
    if (a == b && b == c) {
        printf("Classification: Equilateral\n");
    } else if (a == b || b == c || a == c) {
        printf("Classification: Isosceles\n");
    } else {
        printf("Classification: Scalene\n");
    }

    /* 3. Pythagorean angle test (cast to long long to prevent overflow) */
    long long sq_a = (long long)a * a;
    long long sq_b = (long long)b * b;
    long long sq_c = (long long)c * c;

    if (sq_a + sq_b == sq_c || sq_a + sq_c == sq_b || sq_b + sq_c == sq_a) {
        printf("Angle property: Right-Angled (satisfies Pythagorean theorem)\n");
    }

    return 0;
}

//Example Input/Output:

/*
Enter the lengths of the three sides: 3 4 5
Valid triangle confirmed.
Classification: Scalene
Angle property: Right-Angled (satisfies Pythagorean theorem)

Enter the lengths of the three sides: 5 5 5
Valid triangle confirmed.
Classification: Equilateral

Enter the lengths of the three sides: 1 2 10
Invalid: The sides (1, 2, 10) cannot form a closed triangle.
*/