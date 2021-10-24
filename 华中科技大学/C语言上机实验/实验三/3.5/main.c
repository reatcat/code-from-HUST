#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,j=1,l,an;
    for(i=0; i<10; i++)
    {
        for(l=40-2*i; l>1; l=l-2)
        {
            printf("  ");
        }

        for(j=0; j<i+1; j++)
        {
            if(j==0)
                an=1;
            else
                an=an*(i-j+1)/j;
            printf("%-4d",an);
        }
        printf("\n");

    }


    return 0;
}
