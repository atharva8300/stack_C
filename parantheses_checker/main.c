#include <stdio.h>
#include <string.h>
#include <conio.h>
#define max 20
void push(char stk[],char c);
char pop(char stk[]);
void display_stack(char stk[]);
int top = -1 ;

int main()
{
    char a[max]  ;//expression
    char stack[max];
    char temp ;
    int flag = 1,i=0 ;
    printf("enter the expression : ");
    gets(a);
    printf("\n");
    puts(a);
    printf("\n");
    while(a[i]!='\0')
    {
        if(a[i] == '(' || a[i] == '{' || a[i]=='[')
            {push(stack,a[i]);}
        if(a[i] == ')' || a[i] == '}' || a[i]==']')
        {
            if(top == -1)
            {
                flag = 0;
            }
            else{
                display_stack(stack);
                temp = pop(stack);
                //printf("\n\npopped value is ....%c\n\n",temp);
                //printf("\nIN else");
                if(a[i]==')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                }
                if(a[i]=='}' && (temp == '(' || temp == '['))
                {
                    flag = 0;
                }
                if(a[i]==']' && (temp == '{' || temp == '('))
                {
                    flag = 0;
                }
            }
        }
        i++;
    }
    if(top>=0)
    {
        flag = 0;
    }
    if(flag == 0)
    {
        printf("\n\n *****invalid exp *****\n\n");
    }
    else{printf("\n\n*****valid exp*****\n\n");
    getch();
    return 0 ;
}
}
void push(char stk[],char c)
{
    top ++;
    stk[top] = c ;
}
char pop(char stk[])
{
    char c ;
    c = stk[top];
    top -- ;
    return c ;
}
void display_stack(char stk[])
{
    printf("\n the stack : \n");
    for(int i =0 ;i<=top;i++)
    {
        printf("%c\t",stk[i]);
    }
    printf("\n");
}
