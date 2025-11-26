#include <stdio.h>
#include "bank.h"

int main() {
    Account accounts[100];

    /* load saved accounts from file on start */
    int count = loadAccounts(accounts);

    int choice, acc;
    float amt;
    char name[50];

    while (1) {
        printf("\n--- Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Show Balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            /* get name and create */
            printf("Enter your name: ");
            scanf("%s", name);
            createAccount(accounts, &count, name);

            /* save after creating new account */
            saveAccounts(accounts, count);
            printf("Account created and saved.\n");
        }

        else if (choice == 2) {
            /* deposit flow: ask acc and amount */
            printf("Account Number: ");
            scanf("%d", &acc);
            printf("Amount: ");
            scanf("%f", &amt);
            deposit(accounts, count, acc, amt);

            /* save after deposit */
            saveAccounts(accounts, count);
            printf("Deposit done and saved.\n");
        }

        else if (choice == 3) {
            /* withdraw flow: check account and balance */
            printf("Account Number: ");
            scanf("%d", &acc);
            printf("Amount: ");
            scanf("%f", &amt);
            withdraw(accounts, count, acc, amt);

            /* save after withdraw */
            saveAccounts(accounts, count);
            printf("If successful, changes saved.\n");
        }

        else if (choice == 4) {
            /* display account details */
            printf("Account Number: ");
            scanf("%d", &acc);
            showBalance(accounts, count, acc);
        }

        else if (choice == 5) {
            /* final save before exit */
            saveAccounts(accounts, count);
            printf("Data saved. Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

