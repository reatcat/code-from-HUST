#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,k,p,i,d;
    printf("Input m,n\n");
    scanf("%d%d",&m,&n);
    if(m<n)
    {
        m=m<<8;//����m,m
        m=m+n;
        n=m>>8;
        m=m&0xff;
    }
    k=0;
    while(m&(~0)>>31&&n&(~0)>>31)//�ж�ż��
    {
        m>>1;//��2Լ��
        n>>1;
        k++;
    }
    p<<k;//p=2��k�η�
    while((d=m-n)!=n)
    {
        if(d>n) m=d;
        else m=n^d^(n=d);//��Ϊһ�����ʽ���
    }
    d*=p;
    printf("the greatest common divisor : %d",d);
    return 0;
}
