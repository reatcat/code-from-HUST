#include<stdio.h>
int cost,money=0,save=0;
int main(){
    int i;
    for(i=1;i<=12;i++)
	{
        money+=300;                                                              //每月都会得到300元
        scanf("%d",&cost);
        money-=cost;                                                              //减去支出
        if(money<0)
		{
		printf("-%d",i);
		return 0;//直接结束 
		}                       //若透支就输出月份的负数
        if(money>=100)
		{
		save+=100*(money/100);
		money%=100;
		}//存钱
    }
    printf("%d",save*6/5+money);
    return 0;
}
