#include<stdio.h>
int n;
int a[1000];
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){ 
        for(j=1;j<=i/2;j++){
            a[i]+=a[j];//�ù��ɼ���ó� 
        }
        a[i]++; 
    }
    printf("%d",a[n]);
    return 0;
}
