#include <stdio.h>

int ATM_Transaction();
int anotherTransaction, pin;
double balance = 1000.0; // Change the data type to double

int main()
{
    printf("******** Welcome to El Banco Corrupto Grande ******** \n");
    printf("only 3 atempts allowed: ");
    printf(" Enter your pin number please: \n");
    int count=0;
    scanf("%d", &pin);
    while(pin != 1234)
    {
      printf("Sorry, your pin is wrong. Please try again with the card\n");
      printf(" Enter your pin number please: \n");
      scanf("%d", &pin);
      count++;
      if(count>=3)
        return 0;
    }
   
      ATM_Transaction();
    

    return 0;
}

int ATM_Transaction()
{
    int choice;
    printf("Enter any option to be served!\n\n");
    printf("1. Balance Enquiry \n");
    printf("2. Cash Withdraw\n");
    printf("3. Deposit Cash\n");
    printf("4. Exit \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Your bank balance is: %lf", balance); // Use %lf for double
        printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit\n\n");
        scanf("%d", &anotherTransaction);
        if (anotherTransaction == 1)
        {
            ATM_Transaction();
        }
        break;

    case 2:
        printf("Please enter amount to withdraw: ");
        scanf("%lf", &amountToWidthdraw); // Use %lf for double
        if (amountToWidthdraw <= balance)
        {
            printf("Please collect your cash\n");
            balance = balance - amountToWidthdraw;
            printf("Your available balance is %lf\n", balance);
            printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit\n\n");
            scanf("%d", &anotherTransaction);
            if (anotherTransaction == 1)
            {
                ATM_Transaction();
            }
        }
        else
        {
            printf("Sorry, insufficient funds in your account\n");
            printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit\n\n");
            scanf("%d", &anotherTransaction);
            if (anotherTransaction == 1)
            {
                ATM_Transaction();
            }
        }
        break;

    case 3:
        printf("Please enter amount to deposit: ");
        double amountToDeposit; // Change the data type to double
        scanf("%lf", &amountToDeposit); // Use %lf for double
        balance = amountToDeposit + balance;
        printf("Thank you for depositing, your new balance is: %lf", balance); // Use %lf for double
        printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n");
        scanf("%d", &anotherTransaction);
        if (anotherTransaction == 1)
        {
            ATM_Transaction();
        }
        break;

    default:
        printf("Thanks for using ATM services, see you soon\n");
    }
    return 0;
}
