#include <stdio.h>
#include <string.h>
#include "bank.h"

/* create a new account */
void createAccount(struct Account *acc) {
    printf("Enter Account ID: ");
    scanf("%d", &acc->id);

    printf("Enter Your Name: ");
    scanf("%49s", acc->name);

    acc->balance = 0;
    printf("Account Created Successfully!\n");
}

/* add money to balance */
void deposit(struct Account *acc, float amount) {
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    acc->balance += amount;
    printf("Amount Deposited Successfully!\n");
}

/* withdraw money if balance is enough */
void withdraw(struct Account *acc, float amount) {
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    if (amount > acc->balance) {
        printf("Insufficient Balance!\n");
        return;
    }
    acc->balance -= amount;
    printf("Withdrawal Successful!\n");
}

/* show account details */
void showBalance(struct Account acc) {
    printf("\n--- Account Details ---\n");
    printf("ID: %d\n", acc.id);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}
