#include<stdio.h>
#include<string.h>
int judge(char a)
{
	if(a>='a'&&a<='z')
	return 1;
	else
    return 0;
}
int main()
{
	char a[1000],b[1000],c[1000];
	scanf("%s\n%s",a,b);
	int l1=strlen(a);//原文的长
	int l2=strlen(b);//密钥的长
	int i=0,j=0,k;
	for(i=0;i<l2;i++,j++)
	{
		 if(j==l1)
		 j=0;//重复使用
        if(judge(b[i]))
        {
            if(!judge(a[j]))
			a[j]+='a'-'A';//如果目标是小写，密码是大写，把密码改成小写
            c[i]=b[i]-a[j]+'a';//解密 
            if(c[i]<'a')
			c[i]+=26;//越界
        }
        else
        {
            if(judge(a[j]))
			a[j]+='A'-'a';
            c[i]=b[i]-a[j]+'A';//解密 
            if(c[i]<'A')
			c[i]+=26;//越界 
        }
	}
	for(i=0;i<l2;i++)
		printf("%c",c[i]);
	
	return 0;
} 
