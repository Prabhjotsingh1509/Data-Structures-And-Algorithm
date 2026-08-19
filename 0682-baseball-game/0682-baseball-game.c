#include<stdlib.h>
typedef struct
{
    int data[1000];
    int top;
}stack;
void push(stack * st,int ch)
{
    st->data[++st->top]=ch;
}
void pop(stack *st)
{
    if(st->top == -1)
    {
        return;
    }
    st->top--;
}
int calPoints(char** operations, int operationsSize) 
{
    stack record;
    record.top=-1;
    for(int i=0;i<operationsSize;i++)
    {
        if(operations[i][0]=='+')
        {
            int n_score=record.data[record.top]  + record.data[record.top-1];
            push(&record,n_score);
        }
        else if( operations[i][0]=='D')
        {
            int n_score=(record.data[record.top])*2 ;
            push(&record, n_score);
        }
        else if(operations[i][0]=='C')
        {
            pop(&record);
        }
        else
        {
           push(&record,atoi(operations[i]));
        }

    }
    int f_score=0;
    for(int i= record.top;i>=0;i--)
    {
        f_score+=record.data[i];
    }
    return f_score;
}