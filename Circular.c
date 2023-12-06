/* JULIA JOMON
    CU-30   */
    
#include <stdio.h>
#define MAX_SIZE 10
int Queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
   if((rear+1)%MAX_SIZE== front){
       printf("Queue is full\n");
       return ;
   }
   else if (front==-1 && rear == -1)
   {
    front= rear=0;
    Queue[rear]=item;
   }
   
   else{
       rear = (rear + 1)%MAX_SIZE;
       Queue[rear] = item;
       printf("%d",item);
   }
}


void dequeue()
{
    int item;
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }
    else{
        item = Queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        } 
        else {
            front = (front + 1) %MAX_SIZE;
        }
        printf("Deleted : %d\n",item);
    }

}

void display()
{   
    int i = front;
    if(front == -1 && rear == -1 ){
        printf("Queue is empty\n");
        return;
    }
    else
        while(i <=rear){
            printf("%d ",Queue[i]);
            i++;
        }
}
int main()
{
    int opp,item;
    char ch = 'y';
    do
    {   
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        scanf("%d",&opp);

        switch (opp)
        {
        case 1 :
            printf("Enter value to push: ");
            scanf("%d",&item);
            enqueue(item);
            break;

        case 2 :
            dequeue();
            break;

        case 3 :
            display();
            break;

        default:
            break;
        }
        printf("Do you want to continue(y/n) ");
        scanf("%s",&ch);
    }while (ch == 'y');
    return 0;   

}