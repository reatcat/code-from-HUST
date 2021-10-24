#include<stdio.h>
int a[101]={0},b[10000][101]={0};
int main()
{
    int n,m,q,w,count=0,i,x,j;
    scanf("%d%d",&n,&m);
    m=m*1.5;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&q,&w);//利用二维数组下标代替结构 
        b[q][w]++;
        a[w]++;//成绩读出用于排序 
    }//下标代表成绩，个数排定 
    for(i=100;count<m;i--)
        count+=a[i];//依次找出合适的选手  
    printf("%d %d\n",i+1,count);
    x=i+1;
    for(i=100;i>=x;i--)
        for(j=1000;j<=10000;j++)
            if(b[j][i]) 
				printf("%d %d\n",j,i);
    return 0;
}

