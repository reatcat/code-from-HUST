#include<stdio.h>
int i,j,k,m,n,ans;
int a[405]; //����˳�� 
int mord[21][21],t[21][21];
int cnt[21],last_[21]; //last_ ÿ����������ʱ�� 
int rec[21][8001]; //ÿ̨������ÿ��ʱ���Ƿ�ռ�� 
int max(int a,int b)
{
	if(a>=b)
	return a;
	else 
	return b;
}
int main()
{
    scanf("%d%d",&m,&n);
    for (i=1; i<=m*n; i++)
        scanf("%d",&a[i]);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            scanf("%d",&mord[i][j]);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            scanf("%d",&t[i][j]);
    for (i=1; i<=m*n; i++) {
        cnt[a[i]]++;
        int tmp1=a[i],tmp2=cnt[tmp1]; //tmp1:���� tmp2:����
        int tmpm=mord[tmp1][tmp2]; //������ //t[tmp1][tmp2]
        for (j=last_[tmp1];;j++) {
            bool flag = 1;
            for (k=j+1; k<=j+t[tmp1][tmp2]; k++)
                if (rec[tmpm][k]) { 
                    flag = 0;
                    break;
                }
            if (flag) {
                for (k=j+1; k<=j+t[tmp1][tmp2]; k++)
                    rec[tmpm][k] = 1; //����յ�
                last_[tmp1] = max(last_[tmp1],j+t[tmp1][tmp2]);
                ans = max(ans,last_[tmp1]); //���¸��ǵĽ�������� 
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
