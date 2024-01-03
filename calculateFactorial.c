#include <stdio.h>
int calculateFactorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * calculateFactorial(num - 1);
    }
}
int main()
{
    int number = 5;
    printf("Factorial of %d is %d", number, calculateFactorial(number));
    return 0;
}