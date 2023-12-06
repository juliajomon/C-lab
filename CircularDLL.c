/* JULIA JOMON
    CU-30   */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}Node;

struct Node* front ;
struct Node* rear ;

void enqueue(int item){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=item;
    
    if(front==0)
    {   front = rear = newNode;
        newNode->prev = rear;
        newNode->next= front;
    }
    else
    {   
        rear->next= newNode;
        newNode->prev = rear;
        newNode->next = front;
        front->prev = newNode;
        rear= newNode;
    }
}

void dequeue()
{
   int item;
   struct Node* temp = front;

   if(front == NULL) {
       printf("empty\n");
       return;
   }

   item = front->data;

   if(front == rear) {
       front = rear = NULL;
   }
   else {
       rear->next = front->next;
       front = front->next;
       front->prev = rear;
   }

   free(temp);
   printf("Deleted: %d ",item);
}

void display(){
    struct Node* temp = front;
    if(front == NULL) {
       printf("empty\n");
       return;
    }
    else{
        do{
            printf("%d->",temp->data);
            temp=temp->next;
        }while(temp!=front);
        printf("NULL\n");
    }
}

int main()
{
    int op,value;
    char ch;
    do{
            printf("1.enqueue\n2.Dequeue\n3.Display\n");
            scanf("%d",&op);
            switch(op){
                case 1 :
                    printf("enter value: ");
                    scanf("%d",&value);
                    enqueue(value);
                    break;

                case 2 :
                    dequeue();
                    break;

                case 3 :
                    display();
                    break;

                default :
                    printf("Invalid");
                    break;
            }
            printf("Do you want to cotinue: ");
            scanf("%s",&ch);
        }while(ch == 'y' );
        return 0;
}


