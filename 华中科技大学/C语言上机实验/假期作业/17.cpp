#include<stdio.h>
int a[101]={0},b[10000][101]={0};
int main()
{
    int n,m,q,w,count=0,i,x,j;
    scanf("%d%d",&n,&m);
    m=m*1.5;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&q,&w);//���ö�ά�����±����ṹ 
        b[q][w]++;
        a[w]++;//�ɼ������������� 
    }//�±����ɼ��������Ŷ� 
    for(i=100;count<m;i--)
        count+=a[i];//�����ҳ����ʵ�ѡ��  
    printf("%d %d\n",i+1,count);
    x=i+1;
    for(i=100;i>=x;i--)
        for(j=1000;j<=10000;j++)
            if(b[j][i]) 
				printf("%d %d\n",j,i);
    return 0;
}

