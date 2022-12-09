#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int in_range(int a);
int is_empty(FILE *fp);
int ilgis(int a, int b);

int ilgis(int a, int b)
{
    int count_a=1, count_b=1;

    if(b != 0)
    {
        while(a>=10)
        {
            a /= 10;
            ++count_a;
        }
    }
    else
        count_a = 1;

    if(b != 0)
    {
        while(b>=10)
        {
            b /= 10;
            ++count_b;
        }
    }
    else
        count_b = 1;
    
    return count_a + count_b;
}

int main()
{
    
    char s[MAX], file_name[MAX] = "in.txt";
    FILE *fp;
    printf("Programa praso pateikti realuji skaiciu faile in.txt");
    printf(".\nTas skaicius turi buti >= 10 ir <= 1000 ir su ne daugiau kaip 3 skaiciais po kablelio\n");
    int file_flag;
    
    redo:
    file_flag = 0;
    while(file_flag != 1)// File validation
    {
        printf("Atidaromas failas pavadinimu '%s'\n", file_name);
        fp = fopen(file_name, "r");
        if(fp != NULL)// checks if file exists
            file_flag = 1;
        else
        {
            printf("Failas neegzistuoja. Iveskite failo su teisingais duomenimis pavadinima\n");
            scanf("%s", file_name);
            fclose(fp);
            printf("Ivestas failas pavadinimu '%s'\n", file_name);
        }
    }

    int flag = 0;
    int a, b, c;
    int decimal_flag = 0; // if 1 number has a decimal point

    while(flag != 1)
    {
        if(fscanf(fp, "%d", &a) == 1)
        {
            if(in_range(a) != 1)
            {
                fclose(fp);
                printf("Duomenys netinka, iveskite kito failo pavadinima\n");
                scanf("%s", file_name);
                goto redo;
            }
            char comma = fgetc(fp);
            if(comma == EOF)
            {
                b = 0;
                fclose(fp);
                flag = 1;
            }
            else if(comma != ',')
            {
                file_flag = 0;
                printf("Duomenys netinka, iveskite kito failo pavadinima\n");
                scanf("%s", file_name);
                fclose(fp);
                goto redo; 
            }
            else
            {
                if(fscanf(fp, "%d", &b) == 1 && fgetc(fp) == EOF && b > 0 && b < 1000)
                {
                    flag = 1;
                    decimal_flag = 1;
                    fclose(fp);
                }
                else
                {   
                    file_flag = 0;
                    printf("Duomenys netinka, iveskite kito failo pavadinima\n");
                    scanf("%s", file_name);
                    fclose(fp);
                    goto redo;
                }
            } 
        }
        else
        {
            file_flag = 0;
            printf("Duomenys netinka, iveskite kito failo pavadinima\n");
            scanf("%s", file_name);
            fclose(fp);
            goto redo;
        }
    }    
   
    int lenght = ilgis(a, b);
    printf("skaiciaus ilgis = %d\n", lenght);
    return 0;
}

int in_range(int a) // checks if input is within required range
{
    //printf("FUNKCIJA CALLINTA a = %.4f\n", *a);
    if(a <= 10 || a >= 1000)
        return 0;
    return 1;
}

int is_empty(FILE *fp)
{
    int counter=0;
    while(1) 
    {
        if( feof(fp) ) 
        { 
            break;
        }
        ++counter;
    }
    if(counter==1)
    {
        return 0;
    }
    return 1;
}
