#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[20];
    while(scanf("%s",s)!=EOF){
    if(strlen(s)!=11)
        printf("长度不合法");
       else if(s[0]!='1')
        printf("第一位不合法");
        else if(s[1]!='3'&&s[1]!='4'&&s[1]!='5'&&s[1]!='7'&&s[1]!='8')
        printf("第二位不合法");
        else
            printf("合法");


    }

    return 0;
}
