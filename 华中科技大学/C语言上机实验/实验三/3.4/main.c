#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int n=0;
    printf("ÇëÊäÈëÕıÎÄ\n");
    while((c=getchar())!=EOF)
    {
        if(c!=' ')
            n=0;
        else n++;

        if(n<=1)
            putchar(c);


    }

    return 0;
}
