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
	printf("������x��y��ֵ\n");
	scanf("%d%d",&x,&y);
	//swap(x,y);
	swap1(&x,&y);
	printf("��ɽ������x��y��ֵΪ��%d %d",x,y);
}
