#include "head.h"
#include "cnfs.h"
#include "res.h"
#include "new.h"
#include "game.h"
int main() {
  pcnf L;
  SqList An;
  int suc = 1;
  int shudu[9][9];
  clock_t start, end;  //��¼��ʼʱ�������ʱ��
  double duration;     //��¼��������ʱ��
  char filename[200];  //�ļ���
  int op = 1, tag;     //�˵�ѡ��
  int b;
  int num;
  int dignum = 0;
  double time;
  double s;  //��¼Ч�ʵ�����
  while (op) {
    system("cls");
    printf("        ����SAT��������Ϸ������Ĳ˵�\n");
    printf("-------------------------------------------------\n");
    printf("    1.��ȡcnf�ļ�      2.չʾcnf�ļ�\n");
    printf("    3.DPLL�������     4.����Ϊres\n");
    printf("    5.������Ϸ         0.�˳�\n");
    printf("----------------------------------------\n");
    printf("��ѡ����Ҫ���еĲ���[0-5]:\n");
    scanf("%d", &op);

    switch (op) {
      case 1:  //����cnf�ṹ��
          if (Bn.elem)
          {
          free(Bn.elem);
            Bn.elem = NULL;
          free(An.elem);
            An.elem = NULL;
          destory(L);
          }
        printf("�������ļ���:\n");
        scanf("%s", filename);
        if (createCNF(&L, filename) == OK) {
        printf("cnf�����ɹ�\n");
        InitList(L, An);
        InitList(L, Bn);
        Bn.length = 0;
        sort(L, key, value);
        } 
        else
        printf("cnf����ʧ��\n");
        getchar();
        getchar();
        break;

      case 2:  //��ʾcnf�ṹ
        showCNF(L);
        getchar();
        getchar();
        break;

      case 3:   // DPLL�㷨
        start = clock();
        tauto(L);
        printf("��ѡ����Ѳ��ԣ�\n");
        printf("����1���������ֳ��ִ�������\t����2�������Ӿ�ĳ�������\n");
        scanf("%d", &choose);
        if (DPLL(L, An) == OK) {
          tag = 1;
          printf("������Ϊ����������\n");
        } else {
          tag = 0;
          printf("������Ϊ������������\n");
        }
        end = clock();
        duration = ((double)(end - start)) / CLK_TCK * 1000;
        printf("����ʱ��Ϊ��%f����\n", duration);

        for (int i = 1; i < An.length;i++)
        {
          if (An.elem[i] == -1)
            printf("%d ", -i);
          else
            printf("%d ", i);
        }
        getchar();
        getchar();
        break;

      case 4:
        if (ResWrite(tag, duration, An, filename) == OK)
          printf("���д��ɹ�\n");
        else
          printf("���д��ʧ��\n");
        getchar();
        getchar();
        break;
      case 5:
        int option;
        option = 1;
        int beifen[9][9];
        suc = 1;
        
        while (suc) {
          system("cls");
          printf("        \t������Ϸ          \n");
          printf("-------------------------------------------------\n");
          printf("    1.������������       2.�ڶ�\n");
          printf("    3.��Ϸ              4.����Ϊcnf\n");
          printf("    5.ʹ��DPLL���       6.�����\n");
          printf("    0.Exit\n");
          printf("----------------------------------------\n");
          printf("��ѡ����Ҫ���еĲ���[0-6]:\n");
          scanf("%d", &suc);
          
          switch (suc) {
            case 1:
              if (sd(shudu) == OK)
                printf("����������ɳɹ���\n");
              output_sudoku(shudu);
              for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                  beifen[i][j] = shudu[i][j];
        getchar();
        getchar();
        break;
            case 2:
              
              printf("��������Ҫ��ȥ�ĸ�����һ�㲻����30��\n");
              scanf("%d", &dignum);

              if (digsudu(shudu, dignum,beifen) == OK)
                printf("�ڶ������������ɹ���\n");
              else
                printf("�ڶ�����������ʧ�ܣ�\n");
              output_sudoku(shudu);
              getchar();
              getchar();
              break;
            case 3:
              while (option) {
                system("cls");
                output_sudoku(shudu);
                printf("��������Ҫ��������кţ�(����1 1)\n");
                int row, col;
                scanf("%d %d", &row, &col);
                while(shudu[row - 1][col - 1] != 0) {
                  printf("����ȷ����������!\n");
                  printf("��������Ҫ��������кţ�(����1 1)\n");
                scanf("%d %d", &row, &col);
                }
                printf("������Ҫ��������֣�\n");
                int state;
                scanf("%d", &state);
                if (check_sudoku(shudu, row-1, col-1, state) == OK){
                  shudu[row-1][col-1] = state;
                printf("��ϲ������ȷ��\n");
                  if (check(shudu) == OK) { printf("���Ǹ����ˣ�");
                  break;
                  }
              }
              else{
                  printf("�������\n");
              }   
              printf("�㻹��������𣿣�1/0��:");
              scanf("%d", &option);
              }
              getchar();
              getchar();
              break;
            case 4:
              printf("�������ļ���:\n");
              scanf("%s", filename);
             if (savecnf(shudu, filename,dignum) == OK)
                printf("����Ϊcnf�ɹ�");
             else
                printf("����ʧ��");
              getchar();
              getchar();
              break;
            case 5:
              printf("�������ļ���:\n");
              scanf("%s", filename);
              if (createCNF(&L, filename) == OK) {
                printf("cnf�����ɹ�\n");
                InitList(L, An);
                InitList(L, Bn);
                Bn.length = 0;
                sort(L, key, value);
              } else
                printf("cnf����ʧ��\n");
              start = clock();
              tauto(L);
              printf("��ѡ����Ѳ��ԣ�\n");
              printf(
                  "����1���������ֳ��ִ�������\t����2�������Ӿ�ĳ�������\n");
              scanf("%d", &choose);
              if (DPLL(L, An) == OK) {
                tag = 1;
                printf("������Ϊ����������\n");
              } else {
                tag = 0;
                printf("������Ϊ������������\n");
              }
              end = clock();
              duration = ((double)(end - start)) / CLK_TCK * 1000;
              printf("����ʱ��Ϊ��%f����\n", duration);
              if (sudures(An, filename,beifen) == OK)
                printf("���������𰸳ɹ���");
              else {
                printf("δ�ܳɹ�����𰸣�");
              }
              getchar();
              getchar();
              break;
            case 6:
              output_sudoku(beifen);
              getchar();
              getchar();
              break;
            default:
              printf("��������ȷ����䣡");
              getchar();
              getchar();
              break;
            case 0:
              break;

          }
        }
        getchar();
        getchar();
        break;
      default:
        printf("��������ȷ����䣡");
        getchar();
        getchar();
        break;
      case 0:
        break;
    }  // end of switch
  }    // end of while
  return 0;
}