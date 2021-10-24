#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159//不用;
int main()
{
    int f,newint;
    unsigned short p,k;//无符号整型
    double c,r,s;
    /*任务一*/
    printf("Input Fahrenheit:");
    scanf("%d",&f);
    c=5.0/9.0*(f-32);//精度提升
    printf("\n%d(F)=%.2f(C)\n\n",f,c);
    /*任务二*/
    printf("input the radius r:");
    scanf("%lf",&r);//输入double类型
    s=PI * r * r;
    printf("\nThe acreage is %.2f\n\n",s);
    /*任务三*/
    k=0xa1b2;
    p=0x8423;
    newint=p&0xff00|k>>8;
    printf("new int =%#x\n\n",newint);

    return 0;
}

