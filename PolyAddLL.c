/* JULIA JOMON
    CU-30   */

#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coeff;
    int exp;
    struct Node* next;
}Node;

struct Node* insert(struct Node* head,int coef,int exp)
{
    struct Node* temp;
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    if(head == NULL || exp > head-> exp){
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp=head;
        while(temp->next  !=NULL ){
            temp=temp->next;
        }
        newNode->next= temp->next;
        temp->next= newNode;
    }
    return head;
};
struct  Node* create(struct Node* head)
{   
    int exp, coeff;
    char ch= 'y';
   do{
        printf("enter exponent ");
        scanf("%d",&exp);
        printf("Enter coeff: ");
        scanf("%d",&coeff);
        head = insert(head,coeff,exp);

        printf("Do you want to continue(y/n): ");
        scanf("%s",&ch);
   }while(ch == 'y');
   return head;
};

void display (struct Node* head){
    struct Node* temp = head;
    if(head == NULL){
        printf("No Polynomial");
        return;
    }
    else{
        while(temp!= NULL){
            printf("%dx^%d->",temp->coeff,temp->exp);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    
}
void PolyAdd(struct Node* head1 , struct Node* head2)
{
   struct Node* temp1 = head1;
   struct Node* temp2 = head2;
   struct Node* head3 = NULL;
   while(temp1 != NULL && temp2 != NULL)
   {
       if(temp1->exp > temp2->exp){
           head3=insert(head3, temp1->coeff,temp1->exp);
           temp1 = temp1->next;
       }
       else if(temp1->exp < temp2->exp){
           head3=insert(head3, temp2->coeff,temp2->exp);
           temp2 = temp2->next;
       }
       else if(temp1->exp == temp2->exp){
           head3=insert(head3, temp2->coeff+temp1->coeff,temp2->exp);
           temp2 = temp2->next;
           temp1 = temp1->next;
       }
   }
   while(temp1 != NULL)
   {
       head3=insert(head3, temp1->coeff,temp1->exp);
       temp1 = temp1->next;
   }

   while(temp2!=NULL)
   {
       head3=insert(head3, temp2->coeff,temp2->exp);
       temp2 = temp2->next;
   }

  printf("sum polynomial: ");
  display(head3);
}


int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    printf("Enter polynomial 1:\n ");
    head1 =create(head1);
    display(head1);
    printf("Enter polynomial 2:\n");
    head2 = create(head2);
    display(head2);
    PolyAdd(head1,head2);
    return 0;
}
