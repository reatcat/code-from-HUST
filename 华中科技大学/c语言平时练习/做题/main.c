#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
int n,i,m,h,a,b;
scanf("%d",&n);
for(i=49;i<=n;i++){
        b=sqrt(i);
if(i==b*b){
    for(a=0;a<=i;a++)
    if((i-a*a)%10==0){
       m= (i-a*a)/10;
       h=sqrt(m);
       if(m==h*h)
      printf("%d=%d*%d=%d*%d*10+%d*%d\n",i,b,b,h,h,a,a);
       else break;
    }
}

}



    return 0;
}


