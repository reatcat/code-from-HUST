#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    printf("%p\n",&a);
    printf("%p\n",a);
    printf("%p\n",&a[0]);
    printf("%p\n",&a[1]);
    return 0;
}
