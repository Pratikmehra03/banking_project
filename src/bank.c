#include <stdio.h>
#include <string.h>
#include "bank.h"

void createAccount(struct Account *acc) {
    printf("Enter Account ID: ");
    scanf("%d", &acc->id);

    printf("Enter Your Name: ");
    scanf("%s", acc->name);

    acc->balance = 0;
    printf("Account Created Successfully!\n");
}

void deposit(struct Account *acc, float amount) {
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    acc->balance += amount;
    printf("Amount Deposited Successfully!\n");
}

void withdraw(struct Account *acc, float amount) {
    if (amount > acc->balance) {
        printf("Insufficient Balance!\n");
        return;
    }
    acc->balance -= amount;
    printf("Withdrawal Successful!\n");
}

void showBalance(struct Account acc) {
    printf("\n--- Account Details ---\n");
    printf("ID: %d\n", acc.id);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}
