// Program 059 — Menu-Driven Modular Calculator

#include <stdio.h>
#include <limits.h>

/* UI & Stream Helper Prototypes */
void display_menu(void);
void flush_stdin(void);

/* Arithmetic & Scientific Function Prototypes */
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
int divide(double a, double b, double *result);
int modulo(long long a, long long b, long long *result);
double power(double base, int exp);
long long safe_abs(long long n);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
unsigned long long nPr(int n, int r);
unsigned long long nCr(int n, int r);

int main(void)
{
    int choice = 0;

    while (1)
    {
        display_menu();
        printf("Enter your choice (0 to exit): ");

        if (scanf("%d", &choice) != 1)
        {
            flush_stdin();
            printf("Error: Invalid input. Please enter a numeric menu option.\n\n");
            continue;
        }

        if (choice == 0)
        {
            printf("Exiting modular calculator. Goodbye!\n");
            break;
        }

        switch (choice)
        {
        case 1:
        {
            double a = 0.0, b = 0.0;
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &a, &b) != 2)
            {
                flush_stdin();
                printf("Error: Invalid numeric operands.\n\n");
                break;
            }
            printf("Result: %.4f + %.4f = %.4f\n\n", a, b, add(a, b));
            break;
        }
        case 2:
        {
            double a = 0.0, b = 0.0;
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &a, &b) != 2)
            {
                flush_stdin();
                printf("Error: Invalid numeric operands.\n\n");
                break;
            }
            printf("Result: %.4f - %.4f = %.4f\n\n", a, b, subtract(a, b));
            break;
        }
        case 3:
        {
            double a = 0.0, b = 0.0;
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &a, &b) != 2)
            {
                flush_stdin();
                printf("Error: Invalid numeric operands.\n\n");
                break;
            }
            printf("Result: %.4f * %.4f = %.4f\n\n", a, b, multiply(a, b));
            break;
        }
        case 4:
        {
            double a = 0.0, b = 0.0, res = 0.0;
            printf("Enter dividend and divisor: ");
            if (scanf("%lf %lf", &a, &b) != 2)
            {
                flush_stdin();
                printf("Error: Invalid numeric operands.\n\n");
                break;
            }
            if (divide(a, b, &res))
            {
                printf("Result: %.4f / %.4f = %.4f\n\n", a, b, res);
            }
            else
            {
                printf("Error: Division by zero is undefined.\n\n");
            }
            break;
        }
        case 5:
        {
            long long a = 0, b = 0, res = 0;
            printf("Enter two integers (dividend and divisor): ");
            if (scanf("%lld %lld", &a, &b) != 2)
            {
                flush_stdin();
                printf("Error: Invalid integer operands.\n\n");
                break;
            }
            if (modulo(a, b, &res))
            {
                printf("Result: %lld %% %lld = %lld\n\n", a, b, res);
            }
            else
            {
                printf("Error: Modulo by zero is undefined.\n\n");
            }
            break;
        }
        case 6:
        {
            double base = 0.0;
            int exp = 0;
            printf("Enter base (real) and exponent (integer): ");
            if (scanf("%lf %d", &base, &exp) != 2)
            {
                flush_stdin();
                printf("Error: Invalid base or integer exponent.\n\n");
                break;
            }
            if (base == 0.0 && exp < 0)
            {
                printf("Error: 0 raised to a negative power causes division by zero.\n\n");
            }
            else
            {
                printf("Result: %.4f ^ %d = %.6f\n\n", base, exp, power(base, exp));
            }
            break;
        }
        case 7:
        {
            long long a = 0, b = 0;
            printf("Enter two integers: ");
            if (scanf("%lld %lld", &a, &b) != 2 || a == LLONG_MIN || b == LLONG_MIN)
            {
                flush_stdin();
                printf("Error: Invalid integers provided.\n\n");
                break;
            }
            printf("GCD(%lld, %lld) = %lld\n", a, b, gcd(a, b));
            printf("LCM(%lld, %lld) = %lld\n\n", a, b, lcm(a, b));
            break;
        }
        case 8:
        {
            int n = 0, r = 0;
            printf("Enter n and r (0 <= r <= n): ");
            if (scanf("%d %d", &n, &r) != 2 || n < 0 || r < 0 || r > n)
            {
                flush_stdin();
                printf("Error: Invalid values. Ensure 0 <= r <= n.\n\n");
                break;
            }
            printf("%dP%d = %llu\n", n, r, nPr(n, r));
            printf("%dC%d = %llu\n\n", n, r, nCr(n, r));
            break;
        }
        default:
            printf("Error: Invalid choice. Please select between 0 and 8.\n\n");
        }
    }

    return 0;
}

/* --- UI & Input Helpers --- */

void display_menu(void)
{
    printf("=========================================\n");
    printf("        MODULAR C SCIENTIFIC CALC        \n");
    printf("=========================================\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulo (%%)\n");
    printf("6. Power (base^exp)\n");
    printf("7. GCD & LCM\n");
    printf("8. Permutations (nPr) & Combinations (nCr)\n");
    printf("0. Exit\n");
    printf("-----------------------------------------\n");
}

void flush_stdin(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* Discard remaining characters */
    }
}

/* --- Dedicated Math Functions --- */

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

int divide(double a, double b, double *result)
{
    if (b == 0.0)
    {
        return 0;
    }
    *result = a / b;
    return 1;
}

int modulo(long long a, long long b, long long *result)
{
    if (b == 0)
    {
        return 0;
    }
    *result = a % b;
    return 1;
}

double power(double base, int exp)
{
    if (exp == 0)
    {
        return 1.0;
    }

    long long abs_exp = (exp < 0) ? -(long long)exp : (long long)exp;
    double result = 1.0;

    for (long long i = 0; i < abs_exp; i++)
    {
        result *= base;
    }

    return (exp < 0) ? (1.0 / result) : result;
}

long long safe_abs(long long n)
{
    return (n < 0) ? -n : n;
}

long long gcd(long long a, long long b)
{
    a = safe_abs(a);
    b = safe_abs(b);
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    return (safe_abs(a) / gcd(a, b)) * safe_abs(b);
}

unsigned long long nPr(int n, int r)
{
    unsigned long long result = 1ULL;
    for (int i = 0; i < r; i++)
    {
        result *= (unsigned long long)(n - i);
    }
    return result;
}

unsigned long long nCr(int n, int r)
{
    if (r > n / 2)
    {
        r = n - r;
    }
    unsigned long long num = 1ULL;
    unsigned long long den = 1ULL;

    for (int i = 1; i <= r; i++)
    {
        unsigned long long mult = (unsigned long long)(n - i + 1);
        unsigned long long div = (unsigned long long)i;

        long long common = gcd((long long)mult, (long long)div);
        mult /= (unsigned long long)common;
        div /= (unsigned long long)common;

        num *= mult;
        den *= div;

        common = gcd((long long)num, (long long)den);
        num /= (unsigned long long)common;
        den /= (unsigned long long)common;
    }
    return num / den;
}

// Expected output:

/*
=========================================
        MODULAR C SCIENTIFIC CALC
=========================================
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Division (/)
5. Modulo (%)
6. Power (base^exp)
7. GCD & LCM
8. Permutations (nPr) & Combinations (nCr)
0. Exit
-----------------------------------------
Enter your choice (0 to exit): 4
Enter dividend and divisor: 22 7
Result: 22.0000 / 7.0000 = 3.1429

Enter your choice (0 to exit): 4
Enter dividend and divisor: 10 0
Error: Division by zero is undefined.

Enter your choice (0 to exit): 0
Exiting modular calculator. Goodbye!
*/