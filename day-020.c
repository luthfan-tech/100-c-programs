//Program 020 — Time Converter (Seconds to Hours, Minutes, and Seconds)

#include <stdio.h>

int main(void) {
    int total_seconds = 0;

    printf("Enter the total number of seconds: ");
    if (scanf("%d", &total_seconds) != 1 || total_seconds < 0) {
        printf("Error: Please enter a valid non-negative integer for seconds.\n");
        return 1;
    }

    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

    printf("\n--- Time Breakdown ---\n");
    printf("Verbose:      %d hour(s), %d minute(s), %d second(s)\n", hours, minutes, seconds);
    printf("Clock format: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}

//Expected output:

/*
Enter the total number of seconds: 7543

--- Time Breakdown ---
Verbose:      2 hour(s), 5 minute(s), 43 second(s)
Clock format: 02:05:43
*/