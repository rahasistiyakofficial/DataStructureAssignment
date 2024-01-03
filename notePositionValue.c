#include <stdio.h>
#include <stdlib.h>
#define null NULL

struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = null;
    return newNode;
}
void addNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    while (temp->next != null)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void addAfterValue(struct Node *head, int value, int data)
{
    struct Node *temp = head;
    while (temp != null)
    {
        if (temp->data == value)
        {
            struct Node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}
void addAtPosition(struct Node *head, int position, int data)
{
    struct Node *newNode = createNode(data);
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp != null && i < position; ++i)
    {
        temp = temp->next;
    }
    if (temp == null)
    {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeByValue(struct Node *head, int value)
{
    struct Node *temp = head;
    struct Node *prev = null;
    if (temp != null && temp->data == value)
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != null && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == null)
    {
        printf("Value not found in the list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void removeAtPosition(struct Node *head, int position)
{
    struct Node *temp = head;
    if (head == null)
    {
        printf("List is empty\n");
        return;
    }
    if (position == 0)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != null && i < position - 1; i++)
    {

        temp = temp->next;
    }
    if (temp == null || temp->next == null)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
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
    addNode(head, 10);
    addNode(head, 15);
    addAfterValue(head, 10, 25);
    removeByValue(head, 10);
    addAtPosition(head, 2, 20);
    removeAtPosition(head, 3);
    printf("Linked List: ");
    printList(head);
    return 0;
}