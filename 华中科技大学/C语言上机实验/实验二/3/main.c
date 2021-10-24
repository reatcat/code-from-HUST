#include <stdlib.h>

int main()
{
    int n[10],day,i,m=0,s=0;
    scanf("%d",&day);
    if(day<=2)
        printf("0");
    else{
        for(i=0;i<day;i++)
            scanf("%d",&n[i]);
    for(i=1;i<day-1;i++)
    {
        if((n[i+1]>n[i]&&n[i-1]>n[i])||(n[i+1]<n[i]&&n[i-1]<n[i]))
            s++;
    }

    printf("%d",s);}
    return 0;
}
