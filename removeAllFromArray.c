#include <stdio.h>

void removeAll(int source[], int size, int element)
{
    int newIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (source[i] != element)
        {
            source[newIndex] = source[i];

            newIndex++;
        }
    }

    for (int i = newIndex; i < size; i++)
    {
        source[i] = 0;
    }
}

int main()
{
    int source[] = {10, 2, 30, 2, 50, 2, 2, 0, 0};
    int size = 9;
    int element = 2;

    printf("Original array: [ ");
    for (int i = 0; i < size; i++)
    {

        printf("%d ", source[i]);
    }
    printf("]\n");

    removeAll(source, size, element);

    printf("After removing all occurrences of %d: [ ", element);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", source[i]);
    }
    printf("]\n");

    return 0;
}