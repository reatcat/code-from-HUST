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
            if(b[temp]==0)ans++;   //�µ�Ʒ��,ans++
            b[temp]++;
        }
        while(time-a[head].ti>=86400)
		{    //��ʮ��Сʱǰ�ģ��ӳ�����
            temp=a[head].ct;
            b[temp]--;
            if(b[temp]==0)
                ans--;     //Ʒ�������ans--
            head=head+1;
        }
        printf("%d\n",ans);  //ans�Ѿ�ͳ�ƺ���������
    }
    return 0;
}
