#include<stdio.h> 
#include<string.h>
int main(void)
{
	char*(*p[3])(char*t,const char*s); 
	p[0]=strcpy;
	p[1]=strcat;
	p[2]=strtok;
	char a[80],b[80],*result;
	int choice;
	while(1)
	{
		do
		{
			scanf("%d",&choice);
		}while(choice<1||choice>4);
		if(choice<4){
		getchar();
		gets(a);
		gets(b);
		result=p[choice-1](a,b);
		printf("%s\n",result);
		}
     else goto down;
	}
	down:
		return 0;
}
