#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int createArray(int n, int **arr, int low, int high); // 1a
int* generateArray(int n, int low, int high); // 1b

int main()
{
    int n, *arr1, *arr2;
    printf("Ivesktie masyvo dydi: ");
    while(scanf("%d", &n) != 1 || getchar() != '\n')
    {
        printf("Netinkama ivestis\n");
        while(getchar() != '\n')
            ;
    }

    int low = 43;
    int high = 5600;
    
    createArray(n, &arr1, low, high);
    for(int i = 0; i < n; ++i)
        printf("%d\n", arr1[i]);
    
    arr2 = generateArray(n, low, high);
    for(int i = 0; i < n; ++i)
        printf("%d\n", arr2[i]);
    return 0; 
}

int* generateArray(int n, int low, int high)
{
    srand(time(NULL));
    int *arr = (int *)calloc(n, sizeof(int));
    if(arr == NULL)
        return 0;
    printf("Masyvo reziai [%d;%d]\n", low, high);
    for(int i = 0; i < n; ++i)
    {
        int t = (rand() % (high - low + 1) + low);
        *(arr + i) = t;
    }
    return arr;
}

int createArray(int n, int **arr, int low, int high)
{
    srand(time(NULL));
    *arr = (int *)calloc(n, sizeof(int));
    if(arr == NULL)
        return 0;
    printf("Masyvo reziai [%d;%d]\n", low, high);
    for(int i = 0; i < n; ++i)
    {
        int t = (rand() % (high - low + 1) + low);
        (*arr)[i] = t;
    }
}