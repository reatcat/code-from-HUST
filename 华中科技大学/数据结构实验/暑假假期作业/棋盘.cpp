#include<bits/stdc++.h>
using namespace std;
//#define maxn 99999999
#define max 1005
int f[max];
int n,m,x[max],y[max],z[max][max],col[max];
int sta,en,flag,s[max];
int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
void dj(int k)//djÌØË¹À­	
{
	s[k]=0;
	int t;
	int maxn;
	for(int i=1;i<=m;i++)
	{
		maxn=99999999;
    	for(int j=1;j<=m;j++)                 
    	{
        	if(f[j]==0&&s[j]<maxn)
       		{
            	maxn=s[j];
				t=j;
        	}
    	}
    	f[t]=1;
    	for(int j=1;j<=m;j++)
		{
			s[j]=min(s[t]+z[t][j],s[j]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(z,1,sizeof(z));
  	memset(s,1,sizeof(s));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&col[i]);
		if(x[i]==1&&y[i]==1)
		{
			sta=i;
		}
		if(x[i]==n&&y[i]==n)
		{
			flag=1;
			en=i;
		}
	}
	if(flag==0)
	{
		en=m+1;
		x[en]=y[en]=n;
	}
	for(int i=1;i<m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(abs(x[i]-x[j])+abs(y[i]-y[j])==1)
			{
				z[i][j]=z[j][i]=abs(col[i]-col[j]);
			}
			if(abs(x[i]-x[j])+abs(y[i]-y[j])==2)
			z[i][j]=z[j][i]=2+abs(col[i]-col[j]);
		}
	}
	if(flag==0)
	{
		for(int i=1;i<=m;i++)
		{
			if(abs(x[i]-x[en])+abs(y[i]-y[en])==1)
			{
				z[i][en]=z[en][i]=2;
			}
		}
		m++;
	}
	dj(sta); 
	if(s[en]<99999999)
	printf("%d",s[en]);
	else
	printf("-1");
	return 0;
}

