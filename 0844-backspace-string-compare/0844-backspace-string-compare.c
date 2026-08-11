typedef struct
{
    int data[200];
    int top;
}stack;
void push(stack * st,char ch)
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
bool backspaceCompare(char* s, char* t) {
    stack st1,st2;
    st1.top=-1;
    st2.top=-1;
    int i=0;
    while( s[i]!= '\0')
    {
        if(s[i]>='a' && s[i]<='z')
        {
            push(&st1,s[i]);
        }
        else
        {
            pop(&st1);
        }
        i++;
    }
    i=0;
    while( t[i] != '\0')
    {
        if(t[i]>='a' && t[i]<='z')
        {
            push(&st2,t[i]);
        }
        else
        {
            pop(&st2);
        }
        i++;
    }
    if(st1.top != st2.top)
    {
        return false;
    }

    for(int i=0;i<=st1.top;i++)
    {
        if(st1.data[i] != st2.data[i])
        {
            return false;
        }
    }
    return true;
}