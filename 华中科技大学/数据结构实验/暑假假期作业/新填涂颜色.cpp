#include<stdio.h>
#define MAX 100
	int n;//为了在子函数中也用到 
	int a[MAX][MAX];//利用存储 
void dis(int x,int y)//分类数组
{
if(x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1)//此处还是要从0开始 
{
		if(a[x][y] == 1 || a[x][y] == 3) return ;
		else{
		a[x][y] = 3;
		dis(x + 1, y); 
		dis(x - 1, y);
		dis(x, y + 1); 
		dis(x, y - 1);}
	}
 } 
int main()
{

	scanf("%d",&n);//输入宫格的规模 
	int i,j;
//	int b[MAX][MAX];//利用另一个数组来存放状态 
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++){
		scanf("%d",&a[i][j]);//对于输入的数据进行存储，存到数组当中 
	}
	//利用分治思想，将数组分为不同的三种状态 
	 dis(1,1);
	 for(i=1;i<=n;i++){
	 	for(j=1;j<=n;j++)
	 {
	 	if(a[i][j]==-1)
	 	printf("0 ");
	 	else if(a[i][j]==1)
	 	printf("1 ");
	 	else if(a[i][j]==0)
	 	printf("2 ");
	 }
	 printf("\n");
	 }
	return 0;
 } 
