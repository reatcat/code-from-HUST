#include<stdio.h>
int n,k,sum,ans,a[100];
int isprime(int a)
{
	int i;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		return 0;
	}
	return 1;
}
void xuanshu(int l,int f)//l������k������� ��f����ǰ��ѡ�����ĸ��� 
{
	if(l==0)
	{
	ans+=isprime(sum);
	}
	else{
		f++;
	    for(int i=f;i<=n;i++)
	    {
	    	sum+=a[i];
	    	l--;
	    	xuanshu(l,i);//�õݹ�����ʾ��f����ȡ
	    	sum-=a[i];//���֮ǰѡ����
	    	l++;
		}
	}
	
}
int main()
{
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	xuanshu(k,0);
	printf("%d",ans);
	return 0;
 } 
