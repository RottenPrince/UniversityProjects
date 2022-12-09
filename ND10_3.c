#include <stdio.h>
#include <assert.h>

char* strncpy(char* dest, const char* src, size_t num)
{
    if (dest == NULL) {
        return NULL;
    }

    char* ptr = dest;

    while (*src && num--)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return ptr;
}

int main()
{
    char dest[20];
    dest[20] = "";
    assert(strncpy(dest,"asdfr",5) == &dest);
     dest[20] = "";
    assert(strncpy(dest,"fydfsdffsjdhfh",5) == &dest);
    assert(strncpy(dest,"fjdfjdfjkdjkdf",19) == &dest);
    return 0;
}