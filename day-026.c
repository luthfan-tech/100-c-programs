//Program 026 — Grade Calculator (Nested vs Chained if-else)

#include <stdio.h>

int main(void) {
    int score = 0;

    printf("Enter score (0 - 100): ");
    if (scanf("%d", &score) != 1 || score < 0 || score > 100) {
        printf("Error: Please enter an integer between 0 and 100.\n");
        return 1;
    }

    char grade = 'F';
    const char *remark = "";

    /* Chained if-else: clean, readable, flat indentation */
    if (score >= 90) {
        grade = 'A';
        remark = "Outstanding";
    } else if (score >= 80) {
        grade = 'B';
        remark = "Very Good";
    } else if (score >= 70) {
        grade = 'C';
        remark = "Good";
    } else if (score >= 60) {
        grade = 'D';
        remark = "Satisfactory";
    } else {
        grade = 'F';
        remark = "Needs Improvement";
    }

    printf("\n--- Grade Report ---\n");
    printf("Score:  %d/100\n", score);
    printf("Grade:  %c\n", grade);
    printf("Remark: %s\n", remark);

    return 0;
}
//Example Input/Output:

/*
Enter score (0 - 100): 84

--- Grade Report ---
Score:  84/100
Grade:  B
Remark: Very Good
*/