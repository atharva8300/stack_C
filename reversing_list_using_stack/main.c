#include <stdio.h>
#include <conio.h>
int stk[100];
int top = -1 ;
int pop();
void push(int);
int main()
{
    int val ,n;
    int a[100];
    printf("enter number of elements : ");
    scanf("%d",&n);
    for(int i =0 ; i<n;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
        printf("\n");
    }
    for(int i=0;i<n;i++)
        push(a[i]);
    for(int i=0;i<n;i++)
    {
        val = pop();
        a[i] = val ;
    }
    printf("\nin reversed order : ");
    for(int i = 0 ;i<n;i++)
    {
        printf("\n%d",a[i]);
    }
    return 0;
}
void push(int num)
{
    top++;
    stk[top] = num ;
}
int pop()
{
    return stk[top--];
}
