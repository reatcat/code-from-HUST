#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salary,x;
    double tax;
    printf("�����빤��\n");
    scanf("%d",&salary);
    x=salary/1000;//�жϹ��ʵ�����
    if(x<=4)
    {
        switch(x)//˰���ж�
        {
        case 0:
            tax=0;
            break;
        case 1:
            tax=(salary-1000)*0.05;
            break;
        case 2:
            tax=(salary-2000)*0.1+50;
            break;
        case 3:
            tax=(salary-3000)*0.15+150;
            break;
        case 4:
            tax=(salary-4000)*0.2+300;
            break;
        }
    }
    else tax=(salary-5000)*0.25+500;
    printf("tax=%lf",tax);
    return 0;
}
