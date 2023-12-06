/* JULIA JOMON
    CU-30   */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
}Node;
struct Node* front =NULL;
struct Node* rear = NULL;
void enqueueRear(int item){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if(front== NULL && rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}
void enqueueFront(int item){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if(front== NULL && rear == NULL){
        front = rear = newNode;
    }
    else{
        newNode->next = front;
        front= newNode;
    }
}

void dequeueFront(){
    int item;
    struct Node* temp;
    if(front== NULL && rear == NULL){
        printf("Empty\n");
        return;
    }
    else if(front == rear){
        item = front->data;
        front= rear=NULL;
        printf("Deleted %d\n",item);
    }
    else{
        item=front->data;
        temp= front;
        front=temp->next;
        free(temp);
        printf("Deleted %d\n",item);
    }
}

void dequeueRear(){
    int item;
    struct Node* temp;
    if(front== NULL && rear == NULL){
        printf("Empty\n");
        return;
    }
    else if(front == rear){
        item = front->data;
        front= rear=NULL;
        printf("Deleted %d\n",item);
    }
    else{
        temp = front;
        while(temp->next!=rear){
            temp = temp->next;
        }
        if (temp->next == rear)
        {
           item = rear->data;
           temp->next = NULL;
           free(rear);
           rear = temp;
           printf("Deleted %d\n",item);
        }
    }
}
void display(){
    struct Node* temp = front;
    if(front== NULL && rear == NULL){
        printf("Empty\n");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int op,value;
    char ch='y';
    do{
        printf("1.Add at front\n2.Add at Rear\n3.Delete from Front\n4.Delete from rear\n5.Display\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1 :
            printf("Enter value");
            scanf("%d",&value);
            enqueueFront(value);
            break;

        case 2 :
            printf("Enter value");
            scanf("%d",&value);
            enqueueRear(value);
            break;

        case 3 :
            dequeueFront();
            break;

        case 4 :
            dequeueRear();
            break;

        case 5 :
            display();
            break; 
        
        default:
            break;
        }
        printf("Do you want to continue");
        scanf("%s",&ch);
    }while(ch == 'y');
    return 0;
}
