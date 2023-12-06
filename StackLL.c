/* JULIA JOMON
    CU-30   */

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;

void push(struct Node** top,int item){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = *top;
    *top = newNode;
    
}

void pop(struct Node** top){
    int item;
    struct  Node* temp;
    if(*top == NULL){
        printf("Empty");
        return;
    }
    else 
        item= (*top)->data;
        temp = *top;
        *top = (*top)->next;
        free(temp);
        printf("deleted %d ",item);
}

void peek(struct Node* top){
    if(top == NULL){
        printf("Empty");
        return;
    }
    else 
        printf("top=%d",top->data);
        
}

void display(struct Node* top){
    struct  Node* temp ;
    if(top == NULL){
        printf("Empty");
        return;
    }
        temp = top;

        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        } 
        printf("NULL\n");
}

int main(){
    struct Node* top = NULL;
    int value,op;
    char ch='y';
    do{
        printf("Enter Choice\n1.Push\n2.Pop\n3.Peek\n4.Display ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter value to push");
            scanf("%d",&value);
            push(&top,value);
            break;
        
        case 2 :
            pop(&top);
            break;

        case 3 :
            peek(top);
            break;

        case 4 :
            display(top);
            break;
        
        default:
            printf("Invald");
            break;
        }
        printf("Do you want to continue: ");
        scanf("%s",&ch);
    }while(ch=='y');
    return 0;
}
