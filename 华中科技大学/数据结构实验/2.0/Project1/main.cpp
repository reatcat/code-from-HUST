#include "function.h"
int main() {
  clock_t start, end;  //��¼��ʼʱ�������ʱ��
  double duration;     //��¼��������ʱ��
  char filename[200];  //�ļ���
  int op = 1, tag;     //�˵�ѡ��
  int b;
  double time;
  HNode* head=(HNode*)malloc(sizeof(HNode));
  FILE* fp;
  while (op) {
    system("cls");
    printf("        ����SAT��������Ϸ������Ĳ˵�\n");
    printf("-------------------------------------------------\n");
    printf("    1.creat cnf       2.show cnf\n");
    printf("    3.DPLL            4.res\n");
    printf("    5.improve         0.exit\n");
    printf("----------------------------------------\n");
    printf("��ѡ����Ҫ���еĲ���[0-5]:\n");
    scanf("%d", &op);

    switch (op) {
      case 1:  //����cnf�ṹ��
        printf("�������ļ���:\n");
        scanf("%s", filename);
        fp = fopen(filename, "r");
        CreateCNF(head, fp);
        fclose(fp);
          printf("cnf��ʽ�����ɹ�\n");
        printf("%d %d", boolnum, clausenum);
        /*else {
          printf("cnf��ʽ����ʧ��\n");
          getchar();
          getchar();
          break;
        }*/
        getchar();
        getchar();
        break;

      case 2:  //��ʾcnf�ṹ
        
        getchar();
        getchar();
        break;

      case 3:              // DPLL�㷨
        
        getchar();
        getchar();
        break;

      case 4:
        
        getchar();
        getchar();
        break;
      case 5:
        
        getchar();
        getchar();
        break;

      case 0:
        break;
    }  // end of switch
  }    // end of while
  return 0;
}