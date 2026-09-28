//Program 010 — Escape Sequences in Action

#include <stdio.h>

int main(void) {
    /* 1. Tabular data using \t */
    printf("Item\t\tPrice\tDiscount\n");
    printf("Apple\t\t$1.50\t10%%\n");
    printf("Banana\t\t$3.00\t15%%\n");
    printf("Notebook\t$5.25\t5%%\n");

    /* 2. Escaping special characters */
    printf("\nQuotes: \"Code every single day.\"\n");
    printf("Path:   C:\\Users\\Dell\\Desktop\\100-c-programs\n");

    return 0;
}

//Expected output:

/*
Item		Price	Discount
Apple		$1.50	10%
Banana		$3.00	15%
Notebook	$5.25	5%

Quotes: "Code every single day."
Path:   C:\Users\Dell\Desktop\100-c-programs
*/