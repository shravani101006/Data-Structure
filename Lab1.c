#include <stdio.h>
#define n 5

int top=-1;
int stack[n];
void Push()
{
    int x;
    int i;
    if(top==n-1)
    {
        printf("Stack overflow.");
    }
    else
    {
        printf("Enter value:");
        scanf(" %d",&x);
        top++;
        stack[top]=x;
        for (i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}

void Pop()
{
    int j;
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        int item=stack[top];
        top--;
        printf("Popped %d \n", item);
        for (j=top;j>=0;j--)
        {
            printf("%d\t",stack[j]);
        }
        printf("\n");
    }
}

void Peek()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("Top element: %d\n",stack[top]);
        top--;
    }
}

int main()
{
    int ch;
    printf("1.Push\n2.Pop\n3.Peek\n4.Exit\n\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Peek();
                break;
            case 4: 
                printf("Exiting");
                return 0;
                break;
            default:
                printf("Invalid choice");
        }
    }
}