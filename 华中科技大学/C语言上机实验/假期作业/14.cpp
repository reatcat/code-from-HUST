//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s[100],f[100],ans[100];
//	int a[26],b[26],c[26];
//    int n,p,i=0,j=0;
//    scanf("%d%s%d",&n,s,&p);
//    for(i=0;i<n;i++) 
//	a[s[i]-'a']++;
//	for(i=0;i<26;i++) 
//    {
//        b[i]=c[i-1]+1;
//        c[i]=b[i]+a[i]-1;
//    }
//    for(i=0;i<n;i++)
//    {
//    	while(a[j]!=0)
//    	{
//    		f[i]='a'+j;
//			a[j]--;
//		}
//		if(a[j]==0)
//		j++;
//	}
//	ans[0]=s[p-1];
//	ans[1]=f[p-1]; 
//	for(i=2;i<n;i++)
//	{
//		for(j=0;j<n;j++)
//		{
//			if(f[p-1]==s[j])
//			{
//				ans[i]=f[j];
//				p=j+1;
//				break;
//			}
//		}
//	}
//	for(i=0;i<n;i++)
//	printf("%c",ans[i]);
//  return 0;
//}
#include<stdio.h>
#define N 10000
char s[N],ans[N];
int a[26],b[26],c[26];
int main()
{
    int n,p,i;
    scanf("%d%s%d",&n,s,&p);
    for(i=0;i<n;i++) 
	a[s[i]-'a']++;
    for(i=0;i<26;i++) 
    {
        b[i]=c[i-1]+1;
        c[i]=b[i]+a[i]-1;
    }
    int now=b[s[p-1]-'a'];
    for(i=0;i<n;i++)
    {
        ans[i]=s[now-1];
        now=c[s[now-1]-'a']--;
    }
    for(i=n-1;i>=0;i--) 
	putchar(ans[i]);
	return 0;
}
