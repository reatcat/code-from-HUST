#include<math.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
int max(int a,int b)
{
	return (a>b)?a:b;
}
int min(int a,int b)
{
	return (a>b)?b:a;
}
int n,m,v[200010],w[200010];
int l[200010],r[200010];
long long s,cur,sum,ans,pre_v[200010]={0},pre_n[200010]={0};
int check(int mid)
{
	cur=0;sum=0;//��Ϊÿ�ζ��ֳ���midֵ����һ��
	for(int i=1;i<=n;i++)
	{
		if(w[i]>=mid)pre_v[i]=pre_v[i-1]+v[i],pre_n[i]=pre_n[i-1]+1;//������������ż�¼ǰ׺��
		else pre_v[i]=pre_v[i-1],pre_n[i]=pre_n[i-1];
	}
	for(int i=1;i<=m;i++)
	cur+=(pre_n[r[i]]-pre_n[l[i]-1])*(pre_v[r[i]]-pre_v[l[i]-1]);//������ֵ
	sum=llabs(cur-s);//llabs()��algorithm����ĺ���
	return cur>s;//�ж�cur��s�Ĵ�С
}
int main()
{
	int maxx=-1,minn=0x7fffffff;
	scanf("%d%d%lld",&n,&m,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&v[i]);
		maxx=max(maxx,w[i]);//ȷ������������
		minn=min(minn,w[i]);
	}
	for(int i=1;i<=m;i++)
	scanf("%d%d",&l[i],&r[i]);
	int r=maxx,l=minn,mid,cnt=0;
	ans=999999999999999;//��Ҫ������һ��
	while(l<=r)
	{
    	cnt++;
        if(cnt>50)break;//��ֹ����ѭ��
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
		if(sum<ans)ans=sum;
	}
	printf("%lld",ans);//ע��lld
	return 0;
}
