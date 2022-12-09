#include <stdio.h>
int isInRange(int number, int low, int high);

int isInRange(int number, int low, int high)
{
    if(number >= low && number <= high)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int number = 50, low = 10, high = 100;
    if(isInRange(number, low, high) == 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}