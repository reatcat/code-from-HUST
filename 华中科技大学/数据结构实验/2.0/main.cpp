#include "1.h"
int main()
{
    double duration;   //记录程序运行时间
    char filename[200]; //文件名
    FILE* fp;
    HNode* head;
    int op = 1, tag;            //菜单选择
    double time;
    while (op)
    {
        system("cls");
        printf("        基于SAT的数独游戏求解程序的菜单\n");
        printf("-------------------------------------------------\n");
        printf("    1.创建cnf结构       2.展示cnf结构\n");
        printf("    3.DPLL求解          4.保存为res\n");
        printf("    5.数独游戏        0.exit\n");
        printf("----------------------------------------\n");
        printf("请选择你要进行的操作[0-5]:\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1: //创建cnf结构体
            printf("请输入文件名:\n");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if (CreateCNF(head, filename) == OK)
                printf("cnf公式创建成功\n");
            else
            {
                printf("cnf公式创建失败\n");
                getchar(); getchar();
                break;
            }
            getchar(); getchar();
            break;

        //case 2: //显示cnf结构
        //    showCNF(L);
        //    getchar(); getchar();
        //    break;

        //case 3: //DPLL算法
        //    b = Findl(L, An); //先找到第一个单子句或者用于分裂策略的文字
        //    start = clock();
        //    if (DPLL(L, An, b) == OK)
        //    {
        //        tag = 1;
        //        printf("求解成功\n");
        //    }
        //    else
        //    {

        //        tag = 0;
        //        printf("求解失败\n");
        //    }
        //    end = clock();
        //    duration = ((double)(end - start)) / CLK_TCK * 1000;
        //    printf("运行时间为：%f毫秒\n", duration);

        //    for (int i = 1; i < An.length; i++) //输出求解结果，如果求解不成功，就输出正数
        //    {
        //        if (An.elem[i] == -1)  printf("%5d", -i);
        //        else printf("%5d", i);
        //        if (i % 10 == 0)  printf("\n");
        //    }
        //    getchar(); getchar();
        //    break;

        //case 4:
        //    if (ResWrite(tag, duration, An, filename) == OK)
        //        printf("结果写入成功\n");
        //    else printf("结果写入失败\n");
        //    getchar(); getchar();
        //    break;
        //case 5:
        //    printf("请输入未优化程序的运行时间:\n");
        //    printf("如果未优化程序无法在规定时间内求解请输入0\n");
        //    scanf("%lf", &time);
        //    if (time >= duration)
        //    {
        //        s = ((time - duration) / time) * 100;
        //        printf("效率提升了%.2lf %%\n", s);
        //    }
        //    else if (time < duration && time)
        //        printf("负优化\n");
        //    else printf("优化效率为100%%\n");
        //    getchar(); getchar();
        //    break;

        case 0:
            break;
        }//end of switch
    }//end of while
    return 0;
}
}
