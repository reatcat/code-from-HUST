#include<stdio.h>
void isPerfect(int n)
//�����isPerfect�������ж�����n�Ƿ�Ϊ��ȫ��
{
    /**********   Begin   **********/
    int a[10000];
    int i, count = 0, sum = 0, d = 0;
    for (i = 1;i < n-1;i++)
    {
        if (!n % i)
        {
            a[d] = i;
            sum += i;
            d++;
        }
    }
    if (sum != n) printf("%d is not a perfect number", n);
    else
    {
        printf("%d=", n);
        for (;d > 1;d--) {
            printf("%d+", a[count]);
            count++;
        }
        printf("%d", a[d]);
    }
    /**********    End    **********/
}
void main()
{
    int n;
    scanf_s("%d",&n);
    isPerfect(n);
}