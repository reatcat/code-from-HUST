#include<stdio.h>
#include<string.h>
char s1[1000],s2[1000],s[1001];
int x;//��λ 
int max(int a,int b)
{
	return (a>b)?a:b;
}
void reverse(char *s)//��ת���������ڵ�λ��� 
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
	}//��λ����
	for(i=0;i<l;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')//��ֹ���ֳ����� 
		{
			a=s1[i]-'0';//10���� 
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
		c=a+b+x;//���
		x=0;
		if(c>=n)//��Ҫ��λ
		{
			c-=n;
			x=1;
		}
		if(c>=0&&c<=9)//�����־�ֱ��
		{
			s[i]+=c+'0';
		}
		else//�������87ת�ɶ�Ӧ��ĸ
		{
			s[i]+=c+87;
		}
	}
	if(x)//���λ���н�λ 
	{
		s[i]+='1';
	}
	reverse(s);//��ת����
	printf("%s",s);
	return 0;
}
