#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
double e,s=0.0,x=1.0,n=1;
int sign=1;
scanf("%lf",&e);
do{
    s+=x;
    n+=2;
    sign=-sign;
    x=sign/n;

} while(fabs(x)>e/10);
s=4*s;
printf("%.6lf",s);
    return 0;
}

