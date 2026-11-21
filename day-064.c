// Program 064 — Linear Search and Binary Search

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

/* Function Prototypes */
int read_array(int arr[], int n);
void print_array(const int arr[], int n);
bool is_sorted(const int arr[], int n);
int linear_search_iterative(const int arr[], int n, int target);
int linear_search_recursive(const int arr[], int n, int target, int index);
int binary_search_iterative(const int arr[], int n, int target);
int binary_search_recursive(const int arr[], int low, int high, int target);
void print_search_result(const char *method, int index);

int main(void)
{
    int n = 0;
    int target = 0;
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

    printf("Enter target value to search: ");
    if (scanf("%d", &target) != 1)
    {
        fprintf(stderr, "Error: Invalid target integer.\n");
        return EXIT_FAILURE;
    }

    printf("\n--- Input Buffer ---\n");
    print_array(arr, n);
    printf("Target: %d\n", target);

    printf("\n--- Search Results ---\n");
    print_search_result("Linear Search (Iterative)", linear_search_iterative(arr, n, target));
    print_search_result("Linear Search (Recursive)", linear_search_recursive(arr, n, target, 0));

    if (is_sorted(arr, n))
    {
        print_search_result("Binary Search (Iterative)", binary_search_iterative(arr, n, target));
        print_search_result("Binary Search (Recursive)", binary_search_recursive(arr, 0, n - 1, target));
    }
    else
    {
        printf("Binary Search            : Skipped (array is not sorted in ascending order)\n");
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

/* Verifies non-decreasing sort order required by Binary Search. */
bool is_sorted(const int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

/* O(N) Iterative Linear Search. Returns first matching index or -1. */
int linear_search_iterative(const int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

/* O(N) Recursive Linear Search. Returns first matching index or -1. */
int linear_search_recursive(const int arr[], int n, int target, int index)
{
    if (index >= n)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return linear_search_recursive(arr, n, target, index + 1);
}

/* O(log N) Iterative Binary Search on a sorted array. */
int binary_search_iterative(const int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

/* O(log N) Recursive Binary Search on a sorted array. */
int binary_search_recursive(const int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] < target)
    {
        return binary_search_recursive(arr, mid + 1, high, target);
    }
    return binary_search_recursive(arr, low, mid - 1, target);
}

/* Formats search output cleanly. */
void print_search_result(const char *method, int index)
{
    if (index != -1)
    {
        printf("%-25s: Found at index %d\n", method, index);
    }
    else
    {
        printf("%-25s: Not found\n", method);
    }
}

// Expected output:

/*
Enter the number of elements (1 to 100): 6
Enter 6 integer(s):
  arr[0] = 10
  arr[1] = 23
  arr[2] = 35
  arr[3] = 47
  arr[4] = 52
  arr[5] = 68
Enter target value to search: 52

--- Input Buffer ---
[10, 23, 35, 47, 52, 68]
Target: 52

--- Search Results ---
Linear Search (Iterative): Found at index 4
Linear Search (Recursive): Found at index 4
Binary Search (Iterative): Found at index 4
Binary Search (Recursive): Found at index 4
*/