// Program 069 — Two-Pointer Pair Sum and Dutch National Flag Partition

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

/* Function Prototypes */
void swap_int(int *a, int *b);
void print_array(const char *label, const int arr[], int n);
void insertion_sort(int arr[], int n);
bool two_sum_sorted(const int *arr, int n, long long target, int *out_i, int *out_j);
void dutch_national_flag_sort(int arr[], int n);

int main(void)
{
    /* --- Part 1: Converging Two-Pointer Pair Sum --- */
    int n1 = 0;
    int arr1[MAX_CAPACITY];

    printf("=== Part 1: Two-Pointer Pair Sum ===\n");
    printf("Enter number of elements (2 to %d): ", MAX_CAPACITY);
    if (scanf("%d", &n1) != 1 || n1 < 2 || n1 > MAX_CAPACITY)
    {
        fprintf(stderr, "Error: Please enter a valid count between 2 and %d.\n", MAX_CAPACITY);
        return EXIT_FAILURE;
    }

    printf("Enter %d integer(s):\n", n1);
    for (int i = 0; i < n1; i++)
    {
        printf("  arr[%d] = ", i);
        if (scanf("%d", &arr1[i]) != 1)
        {
            fprintf(stderr, "Error: Invalid integer input.\n");
            return EXIT_FAILURE;
        }
    }

    long long target = 0;
    printf("Enter target pair sum: ");
    if (scanf("%lld", &target) != 1)
    {
        fprintf(stderr, "Error: Invalid target sum.\n");
        return EXIT_FAILURE;
    }

    insertion_sort(arr1, n1);
    print_array("\nSorted Array", arr1, n1);

    int idx_i = -1, idx_j = -1;
    if (two_sum_sorted(arr1, n1, target, &idx_i, &idx_j))
    {
        printf("Pair Found  : indices [%d, %d] -> %d + %d = %lld\n",
               idx_i, idx_j, arr1[idx_i], arr1[idx_j], target);
    }
    else
    {
        printf("Result      : No pair sums to %lld.\n", target);
    }

    /* --- Part 2: Dutch National Flag (3-Way Partition of 0s, 1s, 2s) --- */
    int n2 = 0;
    int flags[MAX_CAPACITY];

    printf("\n=== Part 2: Dutch National Flag (0s, 1s, 2s) ===\n");
    printf("Enter number of elements (1 to %d): ", MAX_CAPACITY);
    if (scanf("%d", &n2) != 1 || n2 < 1 || n2 > MAX_CAPACITY)
    {
        fprintf(stderr, "Error: Please enter a valid count between 1 and %d.\n", MAX_CAPACITY);
        return EXIT_FAILURE;
    }

    printf("Enter %d integer(s) (each must be 0, 1, or 2):\n", n2);
    for (int i = 0; i < n2; i++)
    {
        printf("  flags[%d] = ", i);
        if (scanf("%d", &flags[i]) != 1 || flags[i] < 0 || flags[i] > 2)
        {
            fprintf(stderr, "Error: Value must be strictly 0, 1, or 2.\n");
            return EXIT_FAILURE;
        }
    }

    print_array("\nBefore Partition", flags, n2);
    dutch_national_flag_sort(flags, n2);
    print_array("After Partition ", flags, n2);

    return EXIT_SUCCESS;
}

/* Swaps two integers in-place. */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

/* Sorts arr in ascending order via Insertion Sort. */
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*
 * Finds two indices in a sorted array whose elements sum to target in O(N) time.
 * Uses 64-bit widened addition to prevent signed overflow.
 */
bool two_sum_sorted(const int *arr, int n, long long target, int *out_i, int *out_j)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        long long sum = (long long)arr[left] + arr[right];
        if (sum == target)
        {
            *out_i = left;
            *out_j = right;
            return true;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}

/*
 * Dijkstra's Dutch National Flag Algorithm:
 * Partitions 0s, 1s, and 2s in a single O(N) pass with O(1) auxiliary space.
 */
void dutch_national_flag_sort(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap_int(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        { /* arr[mid] == 2 */
            swap_int(&arr[mid], &arr[high]);
            high--;
            /* Do not increment mid: element swapped from high is not yet inspected */
        }
    }
}

// Expected output:

/*
=== Part 1: Two-Pointer Pair Sum ===
Enter number of elements (2 to 100): 6
Enter 6 integer(s):
  arr[0] = 11
  arr[1] = 2
  arr[2] = 15
  arr[3] = 1
  arr[4] = 7
  arr[5] = 4
Enter target pair sum: 15

Sorted Array: [1, 2, 4, 7, 11, 15]
Pair Found  : indices [2, 4] -> 4 + 11 = 15

=== Part 2: Dutch National Flag (0s, 1s, 2s) ===
Enter number of elements (1 to 100): 8
Enter 8 integer(s) (each must be 0, 1, or 2):
  flags[0] = 2
  flags[1] = 0
  flags[2] = 2
  flags[3] = 1
  flags[4] = 1
  flags[5] = 0
  flags[6] = 2
  flags[7] = 1

Before Partition: [2, 0, 2, 1, 1, 0, 2, 1]
After Partition : [0, 0, 1, 1, 1, 2, 2, 2]
*/