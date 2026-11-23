// Program 067 — Insertion Sort and Merging Two Sorted Arrays

#include <stdio.h>
#include <stdlib.h>

#define MAX_HALF_CAPACITY 50

/* Telemetry struct tracking comparisons and memory write operations */
typedef struct
{
    long long comparisons;
    long long writes;
} OpStats;

/* Function Prototypes */
int read_array(int arr[], int n, const char *name);
void print_array(const char *label, const int arr[], int n);
OpStats insertion_sort(int arr[], int n);
OpStats merge_sorted_arrays(const int a[], int n1, const int b[], int n2, int dest[]);

int main(void)
{
    int n1 = 0, n2 = 0;
    int arr1[MAX_HALF_CAPACITY];
    int arr2[MAX_HALF_CAPACITY];
    int merged[MAX_HALF_CAPACITY * 2];

    /* 1. Read First Array */
    printf("Enter size of Array A (1 to %d): ", MAX_HALF_CAPACITY);
    if (scanf("%d", &n1) != 1 || n1 < 1 || n1 > MAX_HALF_CAPACITY)
    {
        fprintf(stderr, "Error: Size must be between 1 and %d.\n", MAX_HALF_CAPACITY);
        return EXIT_FAILURE;
    }
    if (!read_array(arr1, n1, "A"))
    {
        fprintf(stderr, "Error: Invalid integer input for Array A.\n");
        return EXIT_FAILURE;
    }

    /* 2. Read Second Array */
    printf("\nEnter size of Array B (1 to %d): ", MAX_HALF_CAPACITY);
    if (scanf("%d", &n2) != 1 || n2 < 1 || n2 > MAX_HALF_CAPACITY)
    {
        fprintf(stderr, "Error: Size must be between 1 and %d.\n", MAX_HALF_CAPACITY);
        return EXIT_FAILURE;
    }
    if (!read_array(arr2, n2, "B"))
    {
        fprintf(stderr, "Error: Invalid integer input for Array B.\n");
        return EXIT_FAILURE;
    }

    /* 3. Sort Both Arrays via Insertion Sort */
    printf("\n--- Stage 1: Insertion Sort ---\n");
    print_array("Array A (Unsorted)", arr1, n1);
    OpStats stats_a = insertion_sort(arr1, n1);
    print_array("Array A (Sorted)  ", arr1, n1);
    printf("  -> Comparisons: %lld | Memory Writes: %lld\n\n", stats_a.comparisons, stats_a.writes);

    print_array("Array B (Unsorted)", arr2, n2);
    OpStats stats_b = insertion_sort(arr2, n2);
    print_array("Array B (Sorted)  ", arr2, n2);
    printf("  -> Comparisons: %lld | Memory Writes: %lld\n", stats_b.comparisons, stats_b.writes);

    /* 4. Merge Both Sorted Arrays in O(N + M) Time */
    printf("\n--- Stage 2: Two-Pointer Linear Merge ---\n");
    OpStats stats_merge = merge_sorted_arrays(arr1, n1, arr2, n2, merged);
    print_array("Merged Result     ", merged, n1 + n2);
    printf("  -> Comparisons: %lld | Memory Writes: %lld\n", stats_merge.comparisons, stats_merge.writes);

    return EXIT_SUCCESS;
}

/* Reads n integers into arr. Returns 1 on success, 0 on failure. */
int read_array(int arr[], int n, const char *name)
{
    printf("Enter %d integer(s) for Array %s:\n", n, name);
    for (int i = 0; i < n; i++)
    {
        printf("  %s[%d] = ", name, i);
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

/*
 * Shift-Based Insertion Sort:
 * O(N) best case on sorted data, O(N^2) worst case.
 */
OpStats insertion_sort(int arr[], int n)
{
    OpStats stats = {0, 0};

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            stats.comparisons++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                stats.writes++;
                j--;
            }
            else
            {
                break;
            }
        }

        if (j + 1 != i)
        {
            arr[j + 1] = key;
            stats.writes++;
        }
    }

    return stats;
}

/*
 * Stable Two-Pointer Merge of two sorted arrays into dest.
 * Time Complexity: O(n1 + n2).
 */
OpStats merge_sorted_arrays(const int a[], int n1, const int b[], int n2, int dest[])
{
    OpStats stats = {0, 0};
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        stats.comparisons++;
        if (a[i] <= b[j])
        {
            dest[k++] = a[i++];
        }
        else
        {
            dest[k++] = b[j++];
        }
        stats.writes++;
    }

    while (i < n1)
    {
        dest[k++] = a[i++];
        stats.writes++;
    }

    while (j < n2)
    {
        dest[k++] = b[j++];
        stats.writes++;
    }

    return stats;
}

// Expected output:

/*
Enter size of Array A (1 to 50): 3
Enter 3 integer(s) for Array A:
  A[0] = 64
  A[1] = 11
  A[2] = 22

Enter size of Array B (1 to 50): 3
Enter 3 integer(s) for Array B:
  B[0] = 90
  B[1] = 12
  B[2] = 25

--- Stage 1: Insertion Sort ---
Array A (Unsorted): [64, 11, 22]
Array A (Sorted)  : [11, 22, 64]
  -> Comparisons: 3 | Memory Writes: 4

Array B (Unsorted): [90, 12, 25]
Array B (Sorted)  : [12, 25, 90]
  -> Comparisons: 3 | Memory Writes: 4

--- Stage 2: Two-Pointer Linear Merge ---
Merged Result     : [11, 12, 22, 25, 64, 90]
  -> Comparisons: 4 | Memory Writes: 6
*/