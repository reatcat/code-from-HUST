#include <stdio.h>
#include <stdlib.h>
void sort(int *p,int n);
void sort2(int *p,int n);
int main(int argc,char *argv)
{
    int *p,ch;
    int i,j;
    ch=getchar();
    p=(int*)malloc(sizeof(int));
    for(i=0;i<*(argv+2);i++)
    {
        *(p+i)=ch;
        p=(int*)realloc(p,sizeof(int)*i);
        ch=getchar();
    }
    p=(int*)realloc(p,sizeof(int)*i);
    if(*(argv)=='-d'){
        sort1(p,i);
        puts(p);
	}
	else{
		sort2(p,i);
		puts(p);
	}
     
    
    
    return 0;
}
void sort1(int *p,int n)
{
	int i,j;
	int t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(*(p+j)>*(p+j+1))
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}
void sort2(int *p,int n)
{
	int i,j;
	int t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(*(p+j)<*(p+j+1))
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}
