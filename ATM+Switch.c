#include <stdio.h>//ATM simulator using C program

int ATM_Transaction();//Prototype of the functions
int anotherTransaction,amountToWidthdraw,amountToDeposit,pin;//Global variable
double balance = 1000; // Global variable, Initial  balance to be 1000 for everyone

int  main()

{
  printf("******** Welcome to El Banco Corrupto Grande ******** \n");
  printf(" Enter your pin number please: \n");
  scanf("%d",&pin);
    if(pin != 1234)
   {
       printf("Sorry your pin is wrong, Pls try again with the card");
   }
   else
    {
      ATM_Transaction();     // function call
    }
}

int ATM_Transaction()
{
  int choice;
  printf("Enter any option to be served!\n\n");
  printf("1. Balance Enquiry \n");
  printf("2. Cash Withdraw\n");
  printf("3. Deposit Cash\n");
  printf("4. Exit \n");
  scanf("%d",  &choice);

  switch(choice)

  {

    case 1: // BALANCE Enquiry
    printf("Your bank balance is: %f", balance);
    printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit\n\n"); // request for another transaction
    scanf("%d",&anotherTransaction);
    if(anotherTransaction == 1)
      {
        ATM_Transaction();// call our transaction method here
      }
     break;

    case 2:// Second option should be withdraw
    printf("Please enter amount to withdraw: ");
    scanf("%d", &amountToWidthdraw);
    if(amountToWidthdraw <= balance) //bal = 1000
    {
     printf("Pls collect your cash\n");
     balance=balance-amountToWidthdraw;//
     printf("Your available balance is %lf\n",balance);
     printf("\n\nDo you want to perform another transaction?\n Press 1 to proceed and 2 to exit\n\n");
     scanf("%d", &anotherTransaction);
       if(anotherTransaction == 1)
        {
             ATM_Transaction();  // call our ATM_Transaction method here
        }
    }
     else
    {
       printf("Sorry in-sufficient funds in your account");
       printf("\n\nDo you want to perform another transaction?\n Press 1 to proceed and 2 to exit\n\n");
       scanf("%d", &anotherTransaction);
       if(anotherTransaction == 1)
        {
             ATM_Transaction();  // call our ATM_Transaction method here
        }
    }
    break;

    case 3:// DEPOSIT
    printf("Please enter amount to deposit: ");
    scanf("%d", &amountToDeposit);
    balance = amountToDeposit + balance; //600+500
    printf("Thank you for depositing, your new balance is: %f", balance);
    printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n");// request for another transaction
    scanf("%d", &anotherTransaction);
    if(anotherTransaction == 1)
     {
        ATM_Transaction(); // call our transaction method here
     }
    break;
    default:
     printf("Thanks for Using ATM services, See you soon");
  }

}




