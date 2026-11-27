// Matrix I/O, Row/Column Sums, and Row-Major Memory Inspection

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 20

/* Function Prototypes */
int read_matrix(int mat[][MAX_DIM], int rows, int cols);
void compute_sums(const int mat[][MAX_DIM], int rows, int cols,
                  long long row_sums[], long long col_sums[], long long *grand_total);
void print_matrix_table(const int mat[][MAX_DIM], int rows, int cols,
                        const long long row_sums[], const long long col_sums[],
                        long long grand_total);
void inspect_row_major_memory(const int mat[][MAX_DIM], int rows, int cols);

int main(void)
{
    int rows = 0;
    int cols = 0;
    int matrix[MAX_DIM][MAX_DIM] = {{0}};

    printf("Enter number of rows and columns (1 to %d): ", MAX_DIM);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > MAX_DIM || cols < 1 || cols > MAX_DIM)
    {
        fprintf(stderr, "Error: Rows and columns must be integers between 1 and %d.\n", MAX_DIM);
        return EXIT_FAILURE;
    }

    printf("\nEnter %d x %d matrix elements:\n", rows, cols);
    if (!read_matrix(matrix, rows, cols))
    {
        fprintf(stderr, "Error: Invalid integer input encountered.\n");
        return EXIT_FAILURE;
    }

    long long row_sums[MAX_DIM] = {0};
    long long col_sums[MAX_DIM] = {0};
    long long grand_total = 0;

    compute_sums(matrix, rows, cols, row_sums, col_sums, &grand_total);
    print_matrix_table(matrix, rows, cols, row_sums, col_sums, grand_total);
    inspect_row_major_memory(matrix, rows, cols);

    return EXIT_SUCCESS;
}

/* Reads rows x cols integers into mat. Returns 1 on success, 0 on failure. */
int read_matrix(int mat[][MAX_DIM], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("  mat[%d][%d] = ", i, j);
            if (scanf("%d", &mat[i][j]) != 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

/* Computes row sums, column sums, and grand total in a single cache-friendly pass. */
void compute_sums(const int mat[][MAX_DIM], int rows, int cols,
                  long long row_sums[], long long col_sums[], long long *grand_total)
{
    long long total = 0;

    for (int i = 0; i < rows; i++)
    {
        row_sums[i] = 0;
        for (int j = 0; j < cols; j++)
        {
            int val = mat[i][j];
            row_sums[i] += val;
            col_sums[j] += val;
            total += val;
        }
    }

    *grand_total = total;
}

/* Displays the formatted matrix with aligned row sums and column sums. */
void print_matrix_table(const int mat[][MAX_DIM], int rows, int cols,
                        const long long row_sums[], const long long col_sums[],
                        long long grand_total)
{
    printf("\n--- Matrix & Marginal Sums ---\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%6d ", mat[i][j]);
        }
        printf(" | Row %d Sum: %lld\n", i, row_sums[i]);
    }

    for (int j = 0; j < cols; j++)
    {
        printf("-------");
    }
    printf("-+------------------\n");

    for (int j = 0; j < cols; j++)
    {
        printf("%6lld ", col_sums[j]);
    }
    printf(" | Total: %lld\n", grand_total);
}

/* Inspects physical row-major memory addresses and stride offsets. */
void inspect_row_major_memory(const int mat[][MAX_DIM], int rows, int cols)
{
    const int *base_ptr = &mat[0][0];

    printf("\n--- Row-Major Memory Layout Telemetry ---\n");
    printf("Base Address (&mat[0][0]) : %p\n", (const void *)base_ptr);
    printf("Physical Row Stride       : %d ints (%zu bytes)\n\n",
           MAX_DIM, (size_t)MAX_DIM * sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int physical_offset = (i * MAX_DIM) + j;
            int logical_index = (i * cols) + j;
            printf("  mat[%d][%d] = %-5d | Addr: %p | Logical #%d | Stride Offset: +%d ints (%zu B)\n",
                   i, j,
                   *(base_ptr + physical_offset),
                   (const void *)&mat[i][j],
                   logical_index,
                   physical_offset,
                   (size_t)physical_offset * sizeof(int));
        }
    }
}

// Expected output:

/*
Enter number of rows and columns (1 to 20): 2 3

Enter 2 x 3 matrix elements:
  mat[0][0] = 10
  mat[0][1] = 20
  mat[0][2] = 30
  mat[1][0] = 40
  mat[1][1] = 50
  mat[1][2] = 60

--- Matrix & Marginal Sums ---
    10     20     30  | Row 0 Sum: 60
    40     50     60  | Row 1 Sum: 150
----------------------+------------------
    50     70     90  | Total: 210

--- Row-Major Memory Layout Telemetry ---
Base Address (&mat[0][0]) : 000000B4A17FF6D0
Physical Row Stride       : 20 ints (80 bytes)

  mat[0][0] = 10    | Addr: 000000B4A17FF6D0 | Logical #0 | Stride Offset: +0 ints (0 B)
  mat[0][1] = 20    | Addr: 000000B4A17FF6D4 | Logical #1 | Stride Offset: +1 ints (4 B)
  mat[0][2] = 30    | Addr: 000000B4A17FF6D8 | Logical #2 | Stride Offset: +2 ints (8 B)
  mat[1][0] = 40    | Addr: 000000B4A17FF720 | Logical #3 | Stride Offset: +20 ints (80 B)
  mat[1][1] = 50    | Addr: 000000B4A17FF724 | Logical #4 | Stride Offset: +21 ints (84 B)
  mat[1][2] = 60    | Addr: 000000B4A17FF728 | Logical #5 | Stride Offset: +22 ints (88 B)
*/