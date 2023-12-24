#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

// isEmpty ------->
void isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        cout << "Stack (Empty) UnderFlow..." << endl;
    }
    else
    {
        cout << "Stack is not Empty!" << endl;
    }
};

// isFull ------->
void isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        cout << "Stack is Full(OverFlow)." << endl;
    }
    else
    {
        cout << "Stack is not Full.." << endl;
    }
};

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    cout << "Stack has been created..." << endl;

    isEmpty(s);
    isFull(s);
    return 0;
}