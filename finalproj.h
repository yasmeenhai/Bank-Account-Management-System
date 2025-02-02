#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//account info
struct account {
    int id ;
    char name[20] ;
    double balance ;
    char type ; //Normal or VIP
};
//linked list to save accounts 
struct node {
    struct account data ;
    struct node* next ;
};

    struct node* head = NULL;  // Initialize the linked list as empty
