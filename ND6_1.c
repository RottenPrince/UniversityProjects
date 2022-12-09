#include <stdio.h>



int main()
{
    int a;
    char s;
    printf("Si programa praso vartotojo ivesti viena skaiciu ir ji grazins to skaiciaus faktoriala\n");
    printf("Iveskite naturaluji skaiciu\n");
    FILE *fp; // file pointer
    
    while(scanf("%d%c", &a, &s) != 2 || s != '\n')// tikrinama ar ivesta reiksme yra naturalusis skacius
    {
        printf("Ivestis netinka, nes ivedete arba ne naturalu skaiciu arba neskaiciu\n");
        while (getchar() != '\n')
            ;
    }

    int fakt = 1;
    for(int i = 1; i <= a; ++i)
    {
        printf("%d", i);
        fakt *= i;
    }
    
    printf("%d faktorialas = %d", a, fakt);
    fp = fopen("out.txt", "w");
    fprintf(fp, "%d faktorialas = %d", a, fakt);
    fclose(fp);
 
    return 0;
}