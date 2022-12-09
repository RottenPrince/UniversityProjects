#include <stdio.h>
#include <string.h>
#define MAX 1000

int find(int a, int b, int c);

int main()
{
    float a, b, c, mid;
    while(scanf("%f;%f;%f", &a,&b, &c) != 3 || getchar() != '\n')
    {
        printf("Netinkama ivestis\n");
        while(getchar() != '\n')
            ;
    }
    mid = find(a, b, c);
    char s[MAX], f[] = ".txt";
    printf("Iveskite failo pavadinima i kuri norite issaugoti skaiciu\n");

    int flag = 0;
    int filename_length;
    char valid[MAX];
    while (flag == 0)
    {
        scanf("%s", s);
        filename_length = strlen(s);
        for (int i = 0; i < 4; ++i)
            valid[3 - i] = s[filename_length - i - 1];
        if (strcmp(valid, ".txt") == 0)
            flag = 1;
        else
            printf("Neteisingas failo formatas. Iveskite vel: ");
    }

    FILE *fp = fopen(s, "w");
    fprintf(fp, "%f", mid);
    fclose(fp);
    return 0;
}

int find(int a, int b, int c)
{
    if((a<b) && (b<c))
    {
        return b;
    }
    else if((b<a) && (a>c))
    {
        return a;
    }
    else if((c<a) && (c>b))
    {
        return c;
    }
}