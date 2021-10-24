#include<stdio.h>
#include<string.h>
int main()
{
    int p=1,ans=0,i,j,n,x;
	int high=0,last,a[500],b[500];
    char c[100];
    scanf("%d",&n);
    scanf("%s",c);
    j=0;
    while(c[j]!=0)
    {
        if((c[j]>='0')&&(c[j]<='9'))a[j+1]=c[j]-'0';
        else a[j+1]=c[j]-'A'+10;
        j++;
    }
    while(ans<=30)
    {
        high=0;
        i=1;

while(i<=j)
        {
            x=a[j-i+1]+a[i]+high;
            high=x/n;
            b[j-i+1]=x%n;
            i++;
        }
        if(high!=0)
		b[0]=high;
        if(high!=0)
        {
            for(i=1;i<=j+1;i++)
			a[i]=b[i-1];
            j++;
        }
        else 
		{
		for(i=1;i<=j;i++)
		a[i]=b[i];
		}
        ans++;
        i=1;
        last=j;
        p=1;
        while(i<=last)
        {
            if(a[i]!=a[last])
			p=0;
            i++;
            last--;
        }
        if(p)
        {
            printf("STEP=%d",ans);
            break;
        }
    }
    if(ans>30)
    printf("Impossible!");
    return 0;
}
