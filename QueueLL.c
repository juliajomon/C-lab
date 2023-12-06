/* JULIA JOMON
    CU-30   */
    #include <stdio.h>
    #include<stdlib.h>

    typedef struct Node{
        int data;
        struct Node* next;
    }Node;
    struct Node  *front =0;
    struct Node *rear = 0;
    void enqueue(int item){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = item;
        newNode->next = NULL;
        if(front == 0&& rear== 0){
            front=rear=newNode;
        }
        else
            {rear->next = newNode;
            rear= newNode;}
    }

    void dequeue(){
        struct Node* temp;
        int item;
        if(front== 0 && rear == 0){
            printf("empty");
            return;
        }
        else if(front == rear){
            item = front->data;
            rear = front = 0;
            printf("deleted: %d\n",item);
            return;
        }
        else
        {
            temp = front;
            item= front->data;
            front= front->next;
            free(temp);
            printf("deleted: %d\n",item);
        }
    }

    void display(){
        struct Node *temp;
        if(front == 0 && rear == 0){
           printf("empty\n"); 
           return;
        }
        else
            temp = front;
            while(temp!=NULL){
                printf("%d->",temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
    }

    int main(){
        int value,op;
        char ch='y';
        do{
            printf("1.enqueue\n2.Dequeue\n3.Display\n");
            scanf("%d",&op);
            switch(op){
                case 1 :
                    printf("enter value");
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
            printf("Do you want to cotinue");
            scanf("%s",&ch);
        }while(ch == 'y' );
        return 0;
    }