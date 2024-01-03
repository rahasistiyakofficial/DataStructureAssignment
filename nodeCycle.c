#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
bool hasCycle(struct Node *head)
{
    struct Node *oneStepMove = head;
    struct Node *twoStepMove = head;
    while (twoStepMove != null && twoStepMove->next != null)
    {
        oneStepMove = oneStepMove->next;
        twoStepMove = twoStepMove->next->next;

        if (oneStepMove == twoStepMove)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    struct Node *head = createNode(5);
    addNode(head, 10);
    addNode(head, 15);
    addNode(head, 20);
    struct Node *temp = head;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    temp->next = head->next;

    bool cycleExists = hasCycle(head);
    if (cycleExists)
    {
        printf("Has Cycle: Yes\n");
    }
    else
    {
        printf("Has Cycle: No\n");
    }
    return 0;
}