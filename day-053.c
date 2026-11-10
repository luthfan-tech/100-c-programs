//Program 053 — Swap Two Numbers: Call by Value vs. Call by Reference

#include <stdio.h>

/* Function Prototypes */
void swap_by_value(int a, int b);
void swap_by_reference(int *a, int *b);

int main(void) {
    int x = 0;
    int y = 0;

    printf("===================================================\n");
    printf("   CALL BY VALUE VS CALL BY REFERENCE DEMONSTRATION \n");
    printf("===================================================\n");

    printf("Enter two integers (x and y): ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Error: Please enter two valid integers.\n");
        return 1;
    }

    printf("\n[Initial State in main]\n");
    printf("  x = %d (Address: %p)\n", x, (void *)&x);
    printf("  y = %d (Address: %p)\n", y, (void *)&y);

    /* --- Experiment 1: Call by Value --- */
    printf("\n---------------------------------------------------\n");
    printf(">> Experiment 1: Calling swap_by_value(x, y)\n");
    printf("---------------------------------------------------\n");
    swap_by_value(x, y);

    printf("\n[Back in main after swap_by_value]:\n");
    printf("  x = %d, y = %d (NO CHANGE - arguments were copied)\n", x, y);

    /* --- Experiment 2: Call by Reference --- */
    printf("\n---------------------------------------------------\n");
    printf(">> Experiment 2: Calling swap_by_reference(&x, &y)\n");
    printf("---------------------------------------------------\n");
    swap_by_reference(&x, &y);

    printf("\n[Back in main after swap_by_reference]:\n");
    printf("  x = %d, y = %d (SUCCESSFULLY SWAPPED via pointers)\n", x, y);
    printf("===================================================\n");

    return 0;
}

/*
 * Call by Value:
 * Receives distinct COPIES of variables.
 * Changes remain confined to this stack frame and are lost upon return.
 */
void swap_by_value(int a, int b) {
    printf("  [Inside swap_by_value - before swap]\n");
    printf("    Local a = %d (Address: %p)\n", a, (void *)&a);
    printf("    Local b = %d (Address: %p)\n", b, (void *)&b);

    int temp = a;
    a = b;
    b = temp;

    printf("  [Inside swap_by_value - after swap]\n");
    printf("    Local a = %d, Local b = %d (Swapped ONLY locally)\n", a, b);
}

/*
 * Call by Reference:
 * Receives the MEMORY ADDRESSES of the caller's variables.
 * Dereferencing (*a, *b) directly mutates the caller's memory slots.
 */
void swap_by_reference(int *a, int *b) {
    printf("  [Inside swap_by_reference]\n");
    printf("    Pointer a holds address: %p -> points to value: %d\n", (void *)a, *a);
    printf("    Pointer b holds address: %p -> points to value: %d\n", (void *)b, *b);

    int temp = *a;
    *a = *b;
    *b = temp;

    printf("  [Memory mutated successfully through dereferencing]\n");
}


//Expected output:

/*
===================================================
   CALL BY VALUE VS CALL BY REFERENCE DEMONSTRATION 
===================================================
Enter two integers (x and y): 45 99

[Initial State in main]
  x = 45 (Address: 00000000005FFEAC)
  y = 99 (Address: 00000000005FFEA8)

---------------------------------------------------
>> Experiment 1: Calling swap_by_value(x, y)
---------------------------------------------------
  [Inside swap_by_value - before swap]
    Local a = 45 (Address: 00000000005FFE80)
    Local b = 99 (Address: 00000000005FFE88)
  [Inside swap_by_value - after swap]
    Local a = 99, Local b = 45 (Swapped ONLY locally)

[Back in main after swap_by_value]:
  x = 45, y = 99 (NO CHANGE - arguments were copied)

---------------------------------------------------
>> Experiment 2: Calling swap_by_reference(&x, &y)
---------------------------------------------------
  [Inside swap_by_reference]
    Pointer a holds address: 00000000005FFEAC -> points to value: 45
    Pointer b holds address: 00000000005FFEA8 -> points to value: 99
  [Memory mutated successfully through dereferencing]

[Back in main after swap_by_reference]:
  x = 99, y = 45 (SUCCESSFULLY SWAPPED via pointers)
===================================================

*/