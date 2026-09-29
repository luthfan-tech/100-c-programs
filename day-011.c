//Program 011: Read and Print an Integer

#include <stdio.h>

int main(void) {
    int user_num = 0;

    printf("Enter your favorite number: ");
    if (scanf("%d", &user_num) != 1) {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    printf("You entered: %d\n", user_num);
    printf("Double of your favorite number is: %d\n", user_num * 2);

    return 0;
}

//Expected output:

/*
Enter your favorite number: 7
You entered: 7
Double of your favorite number is: 14
*/