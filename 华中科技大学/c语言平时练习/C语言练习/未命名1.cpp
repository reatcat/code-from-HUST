#include<stdio.h>
int average(int a[],int n)
{
	int i,j=0,k=0;
	float s;
	for(i=0;i<n;i++)
	k+=a[i];
	s=k/n;
	for(i=0;i<n;i++)
	{
		if(a[i]<s)
		j++;
	}
	return j;
}
int main()
{
	int n,a[100],i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	num=average(a,n);
	printf("%d",num);
	return 0;
}
