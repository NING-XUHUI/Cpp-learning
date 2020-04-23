
#include <stdio.h>
#include <string.h>

int StrLen(const char *str)
{
    const char *p = str;
    while (*p != '\0')
        p++;
    return p - str;
}

int main()
{
    char a[1024];
    int n;
    gets(a);
    n = StrLen(a);
    printf("%d\n", n);
    return 0;
}