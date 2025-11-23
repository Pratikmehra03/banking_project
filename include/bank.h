#ifndef BANK_H
#define BANK_H

struct Account {
    int id;
    char name[50];
    float balance;
};

void createAccount(struct Account *acc);
void deposit(struct Account *acc, float amount);
void withdraw(struct Account *acc, float amount);
void showBalance(struct Account acc);

#endif