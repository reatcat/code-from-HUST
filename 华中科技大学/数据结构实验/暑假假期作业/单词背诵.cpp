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
//pre背的单词
//vis单词在给出的段落中是否出现
//appear单词在目前搜索到出现的次数 
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
        printf("0\n0");//讨论 
        return 0;
    }
    else printf("%d\n",cnt);
    l=m;//从右向左 
    r=m;
    while(true)
    {
        if(!cnt)//cnt==0时对答案进行更新 
        {
            while(!vis[b[r]]) r--;
            //如果区间右端点不是背的单词就将段落长度缩小 
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
            //如果右端点的单词已经在段落里出现过了，就可以缩小段落长度
            //如果右端点的单词只出现了一次，右端点向左移的同时要cnt++ 
        }
        else
        {
            if(l==0) break; 
            if(vis[b[l]])
            {
                if(!appear[b[l]])//如果这种单词在当前枚举的段落里初次出现，当前段落内的种类数加一 
                {
                    cnt--;
                }
                appear[b[l]]++;//该种单词出现的次数增加 
            }
            l--;
        }
    }
    printf("%d",ans);
    return 0;
}
