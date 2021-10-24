#include<stdio.h>
char a[101][101];
int b[101][101]={0};
int n;
void judge(int x,int y)
{
	int k;
	if(a[x][y-1]=='i'&&a[x][y-2]=='z'&&a[x][y-3]=='h'&&a[x][y-4]=='o'&&a[x][y-5]=='n'&&a[x][y-6]=='g')//×ó 
	for(k=0;k<=6;k++) 
	b[x][y-k]=1;
	if(a[x][y+1]=='i'&&a[x][y+2]=='z'&&a[x][y+3]=='h'&&a[x][y+4]=='o'&&a[x][y+5]=='n'&&a[x][y+6]=='g') //ÓÒ 
	for(k=0;k<=6;k++) 
	b[x][y+k]=1;
	if(a[x-1][y]=='i'&&a[x-2][y]=='z'&&a[x-3][y]=='h'&&a[x-4][y]=='o'&&a[x-5][y]=='n'&&a[x-6][y]=='g') 
	for(k=0;k<=6;k++) 
	b[x-k][y]=1;
	if(a[x+1][y]=='i'&&a[x+2][y]=='z'&&a[x+3][y]=='h'&&a[x+4][y]=='o'&&a[x+5][y]=='n'&&a[x+6][y]=='g') 
	for(k=0;k<=6;k++) 
	b[x+k][y]=1;
	if(a[x-1][y-1]=='i'&&a[x-2][y-2]=='z'&&a[x-3][y-3]=='h'&&a[x-4][y-4]=='o'&&a[x-5][y-5]=='n'&&a[x-6][y-6]=='g') 
	for(k=0;k<=6;k++) 
	b[x-k][y-k]=1;
	if(a[x+1][y+1]=='i'&&a[x+2][y+2]=='z'&&a[x+3][y+3]=='h'&&a[x+4][y+4]=='o'&&a[x+5][y+5]=='n'&&a[x+6][y+6]=='g') 
	for(k=0;k<=6;k++) 
	b[x+k][y+k]=1;
	if(a[x-1][y+1]=='i'&&a[x-2][y+2]=='z'&&a[x-3][y+3]=='h'&&a[x-4][y+4]=='o'&&a[x-5][y+5]=='n'&&a[x-6][y+6]=='g') 
	for(k=0;k<=6;k++) 
	b[x-k][y+k]=1;
	if(a[x+1][y-1]=='i'&&a[x+2][y-2]=='z'&&a[x+3][y-3]=='h'&&a[x+4][y-4]=='o'&&a[x+5][y-5]=='n'&&a[x+6][y-6]=='g') 
	for(k=0;k<=6;k++) 
	b[x+k][y-k]=1;
}
int main()
{
	scanf("%d",&n);
	int i,j;
	  for (i = 1; i <= n; i++)
    {
        getchar();
   //     getchar();
        for (j = 1; j <= n; j++)
            scanf("%c", &a[i][j]);
    }
    
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	      if(a[i][j]=='y') 
		  judge(i,j); 
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
           {
           	if(b[i][j]) 
           	printf("%c",a[i][j]);
           	else 
			   printf("*");
		   }
		printf("\n");
	}
    return 0;
}
