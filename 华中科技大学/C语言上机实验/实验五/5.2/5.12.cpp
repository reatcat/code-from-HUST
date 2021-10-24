#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void visited(int pa[20][20], int i, int j,int x,int y); 
int main()
{
	int a[20][20];
	int x,y,i,j;
    scanf("%d%d",&x,&y);
    for(i=0;i<x+2;i++)
    {
        for(j=0;j<y+2;j++)
        {
            if((i==0)||(j==0)||(i==x+1)||(j==y+1)) a[i][j]=-1;
        }
    }
    for(i=1;i<x+1;i++)
    {
        for(j=1;j<y+1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
	visited(a, 1, 1, x, y);

	return 0;
}
void visited(int pa[20][20], int i, int j,int x,int y)
{
	int n, m;
	pa[i][j] = 2;
	if(i == x && j == y){
		printf("\n");
		for(n=1; n<x+1; n++){
			for(m=1; m<y+1; m++){
                if(m<y){
                    if(pa[n][m] == 2)
                        printf("1 ");
                    else if(pa[n][m] == 1)
                        printf("0 ");
                    else
                        printf("0 ");}
                else{
                    if(pa[n][m] == 2)
                        printf("1");
                    else if(pa[n][m] == 1)
                        printf("0");
                    else
                        printf("0");}
			}
			printf("\n");
		}
	}

	if(pa[i-1][j] == 1)
		visited(pa, i-1, j, x, y);
	if(pa[i+1][j] == 1)
		visited(pa, i+1, j, x, y);
	if(pa[i][j-1] == 1)
		visited(pa, i, j-1, x, y);
	if(pa[i][j+1] == 1)
		visited(pa, i, j+1, x, y);

	pa[i][j] = 1;
}
