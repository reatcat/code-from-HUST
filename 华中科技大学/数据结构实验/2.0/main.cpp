#include "1.h"
int main()
{
    double duration;   //��¼��������ʱ��
    char filename[200]; //�ļ���
    FILE* fp;
    HNode* head;
    int op = 1, tag;            //�˵�ѡ��
    double time;
    while (op)
    {
        system("cls");
        printf("        ����SAT��������Ϸ������Ĳ˵�\n");
        printf("-------------------------------------------------\n");
        printf("    1.����cnf�ṹ       2.չʾcnf�ṹ\n");
        printf("    3.DPLL���          4.����Ϊres\n");
        printf("    5.������Ϸ        0.exit\n");
        printf("----------------------------------------\n");
        printf("��ѡ����Ҫ���еĲ���[0-5]:\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1: //����cnf�ṹ��
            printf("�������ļ���:\n");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if (CreateCNF(head, filename) == OK)
                printf("cnf��ʽ�����ɹ�\n");
            else
            {
                printf("cnf��ʽ����ʧ��\n");
                getchar(); getchar();
                break;
            }
            getchar(); getchar();
            break;

        //case 2: //��ʾcnf�ṹ
        //    showCNF(L);
        //    getchar(); getchar();
        //    break;

        //case 3: //DPLL�㷨
        //    b = Findl(L, An); //���ҵ���һ�����Ӿ�������ڷ��Ѳ��Ե�����
        //    start = clock();
        //    if (DPLL(L, An, b) == OK)
        //    {
        //        tag = 1;
        //        printf("���ɹ�\n");
        //    }
        //    else
        //    {

        //        tag = 0;
        //        printf("���ʧ��\n");
        //    }
        //    end = clock();
        //    duration = ((double)(end - start)) / CLK_TCK * 1000;
        //    printf("����ʱ��Ϊ��%f����\n", duration);

        //    for (int i = 1; i < An.length; i++) //���������������ⲻ�ɹ������������
        //    {
        //        if (An.elem[i] == -1)  printf("%5d", -i);
        //        else printf("%5d", i);
        //        if (i % 10 == 0)  printf("\n");
        //    }
        //    getchar(); getchar();
        //    break;

        //case 4:
        //    if (ResWrite(tag, duration, An, filename) == OK)
        //        printf("���д��ɹ�\n");
        //    else printf("���д��ʧ��\n");
        //    getchar(); getchar();
        //    break;
        //case 5:
        //    printf("������δ�Ż����������ʱ��:\n");
        //    printf("���δ�Ż������޷��ڹ涨ʱ�������������0\n");
        //    scanf("%lf", &time);
        //    if (time >= duration)
        //    {
        //        s = ((time - duration) / time) * 100;
        //        printf("Ч��������%.2lf %%\n", s);
        //    }
        //    else if (time < duration && time)
        //        printf("���Ż�\n");
        //    else printf("�Ż�Ч��Ϊ100%%\n");
        //    getchar(); getchar();
        //    break;

        case 0:
            break;
        }//end of switch
    }//end of while
    return 0;
}
}
