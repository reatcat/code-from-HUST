#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct student
{
    int nu;
    int c;
    int m;
    int e;
    int sum;
}stu[302];

void sort(int n)
{
    int t,i,j;
    struct student temp;
    for(i=1;i<6;i++)
        for(j=i+1;j<n+1;j++)
            if(stu[i].sum<stu[j].sum||stu[i].sum==stu[j].sum&&stu[i].c<stu[j].c||stu[i].sum==stu[j].sum&&stu[i].c==stu[j].c&&stu[i].nu>stu[j].nu)
            {
                temp=stu[i];
                stu[i]=stu[j];
                stu[j]=temp;
            }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<n+1;i++)
    {
        stu[i].nu=i;
        scanf("%d %d %d",&stu[i].c,&stu[i].m,&stu[i].e);
        stu[i].sum=stu[i].c+stu[i].m+stu[i].e;
    }
    sort(n);
    for(i=1;i<6;i++)
        printf("%d %d\n",stu[i].nu,stu[i].sum);
    return 0;
}
