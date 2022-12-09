#include <stdio.h>

long getFileSize(char *fileName);

long getFileSize(char *fileName)//fseek()  "rb" ftell()
{
    FILE *fp = fopen(fileName, "rb");
    int c = fgetc(fp);
    if(c != EOF)
    {
        fseek(fp, 0, SEEK_END); // moving pointer to end
        //printf("%ld", ftell(fp)); // printing position of pointer
        return ftell(fp);
    }
    else
        return -1;
}

int main()
{
    char name[] = "test1.txt";
    printf("%d", getFileSize(name));
}