#include <stdio.h>
#include <stdlib.h>

int main()
{
     int salary,x;
    double tax;
    scanf("%d",&salary);
    x=salary/1000;
    if(x==0)
        tax=0;
    else if(x==1)
     tax=(salary-1000)*0.05;
    else if(x==2)
        tax=(salary-2000)*0.1+50;
    else if(x==3)
        tax=(salary-3000)*0.15+150;
    else if(x==4)
        tax=(salary-4000)*0.2+300;
    else if(x>=5)
        tax=(salary-5000)*0.25+500;

    printf("tax=%lf",tax);
    return 0;
}
