#include <stdio.h>
#include<stdlib.h>
#define n 5
int queue[n];
int front=-1,rear=-1,count=0;

void enqueue(int x)
{
    if(rear==n-1)
        printf("Queue Overflow.\n");
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
        printf("Element inserted\n");
    }
    else
    {
        rear++;
        queue[rear]=x;
        printf("Element inserted\n");
    }
}

void dequeue()
{
        if (front==-1 && rear==-1)
            printf("Queue Underflow.\n");
        else if(front==rear)
            front=rear=-1;
        else
        {
            printf("Element deleted: %d\n",queue[front]);
            front++;
        }
}

void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}
int main(){
    int ch,x;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while(1){
        printf("Enter choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter a number: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.");
        }
    }
    return 0;
}