// Elle Nguyen, CIS 2107, Section 4
// 02/12/23 Lab 3 ATM Machine
// Write a C Program for an ATM machine by implementing functions.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Header-file for boolean data-type
#include <math.h>

// function prototypes
// initialize as pointers to update in main function
void balance(int *currentBalance);
void cashWithdrawal(int *currentBalance, int *withdraw, int *numTransaction);
void cashDeposition(int *currentBalance, int *deposit, int *numTransaction);
void quit(int *numTransaction);
void receipt(void);

// function main begins program execution
int main(void) {
    int PIN;
    int attempts = 1;
    unsigned int currentBalance = 5000;
    unsigned int withdraw = 0;
    unsigned int deposit = 0;
    int option;
    int numTransaction = 0;
    bool CONTINUE = true;

    // output welcoming message
    puts("Welcome to \"TEMPLE ATM MACHINE\"");

    // prompt user for PIN
    printf("%s", "\n\tPlease enter your PIN number: ");
    scanf("%d", &PIN);

    // check if the PIN number is 3014
    while (PIN != 3014 || PIN <= 0) {
        puts("\tThis is an incorrect PIN number.");

        // within 3 attempts
        // prompt user for PIN again
        if (attempts < 3) {
            ++attempts; // increment attempts
            printf("%s", "\n\tPlease re-enter your PIN number: ");
            scanf("%d", &PIN);
        } 
        
        // more than 3 attempts
        // output closing message & exit the program
        else {
            puts("\nYou have entered incorrect PIN number over 3 times.");
            puts("Thank you for using \"TEMPLE ATM MACHINE\"");
            exit(1);
        }
    }
    
    // run the program when user enters the right PIN number
    puts("\nYou have successfully logged into your bank account.");

    // run the program until user chooses to quit
    while (CONTINUE) {
        puts("\n\tThe ATM transactions are: \n\t1. Balance \n\t2. Cash withdrawal \n\t3. Cash deposition \n\t4. Quit");

        // prompt user for transaction
        printf("%s", "\nPlease select your transaction: ");
        scanf("%d", &option);

        // determine the transaction
        switch (option) {
            // balance
            case 1:
                balance(&currentBalance);
                break; // done with transactions

            // cash withdrawal
            case 2:
                cashWithdrawal(&currentBalance, &withdraw, &numTransaction);
                break; // done with transactions

            // cash deposition
            case 3:
                cashDeposition(&currentBalance, &deposit, &numTransaction);
                break; // done with transactions

            // quit
            case 4:
                quit(&numTransaction);
                CONTINUE = false;   // end while loop
                break;  // done with transactions

            // other prompts
            default:
                puts("\nPlease select your transaction.");
        }
    }
}

// output the current balance
void balance(int *currentBalance) {
    printf("Your current balance is: $%u\n", *currentBalance);
}

// withdraw at most $1000/day
void cashWithdrawal(int *currentBalance, int *withdraw, int *numTransaction) {
    // declare variable
    double amount;

    // output option
    puts("\nYou have chosen cash withdrawal.");
    puts("Please be aware that withdrawal limit is $1000 a day and there are no coins.");

    // prompt user for amount
    printf("%s", "\nPlease enter the amount in multiples of 20s to withdraw: ");
    scanf("%lf", &amount);

    // check if amount goes over the limit
    if ((int) *withdraw + amount > 1000) {
        // output error message
        puts("You have reached the withdrawal limit.");
        exit(1);    // not perform transaction and exit the program
    }

    // check if amount is negative or a decimal
    else if (amount <= 0 || trunc(amount) != amount) {
        // output error message
        puts("This is not a valid withdrawal amount.");
    }

    // check if amount is multiple of 20s
    else if ((int) amount % 20 != 0) {
        // output error message
        puts("This is not a valid withdrawal amount.");
    }
    
    // valid withdrawal
    else {
        // calculate amount withdrawn and prompt for receipt
        *withdraw += amount;
        *currentBalance -= amount;
        ++*numTransaction;
        receipt();

        // output receipt
        printf("\nYou have withdrawn $%u in total.\n", *withdraw);
        printf("You can still withdraw $%u left.\n", 1000 - (int) *withdraw);
    }
}

// deposit at most $10,000
void cashDeposition(int *currentBalance, int *deposit, int *numTransaction) {
    // declare variable
    double amount;

    // output option
    puts("\nYou have chosen cash deposition.");
    puts("Please be aware that deposition limit is $10,000 a day and there are no coins.");

    // prompt user for amount
    printf("%s", "\nPlease enter the amount to deposit: ");
    scanf("%lf", &amount);

    // check if amount goes over the limit
    if ((int) *deposit + amount > 10000) {
        // output error message
        puts("You have reached the deposit limit.");
        exit(1);    // not perform transaction and exit the program
    }

    // check if amount is negative or a decimal
    else if (amount <= 0 || trunc(amount) != amount) {
        // output error message
        puts("This is not a valid deposit amount.");
    }

    // valid deposit
    else {
        // calculate amount deposited and prompt for receipt
        *deposit += amount;
        *currentBalance += amount;
        ++*numTransaction;
        receipt();

        // output receipt
        printf("\nYou have deposited $%u successfully.\n", *deposit);
        printf("You can still deposit $%u left.\n", 10000 - (int) *deposit);
    }
}

// output Thank you message and receipts
void quit(int *numTransaction) {
    printf("\nYou have completed %u transaction(s).\n", *numTransaction);
    receipt();
    puts("\nThank you for using \"TEMPLE ATM MACHINE\"");
    exit(0);
}

// output receipt
void receipt() {
    // declare variable
    int in;

    // prompt user to print receipt
    puts("Would you like a receipt? \n\t1. Yes \n\t2. No");
    scanf("%d", &in);

    // if user enters 1, print receipt
    if (in == 1) {
        puts("Receipt printing...");
    }
}