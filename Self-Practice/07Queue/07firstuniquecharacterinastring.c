/* Find the first unique character of the string
or
1st non-Repeating char in a stream*/
#include <stdio.h>
#define SIZE 50

char queue[SIZE];
int front = -1, rear = -1;

void enqueue(char x)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is overflow");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = x;
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
}
int main()
{
    int i = 0;
    int freq[26] = {0};
    char str[50] = "level";

    while (str[i] != '\0')
    {
        if (freq[str[i] - 'a'] == 0)
        {
            enqueue(str[i]);
        }
        freq[str[i] - 'a']++;

        i++;
    }
    while (front != -1)
    {
        if (freq[queue[front] - 'a'] > 1)
        {
            dequeue();
        }
        else
        {
            printf("%c", queue[front]);
            return 0;
        }
    }
    printf("-1");
}