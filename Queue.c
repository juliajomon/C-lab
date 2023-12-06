/* JULIA JOMON
    CU-30   */

#include <stdio.h>
#define MAX_SIZE 10
int Queue[MAX_SIZE];
int front = 0;
int rear = -1;

void enqueue(int item)
{
    if(front ==MAX_SIZE && rear == MAX_SIZE){
        printf("Queue is full\n");
        return;
    }
    else
        rear = rear+1;
        Queue[rear] = item;
}
void dequeue()
{
    int item;
    if(front == - 1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    else
        item = Queue[front];
        front = front+1;
        printf("Deleted : %d\n",item);
}

void display()
{
    if(front == - 1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    else
        for(int i = front;i<=rear;i++){
            printf("%d ",Queue[i]);
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