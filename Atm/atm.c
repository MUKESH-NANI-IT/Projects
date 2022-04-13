
#include <stdio.h>
int fastCash(int amount);
int deposit();
int withdraw();
void checkBalence();
int balence = 300; // minimum balance in a bank account
int main()
{
    int pin;
    int pins = 9999;
    int pinTries = 1;
    int reciept;
    int options;
    int options2;
    int fastCashChoice;
    printf("Enter your pin : "); // the pin is 9999
    scanf("%d", &pin);
    while (pinTries <= 3)
    {
        if (pin == pins)
        {
            printf("Would you like a reciept:"); // 1 is equal to yes and 2 is equal to no
            scanf("%d", &reciept);
            printf("Choose from the following:\n");
            printf("1. Fast cash\n2. Withdraw\n3. Deposit\n4. Check balence\n5. Get card back");
            scanf("%d", &options);
            while (options <= 5)
            {
                switch (options)
                {
                case 1:
                    fastCash(fastCashChoice);
                    balence = balence - fastCashChoice;
                    break;
                case 2:
                    withdraw(balence);
                    break;
                case 3:
                    deposit(balence);
                    break;
                case 4:
                    checkBalence(balence);
                    break;
                case 5:
                    options2 = 2;
                    break;
                }
                printf("Would you like anohter transaction: "); // 1 is equal to yes and 2 is equal to no
                scanf("%d", &options2);
                if (options2 == 1)
                {
                    printf("1. Fast cash\n2. Withdraw\n3. Deposit\n4. Check balence\n5. Get card back");
                    scanf("%d", &options);
                }
                else
                {
                    options = 5;
                    pinTries = 4;
                    printf("Thank you for useing this ATM, GoodBye\n");
                    break;
                }
            }
        }
        else if (pin != pins)
        {
            printf("Invalid pin, try again:");
            scanf("%d", &pin);
            pinTries++;
        }
        if (pinTries == 3)
        {
            printf("Sorry, you cant continue, please contact your bank");
        }
    }
    return 0;
}
int fastCash(int amount)
{
    int choice;
    printf("1. $20.00\n2. 40.00\n3. 80.00\n4. 100.00\n5. Exit");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        amount = 20;
    case 2:
        amount = 40;
    case 3:
        amount = 80;
    case 4:
        amount = 100;
    case 5:
        break;
    }
    return amount;
}
int withdraw()
{
    int withdrawAmount;
    printf("Enter the amount you would like to withdraw: ");
    scanf("%d", &withdrawAmount);
    balence -= withdrawAmount;
    return balence;
}
int deposit()
{
    int depositAmount;
    printf("Enter an amount you would like to deposit: ");
    scanf("%d", &depositAmount);
    balence += depositAmount;
    return balence;
}
void checkBalence(int balence)
{
    printf("Your current balence is: %d\n", balence);
    return;
}