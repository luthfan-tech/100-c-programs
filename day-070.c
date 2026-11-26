// Program 070 — Dynamic 1D Array & Buffer Analytics Workbench

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    int *data;       /* Contiguous heap buffer pointer */
    size_t size;     /* Active elements count */
    size_t capacity; /* Allocated capacity in elements */
    bool is_sorted;  /* State invariant flag for search optimization */
} ArrayBuffer;

/* --- Function Prototypes --- */
ArrayBuffer *create_buffer(size_t initial_capacity);
void destroy_buffer(ArrayBuffer *buf);
bool ensure_capacity(ArrayBuffer *buf, size_t min_capacity);
void push_back(ArrayBuffer *buf, int val);
void insert_at(ArrayBuffer *buf, size_t index, int val);
void delete_at(ArrayBuffer *buf, size_t index);
void fill_random(ArrayBuffer *buf, size_t count, int min_val, int max_val);
void reverse_buffer(ArrayBuffer *buf);
void clear_buffer(ArrayBuffer *buf);
int cmp_asc(const void *a, const void *b);
void sort_buffer(ArrayBuffer *buf);
void search_value(const ArrayBuffer *buf, int target);
double custom_sqrt(double x);
void compute_analytics(const ArrayBuffer *buf);
void inspect_buffer(const ArrayBuffer *buf, bool show_addresses);
void clear_input_buffer(void);
void print_menu(void);

