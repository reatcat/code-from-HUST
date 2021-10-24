#include<cstdio>
#define max 100000
int a[max],b[max];
long long ans;
void mergesort(int low,int high)//归并排序 
{
    if(low==high)  
		return;
    int mid=(low+high)/2;
	int i=low;
	int j=mid+1;
    mergesort(low,mid),mergesort(mid+1,high);//二路归并 
    int k=low;
    while(i<=mid&&j<=high){//二路 
    	if(a[i]<=a[j])
    		b[k++]=a[i++];
    	else{
    	b[k++]=a[j++];
		ans+=mid-i+1;
	}
	}
    while(i<=mid)
    	b[k++]=a[i++];
    while(j<=high)
    	b[k++]=a[j++];
    for(int l=low;l<=high;l++)
    	a[l]=b[l];
} 

int main()
{
	int n; 
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    mergesort(1,n);
    printf("%lld",ans);
    return 0;
}

