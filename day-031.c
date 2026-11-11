//Program 031: Print Numbers from 1 to N and N to 1 (Comparing while, for, and do-while)

#include <stdio.h>

int main(void) {
    int n = 0;

    printf("Enter a positive integer (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a valid positive integer greater than 0.\n");
        return 1;
    }

    /* Part 1: Ascending 1 to N using a 'for' loop */
    printf("\n1. Ascending (1 to %d) using 'for':\n   ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /* Part 2: Descending N to 1 using a 'while' loop */
    printf("\n2. Descending (%d down to 1) using 'while':\n   ", n);
    int j = n;
    while (j >= 1) {
        printf("%d ", j);
        j--;
    }
    printf("\n");

    /* Part 3: Ascending 1 to N using a 'do-while' loop */
    printf("\n3. Ascending (1 to %d) using 'do-while':\n   ", n);
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= n);
    printf("\n");

    return 0;
}

//Expected output:

/*
Enter a positive integer (N): 5

1. Ascending (1 to 5) using 'for':
   1 2 3 4 5 

2. Descending (5 down to 1) using 'while':
   5 4 3 2 1 

3. Ascending (1 to 5) using 'do-while':
   1 2 3 4 5
*/