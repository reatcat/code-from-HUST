#include<stdio.h>
int n,m;
int find(int k,int *f)
{
    if(f[k]==k)return k;//һ��ʼ��ʼ�� 
    return f[k]=find(f[k],f);//ʵ�������Ҹ� 
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
//	int x[m+1];
//	int y[m+1];
//	int z[m+1];
	int f[n+1];
	int x,y,z;
	for(i=1;i<=n;i++)
        f[i]=i;//ȷ��һ�����ڵ㣬��ôһ��ʼ�Ƿֿ��� 
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)//���� 
		f[find(y,f)]=find(z,f);//�Ժ�һ����Ϊ���ĸ� 
		else  if(find(y,f)==find(z,f))//�ж��Ƿ��� һ������ 
                printf("Y\n");
            else
                printf("N\n");
	}
	
	return 0;
 } 
