#include<stdio.h>
void sca();
void pri();
void pai();
int main()
{
    int c;
    scanf("%d",&c);
     int n;
	char a[n];
    int b[n]; 
   
    switch(c)
    {
        case 1:sca();
        case 2:pai();
        case 3:pri();
    }
    scanf("%d",&c);
    switch(c)
    {
        case 1:sca();
        case 2:pai();
        case 3:pri();
    }
    if(c!=3)
    {
        scanf("%d",&c);
    switch(c)
    {
        case 1:sca();
        case 2:pai();
        case 3:pri();
    }
    }
	

}
void sca()
{ int n;
	char a[n];
    int b[n]; 
    scanf("%d",&n);
    int i;
	for(i=0;i<n;i++)
		scanf("%s",&a[i]);
        scanf("%d",&b[i]);
}
void pai()
{ int n;
	char a[n];
    int b[n]; 
    int i,j,t;
	char s;
	for (i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
			if (b[j] <b[j + 1])
			{
				t = b[j], b[j] =b[j + 1], b[j] = t;
				s = a[j], a[j] = a[j + 1], a[j] = s;
			}
	}
}
void pri()
{ int n;
	char a[n];
    int b[n]; 
    int i;
	for (i = 0;i < n;i++)
	{
		printf("%s",a[i]);
        printf("%d",b[i]);
	}
}
