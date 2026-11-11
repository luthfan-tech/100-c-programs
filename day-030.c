//Program 030 — Simple ATM Transaction Simulator

/*
Initialize a starting account balance (e.g. 10000.00).

Display an interactive menu:
1. Check Balance
2. Deposit Money
3. Withdraw Money
4. Exit

Withdrawal amount must be positive.
Multiples of ₹100 or ₹500 only (ATM physical cash canister constraint).
Disallow overdrafts (withdrawal <= balance).
Preserve a mandatory minimum balance (e.g. ₹500).
*/

#include <stdio.h>

#define INITIAL_BALANCE 10000.00
#define MINIMUM_BALANCE 500.00

int main(void) {
    double balance = INITIAL_BALANCE;
    int choice = 0;

    printf("=========================================\n");
    printf("         STATE BANK ATM SIMULATOR        \n");
    printf("=========================================\n");
    printf("1. Check Account Balance\n");
    printf("2. Deposit Funds\n");
    printf("3. Withdraw Cash\n");
    printf("4. Exit Session\n");
    printf("-----------------------------------------\n");
    printf("Enter selection (1-4): ");

    if (scanf("%d", &choice) != 1) {
        printf("Error: Non-numeric input encountered.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("\n[BALANCE ENQUIRY]\n");
            printf("Available Balance: Rs. %.2f\n", balance);
            printf("Minimum Balance:   Rs. %.2f\n", MINIMUM_BALANCE);
            break;

        case 2: {
            double deposit = 0.0;
            printf("\n[DEPOSIT]\n");
            printf("Enter deposit amount: Rs. ");
            if (scanf("%lf", &deposit) != 1 || deposit <= 0.0) {
                printf("Error: Deposit amount must be a positive number.\n");
                return 1;
            }

            balance += deposit;
            printf("Deposit successful.\nUpdated Balance: Rs. %.2f\n", balance);
            break;
        }

        case 3: {
            double withdraw = 0.0;
            printf("\n[WITHDRAWAL]\n");
            printf("Enter withdrawal amount (multiples of Rs. 100): Rs. ");
            if (scanf("%lf", &withdraw) != 1 || withdraw <= 0.0) {
                printf("Error: Withdrawal amount must be a positive number.\n");
                return 1;
            }

            /* Physical ATM dispenser constraints: no coins/paisa, multiples of 100 */
            if (withdraw != (int)withdraw || (int)withdraw % 100 != 0) {
                printf("Error: Notes must be dispensed in whole multiples of Rs. 100.\n");
                return 1;
            }

            /* Overdraft and minimum reserve check */
            if (withdraw > (balance - MINIMUM_BALANCE)) {
                printf("Error: Transaction declined. Maximum allowable withdrawal is Rs. %.2f\n", 
                       balance - MINIMUM_BALANCE);
                printf("(A mandatory minimum balance of Rs. %.2f must remain.)\n", MINIMUM_BALANCE);
                return 1;
            }

            balance -= withdraw;
            printf("Please collect your cash.\nRemaining Balance: Rs. %.2f\n", balance);
            break;
        }

        case 4:
            printf("\nSession ended. Please take your card.\n");
            break;

        default:
            printf("\nError: Unrecognized option '%d'. Valid choices are 1 through 4.\n", choice);
            return 1;
    }

    return 0;
}

//Expected Output Examples:

/*
=========================================
        STATE BANK ATM SIMULATOR        
=========================================
1. Check Account Balance
2. Deposit Funds
3. Withdraw Cash
4. Exit Session
-----------------------------------------
Enter selection (1-4): 3

[WITHDRAWAL]
Enter withdrawal amount (multiples of Rs. 100): Rs. 2500
Please collect your cash.
Remaining Balance: Rs. 7500.00
*/