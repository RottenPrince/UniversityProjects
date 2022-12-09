#include<stdio.h>
#include<string.h>
#include <assert.h>

void MemCpy(void *dest, void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (int i=0; i<n; i++)
        cdest[i] = csrc[i];
}

int main()
{
    char src[] = "asdfasdf asdfasdf";
    char dest[100];
    MemCpy(dest, src, strlen(src)+1);
    assert(*dest == *src);

   *src = "asdfasdfasdfasdf";
    MemCpy(dest, src, strlen(src)+1);
    assert(*dest == *src);

    *src = "asdfasdfasdfasdfasdf";
    MemCpy(dest, src, strlen(src)+1);
    assert(*dest == *src);

    return 0;
}
