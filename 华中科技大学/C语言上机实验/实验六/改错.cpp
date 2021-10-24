#include<stdio.h>
char *strcopy(char*t,char*s);
int main(void) 
{
	char *s1,*s2;
	char *s3;
	char a[10],b[10];
	s1=a;
	s2=b; 
	scanf("%s",s2); 
	strcopy(s1,s2);
	printf("%s\n",s1);
	scanf("%s",s2);
	s3=strcopy(s1,s2);
	printf("%s\n",s3);
	return 0;
}
char *strcopy(char*t,char*s)
{
	char *p=t; 
	while(*t++=*s++);
	return p;
}
