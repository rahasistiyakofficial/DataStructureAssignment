#include <stdio.h>
#include <stdlib.h>

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
struct Node *mergeSortedLists(struct Node *listA, struct Node *listB)
{
    struct Node *mergedList = NULL;
    struct Node *tail = NULL;

    while (listA != NULL && listB != NULL)
    {
        if (listA->data <= listB->data)
        {
            if (mergedList == NULL)
            {
                mergedList = listA;
                tail = listA;
            }
            else
            {
                tail->next = listA;
                tail = listA;
            }
            listA = listA->next;
        }
        else
        {
            if (mergedList == NULL)
            {
                mergedList = listB;
                tail = listB;
            }
            else
            {
                tail->next = listB;
                tail = listB;
            }
            listB = listB->next;
        }
    }
    if (listA != NULL)
    {
        if (mergedList == NULL)
        {
            mergedList = listA;
        }
        else
        {
            tail->next = listA;
        }
    }
    else
    {
        if (mergedList == NULL)
        {
            mergedList = listB;
        }
        else
        {
            tail->next = listB;
        }
    }
    return mergedList;
}
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *listA = createNode(5);
    listA->next = createNode(10);
    struct Node *listB = createNode(7);
    listB->next = createNode(12);
    printf("List A: ");
    printList(listA);
    printf("List B: ");
    printList(listB);

    struct Node *mergedList = mergeSortedLists(listA, listB);
    printf("Merged List: ");
    printList(mergedList);
    return 0;
}