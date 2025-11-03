
#include <stdio.h>
#include <ctype.h>

#define n 5
int queue[5];
int front = -1;
int rear = -1;

void enque(int x){

    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear+1)%n == front){
        printf("Queue overflow\n");
    }
    else{
        rear = (rear+1)%n;
        queue[rear] = x;
    }
}

void deque(){

    if(front == -1 && rear == -1){
        printf("Queue underflow\n");
    }
    else if(front == rear){
        printf("Deleted element = %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Deleted element = %d\n", queue[front]);
        front = (front+1)%n;
    }
}

void display(){
    for(int i = front;; i=(i+1)%n){
        printf("%d ", queue[i]); 
        if (i==rear)
            break;
    }
    printf("\n");
}

int main(){

    int ch;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");

     while(1){
        int x;
        while(1){
            printf("Enter a choice: ");
            scanf("%d", &ch);
            switch(ch){
            case 1: printf("Enter number to insert: ");
                    scanf("%d", &x);
                    enque(x);
                    break;
            case 2: deque();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid choice");
            }

        }
    }
    return 0;
}