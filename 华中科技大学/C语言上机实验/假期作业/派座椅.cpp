#include<stdio.h>
int max(int a,int b)
{
	return (a>b)?a:b;
} 
int min(int a,int b)
{
	return (a>b)?b:a;
}
int m,n,k,l,d;//���������������Ŀһ�µ� 
int x[1005],y[1005];//������������ 
int c[1005],o[1005];//Ͱ��Ҫ�õ�����
int main() {
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d); 
    for(int i=1;i<=d;i++) { 
        int xi,yi,pi,qi; 
        scanf("%d%d%d%d",&xi,&yi,&pi,&qi); 
        if(xi==pi) 
            x[min(yi,qi)]++;//��ʾ���������ŵļ�ֵ 
        else 
            y[min(xi,pi)]++; //�ǵ�ȡmin����������ǰһ�����걣��һ�� 
    } 
    for(int i=1;i<=k;i++){//��ʼͰ�� 
        int maxn=-1;//Ϊ�����ÿ�ε����ֵ����Ҫÿ��ɨһ�� 
        int p; 
        for(int j=1;j<m;j++){ 
            if(y[j]>maxn){ 
                maxn=y[j]; 
                p=j; 
            } 
        } 
        y[p]=0;//���max֮��һ��Ҫ�ǵ����㣡�����������Ŷ��ٴζ���һ���� 
        c[p]++;//Ͱ�Ų����� 
    } 
    for(int i=1;i<=l;i++){ 
        int maxn=-1; 
        int p; 
        for(int j=1;j<n;j++){ 
            if(x[j]>maxn){ 
                maxn=x[j]; 
                p=j; 
            } 
        } 
        x[p]=0; //ͬ�� 
        o[p]++; 
    } 
    for(int i=0;i<1005;i++)//����� 
    { 
        if(c[i])//��ʾ��Ҫ�������� 
            printf("%d ",i); 
    } 
    printf("\n"); 
    for(int i=0;i<1005;i++) 
    { 
        if(o[i]) 
            printf("%d ",i); //ͬ�� 
    } 
    return 0; 
}
