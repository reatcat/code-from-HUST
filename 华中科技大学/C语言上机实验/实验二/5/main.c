#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short x,m,n,a=0xff;
    scanf("%d%d%x",m,n,x);
    if(m>=0&&m<=15&&n>=1&&n<=(16-m)){
     x=x<<(15-m)&(~0)<<16-n;
    printf("%hx",x);
    }
    return 0;
}
