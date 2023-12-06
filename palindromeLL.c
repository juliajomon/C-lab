/* JULIA JOMON
    CU-30   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* prev;
    char data;
    struct Node* next;
} Node;

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(char item){
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (newNode == NULL) {
     printf("Memory allocation failed\n");
     return;
 }
 newNode->data= item;
 newNode->next=NULL;
 newNode->prev=NULL;
 if(front==NULL){
     front=rear=newNode; 
 }
 else{
     rear->next=newNode;
     newNode->prev=rear;
     rear = newNode;
 }
}

 void palindrome(){
    struct Node* head = front;
    struct Node* tail = rear;
    while(head!=tail){
        if(head->data!=tail->data){
            printf("Not palindrome");
            exit(1);
        }
        else if(head->data==tail->data){
            head=head->next;
            tail=tail->prev;
            
        }
    }
    printf("palindrome");
    
 }

 int main(){
    char pal[100];
    printf("Enter Word: ");
    scanf("%s",pal);
    int n =strlen(pal);
    for(int i=0;i<n;i++){
        enqueue(pal[i]);
    }
    palindrome();
    return 0;
 }