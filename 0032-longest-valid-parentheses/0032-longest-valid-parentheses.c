typedef struct
{
    int data[30005];
    int top;
} stack;

void push(stack *st, int value)
{
    st->data[++st->top] = value;
}

int isempty(stack *st)
{
    return st->top == -1;
}

void pop(stack *st)
{
    if (!isempty(st))
    {
        st->top--;
    }
}

int longestValidParentheses(char* s)
{
    stack st;
    st.top = -1;

    int max = 0;

    // Boundary before the string
    push(&st, -1);

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            push(&st, i);
        }
        else
        {
            pop(&st);

            if (isempty(&st))
            {
                // Current ')' becomes a new boundary
                push(&st, i);
            }
            else
            {
                int length = i - st.data[st.top];

                if (length > max)
                {
                    max = length;
                }
            }
        }
    }

    return max;
}