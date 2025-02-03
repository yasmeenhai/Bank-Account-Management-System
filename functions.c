#include "finalproj.h"

void createAccount(struct node** head){
    struct node* newNode = (struct node*)malloc(sizeof(struct node))  ;
    //check if the new node is allocated correctly 
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the ID: ");
    scanf("%d", &newNode->data.id);
    //check that the same id was not used before 
    struct node* temp = *head;
    while (temp) {
        if (temp->data.id == newNode->data.id) {
            printf("Error: ID already exists! Please enter a different ID: ");
            scanf("%d", &newNode->data.id);
        }
        temp = temp->next;
    }
    printf("Enter your name: ");
    scanf(" %[^\n]", newNode->data.name);
    printf("Enter your balance: ");
    scanf("%lf", &newNode->data.balance);
    printf("Acount type (Normal (1) or VIP (2) ?) ");
    scanf(" %c", &newNode->data.type);
    while (newNode->data.type != '1' && newNode->data.type != '2') {
        printf("Error: Invalid input! Please enter 1 for Normal or 2 for VIP: ");
        scanf(" %c", &newNode->data.type);
    }
    //add the new account at the top of the linked list
    newNode->next = *head;
    *head = newNode;
    printf("Account created successfully!\n\n");
    return;
}

void displayAccounts(struct node* head) {
    if (head == NULL) {
        printf("there is no accounts yet \n\n");
        return;
    }
    
    struct node* temp = head;
    while (temp != NULL) {
        printf("\nAccount ID: %d\n", temp->data.id);
        printf("Name: %s\n", temp->data.name);
        printf("Balance: %.2lf\n", temp->data.balance);
        printf("Type: %c\n", temp->data.type);
        temp = temp->next;
    }
    printf("\n\n");
    return;
}

void searchAccountByID(){
    printf ("Enter the ID to be searched :");
    int num ;
    int found = 0;
    scanf("%d",&num);
    struct node* temp = head;
    while (temp != NULL){
        if(temp->data.id == num ){
            printf("\nAccount ID: %d\n", temp->data.id);
            printf("Name: %s\n", temp->data.name);
            printf("Balance: %.2lf\n", temp->data.balance);
            printf("Type: %c\n\n\n", temp->data.type); 
            found = 1 ;
            break;
        }
        temp = temp->next;
    }

    if (!found){
            printf("there is no account with this ID \n\n");
        }
return;
}

void updateAccountByID(){
    printf("Enter the account ID to be updated: ");
    int num;
    scanf("%d",&num);
    int found = 0;
    struct node* temp = head;
    while (temp != NULL){
        if(temp->data.id == num ){
            printf("updated name: ");
            scanf(" %[^\n]", temp->data.name);
            printf("updated acount type (Normal (1) or VIP (2)): ");
            scanf(" %c", &temp->data.type);

            while (temp->data.type != '1' && temp->data.type != '2') {
                printf("Error: Invalid input! Please enter 1 for Normal or 2 for VIP: ");
                scanf(" %c", &temp->data.type);
            }
            printf("\n\n\nAccount ID: %d\n", temp->data.id);
            printf("Name: %s\n", temp->data.name);
            printf("Balance: %.2lf\n", temp->data.balance);
            printf("Type: %c\n\n\n", temp->data.type); 
            printf("account updated successfully \n\n\n");
            found = 1 ;
            break;
        }
        temp = temp->next;
    }

    if (!found){
            printf("there is no account with this ID \n\n");
        }

    return;
}

void depositMoney() {
    printf("Please enter account ID: ");
    int num;
    scanf("%d", &num); 

    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == num) { 
            printf("Deposit amount: ");
            double amount;
            scanf("%lf", &amount);

            temp->data.balance += amount;
            printf("Successful transaction! New balance: %.2lf\n\n", temp->data.balance);
            return; 
        }
        temp = temp->next;
    }

    // If the loop finishes without finding the ID
    printf("Incorrect ID, no account found with this ID.\n\n");
}

void withdrawMoney(){
    
    printf("Please enter account ID: ");
    int num;
    scanf("%d", &num); 

    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == num) { 
            printf("Deposit amount: ");
            double amount;
            scanf("%lf", &amount);
        if (temp->data.balance < amount ){
            printf("Error: Insufficient funds. Your current balance is %.2lf.\n", temp->data.balance);
            return; 
        }
        else {
            temp->data.balance -= amount;
            printf("Successful transaction! New balance: %.2lf\n\n", temp->data.balance);
            return; 
        }
        }
        temp = temp->next;
    }

    // If the loop finishes without finding the ID
    printf("Incorrect ID, no account found with this ID.\n\n");

}

void findHighestBalance(){
    if (head == NULL) {
        printf("there is no accounts yet \n\n");
        return;
    }
    
    struct node* temp = head;
    struct node* loc = head;
    double max = head->data.balance;

    while (temp != NULL) {
     if (temp->data.balance > max ){
        max = temp->data.balance;
        loc = temp;
     }
        temp = temp->next;
    }

    printf("\nAccount ID: %d\n", loc->data.id);
    printf("Name: %s\n", loc->data.name);
    printf("Balance: %.2lf\n", loc->data.balance);
    printf("Type: %c\n", loc->data.type);
    printf("\n\n");
    return;
}

void deleteAccount() {
    printf("Enter the account ID to be deleted: ");
    int num;
    scanf("%d",&num);
    struct node* temp = head;
    struct node* prev = NULL;

    // Iterate through the linked list to find the account with the given ID
    while (temp != NULL) {
        // Check if the current node's ID matches the input ID
        if (temp->data.id == num) {
            // If the node to be deleted is the head
            if (prev == NULL) {
                head = temp->next;  // Move the head to the next node
            } else {
                prev->next = temp->next;  // Bypass the node to be deleted
            }

            // Free the memory allocated for the node
            free(temp);

            printf("Account with ID %d has been successfully deleted.\n", num);
            return;  // Exit the function as the account has been deleted
        }

        // Move to the next node
        prev = temp;
        temp = temp->next;
    }

    // If the account with the given ID was not found
    printf("Account with ID %d not found.\n", num);
}

void exitprogram() {
    struct node* temp = head;
    struct node* nextNode;

    
    while (temp != NULL) {
        nextNode = temp->next;  
        free(temp);  
        temp = nextNode;  
    }

    head = NULL;

    printf("Exiting program.\n");
    return;
}

