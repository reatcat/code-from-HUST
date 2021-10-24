#include <iostream>
#include <algorithm>//借用（sort） 
using namespace std;
#define maxm 555555
#define maxn 5555
struct EDGE {
	int u,v,w;
} edge[maxm];
int n,m;
int f[maxn];
int find(int x) {
	if (f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
int compare(EDGE a,EDGE b)
{
	if(a.w<b.w) return 1;
	else return 0;
 } 
int main() {
	cin>>n>>m;
	for (int i=1; i<=n; i++) 
	f[i]=i;
	for (int i=1; i<=m; i++) {
		cin>>edge[i].u;
		cin>>edge[i].v;
		cin>>edge[i].w;
	}
	sort(edge+1,edge+1+m,compare);//排序，其实可以重载运算符，懒得写
	int ans=0,cnt=0;
	for (int i=1; i<=m; i++) {
		int ance1=find(edge[i].u),ance2=find(edge[i].v);
		if (ance1!=ance2) {
			ans+=edge[i].w;
			cnt++;
			f[ance1]=ance2;
		}
		if (cnt==n-1) break;
	}
	if (cnt<n-1) printf("orz\n");
	printf("%d\n",ans);
	return 0;
}

