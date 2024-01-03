#include <stdio.h>
int fibonacci(int num)
{
    if (num <= 1)
    {
        return num;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}
int main()
{
    int num = 5;
    printf("Fibonacci number at position %d is %d", num, fibonacci(num));
    return 0;
}