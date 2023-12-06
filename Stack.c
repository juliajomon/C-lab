/* JULIA JOMON
    CU-30   */

#include <stdio.h>
#define MAX_SIZE 10
int  top = -1 ;
int Stack[MAX_SIZE] ;

void push(int item)
{
    if(top == MAX_SIZE -1)
        printf("full");
    else
        top=top+1;
        Stack[top]=item;
}
void pop()
{
    int item;
    if(top == -1){
		printf("Empty\n");
		return;
	}
        
    else
        item = Stack[top];
        top=top-1;
        printf("deleted %d\n", item);
}

void peek()
{
    if(top == -1){
		printf("empty\n");
		return;
	}
        
    else
        printf("%d\n",Stack[top]);
}

void display()
{
	if(top == -1){
        printf("empty\n");
		return;
	}
    else
		for(int i=top;i>=0;i--){
			printf("%d\n",Stack[i]);
    }
}
int main()
{
    int opp,item;
    char ch = 'y';
    do
    {   
        printf("Size of stack is %d\n",MAX_SIZE);
        printf("Space left %d\n",(10-top));
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
        scanf("%d",&opp);

        switch (opp)
        {
        case 1 :
            printf("Enter value to push: ");
            scanf("%d",&item);
            push(item);
            break;

        case 2 :
            pop();
            break;

        case 3 :
            peek();
            break;

        case 4 :
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