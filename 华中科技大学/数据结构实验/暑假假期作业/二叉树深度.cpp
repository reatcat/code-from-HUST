#include<cstdio>
int max(int a,int b){
	if(a>b) return a;
	else return b;
} 
struct node{
	int lchild;
	int rchild;
}tree[1000000];
int ans,n;
void dfs(int root,int dep){
	if(root==0) return;
	ans=max(ans,dep);
	dfs(tree[root].lchild,dep+1);
	dfs(tree[root].rchild,dep+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&tree[i].lchild,&tree[i].rchild);
	}
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
