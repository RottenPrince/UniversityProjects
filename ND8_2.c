#include <stdio.h>
#define MAX 1000
int find_largest(FILE *fp, int argc, char **argv, char **filename);

int main(int argc, char *argv[])
{
    FILE *fp;
    char *file_name;
    *file_name = find_largest(fp, argc, argv, &file_name);
    printf("%s", file_name);
}

int find_largest(FILE *fp, int argc, char **argv, char **filename)
{
    int max, size = 0;
    fp = fopen(argv[1], "r");
    fseek(fp, 0L, SEEK_END);
    max = ftell(fp); // pirmo failo dydis
    *filename = argv[1];
    for(int i = 2; i < argc; ++i)
    {
        fclose(fp);
        fp = fopen(argv[i], "r");
        if(fp == NULL)
            ++i;
        fseek(fp, 0L, SEEK_END);
        size = ftell(fp);
        if(size > max)
        {
            max = size;
            *filename = argv[i];
        }
    }
    return **filename;
}