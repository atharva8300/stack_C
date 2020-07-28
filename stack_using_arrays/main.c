#include <stdio.h>
#include <conio.h>
#define MAX 10
void push(int a[]);
int pop(int a[]);
void peek(int a[]);
void display_stack(int a[]);
void display_menu();

int top = -1 ;
int main()
{
    int a[MAX];
    int option,r=0;
    do
    {
        display_menu();
        printf("your choice: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: push(a);
                    break ;
            case 2: r  = pop(a);
                    if(r == -1)
                    {
                        printf("\nempty stack/overflow\n");
                    }
                    else
                    {
                        printf("popped element = %d",r);
                    }
                    break ;
            case 3: peek(a);
                    break ;
            case 4: display_stack(a);
                    break ;
        }

    }while(option!=5);
    getch();
    return 0;
}
void display_menu()
{
    printf("\n1.push\n2.pop\n3.peek\n4.display stack\n5.exit\n");
}
void display_stack(int a[])
{
    if(top == -1)
    {
        printf("empty");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",a[i]);
        }
    }
}
void push(int a[])
{
    int val = 0 ;
    printf("\nenter value to be inserted : ");
    scanf("%d",&val);
    if(top == MAX-1)
    {
        printf("overflow");
    }
    else
    {
        top++;
        a[top] = val;
    }

}
int pop(int a[])
{
    int r = -1;
    if(top == -1)
    {
        return r;
    }
    else
    {
        r = a[top];
        top --;
        return r ;
    }
}
void peek(int a[])
{
    printf("\n%d\n",a[top]);
}
