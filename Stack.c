#include <stdio.h>
#define MAX_SIZE 5

int Stack[MAX_SIZE];
int item,top=0; 


void Push(int item , int Stack[MAX_SIZE])
{
	if(top == MAX_SIZE )
		printf("Stack is empty");
	else
		Stack[top] = item;
		top++;
}

void Pop(int Stack[MAX_SIZE])
{
	if (top== 0)
		printf("Stak is empty");
	else
		item = Stack[top] ;
		top--;
}

void Peek(int Stack[MAX_SIZE])
{
	if( top == MAX_SIZE-1)
		printf("Stack is empty");
	else
		printf("last element %d \n", Stack[top]);
		
}


void Display(int Stack[MAX_SIZE] )
{
	if (top== 0)
		printf("Stak is empty");
	else
	{
	 for(int i=0;i<top;i++)
		printf("%d ", Stack[i]);
	}
	printf("\n");
}


int main()
{
	int con;
	int opp;
	do{
		printf("\n 1.Push \n 2.Pop \n 3.Peek \n 4.Display \n");
		printf("enter choice \t");
		scanf("%d", &opp);
		
		switch(opp)
		{
			case 1 :
			 printf("enter item \t");
			 scanf("%d",&item);
			 Push( item , Stack);
			 printf("item pushed \n");
			 break;
			 
			case 2 :
			 Pop(Stack);
			 printf("item deleted \n ");
			 break;
			 
			case 3 :
			 Peek(Stack);
			 break;
			 
			case 4 :
			 Display(Stack);
			 break;
			 
			default :
			 printf("Invalid");
			 break;
		}
		printf("Do you want to continue(1/0)");
		scanf("%d",&con);	
	}while(con == 1);
	return 0;	
}
	
	
	
