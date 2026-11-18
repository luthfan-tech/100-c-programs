// Program 061 — Array Traversal, Sum, Average, Minimum, and Maximum

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

/* Function Prototypes */
int read_array(int arr[], int n);
void compute_array_stats(const int arr[], int n, long long *sum, double *avg,
                         int *min_val, int *min_idx, int *max_val, int *max_idx);
void print_array(const int arr[], int n);

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
        fprintf(stderr, "Error: Invalid input encountered while reading array elements.\n");
        return EXIT_FAILURE;
    }

    long long sum = 0;
    double avg = 0.0;
    int min_val = 0, min_idx = 0;
    int max_val = 0, max_idx = 0;

    compute_array_stats(arr, n, &sum, &avg, &min_val, &min_idx, &max_val, &max_idx);

    printf("\n--- Array Contents ---\n");
    print_array(arr, n);

    printf("\n--- Statistical Summary ---\n");
    printf("Count   : %d\n", n);
    printf("Sum     : %lld\n", sum);
    printf("Average : %.2f\n", avg);
    printf("Minimum : %d (at index %d)\n", min_val, min_idx);
    printf("Maximum : %d (at index %d)\n", max_val, max_idx);

    return EXIT_SUCCESS;
}

/* Reads n integers into arr. Returns 1 on success, 0 on invalid input/EOF. */
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

/* Computes sum, average, min/max values, and their 0-based indices in a single O(N) pass. */
void compute_array_stats(const int arr[], int n, long long *sum, double *avg,
                         int *min_val, int *min_idx, int *max_val, int *max_idx)
{
    if (n <= 0 || arr == NULL)
    {
        return;
    }

    long long total = arr[0];
    int cur_min = arr[0];
    int cur_min_idx = 0;
    int cur_max = arr[0];
    int cur_max_idx = 0;

    for (int i = 1; i < n; i++)
    {
        total += arr[i];

        if (arr[i] < cur_min)
        {
            cur_min = arr[i];
            cur_min_idx = i;
        }
        if (arr[i] > cur_max)
        {
            cur_max = arr[i];
            cur_max_idx = i;
        }
    }

    *sum = total;
    *avg = (double)total / n;
    *min_val = cur_min;
    *min_idx = cur_min_idx;
    *max_val = cur_max;
    *max_idx = cur_max_idx;
}

/* Prints array elements in a clean bracketed format. */
void print_array(const int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i < n - 1) ? ", " : "");
    }
    printf("]\n");
}

// Expected output:

/*
Enter the number of elements (1 to 100): 5
Enter 5 integer(s):
  arr[0] = -12
  arr[1] = 45
  arr[2] = 0
  arr[3] = -27
  arr[4] = 19

--- Array Contents ---
[-12, 45, 0, -27, 19]

--- Statistical Summary ---
Count   : 5
Sum     : 25
Average : 5.00
Minimum : -27 (at index 3)
Maximum : 45 (at index 1)
*/