#include <stdio.h>
#include <ctype.h>
int getPositiveNumber(char *msg);



int main()
{
    int number = 0;
    char msg;
    getPositiveNumber(&msg);
    printf("Skaicius: %c", msg);
    return 0;
}

int getPositiveNumber(char *msg)
{
    printf("Iveskite teigiama skaiciu\n");
    while(1)
    {
        char f;
        scanf("%c", &*msg);
        
        if(*msg >= '0' && *msg <= '9')
        {
            return 0;
        }
        else
            printf("Iveskite skaitemeni is naujo\n");
        
        
    }
        

}

