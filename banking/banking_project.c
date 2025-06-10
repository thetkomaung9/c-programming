#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char username[50];
    char password[50];
    float balance;
} Account;

void create_account() {
    Account acc;
    FILE *fp = fopen("accounts.txt", "a+");

    printf("Enter username: ");
    scanf("%s", acc.username);

    char line[150];
    while (fgets(line, sizeof(line), fp)) {
        Account temp;
        sscanf(line, "%s %s %f", temp.username, temp.password, &temp.balance);
        if (strcmp(temp.username, acc.username) == 0) {
            printf("Username already exists.\n");
            fclose(fp);
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", acc.password);
    printf("Enter initial deposit: ");
    scanf("%f", &acc.balance);

    fprintf(fp, "%s %s %.2f\n", acc.username, acc.password, acc.balance);
    fclose(fp);
    printf("Account created successfully.\n");
}

int login(Account *loggedIn) {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("accounts.txt", "r");
    if (!fp) {
        printf("Unable to open file.\n");
        return 0;
    }

    while (fscanf(fp, "%s %s %f", loggedIn->username, loggedIn->password, &loggedIn->balance) == 3) {
        if (strcmp(username, loggedIn->username) == 0 &&
            strcmp(password, loggedIn->password) == 0) {
            fclose(fp);
            printf("Login successful.\n");
            return 1;
        }
    }

    fclose(fp);
    printf("Login failed.\n");
    return 0;
}

void update_account(Account acc) {
    FILE *fp = fopen("accounts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    Account tempAcc;
    while (fscanf(fp, "%s %s %f", tempAcc.username, tempAcc.password, &tempAcc.balance) == 3) {
        if (strcmp(tempAcc.username, acc.username) == 0) {
            fprintf(temp, "%s %s %.2f\n", acc.username, acc.password, acc.balance);
        } else {
            fprintf(temp, "%s %s %.2f\n", tempAcc.username, tempAcc.password, tempAcc.balance);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

void deposit(Account *acc) {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    acc->balance += amount;
    update_account(*acc);
    printf("Deposit successful. New balance: %.2f\n", acc->balance);

    FILE *log = fopen("history.txt", "a");
    fprintf(log, "%s deposited %.2f\n", acc->username, amount);
    fclose(log);
}

void withdraw(Account *acc) {
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    if (amount > acc->balance) {
        printf("Insufficient funds.\n");
        return;
    }
    acc->balance -= amount;
    update_account(*acc);
    printf("Withdrawal successful. New balance: %.2f\n", acc->balance);

    FILE *log = fopen("history.txt", "a");
    fprintf(log, "%s withdrew %.2f\n", acc->username, amount);
    fclose(log);
}

void view_history(const char *username) {
    char line[150];
    FILE *fp = fopen("history.txt", "r");
    if (!fp) {
        printf("No transaction history found.\n");
        return;
    }
    printf("Transaction history for %s:\n", username);
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, username)) {
            printf("%s", line);
        }
    }
    fclose(fp);
}

int main() {
    int choice;
    Account user;

    while (1) {
        printf("\n=== Banking System ===\n");
        printf("1. Create Account\n2. Login\n0. Exit\nChoose option: ");
        scanf("%d", &choice);

        if (choice == 1) create_account();
        else if (choice == 2 && login(&user)) {
            while (1) {
                printf("\n--- Welcome, %s ---\n1. Deposit\n2. Withdraw\n3. View History\n0. Logout\nChoose option: ", user.username);
                scanf("%d", &choice);

                if (choice == 1) deposit(&user);
                else if (choice == 2) withdraw(&user);
                else if (choice == 3) view_history(user.username);
                else if (choice == 0) break;
                else printf("Invalid option.\n");
            }
        } else if (choice == 0) break;
        else printf("Invalid choice.\n");
    }
    return 0;
}

