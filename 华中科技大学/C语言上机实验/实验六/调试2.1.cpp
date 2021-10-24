#include<stdio.h> 
#include<string.h>
int main(void)
{
	char*(*p)(char*t,const char*s); 
	char a[80],b[80],*result;
	int choice;
	while(1)
	{
		do
		{
			scanf("%d",&choice);
		}while(choice<1||choice>4);
		switch(choice)
		{
			case 1: p=strcpy;break;
			case 2: p=strcat;break;
			case 3: p=strtok;break;
			case 4: goto down;
		}
     	getchar();
		gets(a);
		gets(b);
		result=p(a,b);
		printf("%s",result);
	}
	down:
		return 0;
}
