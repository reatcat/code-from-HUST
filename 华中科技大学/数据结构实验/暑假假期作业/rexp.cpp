#include<cstdio> 
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
	
}
int digui(int n)//���õݹ����ʽ 
{
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='a') n++;
        if(c=='(') n+=digui(0);
        if(c=='|') return max(n,digui(0));
        if(c==')') return n;
    }
    return n;
}
int main()
{
	int ans=digui(0);//��ʾ��0��ʼ
	 
	printf("%d",ans);
    return 0;
}
