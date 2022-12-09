#include <stdio.h>

int getFactorial(int number);

int main()
{
    int number = 1;
    
    int t = getFactorial(number);
    if(t == 0)
        printf("No\n");
    printf("%d", t);
        
    return 0;
}

int getFactorial(int number)
{
    int factorial = number;
    if(number == 0) 
        return 0;
    if(getFactorial(number-1) == 0) 
        return factorial;
    else
        factorial *= getFactorial(number-1);
    
}
