// Program 062 — In-Place Array Reversal and Cyclic Rotation

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

/* Function Prototypes */
void print_array(const int arr[], int n);
void copy_array(const int src[], int dest[], int n);
void reverse_range(int arr[], int left, int right);
void rotate_left(int arr[], int n, int k);
void rotate_right(int arr[], int n, int k);

int main(void)
{
    int n = 0;
    int k = 0;
    int arr[MAX_CAPACITY];
    int temp_arr[MAX_CAPACITY];

    /* 1. Read and validate N */
    printf("Enter number of elements N (1 <= N <= %d): ", MAX_CAPACITY);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CAPACITY)
    {
        fprintf(stderr, "Error: N must be a valid integer between 1 and %d.\n", MAX_CAPACITY);
        return EXIT_FAILURE;
    }

    /* 2. Read N integers into arr */
    printf("Enter %d integer(s):\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("  arr[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1)
        {
            fprintf(stderr, "Error: Invalid integer input.\n");
            return EXIT_FAILURE;
        }
    }

    /* 3. Read rotation count k */
    printf("Enter rotation steps k: ");
    if (scanf("%d", &k) != 1)
    {
        fprintf(stderr, "Error: Invalid input for rotation steps k.\n");
        return EXIT_FAILURE;
    }

    printf("\n--- In-Place Array Mutation Demonstrations ---\n");

    /* Demo 1: Full Array Reversal */
    copy_array(arr, temp_arr, n);
    printf("\n1. Full Array Reversal:\n");
    printf("  Before: ");
    print_array(temp_arr, n);
    reverse_range(temp_arr, 0, n - 1);
    printf("  After : ");
    print_array(temp_arr, n);

    /* Demo 2: Left Rotation by k */
    copy_array(arr, temp_arr, n);
    printf("\n2. Left Rotation by k = %d:\n", k);
    printf("  Before: ");
    print_array(temp_arr, n);
    rotate_left(temp_arr, n, k);
    printf("  After : ");
    print_array(temp_arr, n);

    /* Demo 3: Right Rotation by k */
    copy_array(arr, temp_arr, n);
    printf("\n3. Right Rotation by k = %d:\n", k);
    printf("  Before: ");
    print_array(temp_arr, n);
    rotate_right(temp_arr, n, k);
    printf("  After : ");
    print_array(temp_arr, n);

    return EXIT_SUCCESS;
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

/* Copies n elements from src into dest. */
void copy_array(const int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

/* Reverses elements in the inclusive range [left, right] in-place. */
void reverse_range(int arr[], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

/* Rotates the array to the left by k positions in O(N) time and O(1) auxiliary space. */
void rotate_left(int arr[], int n, int k)
{
    if (n <= 1)
        return;

    k = ((k % n) + n) % n;
    if (k == 0)
        return;

    reverse_range(arr, 0, k - 1);
    reverse_range(arr, k, n - 1);
    reverse_range(arr, 0, n - 1);
}

/* Rotates the array to the right by k positions in O(N) time and O(1) auxiliary space. */
void rotate_right(int arr[], int n, int k)
{
    if (n <= 1)
        return;

    k = ((k % n) + n) % n;
    if (k == 0)
        return;

    reverse_range(arr, 0, n - 1);
    reverse_range(arr, 0, k - 1);
    reverse_range(arr, k, n - 1);
}

// Expected output:

/*
Enter number of elements N (1 <= N <= 100): 5
Enter 5 integer(s):
  arr[0] = 10
  arr[1] = 20
  arr[2] = 30
  arr[3] = 40
  arr[4] = 50
Enter rotation steps k: 2

--- In-Place Array Mutation Demonstrations ---

1. Full Array Reversal:
  Before: [10, 20, 30, 40, 50]
  After : [50, 40, 30, 20, 10]

2. Left Rotation by k = 2:
  Before: [10, 20, 30, 40, 50]
  After : [30, 40, 50, 10, 20]

3. Right Rotation by k = 2:
  Before: [10, 20, 30, 40, 50]
  After : [40, 50, 10, 20, 30]
*/