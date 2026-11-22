// Program 065 — Element Frequency Counter and In-Place Duplicate Removal

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

/* Function Prototypes */
int read_array(int arr[], int n);
void print_array(const int arr[], int n);
void print_frequencies(const int arr[], int n);
int remove_duplicates(int arr[], int n);

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

    printf("\n--- Original Array (Length = %d) ---\n", n);
    print_array(arr, n);

    printf("\n--- Element Frequency Report ---\n");
    print_frequencies(arr, n);

    int new_n = remove_duplicates(arr, n);

    printf("\n--- Deduplicated Array (New Length = %d) ---\n", new_n);
    print_array(arr, new_n);

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

/* Counts and displays distinct element frequencies in O(N^2) without mutating arr. */
void print_frequencies(const int arr[], int n)
{
    bool visited[MAX_CAPACITY] = {false};

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = true;
            }
        }

        printf("  %-6d -> %d %s\n", arr[i], count, (count == 1) ? "time" : "times");
    }
}

/*
 * Compacts arr in-place using a write pointer to keep only first occurrences.
 * Time Complexity: O(N^2), Auxiliary Space: O(1). Returns new logical length.
 */
int remove_duplicates(int arr[], int n)
{
    if (n <= 1)
    {
        return n;
    }

    int write_idx = 0;

    for (int read_idx = 0; read_idx < n; read_idx++)
    {
        bool already_seen = false;

        for (int k = 0; k < write_idx; k++)
        {
            if (arr[k] == arr[read_idx])
            {
                already_seen = true;
                break;
            }
        }

        if (!already_seen)
        {
            arr[write_idx++] = arr[read_idx];
        }
    }

    return write_idx;
}

// Expected output:

/*
Enter the number of elements (1 to 100): 7
Enter 7 integer(s):
  arr[0] = 10
  arr[1] = 20
  arr[2] = 10
  arr[3] = 30
  arr[4] = 20
  arr[5] = 40
  arr[6] = 10

--- Original Array (Length = 7) ---
[10, 20, 10, 30, 20, 40, 10]

--- Element Frequency Report ---
  10     -> 3 times
  20     -> 2 times
  30     -> 1 time
  40     -> 1 time

--- Deduplicated Array (New Length = 4) ---
[10, 20, 30, 40]
*/