#include<stdio.h>
#include<string.h>
int  removeDuplicate(int a[],int n) //ȥ�� 
{
	int i,j,temp;
	for(i=0;i<n;i++)		//ѭ���ж�������ÿһ����
	{
		for(j=i+1;j<n;j++)	//�ж�a[i]��ߵ����Ƿ��a[i]���
		{
			if(a[i]==a[j])
			{
				for(temp = j;temp<n;temp++)
					a[temp]=a[temp+1];	//��a[j]�����Ԫ��ȫ��ǰ��һ��λ��
				j--;	//a[j+1]ȡ��a[j]λ�ã�Ϊʹ�´δ�a[j+1]��ʼ����,j��һ
				n--;	//���鳤�ȼ�һ
			}
		}
	}
	return n;
}
int  bubble_sort(int *a,int n)
{
	int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	n=removeDuplicate(a,n);
	bubble_sort(a,n);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{   
	if(!a[i])
	continue;
	else
		printf("%d ",a[i]);
	}
	return 0;
 } 
