#include "functions.c"

int main(){

    int option;
   while (1){

        printf("1.Creat new account \n");
        printf("2.Display all accounts \n");
        printf("3.Search for an account by ID \n");
        printf("4.Update account details by ID \n");
        printf("5.Deposit money by ID \n");
        printf("6.Withdraw money by ID \n");
        printf("7.Find account with highest balance \n");
        printf("8.Delete account by ID \n");
        printf("9.Exit \n\n");
        printf("Enter your choice: ");
        scanf("%d",&option);
        switch (option) {
            case 1:
                createAccount(&head); 
            break;
            case 2:
                displayAccounts(head);
            break;
            case 3:
                searchAccountByID();
            break;
            case 4:
                updateAccountByID();
            break;
            case 5:
                depositMoney();
            break;
            case 6:
                withdrawMoney();
            break;
            case 7:
                findHighestBalance();
            break;
            case 8:
                deleteAccount();
            break;
            case 9:
                exitprogram();
            break;
            default:  printf("Invalid choice! Try again.\n\n");
            }
         if (option == 9) break;
   }
    return 0;
    }
