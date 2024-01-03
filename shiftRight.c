#include <stdio.h>
void shiftRight(int source[], int size, int k)
{
    for (int i = size - 1; i >= k; i--)
    {
        source[i] = source[i - k];
    }
    for (int i = 0; i < k; i++)
    {
        source[i] = 0;
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

    shiftRight(source, size, k);
    printf("After shifting Right by %d positions: [ ", k);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", source[i]);
    }
    printf("]\n");

    return 0;
}