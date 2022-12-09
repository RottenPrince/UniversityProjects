#include <stdio.h>
#include <string.h>
#include <assert.h>

// test strlen()

int string_length(char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        ++i;
    }
    return i;
}
int main()
{
    assert(string_length("") == 0); // passed
    assert(string_length("asdf1234") == 8); // passed
    assert(string_length("12345") == 5); // failed
    assert(string_length("\0") == 0); // passed but not correct
    assert(string_length("\n") == 0); // failed
    assert(string_length("\t") == 0); // passed but not correct

    return 0;
}