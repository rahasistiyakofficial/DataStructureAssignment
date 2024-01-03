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
    newNode->next = NULL;
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
    printf("Linked List: ");
    printList(head);
    return 0;
}