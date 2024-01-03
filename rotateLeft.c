#include <stdio.h>

void rotateLeft(int source[], int size, int k)
{
    int temp[k];

    for (int i = 0; i < k; i++)
    {
        temp[i] = source[i];
    }

    for (int i = 0; i < size - k; i++)
    {
        source[i] = source[i + k];
    }
    for (int i = size - k, j = 0; i < size; i++, j++)
    {
        source[i] = temp[j];
    }
}

int main()
{
    int source[] = {10, 20, 30, 40, 50, 60};
    int k = 3;
    int size = sizeof(source) / sizeof(source[0]);

    printf("Original array: [ ");
    for (int i = 0; i < size; i++)
    {

        printf("%d ", source[i]);
    }
    printf("]\n");

    rotateLeft(source, size, k);

    printf("After rotating left by %d positions: [ ", k);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", source[i]);
    }
    printf("]\n");

    return 0;
}