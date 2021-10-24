#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int M, N;
	scanf("%d %d",&M,&N);
	int a[M];
	int i=0;
	for(i=0;i<M;i++)
	    a[i]=0;//初始化数组下标均为0 
	int k=0,count=1,l=M;//将count置为1， 
	i=0;//初始化i 
	for(l=M;l>1;) 
	{
		if (count==N)
		{
			k=(i)%M;
			a[k]=1;
			l--;
			count=0;//因为此时遍历下标还在出列元素，而下一个元素才是从1开始报数，故此处应将count置为0，带下标i遍历至下一个未出列元素时count再加1
		}
		i++;
		if (a[i%M]!=1)//没有出现标记 
			count++;
	}
	for(i=0;i<M;i++){
		if(!a[i])
		printf("%d",i+1);//输出数组下标+1 
	}
}

