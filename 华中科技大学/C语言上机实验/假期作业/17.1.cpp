#include<stdio.h>
typedef struct pai
{
	int k;
	int s;
} p;
void sort(p *a,int n)
{
	p temp;
	int i,j;
	int flag=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<j-i-1;j++)
		{
			if(a[j].s<a[j+1].s)
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				flag=1;
			}
			else if(a[j].s==a[j+1].s)
			{
				if(a[j].k>a[k+1].k)
				{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				flag=1;
				}
			}
		}
		if(!flag)
		break;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	p a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].k,&a[i].s);
	}
	sort(a,n);
	m=m*1.5;
	while(a[m-1].s==a[m].s)
	m++
	printf("%d %d\n",a[m-1])
	return 0;
}
