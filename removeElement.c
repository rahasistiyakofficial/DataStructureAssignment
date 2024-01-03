#include <stdio.h>

void removeElement(int source[], int size, int idx)
{
    if (idx < 0 || idx >= size)
    {
        printf("Invalid index. Element not removed.\n");

        return;
    }

    for (int i = idx; i < size - 1; i++)
    {
        source[i] = source[i + 1];
    }
    source[size - 1] = 0;
}

int main()
{
    int source[] = {10, 20, 30, 40, 50, 0, 0};
    int size = 7;
    int idx = 2;

    printf("Original array: [ ");
    for (int i = 0; i < size; i++)
    {

        printf("%d ", source[i]);
    }
    printf("]\n");

    removeElement(source, size, idx);

    printf("After removing the element at index %d: [ ", idx);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", source[i]);
    }
    printf("]\n");

    return 0;
}