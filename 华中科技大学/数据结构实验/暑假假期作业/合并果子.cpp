#include<bits/stdc++.h>//ʹ��sort 
using namespace std;
int a[10001];
int main(){
	int n;
	unsigned long long sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);//�Ƚ���Ԥ���� 
    for(;;){//������ 
        int j=1;
        while(a[j]==0)
        j++;
        if(j==n) break;
        else {
            a[j]+=a[j+1];
            sum+=a[j];//i��j����һ����
            for(int l=j+1;l<n;l++)
             {
                a[l]=a[l+1];
            }
            n--;
        }
        for(int l=j;l<n;l++)//���� 
        {
            if(a[l]>a[l+1])
            {
                swap(a[l],a[l+1]);//���ǽ��� 
            }
        }
    }
    printf("%lld",sum); 
    return 0;
    }
