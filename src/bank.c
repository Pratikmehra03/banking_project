#include <stdio.h>
#include <string.h>
#include "bank.h"

/* find account index by account number, -1 if not found */
int findAccount(Account accounts[], int count, int accNo) {
    for (int i = 0; i < count; i++)
        if (accounts[i].accountNumber == accNo)
            return i;
    return -1;
}

/* create new account with simple numbering */
void createAccount(Account accounts[], int *count, char name[]) {
    accounts[*count].accountNumber = 1000 + *count;
    strcpy(accounts[*count].name, name);
    accounts[*count].balance = 0;
    (*count)++;
}

/* deposit amount into account */
void deposit(Account accounts[], int count, int accNo, float amount) {
    int index = findAccount(accounts, count, accNo);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }
    accounts[index].balance += amount;
}

/* withdraw amount after checking balance */
void withdraw(Account accounts[], int count, int accNo, float amount) {
    int index = findAccount(accounts, count, accNo);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }
    if (accounts[index].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }
    accounts[index].balance -= amount;
}

/* print account details to console */
void showBalance(Account accounts[], int count, int accNo) {
    int index = findAccount(accounts, count, accNo);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }
    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Name: %s\n", accounts[index].name);
    printf("Balance: %.2f\n", accounts[index].balance);
}

/* file handling */
/* save all accounts to accounts.txt (overwrite) */
void saveAccounts(Account accounts[], int count) {
    FILE *fp = fopen("accounts.txt", "w");
    if (!fp) {
        printf("Could not save data.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        /* write: accNo name balance */
        fprintf(fp, "%d %s %.2f\n",
                accounts[i].accountNumber,
                accounts[i].name,
                accounts[i].balance);
    }

    fclose(fp);
}

/* load accounts from accounts.txt into array, return count loaded */
int loadAccounts(Account accounts[]) {
    FILE *fp = fopen("accounts.txt", "r");
    if (!fp)
        return 0; /* file not present yet */

    int count = 0;

    while (fscanf(fp, "%d %s %f",
                  &accounts[count].accountNumber,
                  accounts[count].name,
                  &accounts[count].balance) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}
