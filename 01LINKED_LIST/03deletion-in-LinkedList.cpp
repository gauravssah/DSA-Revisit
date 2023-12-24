#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Next;
};

void traverseTheLinkedList(struct Node *head)
{
    int i = 1;
    int Counter = 0;
    while (head != NULL)
    {
        cout << "The Value At Node" << i << " : " << head->data << endl;
        head = head->Next;
        i++;

        Counter++;
    }

    cout << "Total Nodes in This Linked List is : " << Counter << endl;
}

// Case(1.) Delete At Start of the Linked List.
struct Node *deleteAtFirst(struct Node *head)
{

    struct Node *temp = head;
    head = head->Next;
    free(temp);
    return head;
};

// Case(2.) Delete At End of the Linked List.
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;

    while (ptr1->Next != NULL)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->Next;
    }

    ptr2->Next = NULL;
    free(ptr1);
    return head;
};

// Case(3.) Delete At Given Index of the Linked List.
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->Next;
    int i = 1;
    while (i != (index - 1))
    {
        p = p->Next;
        q = q->Next;
        i++;
    }
    p->Next = q->Next;
    free(q);
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->Next = second;

    second->data = 2;
    second->Next = third;

    third->data = 3;
    third->Next = fourth;

    fourth->data = 4;
    fourth->Next = fifth;

    fifth->data = 5;
    fifth->Next = sixth;

    sixth->data = 6;
    sixth->Next = NULL;
    cout << "Total Node In linkedList is Here." << endl;
    traverseTheLinkedList(head);
    cout << endl;

    // head = deleteAtFirst(head);
    // head = deleteAtEnd(head);
    // head = deleteAtIndex(head, 5);

    traverseTheLinkedList(head);

    return 0;
}