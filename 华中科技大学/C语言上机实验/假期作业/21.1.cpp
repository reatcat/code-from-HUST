#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,l1,l2,l,a,b,c;
string s1,s2,s;
bool x=0;//x用来存上一位有没有进位
int main()
{
	scanf("%d",&n);//进制
	cin>>s1>>s2;//字符串读入
	l1=s1.length();
	l2=s2.length();//记录长度
	l=max(l1,l2);//记录两者中较长的那一个的长度
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());//翻转字符串
	for(int i=l1;i<l;i++)
	{
		s1+='0';
	}
	for(int i=l2;i<l;i++)
	{
		s2+='0';
	}//将较短的那一个的高位补零
	for(int i=0;i<l;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			a=s1[i]-'0';
		}
		else if(s1[i]>='a'&&s1[i]<='z')
		{
			a=s1[i]-87;
		}
		if(s2[i]>='0'&&s2[i]<='9')
		{
			b=s2[i]-'0';
		}
		else if(s2[i]>='a'&&s2[i]<='z')
		{
			b=s2[i]-87;
		}//转换为数字进行计算
		//a-z的ASCLL码是97-122，a-z代表的数字是10-35所以直接减87
		c=a+b+x;//相加
		x=0;
		if(c>=n)//需要进位
		{
			c-=n;
			x=1;
		}
		if(c>=0&&c<=9)//是数字就直接输出
		{
			s+=c+'0';
		}
		else//否则加上87转成对应字母
		{
			s+=c+87;
		}
	}
	if(x)//特判若最高位有进位则再填一个一
	{
		s+='1';
	}
	reverse(s.begin(),s.end());//翻转回来
	cout<<s<<endl;//输出结果
}
