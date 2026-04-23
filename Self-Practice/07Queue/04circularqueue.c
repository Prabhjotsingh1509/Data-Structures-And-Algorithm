#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int Queue[SIZE];
int front =-1;
int rear=-1;

void display()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    int i=front;
    while(1)
    {
        printf("%d\t",Queue[i]);
        if(i==rear)
        {
            break;
        }
        i=(i+1)%SIZE;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    if(front==rear)
    {
        front = rear = -1;
    }
    else{
        front=(front+1)%SIZE;
    }
}
void enqueue(int data)
{
    if((rear+1)%SIZE== front)
    {
        printf("Overflow");
        return;
    }
    if(front ==-1)
    {
        front=0;
    }
    rear=(rear+1)%SIZE;
    Queue[rear]=data;
}
int main()
{
    int n,data;
    printf("-----Display Menu------\n1.Display\n2.dequeue\n3.enqueue\n");
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            display();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            scanf("%d",&data);
            enqueue(data);
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}