#include<stdio.h>
int main()
{
	int n,n1,n2;
	scanf("%d%d%d",&n,&n1,&n2);
	int i,j;
	int a[n1],b[n2];
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n2;j++)
	{
		scanf("%d",&b[j]);
	}
	int score[5][5];
	score[0][0]=0;
	score[0][1]=-1;
	score[0][2]=1;
	score[0][3]=1;
	score[0][4]=-1;
	score[1][0]=1;
	score[1][1]=0;
	score[1][2]=-1;
	score[1][3]=1;
	score[1][4]=-1;
	score[2][0]=-1;
	score[2][1]=1;
	score[2][2]=0;
	score[2][3]=-1;
	score[2][4]=1;
	score[3][0]=-1;
	score[3][1]=-1;
	score[3][2]=1;
	score[3][3]=0;
	score[3][4]=1;
	score[4][0]=1;
	score[4][1]=1;
	score[4][2]=-1;
	score[4][3]=-1;
	score[4][4]=0;
	int a1=0,b1=0;//记录胜利
	int a2=0,b2=0;//记录周期 
	for(i=0;i<n;i++)
	{
		if(score[a[a2]][b[b2]]==1)
		{
			a1++;
		}
		else if(score[a[a2]][b[b2]]==-1)
		{
			b1++;
		}
		a2++;
		b2++;
		if(a2==n1)
		{
			a2=0;
		}
		if(b2==n2)
		{
			b2=0;
		}
	}
	printf("%d %d",a1,b1);
	return 0;
 } 
