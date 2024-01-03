#include <stdio.h>
#include <stdlib.h>
#define null NULL

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = null;
    newNode->prev = null;
    return newNode;
}
void addNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    if (head == null)
    {
        head = newNode;
        return;
    }
    while (temp->next != null)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void reverseLinkedList(struct Node *head)
{
    struct Node *current = head;

    while (current != null)
    {
        struct Node *temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
}
void printList(struct Node *head)
{
    while (head != null)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
}
int main()
{
    struct Node *head = createNode(5);
    addNode(head, 25);
    addNode(head, 20);
    printf("Original Linked List: ");
    printList(head);
    reverseLinkedList(head);
    printf("Reversed Linked List: ");
    printList(head);
    return 0;
}