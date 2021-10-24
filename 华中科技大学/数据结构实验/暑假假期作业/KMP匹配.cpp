#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define max 100000 
char a[max],b[max];
int ans[max];//¥Ê∑≈±Í«© 
int la,lb;
int main()
{
	scanf("%s%s",a+1,b+1);
	la=strlen(a+1);
	lb=strlen(b+1);
	int j;
	for (int i=2;i<=lb;i++)
	   {     
	   while(j&&b[i]!=b[j+1])
        j=ans[j];    
       if(b[j+1]==b[i])j++;    
        ans[i]=j;
       }
    j=0;
    for(int i=1;i<=la;i++)
	   {
          while(j>0&&b[j+1]!=a[i])
           j=ans[j];
          if (b[j+1]==a[i]) 
           j++;
          if (j==lb) {
//		  printf("%d\n",i-lb+1);
		  cout<<i-lb+1<<endl;
		  j=ans[j];}
       }

    for (int i=1;i<=lb;i++)
    printf("%d ",ans[i]);
   	return 0;
}

