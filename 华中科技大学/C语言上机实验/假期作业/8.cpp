#include<stdio.h>
int cost,money=0,save=0;
int main(){
    int i;
    for(i=1;i<=12;i++)
	{
        money+=300;                                                              //ÿ�¶���õ�300Ԫ
        scanf("%d",&cost);
        money-=cost;                                                              //��ȥ֧��
        if(money<0)
		{
		printf("-%d",i);
		return 0;//ֱ�ӽ��� 
		}                       //��͸֧������·ݵĸ���
        if(money>=100)
		{
		save+=100*(money/100);
		money%=100;
		}//��Ǯ
    }
    printf("%d",save*6/5+money);
    return 0;
}
