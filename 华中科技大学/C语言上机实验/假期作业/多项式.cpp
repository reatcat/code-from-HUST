#include<stdio.h>
int n,a[105];
int abs(int n)
{
    return n>0?n:-n;
}
int main()
{
    scanf("%d",&n);
    int i;
    for(i=n;i>=0;i--)
      scanf("%d",&a[i]);//�����һ�ʼ 
    int flag=1;//��һ�� 
    for(i=n;i>=0;i--)
    {
        if(a[i]==0)
		continue;//�ж��Ƿ�Ϊ0 
        if(flag==0&&a[i]>0)
		printf("+");
        if(a[i]<0)
		printf("-");
        if(abs(a[i])!=1||i==0)
		printf("%d",abs(a[i]));
        if(i==0)
		continue;
        printf("x");
        if(i==1)
		continue;
        printf("^%d",i);
        flag=0;
    }
    if(flag==1)
	printf("0");
    printf("\n");
    return 0;
}
