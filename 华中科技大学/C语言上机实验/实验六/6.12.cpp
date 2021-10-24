#include<stdio.h>
#include<string.h>
void task0()
{
    printf("task0 is called!\n");
}
void task1()
{
    printf("task1 is called!\n");
}
void task2()
{
    printf("task2 is called!\n");
}
void task3()
{
    printf("task3 is called!\n");
}
void task4()
{
    printf("task4 is called!\n");
}
void task5()
{
    printf("task5 is called!\n");
}
void task6()
{
    printf("task6 is called!\n");
}
void task7()
{
    printf("task7 is called!\n");
}
void schedular(char *);
void execute(void(*[])(),int );
int main()
{
    char a[50];
    scanf("%s",a);
    schedular(a);
}
void schedular(char *c)
{
    int len=strlen(c);
    void(*p[len])();
    for(int i=0;i<len;i++)
    {
        if(c[i]=='0')p[i]=task0;
        else if(c[i]=='1')p[i]=task1;
        else if(c[i]=='2')p[i]=task2;
        else if(c[i]=='3')p[i]=task3;
        else if(c[i]=='4')p[i]=task4;
        else if(c[i]=='5')p[i]=task5;
        else if(c[i]=='6')p[i]=task6;
        else if(c[i]=='7')p[i]=task7;
    }
    execute(p,len);
}
void execute(void(*p[])(),int len)
{
    for(int i=0;i<len;i++)
    p[i]();
}
