#include<stdio.h>
void swap(int &x,int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
 } 
 void swap1(int *x,int *y)
 {
// 	int temp;
//    temp = *x;
//    *x= *y;
//    *y = temp;
	printf("%d",*x);
 }
int main()
{
	int x,y;
	printf("请输入x和y的值\n");
	scanf("%d%d",&x,&y);
	//swap(x,y);
	swap1(&x,&y);
	printf("完成交换后的x和y的值为：%d %d",x,y);
}
