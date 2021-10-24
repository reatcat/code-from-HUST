#include<stdio.h>
#define mod 998244353
#define ll long long
#define N 1000005
int n,q,a[N];
ll yhsj[2003][2003],ans;
int read(){
 	int k=0,f=1;char c=getchar();
 	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
 	for(;c<='9'&&c>='0';c=getchar())k=(k<<3)+(k<<1)+c-'0';
 	return f*k;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
	yhsj[0][0]=1ll;
	for(int i=1;i<=2002;i++){
		for(int j=1;j<=2002;j++)yhsj[i][j]=(yhsj[i-1][j]+yhsj[i-1][j-1])%mod;
	}
	q=read();
	for(int i=1,x,y;i<=q;i++){
		x=read(),y=read();ans=0ll;int j=y;x++;
		for(int k=1;yhsj[x][k]!=0;k++){
			if(j==n)ans=(a[j]*yhsj[x][k]%mod+ans)%mod,j=1;
			else ans=(a[j]*yhsj[x][k]%mod+ans)%mod,j++;
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
}
