#include <stdio.h>

int input(int *year, int *month, int *day);
int output(int weekday, char **savaites_diena, FILE *fp);



int main()
{
    FILE *fp = fopen("week.txt", "r");
    int y, m, d;
    printf("Programa suskaiciuoja duotos datos savaites diena.\nIvestyje pateikite duomenis formatu YYYY-MM-DD\n");
    while(input(&y, &m, &d) != 1)
    {
        printf("Netinkamas datos formatas. Bandykite is naujo\n");
        while(getchar() != '\n')
            ;
    }

    int weekday  = (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4- y / 100 + y / 400) % 7; 
    char *savaites_diena;

    output(weekday, &savaites_diena, fp);

    printf("%s\n", savaites_diena);
    return 0;
}

int output(int weekday, char **savaites_diena, FILE *fp)
{
    for(int i = 0; i < weekday; ++i)
    {
        fscanf(fp, "%s", *savaites_diena);
    }
}

int input(int *year, int *month, int *day)
{
    if(scanf("%d-%2d-%2d", year, month, day) == 3)
    {
        if(*year >= 0)
        {
            if(*month >= 1 && *month <= 12)
            {
                if(*day >= 1 && *day <= 31)
                {
                    
                    return 1;
                }
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 0;

}