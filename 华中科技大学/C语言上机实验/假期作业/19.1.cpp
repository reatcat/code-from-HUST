#include<stdio.h>
int a[1000],b[1000],c[1000],d[1000];
int main() 
{
    int n,x,y,i;
    scanf("%d", &n);
    for(i=0;i<n;i++) 
	{
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }
    scanf("%d%d",&x,&y);
    int ans=-1;
    for(i=0;i<n;i++) {
        if(x>=a[i]&&y>=b[i]&&x<=a[i]+c[i]&&y<=b[i]+d[i]) 
		{
            ans = i + 1;//ans的最终值恰好是最上面的那张地毯编号
        }
    }
    printf("%d\n",ans);
    return 0;
}
