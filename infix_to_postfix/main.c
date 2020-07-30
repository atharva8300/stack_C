#include <stdio.h>
#include <conio.h>
#define max 50
int top = -1 ;
void infix_postfix(char [],char [],char []);
int get_priority(char a);
void push(char [],char);
char pop(char []);
int main()
{
    char infix[max],postfix[max];
    char stack[max] ;
    printf("enter the infix expression : ");
    gets(infix);
    printf("\ninfix expression : ");
    puts(infix);
    infix_postfix(infix,postfix,stack);
    printf("\n postfix : \n");
    puts(postfix);
    getch();
    return 0;
}
void infix_postfix(char infix[],char postfix[],char stack[])
{
    int len = 0,i=0,j=0;
    char last_open_bracket ;
    postfix[0] = '(' ;
    len = strlen(infix);
    //infix[len++]=')';
    //infix[len]='\0';
    printf("\n");
    puts(infix);
    while(infix[i]!='\0')
    {
        if(infix[i] == '(')
        {
            push(stack,infix[i]);
            i++ ;
        }
        else if(infix[i] == ')')
        {
            while(top!=-1 && stack[top]!= '(')
            {
                postfix[j] = pop(stack);
                j++ ;
            }
            if(top == -1)
            {
                printf("\nincorrect expression ");
                exit(1);
            }
            last_open_bracket = pop(stack); // removes the {
            i++;
        }
        else if(isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if(infix[i]=='+' || infix[i]== '-' || infix[i] == '*' || infix[i]== '/' || infix[i] == '%')
        {
            while((top!=-1)&&(stack[top]!= '(')&&(get_priority(stack[top]) > get_priority(infix[i])))
            {
                postfix[j] = pop(stack);
                j++;
            }
            push(stack,infix[i]);
            i++ ;
        }
        else{
            printf("incorrex ");
            exit(1);
        }
    }
    while((top!=-1)&&stack[top]!='(')
    {
        postfix[j] = pop(stack);
        j++;
    }
    postfix[j]= '\0';
}
int get_priority(char a)
{
    if(a == '/' || a == '*' || a == '%')
    {
        return 1;
    }
    else{return 0;}
}
void push(char stack[],char c)
{
    if(top == max-1)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        stack[++top] = c ;
    }
}
char pop(char stack[])
{
    char val ;
    if(top == -1){
        printf("underflow");
    }
    else{
        val = stack[top];
        top -- ;

    }
    return val ;
}
