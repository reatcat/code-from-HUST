#include<stdio.h> 
int main(){
    int n,a[100],b[100]={0},ans=0,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);  
    for(i=0;i<n;i++)
	{
        for(j=i+1;j<n;j++)
		{
            for(k=0;k<n;k++)
			{
                if(a[k]==a[i]+a[j]&&b[k]!=1)
				{
                    ans++;
                    b[k]=1;//ШЅжи 
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
