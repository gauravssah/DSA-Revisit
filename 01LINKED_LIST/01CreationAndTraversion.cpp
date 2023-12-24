#include <iostream>
using namespace std;

// Creation a Struct type of Node
struct Node
{
    int data;
    struct Node *Link;
};

// Defineing function for traversing the linked list.
void traversingTheLinkedList(struct Node *prt)
{
    while (prt != NULL)
    {
        cout << "The value is : " << prt->data << endl;
        prt = prt->Link;
    }
}

int main()
{
    // Creation of Linked-List Node
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Assigning address in memory to the Nodes.
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Linking First and Second Nodes.
    head->data = 5;
    head->Link = second;

    // Linking Second and third.
    second->data = 8;
    second->Link = third;

    // Linking third and fourth
    third->data = 6;
    third->Link = fourth;

    // Linking fourth and fifth.
    fourth->data = 10;
    fourth->Link = fifth;

    // Assigning fifth Node data and Null for ending the Linked list.
    fifth->data = 12;
    fifth->Link = NULL;

    cout << "Linked List Created.." << endl;

    // Now Traversing the linked list.
    traversingTheLinkedList(head);

    return 0;
}