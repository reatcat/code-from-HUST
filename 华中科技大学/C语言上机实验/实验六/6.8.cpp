#include<stdio.h>
#include<string.h>
int delSubstr(char *str,char *substr);
int main()
{
	int n;
	char str[50],substr[20];
	gets(str);
	gets(substr);
	n=delSubstr(str,substr);
	printf("%s",str);
	printf("\n");
	printf("%d",n); 
	return 0;
}
int delSubstr(char *str,char *substr)
{
	char *i;
	i=strstr(str,substr);
	if(i!=0){
	strcpy(i,i+strlen(substr));
	i=strstr(str,substr);
	if(i!=0)
	{
		strcpy(i,i+strlen(substr));
	}
	
	return 1;	
	}
	else 
	return 0;

	
}
