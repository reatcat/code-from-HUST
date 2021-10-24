#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;

int n,m;
ll s;
ll ans;
int w[200005],v[200005];
int l[200005],r[200005];

ll labs(ll a){if(a<0)return -a;else return a;}

bool ok(int k){
    int i,j;
    int g[200005],t[200005];
    ll res=0;
    memset(g,0,sizeof(g)),memset(t,0,sizeof(t));
    for(i=1;i<=n;i++){
        if(w[i]>=k){
            g[i]=g[i-1]+v[i],t[i]=t[i-1]+1;
        }else g[i]=g[i-1],t[i]=t[i-1];
    }
    ll u,v;
    for(i=1;i<=m;i++){
        u=g[r[i]]-g[l[i]-1];
        v=t[r[i]]-t[l[i]-1];
        res+=u*v;
    }
    ans=min(ans,labs(res-s));
    return res-s>0;
}

int main(){
    int i,j;
    ll lc,rc=-1;
    scanf("%d%d%lld",&n,&m,&s);
    for(i=1;i<=n;i++)scanf("%d%d",&w[i],&v[i]),rc=max(rc,(ll)w[i]);
    for(i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
    ll mid;
    lc=0,rc++,ans=1e20;
    while(lc<rc){
        mid=lc+rc>>1;
        if(!ok(mid))rc=mid;
        else lc=mid+1;
    }
    printf("%lld",ans);
    return 0;
}
