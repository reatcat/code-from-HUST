#include<stdio.h>
int jug(int m, int n)
{
    int ret=1;
    int i=0;
    int b;
    char a[10];
    while(m)
    {
        a[i++]=m%10;
        m/=10;
    }
    while(n)
    {
        a[i++]=n%10;
        n/=10;
    }
    if(i==9)a[9]=0;
    for(i=0; i<10&&ret; i++)
    {
        for(b=i+1; b<10&&ret; b++)
        {
            if(a[i]==a[b])
                ret=0;
        }
    }
    return ret;
}
int main()
{
    int m,n,i;
    printf("请输入2~79之间的数\n");
    scanf("%d",&i);
    for(n=1234; n<98765; n++)
    {
        m=n*i;
        if(m>1e5)
            break;
        else if(jug(m,n))
            printf("%d/%05d=%d\n",m,n,i);
    }
    return 0;
}
