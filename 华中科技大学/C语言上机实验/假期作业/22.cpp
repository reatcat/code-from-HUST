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
		}//总时间累加
		for(j=1;j<=a[i];j++)
			for(k=sum/2;k>=work[j];k--)//只要是总和的一半
				dp[k]=max(dp[k],dp[k-work[j]]+work[j]);//01背包
		t+=sum-dp[sum/2];//累加为另一个脑子
		for(j=1;j<=sum/2;j++)
		dp[j]=0;//清零
	}
    printf("%d",t);
    return 0;
}
