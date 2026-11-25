// Program 068 — Subarray Sums: Prefix Sum Range Queries & Kadane's Algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

/* Function Prototypes */
int read_array(int arr[], int n);
void print_array(const char *label, const int arr[], int n);
void build_prefix_sum(const int arr[], long long prefix[], int n);
long long range_sum(const long long prefix[], int left, int right);
void kadane_max_subarray(const int arr[], int n, long long *max_sum,
                         int *start_idx, int *end_idx);

int main(void)
{
    int n = 0;
    int arr[MAX_CAPACITY];
    long long prefix[MAX_CAPACITY + 1];

    printf("Enter number of elements N (1 to %d): ", MAX_CAPACITY);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CAPACITY)
    {
        fprintf(stderr, "Error: Please enter a valid integer between 1 and %d.\n", MAX_CAPACITY);
        return EXIT_FAILURE;
    }

    printf("Enter %d integer(s) (positive, zero, or negative):\n", n);
    if (!read_array(arr, n))
    {
        fprintf(stderr, "Error: Invalid integer input encountered.\n");
        return EXIT_FAILURE;
    }

    printf("\n--- Input Buffer ---\n");
    print_array("Array", arr, n);

    /* 1. Prefix Sum Preprocessing & O(1) Range Query */
    build_prefix_sum(arr, prefix, n);

    int left = 0, right = 0;
    printf("\n--- 1. Prefix Sum O(1) Range Query ---\n");
    printf("Enter inclusive query range [L, R] (0 <= L <= R < %d): ", n);
    if (scanf("%d %d", &left, &right) != 2 || left < 0 || right >= n || left > right)
    {
        fprintf(stderr, "Error: Invalid range. Must satisfy 0 <= L <= R < %d.\n", n);
        return EXIT_FAILURE;
    }

    printf("Sum of subarray [%d..%d]: %lld\n", left, right, range_sum(prefix, left, right));

    /* 2. Kadane's Maximum Contiguous Subarray */
    long long max_sum = 0;
    int best_start = 0, best_end = 0;
    kadane_max_subarray(arr, n, &max_sum, &best_start, &best_end);

    printf("\n--- 2. Kadane's Maximum Contiguous Subarray ---\n");
    printf("Maximum Subarray Sum : %lld\n", max_sum);
    printf("Optimal Slice Range  : [%d..%d]\n", best_start, best_end);
    printf("Subarray Elements    : [");
    for (int i = best_start; i <= best_end; i++)
    {
        printf("%d%s", arr[i], (i < best_end) ? ", " : "");
    }
    printf("]\n");

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

/* Builds 1-indexed prefix sum array in O(N) time. */
void build_prefix_sum(const int arr[], long long prefix[], int n)
{
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + arr[i];
    }
}

/* Answers inclusive range sum [left, right] in O(1) constant time. */
long long range_sum(const long long prefix[], int left, int right)
{
    return prefix[right + 1] - prefix[left];
}

/*
 * Kadane's Algorithm: Finds maximum contiguous subarray sum and its indices
 * in O(N) time and O(1) auxiliary space. Handles all-negative arrays accurately.
 */
void kadane_max_subarray(const int arr[], int n, long long *max_sum,
                         int *start_idx, int *end_idx)
{
    if (n <= 0 || arr == NULL)
    {
        return;
    }

    long long current_sum = arr[0];
    long long best_sum = arr[0];
    int temp_start = 0;
    int best_start = 0;
    int best_end = 0;

    for (int i = 1; i < n; i++)
    {
        if ((long long)arr[i] > current_sum + arr[i])
        {
            current_sum = arr[i];
            temp_start = i;
        }
        else
        {
            current_sum += arr[i];
        }

        if (current_sum > best_sum)
        {
            best_sum = current_sum;
            best_start = temp_start;
            best_end = i;
        }
    }

    *max_sum = best_sum;
    *start_idx = best_start;
    *end_idx = best_end;
}

// Expected output:

/*
Enter number of elements N (1 to 100): 8
Enter 8 integer(s) (positive, zero, or negative):
  arr[0] = -2
  arr[1] = 1
  arr[2] = -3
  arr[3] = 4
  arr[4] = -1
  arr[5] = 2
  arr[6] = 1
  arr[7] = -5

--- Input Buffer ---
Array: [-2, 1, -3, 4, -1, 2, 1, -5]

--- 1. Prefix Sum O(1) Range Query ---
Enter inclusive query range [L, R] (0 <= L <= R < 8): 3 6
Sum of subarray [3..6]: 6

--- 2. Kadane's Maximum Contiguous Subarray ---
Maximum Subarray Sum : 6
Optimal Slice Range  : [3..6]
Subarray Elements    : [4, -1, 2, 1]
*/