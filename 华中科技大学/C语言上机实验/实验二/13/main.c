#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void move(int *num)
{
    int temp = num[5],i;
    for ( i = 5; i >= 1; i--)
    {
        num[i] = num[i-1];
    }
    num[0] = temp;
}

void changeChar(char *p1, char *p2)
{
    char temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

char code(char ch)
{
    int num[8],i;
    char result;
    for ( i = 0; i < 8; i++)
    {
        num[i] = ch & 1;
        ch = ch >> 1;
    }

    changeChar(num, num + 1);
    changeChar(num + 2, num + 3);
    changeChar(num + 4, num + 5);

    int value = num[6] + num[7] * 2;

    for ( i= 0; i < value; i++)
    {
        move(num);
    }

    int a = 0;
    for( i = 0;i < 8;i++){
        a += num[i] * pow(2,i);
    }
    return a;
}
int main(void){

    char a[40];
    int i;
    scanf("%s",a);
    for(i = 0;i < strlen(a);i++){
        a[i] = code(a[i]);
    }
    printf("%s",a);

    return 0;
}








