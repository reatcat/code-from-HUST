#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n=100,k;

    for(n=100; n<1000; n++)
    {
        k=n*n;
        k=k%1000;
        if(k==n)
        {
            printf("%d\n",n);
        }
    }

    return 0;
}