int main(void)
{
    srand((unsigned int)time(NULL));
    ArrayBuffer *buf = create_buffer(8);
    if (!buf)
    {
        fprintf(stderr, "Fatal: Failed to initialize heap buffer.\n");
        return EXIT_FAILURE;
    }

    /* Seed initial sample data */
    int initial[] = {42, 17, 89, 23, 56};
    for (size_t i = 0; i < 5; i++)
    {
        push_back(buf, initial[i]);
    }

    printf("=== 1D Dynamic Array & Buffer Analytics Workbench ===\n");
    inspect_buffer(buf, false);

    int choice = 0;
    while (1)
    {
        print_menu();
        if (scanf("%d", &choice) != 1)
        {
            clear_input_buffer();
            printf("[Error] Invalid input. Enter a menu number.\n");
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        int val = 0, min_v = 0, max_v = 0;
        size_t idx = 0, count = 0;

        switch (choice)
        {
        case 1:
            printf("Enter integer to append: ");
            if (scanf("%d", &val) == 1)
            {
                push_back(buf, val);
                inspect_buffer(buf, false);
            }
            else
            {
                clear_input_buffer();
                printf("[Error] Invalid integer.\n");
            }
            break;

        case 2:
            printf("Enter index and value (e.g., 2 99): ");
            if (scanf("%zu %d", &idx, &val) == 2)
            {
                insert_at(buf, idx, val);
                inspect_buffer(buf, false);
            }
            else
            {
                clear_input_buffer();
                printf("[Error] Invalid index or value.\n");
            }
            break;

        case 3:
            printf("Enter index to delete: ");
            if (scanf("%zu", &idx) == 1)
            {
                delete_at(buf, idx);
                inspect_buffer(buf, false);
            }
            else
            {
                clear_input_buffer();
                printf("[Error] Invalid index.\n");
            }
            break;

        case 4:
            printf("Enter value to search: ");
            if (scanf("%d", &val) == 1)
            {
                search_value(buf, val);
            }
            else
            {
                clear_input_buffer();
                printf("[Error] Invalid integer.\n");
            }
            break;

        case 5:
            printf("Enter count, min, max (e.g., 10 1 100): ");
            if (scanf("%zu %d %d", &count, &min_v, &max_v) == 3 && count > 0 && min_v <= max_v)
            {
                fill_random(buf, count, min_v, max_v);
                inspect_buffer(buf, false);
            }
            else
            {
                clear_input_buffer();
                printf("[Error] Invalid count or range (require count > 0 and min <= max).\n");
            }
            break;

        case 6:
            reverse_buffer(buf);
            inspect_buffer(buf, false);
            break;

        case 7:
            sort_buffer(buf);
            inspect_buffer(buf, false);
            break;

        case 8:
            inspect_buffer(buf, false);
            break;

        case 9:
            compute_analytics(buf);
            break;

        case 10:
            inspect_buffer(buf, true);
            break;

        case 11:
            clear_buffer(buf);
            printf("[Info] Buffer cleared (capacity retained).\n");
            inspect_buffer(buf, false);
            break;

        default:
            printf("[Error] Unknown option '%d'. Select between 0 and 11.\n", choice);
            break;
        }
    }

    destroy_buffer(buf);
    printf("Heap memory freed cleanly. Goodbye!\n");
    return EXIT_SUCCESS;
}

/* --- Buffer Lifecycle Management --- */

ArrayBuffer *create_buffer(size_t initial_capacity)
{
    if (initial_capacity == 0)
    {
        initial_capacity = 4;
    }
    ArrayBuffer *buf = (ArrayBuffer *)malloc(sizeof(ArrayBuffer));
    if (!buf)
    {
        return NULL;
    }

    buf->data = (int *)malloc(initial_capacity * sizeof(int));
    if (!buf->data)
    {
        free(buf);
        return NULL;
    }

    buf->size = 0;
    buf->capacity = initial_capacity;
    buf->is_sorted = true;
    return buf;
}

void destroy_buffer(ArrayBuffer *buf)
{
    if (buf)
    {
        free(buf->data);
        free(buf);
    }
}

bool ensure_capacity(ArrayBuffer *buf, size_t min_capacity)
{
    if (buf->capacity >= min_capacity)
    {
        return true;
    }

    size_t new_cap = (buf->capacity == 0) ? 4 : buf->capacity;
    while (new_cap < min_capacity)
    {
        if (new_cap > SIZE_MAX / 2)
        {
            return false;
        }
        new_cap *= 2;
    }

    if (new_cap > SIZE_MAX / sizeof(int))
    {
        return false;
    }

    int *new_data = (int *)realloc(buf->data, new_cap * sizeof(int));
    if (!new_data)
    {
        return false;
    }

    buf->data = new_data;
    buf->capacity = new_cap;
    return true;
}

/* --- Data Mutation Operations --- */

void push_back(ArrayBuffer *buf, int val)
{
    if (!ensure_capacity(buf, buf->size + 1))
    {
        printf("[Error] Memory allocation failed.\n");
        return;
    }
    if (buf->size > 0 && val < buf->data[buf->size - 1])
    {
        buf->is_sorted = false;
    }
    buf->data[buf->size++] = val;
}

void insert_at(ArrayBuffer *buf, size_t index, int val)
{
    if (index > buf->size)
    {
        printf("[Error] Index out of bounds (valid: 0 to %zu).\n", buf->size);
        return;
    }
    if (!ensure_capacity(buf, buf->size + 1))
    {
        printf("[Error] Memory allocation failed.\n");
        return;
    }

    if (index < buf->size)
    {
        memmove(&buf->data[index + 1], &buf->data[index], (buf->size - index) * sizeof(int));
    }
    buf->data[index] = val;
    buf->size++;
    if (buf->size > 1)
    {
        buf->is_sorted = false;
    }
}

void delete_at(ArrayBuffer *buf, size_t index)
{
    if (index >= buf->size)
    {
        printf("[Error] Index out of bounds.\n");
        return;
    }
    if (index < buf->size - 1)
    {
        memmove(&buf->data[index], &buf->data[index + 1], (buf->size - index - 1) * sizeof(int));
    }
    buf->size--;
    if (buf->size <= 1)
    {
        buf->is_sorted = true;
    }
}

void fill_random(ArrayBuffer *buf, size_t count, int min_val, int max_val)
{
    if (!ensure_capacity(buf, count))
    {
        printf("[Error] Memory allocation failed.\n");
        return;
    }
    buf->size = count;
    unsigned int span = (unsigned int)(max_val - min_val) + 1U;
    for (size_t i = 0; i < count; i++)
    {
        buf->data[i] = min_val + (int)((unsigned int)rand() % span);
    }
    buf->is_sorted = (count <= 1);
}

void reverse_buffer(ArrayBuffer *buf)
{
    for (size_t i = 0; i < buf->size / 2; i++)
    {
        int temp = buf->data[i];
        buf->data[i] = buf->data[buf->size - 1 - i];
        buf->data[buf->size - 1 - i] = temp;
    }
    if (buf->size > 1)
    {
        buf->is_sorted = false;
    }
}

void clear_buffer(ArrayBuffer *buf)
{
    buf->size = 0;
    buf->is_sorted = true;
}

/* --- Algorithms & Statistical Analytics --- */

int cmp_asc(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

void sort_buffer(ArrayBuffer *buf)
{
    if (buf->size > 1)
    {
        qsort(buf->data, buf->size, sizeof(int), cmp_asc);
    }
    buf->is_sorted = true;
    printf("[Info] Buffer sorted in O(N log N) time.\n");
}

void search_value(const ArrayBuffer *buf, int target)
{
    if (buf->size == 0)
    {
        printf("[Info] Buffer is empty.\n");
        return;
    }
    if (buf->is_sorted)
    {
        int *item = (int *)bsearch(&target, buf->data, buf->size, sizeof(int), cmp_asc);
        if (item)
        {
            printf("[Binary Search O(log N)] Found %d at index %td (Address: %p)\n",
                   target, item - buf->data, (void *)item);
        }
        else
        {
            printf("[Binary Search O(log N)] Value %d not found.\n", target);
        }
    }
    else
    {
        for (size_t i = 0; i < buf->size; i++)
        {
            if (buf->data[i] == target)
            {
                printf("[Linear Search O(N)] Found %d at index %zu (Address: %p)\n",
                       target, i, (void *)&buf->data[i]);
                return;
            }
        }
        printf("[Linear Search O(N)] Value %d not found.\n", target);
    }
}

/* Newton-Raphson square root (avoids <math.h> / -lm dependency). */
double custom_sqrt(double x)
{
    if (x <= 0.0)
    {
        return 0.0;
    }
    double guess = x;
    for (int i = 0; i < 40; i++)
    {
        guess = 0.5 * (guess + x / guess);
    }
    return guess;
}

void compute_analytics(const ArrayBuffer *buf)
{
    if (buf->size == 0)
    {
        printf("[Analytics] Buffer is empty. Add elements first.\n");
        return;
    }

    long long sum = 0;
    int min_val = buf->data[0];
    int max_val = buf->data[0];

    for (size_t i = 0; i < buf->size; i++)
    {
        int v = buf->data[i];
        sum += v;
        if (v < min_val)
            min_val = v;
        if (v > max_val)
            max_val = v;
    }

    double mean = (double)sum / (double)buf->size;
    double variance_sum = 0.0;
    for (size_t i = 0; i < buf->size; i++)
    {
        double diff = (double)buf->data[i] - mean;
        variance_sum += diff * diff;
    }
    double std_dev = custom_sqrt(variance_sum / (double)buf->size);

    /* Copy buffer to compute median without altering original order */
    double median = 0.0;
    int *temp = (int *)malloc(buf->size * sizeof(int));
    if (temp)
    {
        memcpy(temp, buf->data, buf->size * sizeof(int));
        qsort(temp, buf->size, sizeof(int), cmp_asc);
        if (buf->size % 2 == 0)
        {
            median = ((double)temp[buf->size / 2 - 1] + (double)temp[buf->size / 2]) / 2.0;
        }
        else
        {
            median = (double)temp[buf->size / 2];
        }
        free(temp);
    }

    printf("\n=== BUFFER STATISTICAL ANALYTICS ===\n");
    printf("Count      : %zu element(s)\n", buf->size);
    printf("Sum        : %lld\n", sum);
    printf("Min / Max  : %d / %d (Span: %lld)\n", min_val, max_val, (long long)max_val - min_val);
    printf("Mean       : %.2f\n", mean);
    printf("Median     : %.2f\n", median);
    printf("Std Dev    : %.2f\n", std_dev);
    printf("====================================\n");
}

void inspect_buffer(const ArrayBuffer *buf, bool show_addresses)
{
    size_t used_bytes = buf->size * sizeof(int);
    size_t alloc_bytes = buf->capacity * sizeof(int);
    double utilization = (buf->capacity > 0) ? ((double)buf->size / (double)buf->capacity) * 100.0 : 0.0;

    printf("\n--- Buffer State & Memory Telemetry ---\n");
    printf("Size / Capacity : %zu / %zu elements (%.1f%% utilized)\n", buf->size, buf->capacity, utilization);
    printf("Memory Footprint: %zu / %zu bytes (Base Addr: %p)\n", used_bytes, alloc_bytes, (void *)buf->data);
    printf("Sorted Flag     : %s\n", buf->is_sorted ? "YES" : "NO");
    printf("Elements        : [ ");

    for (size_t i = 0; i < buf->size; i++)
    {
        if (show_addresses)
        {
            printf("%d(@%p)", buf->data[i], (void *)&buf->data[i]);
        }
        else
        {
            printf("%d", buf->data[i]);
        }
        if (i < buf->size - 1)
        {
            printf(", ");
        }
    }
    printf(" ]\n---------------------------------------\n");
}

/* --- Interactive CLI Helpers --- */

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* Discard remaining characters */
    }
}

