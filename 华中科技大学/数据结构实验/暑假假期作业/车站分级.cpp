#include<bits/stdc++.h>
using namespace std;
#define max 1005
int n,m,ans,st[max],s,tuopu[max][max],de[max],tt[max],top;
int  is[max]={0},bo[max];
int main() {//�������� 
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
    	memset(is,0,sizeof(is));
    	 scanf("%d",&s);
        for(int j=1;j<=s;j++)
            scanf("%d",&st[j]),is[st[j]]=1;
        for(int j=st[1];j<=st[s];j++)
            if(!is[j])		
                for(int k=1;k<=s;k++)//��ͣ��վ��
                    if(!tuopu[j][st[k]]) tuopu[j][st[k]]=1,de[st[k]]++;//tuopu[i][j]��ʾj>i�ļ���
    }
    do{
        top=0;
        for(int i=1;i<=n;i++)
            if(de[i]==0&&!bo[i]) {
                tt[++top]=i,bo[i]=1;//����Ϊ0�ĵ�ɾ��
            }
        for(int i=1;i<=top;i++)
            for(int j=1;j<=n;j++)
                if(tuopu[tt[i]][j]) tuopu[tt[i]][j]=0,de[j]--;//ȥ��ȥ��
        ans++;
    }while(top);
    printf("%d",ans);
    return 0;
}
