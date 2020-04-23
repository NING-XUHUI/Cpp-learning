

#include <stdio.h>
#include <string.h>


int main()
{
    int a = 0;
    int* p = &a;
    int* q = p;
    

    printf("%d %d %d",*&a,*p,*q);
}