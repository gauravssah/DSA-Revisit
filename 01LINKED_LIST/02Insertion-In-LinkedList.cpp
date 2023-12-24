#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Link;
};

void traversingTheLinkedList(struct Node *temp)
{
    int i = 1;
    while (temp != NULL)
    {
        cout << "The value of Node" << i << " : " << temp->data << endl;
        temp = temp->Link;
        i++;
    }
}

// ----------------------------------------------------------

// Case(1.) Insertion at begning of the node;

struct Node *insertAtStart(struct Node *head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Link = head;
    return newNode;
};

// Case(2.) Insertion at End of the node;

struct Node *inserAtEnd(struct Node *head, int data)
{
    struct Node *endNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    while (temp->Link != NULL)
    {
        temp = temp->Link;
    }

    temp->Link = endNode;
    endNode->data = data;
    endNode->Link = NULL;

    return head;
};

// Case(3.) Insertion at Index of the node;
struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int i = 1;
    while (i != (index - 1))
    {
        temp = temp->Link;
        i++;
    }

    newNode->data = data;
    newNode->Link = temp->Link;
    temp->Link = newNode;

    return head;
};

// Case(4.) Insertion at a Node;
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
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
    fifth->Link = NULL;

    // head = insertAtStart(head, 40);
    // head = inserAtEnd(head, 15);
    // head = insertAtIndex(head, 4, 13);
    // head = insertAfterNode(head, fifth, 31);

    traversingTheLinkedList(head);

    return 0;
}