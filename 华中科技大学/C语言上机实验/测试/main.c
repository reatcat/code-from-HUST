#include<stdio.h>
#include<string.h>
int judge(char *s)
{
	int len=strlen(s);
	int i,t=len/2;
	for(i=0;i<=t;i++)
	{
		if(s[i]!=s[len-1-i])
		return 0;

	}
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[100];
	scanf("%s",s);
	char a[500],b[500];
	int len=strlen(s);
	int i,t=len/2;
	 for(i=0;i<len;i++)
	 {
	 	if(s[i]>='0'&&s[i]<='9')// �ı䵽�µ�������ȥ
	 	a[i+1]=s[i]-'0';
	 	else
	 	a[i+1]=s[i]-'A'+10;//��ֹ����16���ƣ���©����

	 }
	 int step=0;
	 while(step<=30)
	 {
	 	int j=1,high=0,x;
	 	step++;
	 	while(j<=i)
	 	{
	 		x=a[i-j+1]+a[j]+high;//������ĿҪ�����
			 high=x/n;
			  b[i-j+1]=x%n;
			  j++;
		 }
		 b[0]=high;
		 if(judge(b))
		 {
		 	printf("STEP=%d",step);
		 	break;
		 }
		  if(high)
        {
            for(j=1;j<=i+1;j++)
			a[j]=b[j-1];
            i++;//��ֹ�ٴγ��ֽ�λ
        }
        else
        {
        for(j=1;j<=i;j++)
		a[j]=b[j];
		}


	 }
	 if(step>30)
	 printf("Impossible");
	return 0;
}
