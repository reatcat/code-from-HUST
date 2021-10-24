#include<cstdio>
int abs(int a)
{
	if(a>0) return a;
	else return -a;
 } 
 	char c;
	char s[20];
	int ans=0,k;
	char x;
 int digui()
 {
 		while(scanf("%c",&c))
	{
		if(c==']')break;
		scanf("%s %d",s,&k);
		if(c=='R')//REPEAT
		{
			x=getchar();//[
			ans+=k*digui();
			x=getchar();//]
		}
		if(c=='B')//BK
		{
			x=getchar(); 
			ans-=k;
		}
		if(c=='F')//FD
		{
			x=getchar(); 
			ans+=k;
		}
		if(x==']') break;
	}
	return ans;
 }
int main()
{
	int ans;
	ans=abs(digui());
	printf("%d",ans);
	return 0;
 } 
//// #include<bits/stdc++.h>
////using namespace std;
////int func()
////{
////	char ch,x;
////	string wz;//尾缀(K,D,EPEAT) 
////	int k,rt=0/*return*/;
//	while(cin>>c)
//	{
//		if(c==']')break;
//		cin>>s>>k;
//		if(c=='R')//REPEAT
//		{
//			x=getchar();//[
//			ans+=k*func();
//			x=getchar();//]
//		}
//		if(c=='B')//BK
//		{
//			x=getchar(); 
//			ans-=k;
//		}
//		if(c=='F')//FD
//		{
//			x=getchar(); 
//			ans+=k;
//		}
//		if(x==']') break;
//	}
////	return ans;
////}
////int main()
////{
////	cout<<abs(func());//别忘记有abs（绝对值）
////   	return 0;
////}
