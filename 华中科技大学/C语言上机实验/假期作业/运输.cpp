#include<stdio.h>
int max(int a,int b)
{
	if(a>=b)
	return a;
	else 
	return b;
}
int min(int a,int b)
{
	if(a>=b)
	return b;
	else 
	return a;
}
int main()
{
	int n,l,p,max1=0,min1=0,i;
    scanf("%d%d",&l,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p);
        max1=max(max1,max(l-p+1,p));
        min1=max(min1,min(l-p+1,p));
    }
    printf("%d %d",min1,max1);
	return 0;
 } 
