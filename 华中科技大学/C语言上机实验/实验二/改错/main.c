#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159//����;
int main()
{
    int f,newint;
    unsigned short p,k;//�޷�������
    double c,r,s;
    /*����һ*/
    printf("Input Fahrenheit:");
    scanf("%d",&f);
    c=5.0/9.0*(f-32);//��������
    printf("\n%d(F)=%.2f(C)\n\n",f,c);
    /*�����*/
    printf("input the radius r:");
    scanf("%lf",&r);//����double����
    s=PI * r * r;
    printf("\nThe acreage is %.2f\n\n",s);
    /*������*/
    k=0xa1b2;
    p=0x8423;
    newint=p&0xff00|k>>8;
    printf("new int =%#x\n\n",newint);

    return 0;
}

