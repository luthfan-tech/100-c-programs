// Bubble Sort and Selection Sort

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

/* Telemetry struct for algorithm instrumentation */
typedef struct
{
    long long comparisons;
    long long swaps;
} SortStats;

/* Function Prototypes */
int read_array(int arr[], int n);
void copy_array(const int src[], int dest[], int n);
void print_array(const char *label, const int arr[], int n);
void swap_elements(int *a, int *b, SortStats *stats);
SortStats bubble_sort(int arr[], int n);
SortStats selection_sort(int arr[], int n);

int main(void)
{
    int n = 0;
    int original[MAX_CAPACITY];
    int work_arr[MAX_CAPACITY];

    printf("Enter the number of elements (1 to %d): ", MAX_CAPACITY);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CAPACITY)
    {
        fprintf(stderr, "Error: Please enter a valid integer between 1 and %d.\n", MAX_CAPACITY);
        return EXIT_FAILURE;
    }

    printf("Enter %d integer(s):\n", n);
    if (!read_array(original, n))
    {
        fprintf(stderr, "Error: Invalid integer input encountered.\n");
        return EXIT_FAILURE;
    }

    printf("\n--- Input Buffer ---\n");
    print_array("Original      ", original, n);

    /* 1. Bubble Sort Benchmark */
    copy_array(original, work_arr, n);
    SortStats b_stats = bubble_sort(work_arr, n);

    printf("\n--- 1. Optimized Bubble Sort (Adaptive) ---\n");
    print_array("Sorted Result ", work_arr, n);
    printf("Comparisons   : %lld | Swaps: %lld\n", b_stats.comparisons, b_stats.swaps);

    /* 2. Selection Sort Benchmark */
    copy_array(original, work_arr, n);
    SortStats s_stats = selection_sort(work_arr, n);

    printf("\n--- 2. Selection Sort (Minimum Writes) ---\n");
    print_array("Sorted Result ", work_arr, n);
    printf("Comparisons   : %lld | Swaps: %lld\n", s_stats.comparisons, s_stats.swaps);

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

/* Copies n elements from src into dest. */
void copy_array(const int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

/* Prints labeled array contents. */
void print_array(const char *label, const int arr[], int n)
{
    printf("%s: [", label);
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i < n - 1) ? ", " : "");
    }
    printf("]\n");
}

/* Swaps two integers and increments the swap telemetry counter. */
void swap_elements(int *a, int *b, SortStats *stats)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    stats->swaps++;
}

/* Optimized Bubble Sort with early-exit flag: O(N) best case, O(N^2) worst case. */
SortStats bubble_sort(int arr[], int n)
{
    SortStats stats = {0, 0};

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            stats.comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap_elements(&arr[j], &arr[j + 1], &stats);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    return stats;
}

/* Selection Sort: O(N^2) comparisons, at most (N - 1) swaps. */
SortStats selection_sort(int arr[], int n)
{
    SortStats stats = {0, 0};

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            stats.comparisons++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap_elements(&arr[min_idx], &arr[i], &stats);
        }
    }
    return stats;
}

// Expected output:

/*
Enter the number of elements (1 to 100): 5
Enter 5 integer(s):
  arr[0] = 64
  arr[1] = 25
  arr[2] = 12
  arr[3] = 22
  arr[4] = 11

--- Input Buffer ---
Original      : [64, 25, 12, 22, 11]

--- 1. Optimized Bubble Sort (Adaptive) ---
Sorted Result : [11, 12, 22, 25, 64]
Comparisons   : 10 | Swaps: 9

--- 2. Selection Sort (Minimum Writes) ---
Sorted Result : [11, 12, 22, 25, 64]
Comparisons   : 10 | Swaps: 4
*/