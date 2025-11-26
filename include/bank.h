#ifndef BANK_H
#define BANK_H

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

int findAccount(Account accounts[], int count, int accNo);
void createAccount(Account accounts[], int *count, char name[]);
void deposit(Account accounts[], int count, int accNo, float amount);
void withdraw(Account accounts[], int count, int accNo, float amount);
void showBalance(Account accounts[], int count, int accNo);

/* NEW – file handling */
void saveAccounts(Account accounts[], int count);
int loadAccounts(Account accounts[]);

#endif
