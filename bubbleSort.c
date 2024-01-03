#include <stdio.h>

void bubbleSort(int array[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int Array[] = {90, 80, 30, 70, 20, 10};
    int size = sizeof(Array) / sizeof(Array[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    bubbleSort(Array, size);

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    return 0;
}