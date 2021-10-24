#include<stdio.h>
#include<string.h>
int  removeDuplicate(int a[],int n) //去重 
{
	int i,j,temp;
	for(i=0;i<n;i++)		//循环判断数组中每一个数
	{
		for(j=i+1;j<n;j++)	//判断a[i]后边的数是否和a[i]相等
		{
			if(a[i]==a[j])
			{
				for(temp = j;temp<n;temp++)
					a[temp]=a[temp+1];	//将a[j]后面的元素全往前移一个位置
				j--;	//a[j+1]取代a[j]位置，为使下次从a[j+1]开始查找,j减一
				n--;	//数组长度减一
			}
		}
	}
	return n;
}
int  bubble_sort(int *a,int n)
{
	int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	n=removeDuplicate(a,n);
	bubble_sort(a,n);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{   
	if(!a[i])
	continue;
	else
		printf("%d ",a[i]);
	}
	return 0;
 } 
