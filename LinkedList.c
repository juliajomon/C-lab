#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 		int data; 		
        struct node *next; 		 
}node;   
(struct node* head =NULL;
void InsertAtEnd(int Data){ 
	struct node *newNode = (struct node*) malloc(sizeof(struct node)); 	
    newNode->data = Data; 	
    newNode->next = NULL; 	
    if(head == NULL){ 
		head = newNode; 		
        return ; 
    } 	
    struct node* temp = head; 	
    while(temp->next != NULL){ 
		temp = temp->next; 	
    }
 	temp->next = newNode; 
    }  
    
    void InsertAfterData( int target, int Data){
      	struct node *newNode = (struct node*) malloc(sizeof(struct node));  	
        newNode->data = Data; 	
        struct node* temp = head; 	
        while(temp!=NULL && temp->data != target){
     		temp = temp->next; 	
        }  	
        if(temp!=NULL && temp->data == target){
     		newNode->next = temp->next;
     		temp->next = newNode; 	
        } 	
        else 		
        printf("not found"); 		 	
        }  
        
        void InsertBeforeData(int target, int data){
        	struct node *newNode = (struct node*) malloc(sizeof(struct node));  	
            newNode->data = data;  	
            if(head != NULL