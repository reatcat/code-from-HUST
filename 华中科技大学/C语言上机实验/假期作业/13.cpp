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
	int l1=strlen(a);//ԭ�ĵĳ�
	int l2=strlen(b);//��Կ�ĳ�
	int i=0,j=0,k;
	for(i=0;i<l2;i++,j++)
	{
		 if(j==l1)
		 j=0;//�ظ�ʹ��
        if(judge(b[i]))
        {
            if(!judge(a[j]))
			a[j]+='a'-'A';//���Ŀ����Сд�������Ǵ�д��������ĳ�Сд
            c[i]=b[i]-a[j]+'a';//���� 
            if(c[i]<'a')
			c[i]+=26;//Խ��
        }
        else
        {
            if(judge(a[j]))
			a[j]+='A'-'a';
            c[i]=b[i]-a[j]+'A';//���� 
            if(c[i]<'A')
			c[i]+=26;//Խ�� 
        }
	}
	for(i=0;i<l2;i++)
		printf("%c",c[i]);
	
	return 0;
} 
