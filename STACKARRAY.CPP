#include <iostream>
#define MAXLEN 100
using namespace std;

struct stack
{
    int element[MAXLEN];
    int top;
};

stack init()
{
    stack S;
    S.top = -1;
    return S;
}

bool isEmpty(stack S)
{
    return (S.top == -1);
}

bool isFull(stack S)
{
    return (S.top == MAXLEN - 1);
}

int top(stack S)
{
    if (isEmpty(S))
        cout << "Empty stack\n";
    else
        return S.element[S.top];
    return -1; // Returning a default value in case of an empty stack (can be modified as per requirement)
}

stack push(stack S, int x)
{
    if (isFull(S))
        cout << "OVERFLOW\n";
    else
    {
        ++S.top;
        S.element[S.top] = x;
    }
    return S;
}

stack pop(stack S)
{
    if (isEmpty(S))
        cout << "UNDERFLOW\n";
    else
    {
        --S.top;
    }
    return S;
}

void print(stack S)
{
    int i;
    for (i = S.top; i >= 0; --i)
        cout << S.element[i] << " ";
}

int main()
{
    stack S;
    S = init();
    S = push(S, 10);
    S = push(S, 45);
    S = push(S, 1);
    S = push(S, 50);
    cout << "Current stack: ";
    print(S);
    cout << "with top = " << top(S) << ".\n";
    S = pop(S);
    S = pop(S);
    cout << "Current stack: ";
    print(S);
    cout << "with top = " << top(S) << ".\n";
    return 0;
}
