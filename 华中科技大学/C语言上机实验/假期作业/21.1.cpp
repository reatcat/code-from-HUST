#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,l1,l2,l,a,b,c;
string s1,s2,s;
bool x=0;//x��������һλ��û�н�λ
int main()
{
	scanf("%d",&n);//����
	cin>>s1>>s2;//�ַ�������
	l1=s1.length();
	l2=s2.length();//��¼����
	l=max(l1,l2);//��¼�����нϳ�����һ���ĳ���
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());//��ת�ַ���
	for(int i=l1;i<l;i++)
	{
		s1+='0';
	}
	for(int i=l2;i<l;i++)
	{
		s2+='0';
	}//���϶̵���һ���ĸ�λ����
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
		}//ת��Ϊ���ֽ��м���
		//a-z��ASCLL����97-122��a-z�����������10-35����ֱ�Ӽ�87
		c=a+b+x;//���
		x=0;
		if(c>=n)//��Ҫ��λ
		{
			c-=n;
			x=1;
		}
		if(c>=0&&c<=9)//�����־�ֱ�����
		{
			s+=c+'0';
		}
		else//�������87ת�ɶ�Ӧ��ĸ
		{
			s+=c+87;
		}
	}
	if(x)//���������λ�н�λ������һ��һ
	{
		s+='1';
	}
	reverse(s.begin(),s.end());//��ת����
	cout<<s<<endl;//������
}
