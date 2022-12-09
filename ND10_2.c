#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

int strcmp(const char *string1, const char *string2)
{
    int i = 0;
    while(string1 != '\0' || string2 !='\0')
    {
        if(string1[i] == string2[i])
        {
            ++i;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    assert(strcmp("ok", "ok") == 0);
    assert(strcmp("asdf", "asdf") == 0);
    assert(strcmp("0", "1") == -1);
    assert(strcmp("", "") == -1);
    assert(strcmp("", " ") == -1);
    

    return 0;
}