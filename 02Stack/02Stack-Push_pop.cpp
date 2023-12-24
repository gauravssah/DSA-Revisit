#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

// IsEmpty ----->
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// IsFull ------>

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void CheckStackStatus(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack is an Empty Stack.." << endl;
    }
    else
    {
        cout << "Now, Stack is not an Empty Stack.." << endl;
    }

    if (isFull(sp))
    {
        cout << "Now, Stack is full..." << endl;
    }
    else
    {
        cout << "Stack have still Empty space..." << endl;
    }
}

// Push ----->

void push(struct Stack *ptr, int data)
{
    if (isFull(ptr))
    {
        cout << "Stack is overFlow - > At : " << data << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

// Pop ------->

void pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Your stack is empty, can't pop." << endl;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        cout << "The value : " << val << " is pop. " << endl;
    }
}

// printStackData ---->

void printStackData(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Satck is Empty, So can't Print Data." << endl;
    }
    else
    {
        cout << endl;
        cout << "Stack Data Printing..." << endl;
        cout << endl;
        while (ptr->top != -1)
        {
            cout << "Stack Data At : " << ptr->top << " -> " << ptr->arr[ptr->top] << endl;
            ptr->top--;
        }
        cout << "All data of Stack is printed.." << endl;
    }
}

int main()
{
    struct Stack *sp;
    sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);

    pop(sp);

    CheckStackStatus(sp);
    printStackData(sp);

    return 0;
}