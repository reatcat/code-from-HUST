#include<stdio.h>
#include <stdlib.h>
void shuchu(FILE *fp)
{
	char a[32];
	int i,j;
	for(i=0;i<10;i++)
	{
	fgets(a,4,fp);
    
        printf("%s\n",a);
    	
	}
    	fclose(fp); 
}
void shuru(FILE *fp)
{
	int i=0;
	float x;
	for(i=0;i<10;i++)
	{
		scanf("%f",&x);
		fwrite(&x,32,1,fp);
	}
		fclose(fp); 
}
int main()
{
	int i;
	FILE *fp;
	fp=fopen("float.dat","wb+");
	shuru(fp);
	fp=fopen("float.dat","r");
	shuchu(fp); 

	return 0;
 } 
