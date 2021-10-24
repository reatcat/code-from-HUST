#include<stdio.h>
int main(){
    int n,s,h,a,b,i,t=0;
	int c[100]={0}; 
    scanf("%d%d",&n,&s);
    scanf("%d%d",&h,&i);
	h+=i;//输入，借用"i"将淘淘用凳子达到的最大高度复制给"h"
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if(a<=h)
		c[b]++;//如果能摘到，就在用b个力气能摘到苹果的桶子中加一
    }
    for(i=0;i<=100&&s>=0;i++)
	{
        while(c[i]){//多个苹果
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