void print_menu(void)
{
    printf("\n[1] Append Value        [5] Fill Random Data    [9] Run Analytics\n");
    printf("[2] Insert at Index     [6] Reverse Buffer      [10] Inspect Memory Addresses\n");
    printf("[3] Delete at Index     [7] Sort (qsort)        [11] Clear Buffer\n");
    printf("[4] Search Value        [8] Print Buffer        [0] Exit\n");
    printf("Select option > ");
}

// Expected output:

/*

=== 1D Dynamic Array & Buffer Analytics Workbench ===

--- Buffer State & Memory Telemetry ---
Size / Capacity : 5 / 8 elements (62.5% utilized)
Memory Footprint: 20 / 32 bytes (Base Addr: 0000021A4B801420)
Sorted Flag     : NO
Elements        : [ 42, 17, 89, 23, 56 ]
---------------------------------------

Select option > 7
[Info] Buffer sorted in O(N log N) time.

--- Buffer State & Memory Telemetry ---
Size / Capacity : 5 / 8 elements (62.5% utilized)
Memory Footprint: 20 / 32 bytes (Base Addr: 0000021A4B801420)
Sorted Flag     : YES
Elements        : [ 17, 23, 42, 56, 89 ]
---------------------------------------

Select option > 4
Enter value to search: 42
[Binary Search O(log N)] Found 42 at index 2 (Address: 0000021A4B801428)

Select option > 9

=== BUFFER STATISTICAL ANALYTICS ===
Count      : 5 element(s)
Sum        : 227
Min / Max  : 17 / 89 (Span: 72)
Mean       : 45.40
Median     : 42.00
Std Dev    : 25.63
====================================

Select option > 0
Heap memory freed cleanly. Goodbye!*/