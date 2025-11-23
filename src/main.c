#include <stdio.h>
#include "bank.h"

/* menu driven program */
int main() {
    struct Account acc;
    int created = 0;
    int choice;
    float amount;

    while (1) {
        printf("\n--- Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Show Balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&acc);
                created = 1;
                break;

            case 2:
                if (!created) {
                    printf("Please create an account first.\n");
                    break;
                }
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&acc, amount);
                break;

            case 3:
                if (!created) {
                    printf("Please create an account first.\n");
                    break;
                }
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&acc, amount);
                break;

            case 4:
                if (!created) {
                    printf("Create an account first.\n");
                    break;
                }
                showBalance(acc);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
