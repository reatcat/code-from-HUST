#include<stdio.h>
#include<malloc.h>
#include<string.h>


void strsort(char *s[],int size)
{
	char *temp;//
	int i,j;
	for(i=0;i<size-1;i++)
	for(j=0;j<size-i-1;j++)
	if(*s[j]>*s[j+1])//
	{
		temp=s[j];
		s[j]=s[j+1];//
		s[j+1]=temp;
	}
 } 
 int main()
 {
 	int i;
 	int n;
 	scanf("%d",&n);
 	char *s[50],t[50];
 	for(i=0;i<n;i++)
 	{
 		gets(t);
 		s[i]=(char*)malloc(strlen(t)+1);
 		strcpy(s[i],t); //
	 }
	 strsort(s,n);//
	 for(i=0;i<n;i++)
	 puts(s[i]);
	 return 0;
 }
