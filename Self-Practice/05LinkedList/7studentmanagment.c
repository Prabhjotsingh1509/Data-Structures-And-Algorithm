#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int id;
    char name[50];
    struct address
    {
        char city[50];
        int pin;
    } s;
    union
    {
        float cgpa;
        int marks;
    };
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createnode()
{
    int id, pin, marks;
    char name[50], city[50];
    float cgpa;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &newnode->id);
    scanf("%s", newnode->name);
    scanf("%s", newnode->s.city);
    scanf("%d", &newnode->s.pin);
    scanf("%f", &newnode->cgpa);
    printf("data entered");
    newnode->next = NULL;
    return newnode;
}
void insertdata()
{
    struct Node *newnode = createnode();
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void deletedata(int id)
{
    struct Node *temp = head, *prev = NULL;

    if (head == NULL)
    {
        printf("list empty");
        return;
    }
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("invalid id");
        return;
    }
    if (prev == NULL)
    {
        head = temp->next;
        free(temp);
    }
    else if (temp->next == NULL)
    {
        prev->next = NULL;
        free(temp);
    }
    else if (prev->next == temp)
    {
        prev->next = temp->next;
        free(temp);
    }
}
void search(int id)
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("data \n");
            printf("%d\n", temp->id);
            printf("%s\n", temp->name);
            printf("%s\n", temp->s.city);
            printf("%d\n", temp->s.pin);
            printf("%f\n", temp->cgpa);
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("invalid id");
    }
}
void display()
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    while (ptr != NULL)
    {
        printf("data 1");
        printf("%d\n", ptr->id);
        printf("%s\n", ptr->name);
        printf("%s\n", ptr->s.city);
        printf("%d\n", ptr->s.pin);
        printf("%f\n", ptr->cgpa);
        ptr = ptr->next;
    }
}
int main()
{
    int n, id;
    while (1)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insertdata();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        case 4:
            scanf("%d", &id);
            deletedata(id);
            break;
        case 5:
            scanf("%d", &id);
            search(id);
        }
    }
}