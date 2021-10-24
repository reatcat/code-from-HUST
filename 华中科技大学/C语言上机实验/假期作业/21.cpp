#include<stdio.h>
#include<string.h>
char s1[1000],s2[1000],s[1001];
int x;//进位 
int max(int a,int b)
{
	return (a>b)?a:b;
}
void reverse(char *s)//反转过来有利于低位相加 
{
	int c,j,k;
	for(j=0,k=strlen(s)-1;j<k;j++,k--)
	{
		c=s[j];
		s[j]=s[k];
		s[k]=c;
	}
}
int main()
{
	int n,l1,l2,l,i,a,b,c;
	scanf("%d",&n);
	scanf("%s\n%s",s1,s2);
	l1=strlen(s1);
	l2=strlen(s2);
	l=max(l1,l2);
	reverse(s1);
	reverse(s2);
	for(i=l1;i<l;i++)
	{
		s1[i]+='0';
	}
	for(i=l2;i<l;i++)
	{
		s2[i]+='0';
	}//高位补零
	for(i=0;i<l;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')//防止出现超大数 
		{
			a=s1[i]-'0';//10进制 
		}
		else if(s1[i]>='a'&&s1[i]<='z')
		{
			a=s1[i]-87;//97-10
		}
		if(s2[i]>='0'&&s2[i]<='9')
		{
			b=s2[i]-'0';
		}
		else if(s2[i]>='a'&&s2[i]<='z')
		{
			b=s2[i]-87;
		}
		c=a+b+x;//相加
		x=0;
		if(c>=n)//需要进位
		{
			c-=n;
			x=1;
		}
		if(c>=0&&c<=9)//是数字就直接
		{
			s[i]+=c+'0';
		}
		else//否则加上87转成对应字母
		{
			s[i]+=c+87;
		}
	}
	if(x)//最高位还有进位 
	{
		s[i]+='1';
	}
	reverse(s);//翻转回来
	printf("%s",s);
	return 0;
}
