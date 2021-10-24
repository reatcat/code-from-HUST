#include<cstdio>
#define max 10000
struct edge
{
	int v,w,ne;
}a[max];
int n,p,tmp;
int c[max];
int u[max],h[max],in[max],out[max];
int v[max];
int s,d,w;
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&u[i]);
		if(c[i]>0)
		u[i]=-1;//ÐË·Ü×´Ì¬ 
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&s,&d,&w);
		a[++tmp]=(edge){d,w,h[s]};
		h[s]=tmp;
		in[d]++;
		out[s]++;
	}
	for(int tmp=1;tmp<=n;tmp++)
	{
		for(int i=1;i<=n;i++)
		{
			if(in[i]==0&&v[i]==0)
			{
				v[i]=1;
				if(u[i]!=-1)c[i]-=u[i];
				for(int j=h[i];j>0;j=a[j].ne)
				{
					if(c[i]>0)
					{
						c[a[j].v]+=c[i]*a[j].w;
					}
					in[a[j].v]--;
				}
				break;
			}
		}
	}
	int flag=0;
	for(int tmp=1;tmp<=n;tmp++)
	{
		if(out[tmp]==0&&c[tmp]>0)flag=1;
	}
	if(flag)
	{
		for(int tmp=1;tmp<=n;tmp++)
		{
			if(out[tmp]==0&&c[tmp]>0)
			{
				printf("%d %d\n",tmp,c[tmp]);
				
			}
		}
	}
	else
	{
		printf("NULL");
	}
	return 0;
}
