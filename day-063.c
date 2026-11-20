// Program 063 — Second Largest and Second Smallest Elements in a Single Pass

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

/* Function Prototypes */
int read_array(int arr[], int n);
void print_array(const int arr[], int n);
void find_second_extremes(const int arr[], int n,
                          int *first_max, int *second_max, bool *has_second_max,
                          int *first_min, int *second_min, bool *has_second_min);

int main(void)
{
    int n = 0;
    int arr[MAX_CAPACITY];

    printf("Enter the number of elements (1 to %d): ", MAX_CAPACITY);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CAPACITY)
    {
        fprintf(stderr, "Error: Please enter a valid integer between 1 and %d.\n", MAX_CAPACITY);
        return EXIT_FAILURE;
    }

    printf("Enter %d integer(s):\n", n);
    if (!read_array(arr, n))
    {
        fprintf(stderr, "Error: Invalid integer input encountered.\n");
        return EXIT_FAILURE;
    }

    int first_max = 0, second_max = 0;
    int first_min = 0, second_min = 0;
    bool has_second_max = false;
    bool has_second_min = false;

    find_second_extremes(arr, n, &first_max, &second_max, &has_second_max,
                         &first_min, &second_min, &has_second_min);

    printf("\n--- Array Contents ---\n");
    print_array(arr, n);

    printf("\n--- Single-Pass Extrema Analysis ---\n");
    printf("Largest Element         : %d\n", first_max);
    if (has_second_max)
    {
        printf("Second Largest Element  : %d\n", second_max);
    }
    else
    {
        printf("Second Largest Element  : None (fewer than 2 distinct values)\n");
    }

    printf("Smallest Element        : %d\n", first_min);
    if (has_second_min)
    {
        printf("Second Smallest Element : %d\n", second_min);
    }
    else
    {
        printf("Second Smallest Element : None (fewer than 2 distinct values)\n");
    }

    return EXIT_SUCCESS;
}

/* Reads n integers into arr. Returns 1 on success, 0 on failure. */
int read_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("  arr[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1)
        {
            return 0;
        }
    }
    return 1;
}

/* Prints array elements in bracketed format. */
void print_array(const int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i < n - 1) ? ", " : "");
    }
    printf("]\n");
}

/*
 * Computes largest, distinct second largest, smallest, and distinct second smallest
 * in a single O(N) pass without sentinel collisions.
 */
void find_second_extremes(const int arr[], int n,
                          int *first_max, int *second_max, bool *has_second_max,
                          int *first_min, int *second_min, bool *has_second_min)
{
    if (n <= 0 || arr == NULL)
    {
        return;
    }

    int max1 = arr[0], max2 = 0;
    int min1 = arr[0], min2 = 0;
    bool found_max2 = false;
    bool found_min2 = false;

    for (int i = 1; i < n; i++)
    {
        int val = arr[i];

        /* Track Largest and Distinct Second Largest */
        if (val > max1)
        {
            max2 = max1;
            max1 = val;
            found_max2 = true;
        }
        else if (val < max1 && (!found_max2 || val > max2))
        {
            max2 = val;
            found_max2 = true;
        }

        /* Track Smallest and Distinct Second Smallest */
        if (val < min1)
        {
            min2 = min1;
            min1 = val;
            found_min2 = true;
        }
        else if (val > min1 && (!found_min2 || val < min2))
        {
            min2 = val;
            found_min2 = true;
        }
    }

    *first_max = max1;
    *second_max = max2;
    *has_second_max = found_max2;

    *first_min = min1;
    *second_min = min2;
    *has_second_min = found_min2;
}

// Expected output:

/*
Enter the number of elements (1 to 100): 6
Enter 6 integer(s):
  arr[0] = 12
  arr[1] = 35
  arr[2] = 1
  arr[3] = 10
  arr[4] = 34
  arr[5] = 1

--- Array Contents ---
[12, 35, 1, 10, 34, 1]

--- Single-Pass Extrema Analysis ---
Largest Element         : 35
Second Largest Element  : 34
Smallest Element        : 1
Second Smallest Element : 10
*/