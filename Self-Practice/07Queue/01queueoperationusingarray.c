#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

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
    while(i <= rear)
    {
        printf("%d\t",Queue[i]);
        i++;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    front++;
    if(front>rear)
    {
        front = rear = -1;
    }
}
void enqueue(int data)
{
    if(rear == SIZE-1)
    {
        printf("Overflow");
        return;
    }
    if(front ==-1)
    {
        front=0;
    }
    rear++;
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