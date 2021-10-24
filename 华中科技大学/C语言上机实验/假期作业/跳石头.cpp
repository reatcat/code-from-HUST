#include<stdio.h>
int main()
{
	int l,n,m,left,right,mid,now,i,a[50005],s,ans;
	scanf("%d%d%d",&l,&n,&m);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	left=0;right=l;
	while(left<=right)
	{
		mid=(right+left)/2;
		now=0;
		s=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[now]<mid)
				s++;
			else 
			now=i;
			}
		if(s<=m)
		{
			ans=mid;
			left=mid+1;
			}
		else 
		right=mid-1;
		}
	printf("%d",ans);
	return 0;
}
 
