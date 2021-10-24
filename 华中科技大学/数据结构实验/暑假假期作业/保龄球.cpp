#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
int n;
//int a[n+1];
map<int,int>a;//Ïàµ±ÓÚÍ° 
int main ()
{
	scanf("%d",&n);
	int temp;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		a[temp]=i;
	}
	int q;
	scanf("%d",&q);
//	
//	int m;
//	for(;q>0;q--){
//		 scanf ("%d",&m);
//		 int state=0;
//	for(int i=1;i<=n&&!state;i++)
//	{
//		if(a[i]==m){
//		state=1;
//		printf("%d\n",i);	
//		}
//	}
//	if(!state)
//	printf("0\n");
//	}
	int m;
	for(int i=1;i<=q;i++){
        scanf ("%d",&m);
        printf("%d\n",a[m]);
    }
	return 0;
 } 

