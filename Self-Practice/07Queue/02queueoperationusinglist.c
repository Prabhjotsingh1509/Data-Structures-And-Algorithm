#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *rear=NULL;
struct Node *front=NULL;

void enqueue(int data)
{
    struct Node * new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    if(rear==NULL)
    {
        front=rear=new;
        return;
    }
    rear->next=new;
    rear=new;
}
void dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct Node *temp=front;
    front=front->next;
    free(temp);
    if(front == NULL)
    {
        rear=NULL;
    }
}
void display()
{
    if(front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct Node *temp=front;

    while(temp!= NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main()
{
    printf("----Display Menu---\n1.dequeue\n2.enqueue\n3.display\n4.exit\n");
    int n,data;
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            dequeue();
            break;
            case 2:
            scanf("%d",&data);
            enqueue(data);
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid option");
        }
    }
}