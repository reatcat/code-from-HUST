#include<stdio.h>
#define MAX 100
	int n;//Ϊ�����Ӻ�����Ҳ�õ� 
	int a[MAX][MAX];//���ô洢 
void dis(int x,int y)//��������
{
if(x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1)//�˴�����Ҫ��0��ʼ 
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

	scanf("%d",&n);//���빬��Ĺ�ģ 
	int i,j;
//	int b[MAX][MAX];//������һ�����������״̬ 
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++){
		scanf("%d",&a[i][j]);//������������ݽ��д洢���浽���鵱�� 
	}
	//���÷���˼�룬�������Ϊ��ͬ������״̬ 
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
