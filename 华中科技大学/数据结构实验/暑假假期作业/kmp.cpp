#include<iostream>
#include<cstdio>
#include<cstring>
#define max 10000000
using namespace std;
int ans[max];
int la,lb,j; 
char a[max],b[max];
int main()
{
	cin>>a+1;
	cin>>b+1; 
   // scanf("%s%s",a+1,b+1);
    la=strlen(a+1);
    lb=strlen(b+1);
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
          while(j>0&&b[j+1]!=a[i])//匹配失败 
           j=ans[j];//往后 
          if (b[j+1]==a[i]) 
           j++;//直接对 
          if (j==lb){//成功 
		  printf("%d\n",i-lb+1);
		  j=ans[j];
		  }
       }

    for (int i=1;i<=lb;i++)
    printf("%d ",ans[i]);
    return 0;
}
