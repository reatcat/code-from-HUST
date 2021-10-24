#include<stdio.h>
#include<math.h>//此处建树的的话需要 
#define MAX 100
char pre[MAX];
void post(int low, int high)//还可以是一个满二叉树,其中的根节点没有必要 
{
    int mid = (low+high)/2;
    if (low!=high){
    	post(low, mid);//递归左子树 
    	post(mid+1,high);//递归右子树 
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
    scanf("%s", pre+1);//实际上是一个前序遍历 
    post(1,(pow(2,n)));
    return 0;
}
