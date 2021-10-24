#include <stdio.h>
int main()
{
    char s[14];
    int i,j,sum=0,x=1;
    scanf("%s",s);
    for(i=0; i<11; i++)
    {
        if(s[i]=='-')
        {
            sum=sum+0;
        }
        else
        {
            sum=sum+(s[i]-'0')*x;
            x++;
        }
    }
    sum=sum%11;
    if(sum==(s[12]-'0')||(s[12]=='X'&&sum==10))
    {
        printf("Right\n");
    }
    else
    {
        if(sum==10)
        {
            for(j=0; j<12; j++)
            {
                printf("%c",s[j]);
            }
            printf("X");
        }
        else
        {
            for(j=0; j<12; j++)
            {
                printf("%c",s[j]);
            }
            printf("%d",sum);
        }
    }
    return 0;
}

