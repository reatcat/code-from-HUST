#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[20];
    while(scanf("%s",s)!=EOF){
    if(strlen(s)!=11)
        printf("���Ȳ��Ϸ�");
       else if(s[0]!='1')
        printf("��һλ���Ϸ�");
        else if(s[1]!='3'&&s[1]!='4'&&s[1]!='5'&&s[1]!='7'&&s[1]!='8')
        printf("�ڶ�λ���Ϸ�");
        else
            printf("�Ϸ�");


    }

    return 0;
}
