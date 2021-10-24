#include <stdio.h>
#define MAXSIZE 10000
int a[200001],b[200001],ta,tb,x,y,n;
int main(){
	scanf("%d",&n);
	int i=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(x==0)
		{
			scanf("%d",&y);
			a[++ta]=y;
			if(x>b[tb])
			b[tb+1]=x;
			else b[tb+1]=b[tb];
			tb++;
		}
		else if(x==1)ta--,tb--;
		else if(x==2)printf("%d",b[tb]);
	}
	return 0;
}

