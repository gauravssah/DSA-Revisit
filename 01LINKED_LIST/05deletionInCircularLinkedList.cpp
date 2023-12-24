#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Link;
};

void traversingTheLinkedList(struct Node *head)
{
    struct Node *ptr = head;
    int i = 1;

    do
    {
        cout << "The value at Node" << i << " : " << ptr->data << endl;
        ptr = ptr->Link;
        i++;
    } while (ptr->Link != head);
};

// Case(1.) Deletion at the Start of the linked list.

struct Node *deleteAtStart(struct Node *head)
{
    struct Node *temp = head;
    struct Node *prt = head;

    while (prt->Link != head)
    {
        prt = prt->Link;
    }
    head = head->Link;
    prt->Link = head;
    free(temp);
    return head;
};

// Case(2.) Deletion at the End of the linked list.

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->Link;

    while (ptr2->Link != head)
    {

        ptr1 = ptr2;
        ptr2 = ptr2->Link;
    }

    ptr1->Link = head;
    free(ptr2);

    return head;
};

// Case(3.) Deletion at the index of the linked list.
struct Node *deletionAtIndex(struct Node *head, int index)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->Link;

    while (ptr2->Link != head)
    {
        ptr1 = ptr2;
        ptr2 = ptr2->Link;
    }
    ptr1->Link = ptr2->Link;
    free(ptr2);
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fivth;
    struct Node *sixth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fivth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->Link = second;

    second->data = 2;
    second->Link = third;

    third->data = 3;
    third->Link = fourth;

    fourth->data = 4;
    fourth->Link = fivth;

    fivth->data = 5;
    fivth->Link = sixth;

    sixth->data = 6;
    sixth->Link = head;

    // head = deleteAtStart(head);
    // head = deleteAtEnd(head);
    // head = deletionAtIndex(head, 2);

    traversingTheLinkedList(head);

    return 0;
}