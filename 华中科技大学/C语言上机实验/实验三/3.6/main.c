#include <stdio.h>
#include <stdlib.h>
long cifang(int a, int b)
{
    int c=1,i=0;
    for(i=0; i<b; i++)
    {
        c=c*a;
    }
    return c;
}
int dec(int n)
{
    int flag=0,k,i=2;
    k=n;
    if(n!=2)
    {
        do
        {
            if(n%i==0)
                flag=1;
            i++;
        }
        while(i<k);
    }

    return flag;
}
int main()
{
    long m;
    printf("请输入正整数m\n");
    scanf("%ld",&m);
    int i,a,b;
    for(i=2; (a=cifang(2,i)-1)<m; i++)
    {
        a=cifang(2,i)-1;
        b=dec(a);
        if(b==0)
        {
            printf("M(%d)=%d\n",i,a);
        }
    }
    printf("");
    return 0;
}
