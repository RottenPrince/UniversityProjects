#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000

int splitData(int size, int arr[], int size1, int **arr1, int **arr2);

int main()
{
    int size, arr[MAX] = {0};
    printf("Iveskite pradinio masyvo dydi\n");
    while(scanf("%d", &size) != 1 || size <= 0||getchar() != '\n')
    {
        while (getchar() != '\n')
            ;
    }

    srand(time(NULL));
    for(int i = 0 ; i < size; ++i)
    {
        arr[i] = rand() % 1000 + 1;
    }

    int size1, *arr1, *arr2;
    printf("Iveskite kokio dydzio bus pirmasis masyvas\n");
    while(scanf("%d", &size1) != 1 || size1 <= 0 || size1 >= size || getchar() != '\n')
    {
        printf("Bloga ivestis bandykite is naujo\n");
        while (getchar() != '\n')
            ;
    }
    splitData(size, arr, size1, &arr1, &arr2);
    return 0;
}

int splitData(int size, int arr[], int size1, int **arr1, int **arr2)
{
    int size2;
    
    size2 = size - size1;
    *arr1 = (int *)calloc(size1, sizeof(int));
    *arr2 = (int *)calloc(size2, sizeof(int));
    if(*arr1 == NULL || *arr2 == NULL)
        return 0;
    printf("Pirmas masyvas\n");
    for(int i = 0; i < size1-1; ++i)
    {
        (*arr1)[i] = arr[i];
        printf("%d\n", arr1[i]);
    }
    printf("Antras masyvas\n");
    for(int i = size1; i < size; ++i)
    {
        (*arr2)[i] = arr[i];
        printf("%d\n", arr2[i]);
    }

}
