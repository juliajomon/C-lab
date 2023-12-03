#include <stdio.h>
#define MAX_SIZE 10
int  top = -1 ;
int Stack[MAX_SIZE] ;
int item;

void push(int item)
{
    if(top == MAX_SIZE -1)
        printf("full");
    else
        top=top+1;
        Stack[top]=item;
}
int pop()
{
    
    if(top == -1){
		printf("Empty\n");
		return 0 ;
	}
        
    else
        item = Stack[top];
        top=top-1;
        return item;
}

int peek()
{
    if(top == -1){
		printf("empty\n");
		return 0;
	}
        
    else
        return Stack[top];
}

void postfix(char pos)
{   
    int op,x,y;
        if(pos=='+'||pos=='-' || pos=='/' || pos=='*'  || pos == '$'){
            float cal;
            switch (pos)
            {
            case '+':
                y = pop();
                x = pop();
                cal =(x+y);
                push(cal);
                break;

            case '-' :
                y = pop();
                x = pop();
                cal = x-y;
                push(cal);
                break;

            case '*' :
                y = pop();
                x = pop();
                cal =x*y;
                push(cal);
                break;

            case '/' :
                y = pop();
                x = pop();
                cal = x/y;
                push(cal);
                break;

            case '$':
            printf("\nEvaluation result = %d", peek());
                break;
            
            default:
                break;
            }
        }
        else if (pos >= '0' && pos <= '9')
             push(pos- '0' );
    
        

}

int main()
{  
   char post[MAX_SIZE];
   int i =0;
   printf("enter postfix expression and end with $: ");
   do{
       scanf(" %c",&post[i]);
       printf("%c",post[i]);
       postfix(post[i]);
       i++;
   }while(post[i-1]!='$');
   
}
