#include<cstdio>
#define MAX 102
int max(int a,int b){
	if(a>b) return a;
	else return b;
}

int n,f[MAX];
int d[MAX]; //depth
int l[MAX]; //length
int depth,length,disu=0,disv=0;
void find(int u,int v){//并查集 
	if(u==v){//
		printf("%d",disu*2+disv);
		return;
	}
	if(d[u]==d[v]){
		v=f[v];
		u=f[u];
		disu++;
		disv++;
	}
	else if(d[u]<d[v]){
		v=f[v];
		disv++;
	}
		else {
		u=f[u];
		disu++;	
		}
	find(u,v);
	return;
}
int main(){
	scanf("%d",&n);
	int u,v;
	d[1]=1; 
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		f[v]=u;//表示祖先为u 
		d[v]=d[u]+1;
		depth=max(depth,d[v]);
		l[d[v]]++;//同深度 
		length=max(length,l[d[v]]);
	}
	scanf("%d%d",&u,&v);
	printf("%d\n",depth);
	printf("%d\n",length);
	find(u,v);
	return 0;
}
