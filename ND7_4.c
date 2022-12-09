#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000
void generateArray(int data[], int size, int low, int high);


int main()
{
    int size = 10;
    int data[size];
    int low = 5, high = 1654;
    generateArray(data, size, low, high);
    
        
    return 0;
}

void generateArray(int data[], int size, int low, int high)
{
    srand(time(NULL));
    
    for(int i = 0; i < size; ++i)
    {
        int t = rand();
        if(t >= low && t <= high)
        {
            data[i] = t;
            printf("%d\n", data[i]);
        }
            
       
    }
}