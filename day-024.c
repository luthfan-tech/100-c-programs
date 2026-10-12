//Program 024 — Vowel or Consonant Checker (Characters and <ctype.h>)

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch = '\0';

    printf("Enter a single character: ");
    if (scanf(" %c", &ch) != 1) {
        printf("Error: Failed to read input.\n");
        return 1;
    }

    /* Verify if the input is an alphabetic letter */
    if (!isalpha((unsigned char)ch)) {
        printf("The character '%c' (ASCII: %d) is not an alphabetic letter.\n", ch, (int)ch);
        return 0;
    }

    /* Normalize to lowercase for simple comparison */
    char lower_ch = (char)tolower((unsigned char)ch);

    if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || 
        lower_ch == 'o' || lower_ch == 'u') {
        printf("The character '%c' (ASCII: %d) is a Vowel.\n", ch, (int)ch);
    } else {
        printf("The character '%c' (ASCII: %d) is a Consonant.\n", ch, (int)ch);
    }

    return 0;
} 

//Expected output:

/*
Enter a single character: E
The character 'E' (ASCII: 69) is a Vowel.

Enter a single character: z
The character 'z' (ASCII: 122) is a Consonant.

Enter a single character: 7
The character '7' (ASCII: 55) is not an alphabetic letter.
*/