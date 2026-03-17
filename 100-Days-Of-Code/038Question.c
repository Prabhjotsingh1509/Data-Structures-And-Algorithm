/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty()
{
    return (front == -1);
}

// Check full
int full()
{
    return ((rear + 1) % MAX == front);
}

// push_front
void push_front(int x)
{
    if (full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (empty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x)
{
    if (full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (empty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
int pop_front()
{
    if (empty())
        return -1;

    int val = deque[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return val;
}

// pop_back
int pop_back()
{
    if (empty())
        return -1;

    int val = deque[rear];

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX) % MAX;

    return val;
}

// front element
int getFront()
{
    if (empty())
        return -1;
    return deque[front];
}

// rear element
int getBack()
{
    if (empty())
        return -1;
    return deque[rear];
}

// size
int size()
{
    if (empty())
        return 0;

    if (rear >= front)
        return rear - front + 1;

    return MAX - front + rear + 1;
}

// display
void display()
{
    if (empty())
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// reverse
void reverse()
{
    if (empty())
        return;

    int temp[MAX], i = front, j = 0;

    while (1)
    {
        temp[j++] = deque[i];
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    front = 0;
    rear = j - 1;

    for (int k = 0; k < j; k++)
        deque[k] = temp[j - k - 1];
}

// simple sort (ascending)
void sort()
{
    int n = size();
    int temp[MAX], i = front;

    for (int j = 0; j < n; j++)
    {
        temp[j] = deque[i];
        i = (i + 1) % MAX;
    }

    // bubble sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (temp[j] > temp[j + 1])
            {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }

    front = 0;
    rear = n - 1;

    for (int i = 0; i < n; i++)
        deque[i] = temp[i];
}