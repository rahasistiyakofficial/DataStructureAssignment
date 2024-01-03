#include <stdio.h>

void selectionSort(int array[], int size)
{
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
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