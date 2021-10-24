#include <stdio.h>
#include <stdlib.h>
long dec(long k)
{
    long a[1000000] ;
    int i,j;
    for(a[0]=a[1]=0,i=2;i<k;i++)
        a[i]=1;
    for(i=2;i<k/2;i++)
        if(a[i])
    {
        for(j=i*i;j<k;j+=i)
            a[j]=0;
    }
    for(i=2,j=0;i<k;i++)
    if(a[i])
            return i;
    else return 0;

}
int main()
{
    long m;
    printf("请输入4~1000000之间的数\n");
    scanf("%ld",&m);
    long k,a,b;
    for(k=2;k<m;k++)
    {
        a=dec(k);
        if(a!=0){
            b=dec(a+2);
            if(b!=0){
                printf("(%d,%d)",a,b);
            }
        }
    }
    return 0;
}
