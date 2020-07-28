#include <stdio.h>
#include <conio.h>
typedef struct
{
    int data ;
    struct node *next ;
}node ;
node *top  = NULL ;

node* push(node *);
node* pop(node *);
void peek(node *);
void display_stack(node *);
void display_menu();

int main()
{
    int option=0,r=0;
    do
    {
        display_menu();
        printf("\nenter your choice : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: top = push(top);
                    break ;
            case 2: top = pop(top);
                    break;
            case 3: peek(top);
                    break ;
            case 4: display_stack(top);
                    break ;
        }
    }while(option != 5);
    getch();
    return 0;
}
void display_menu()
{
    printf("\n1.push\n2.pop\n3.peek\n4.display stack\n5.exit\n");
}
node* push(node *top)
{
    int val = 0 ;
    node *new_node;
    printf("\nenter value to be pushed : ");
    scanf("%d",&val);
    if(top == NULL)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->next = NULL ;
        new_node->data = val;
        top = new_node ;
    }
    else
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->data = val;
        new_node->next = top ;
        top = new_node ;
    }
    return top ;
}
node* pop(node *top)
{
    int r = -1 ;
    node *ptr ;
    if(top == NULL)
        printf("empty stack");
    else
    {
        ptr = top ;
        //printf("%p   %p\n",ptr,top);
        r = top->data ;
        printf("\npopped value = %d\n",r);
        top = top->next ;
        //printf("%p   next top\n",top);
        free(ptr);
    }
    return top ;
}
void display_stack(node *top)
{
    node *ptr ;
    ptr = top ;
    if(top == NULL)
        printf("empty stack");
    else{
        while(ptr != NULL)
        {
            printf("\n%d\n",ptr->data);
            ptr = ptr->next ;
        }
    }
}
void peek(node *top){
    if(top == NULL)
        printf("empty");
    else{
        printf("\n%d\n",top->data);
    }
}
