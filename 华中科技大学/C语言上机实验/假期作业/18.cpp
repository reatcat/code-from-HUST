#include<stdio.h>
int main(){
    int n,s,h,a,b,i,t=0;
	int c[100]={0}; 
    scanf("%d%d",&n,&s);
    scanf("%d%d",&h,&i);
	h+=i;//���룬����"i"�������õ��Ӵﵽ�����߶ȸ��Ƹ�"h"
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if(a<=h)
		c[b]++;//�����ժ����������b��������ժ��ƻ����Ͱ���м�һ
    }
    for(i=0;i<=100&&s>=0;i++)
	{
        while(c[i]){//���ƻ��
            s-=i;
            t++;
            c[i]--;
            if(s<0)
			{
                t--;
                break;
            }
        }
    }
    printf("%d",t); 
    return 0;
}
