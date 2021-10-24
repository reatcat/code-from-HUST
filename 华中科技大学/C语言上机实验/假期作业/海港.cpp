#include<stdio.h>
struct node{
    int ti,ct;
}a[300005];
int b[100005];
int n,k,tot,time,i,j,temp;
int ans,head;
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&time,&k);
        while(k--){
            scanf("%d",&temp);
            a[++tot].ti=time;
            a[tot].ct=temp;
            if(b[temp]==0)ans++;   //新的品种,ans++
            b[temp]++;
        }
        while(time-a[head].ti>=86400)
		{    //二十四小时前的，扔出队列
            temp=a[head].ct;
            b[temp]--;
            if(b[temp]==0)
                ans--;     //品种灭绝，ans--
            head=head+1;
        }
        printf("%d\n",ans);  //ans已经统计好种类数了
    }
    return 0;
}
