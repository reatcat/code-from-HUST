#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int M, N;
	scanf("%d %d",&M,&N);
	int a[M];
	int i=0;
	for(i=0;i<M;i++)
	    a[i]=0;//��ʼ�������±��Ϊ0 
	int k=0,count=1,l=M;//��count��Ϊ1�� 
	i=0;//��ʼ��i 
	for(l=M;l>1;) 
	{
		if (count==N)
		{
			k=(i)%M;
			a[k]=1;
			l--;
			count=0;//��Ϊ��ʱ�����±껹�ڳ���Ԫ�أ�����һ��Ԫ�ز��Ǵ�1��ʼ�������ʴ˴�Ӧ��count��Ϊ0�����±�i��������һ��δ����Ԫ��ʱcount�ټ�1
		}
		i++;
		if (a[i%M]!=1)//û�г��ֱ�� 
			count++;
	}
	for(i=0;i<M;i++){
		if(!a[i])
		printf("%d",i+1);//��������±�+1 
	}
}

