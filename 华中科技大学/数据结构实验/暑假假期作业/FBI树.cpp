#include<stdio.h>
#include<math.h>//�˴������ĵĻ���Ҫ 
#define MAX 100
char pre[MAX];
void post(int low, int high)//��������һ����������,���еĸ��ڵ�û�б�Ҫ 
{
    int mid = (low+high)/2;
    if (low!=high){
    	post(low, mid);//�ݹ������� 
    	post(mid+1,high);//�ݹ������� 
    }
    int i;
    int a=0,b=0;
//    int state=0;
     for (i=low;i<=high;i++)
        if (pre[i]=='0') a++;
        else b++;
    if (a&&b) printf("F");
    else if (a) printf("B");
    else printf("I");


}
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", pre+1);//ʵ������һ��ǰ����� 
    post(1,(pow(2,n)));
    return 0;
}
