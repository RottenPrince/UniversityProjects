#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != 2 || getchar() != '\n')
    {
        printf("Netinkama ivestis bandykite is naujo\n");
        while(getchar() != '\n')
            ;
    }
    printf("Pries funkcija a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("  Po funkcijos a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}