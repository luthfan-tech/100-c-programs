//Program 047 — Palindromic Alphabet and Character Pyramid

#include <stdio.h>

#define MAX_ALPHABET_ROWS 26

int main(void) {
    int rows = 0;

    printf("Enter the number of rows (1 - %d): ", MAX_ALPHABET_ROWS);
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > MAX_ALPHABET_ROWS) {
        printf("Error: Please enter a valid integer between 1 and %d.\n", MAX_ALPHABET_ROWS);
        return 1;
    }

    printf("\n--- Palindromic Character Pyramid (%d Rows) ---\n\n", rows);

    for (int i = 1; i <= rows; i++) {
        /* Phase 1: Leading alignment spaces (2 ASCII spaces per missing column) */
        for (int space = 1; space <= (rows - i); space++) {
            printf("  ");
        }

        /* Phase 2: Ascending branch from 'A' up to row peak */
        for (int j = 0; j < i; j++) {
            printf("%c ", (char)('A' + j));
        }

        /* Phase 3: Descending branch from (peak - 1) down to 'A' */
        for (int j = i - 2; j >= 0; j--) {
            printf("%c ", (char)('A' + j));
        }

        printf("\n");
    }

    printf("\n------------------------------------------------\n");
    return 0;
}

//Expected output

/*
Enter the number of rows (1 - 26): 5

--- Palindromic Character Pyramid (5 Rows) ---

        A 
      A B A 
    A B C B A 
  A B C D C B A 
A B C D E D C B A 

------------------------------------------------
*/