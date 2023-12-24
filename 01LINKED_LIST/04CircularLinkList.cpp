#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Link;
};

void traversingTheLinedList(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    int i = 1;

    do
    {
        cout << "The value at Node" << i << " : " << ptr->data << endl;
        ptr = ptr->Link;
        i++;
    } while (ptr != head);
};

// Case(1.) Inserting at the start of the linked list.

struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    newNode->data = data;
    newNode->Link = head;
    do
    {
        ptr = ptr->Link;
    } while (ptr->Link != head);
    ptr->Link = newNode;
    head = newNode;
    return head;
};

// Case(2.) Inserting at the end of linked list.

struct Node *insertAtEnd(struct Node *head, int data)
{

    struct Node *endNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    while (temp->Link != head)
    {
        temp = temp->Link;
    }

    endNode->data = data;
    endNode->Link = head;
    temp->Link = endNode;

    return head;
};

// Case(3.) Inserting at the Index of linked list.

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    int i = 1;
    while (i != (index - 1))
    {
        ptr = ptr->Link;
        i++;
    }
    newNode->data = data;
    newNode->Link = ptr->Link;
    ptr->Link = newNode;

    return head;
};

// Case(4.) Inserting at the Given Node of linked list.
struct Node *insertAtNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    while (temp->Link != prevNode)
    {
        temp = temp->Link;
    }
    newNode->data = data;
    newNode->Link = temp->Link;
    temp->Link = newNode;
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->Link = second;

    second->data = 2;
    second->Link = third;

    third->data = 3;
    third->Link = fourth;

    fourth->data = 4;
    fourth->Link = fifth;

    fifth->data = 5;
    fifth->Link = head;

    // head = insertAtStart(head, 11);
    // head = insertAtEnd(head, 50);
    // head = insertAtIndex(head, 55, 4);
    // head = insertAtNode(head, second, 80);

    traversingTheLinedList(head);

    return 0;
}