#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}
int a[5],i,j,k,sum,t,work[21],dp[2501];
int main(){
	for(i=1;i<=4;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=4;i++){
		sum=0;	
		for(j=1;j<=a[i];j++)
		{
		scanf("%d",&work[j]);
		sum+=work[j];
		}//��ʱ���ۼ�
		for(j=1;j<=a[i];j++)
			for(k=sum/2;k>=work[j];k--)//ֻҪ���ܺ͵�һ��
				dp[k]=max(dp[k],dp[k-work[j]]+work[j]);//01����
		t+=sum-dp[sum/2];//�ۼ�Ϊ��һ������
		for(j=1;j<=sum/2;j++)
		dp[j]=0;//����
	}
    printf("%d",t);
    return 0;
}
