#include<iostream>
#include<cstring>
#include<cstdio>
#define max 1000000
using namespace std;
const int p=max; 
int base=313;
int n,m,cnt,ans=1<<30,l,r;
char s[33];
int a[max],b[max];
int appear[max],vis[max],pre[max];
//pre���ĵ���
//vis�����ڸ����Ķ������Ƿ����
//appear������Ŀǰ���������ֵĴ��� 
int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
int hashs(char a[])
{
    int len=strlen(a);
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum=(sum*base+a[i])%p;
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i]=hashs(s);
        pre[a[i]]=1;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s",s);
        b[i]=hashs(s);
        if(pre[b[i]]&&!vis[b[i]])
        {
            vis[b[i]]=1;
            cnt++;
        }
    }
    if(cnt==0)
    {
        printf("0\n0");//���� 
        return 0;
    }
    else printf("%d\n",cnt);
    l=m;//�������� 
    r=m;
    while(true)
    {
        if(!cnt)//cnt==0ʱ�Դ𰸽��и��� 
        {
            while(!vis[b[r]]) r--;
            //��������Ҷ˵㲻�Ǳ��ĵ��ʾͽ����䳤����С 
            ans=min(ans,r-l);   
            if(appear[b[r]]>=1) 
            {
                if(appear[b[r]]==1)
                {
                    cnt++;
                }
                appear[b[r]]--;
                r--;
            }
            //����Ҷ˵�ĵ����Ѿ��ڶ�������ֹ��ˣ��Ϳ�����С���䳤��
            //����Ҷ˵�ĵ���ֻ������һ�Σ��Ҷ˵������Ƶ�ͬʱҪcnt++ 
        }
        else
        {
            if(l==0) break; 
            if(vis[b[l]])
            {
                if(!appear[b[l]])//������ֵ����ڵ�ǰö�ٵĶ�������γ��֣���ǰ�����ڵ���������һ 
                {
                    cnt--;
                }
                appear[b[l]]++;//���ֵ��ʳ��ֵĴ������� 
            }
            l--;
        }
    }
    printf("%d",ans);
    return 0;
}
