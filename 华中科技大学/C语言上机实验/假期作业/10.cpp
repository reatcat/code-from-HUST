//#include<stdio.h>
//#include<math.h>
//int main()
//{  
//	int l;
//	scanf("%d",&l);
//	int i,n,m=1,sum=2,count=0;
//	for(n=2;;n++)
//	{
//		for(i=2;i<=sqrt(n);i++)
//		{//�ж��Ƿ�Ϊ���� 
//		if(!(m=n%i))
//		break;} 
//		if(m)
//		{
//			sum+=n;
//			if(sum>l) 
//			break;
//			printf("%d\n",n);
//			count++;
//			
//			
//		}
//		} 
//	printf("%d",count);
//	return 0;
// } 
#include <math.h>
#include <stdio.h>
int prime(int x);
int main()
{
    int l;
    scanf("%d", &l);
    int i, sum = 0, num = 0;
    for (i = 2;; i++)
        if (prime(i)) //���i������
        {
            sum += i;
            if (sum > l)
                break;
            printf("%d\n", i);
            num++;
        }
    printf("%d", num);
}

int prime(int x)//�ж�����
{
    int i;
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    for (i = 2; i <= sqrt(x); i++)
        if (!(x % i))
            return 0;
    return 1;
}
