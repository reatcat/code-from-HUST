#include "function.h"
int main() {
  clock_t start, end;  //记录开始时间与结束时间
  double duration;     //记录程序运行时间
  char filename[200];  //文件名
  int op = 1, tag;     //菜单选择
  int b;
  double time;
  HNode* head=(HNode*)malloc(sizeof(HNode));
  FILE* fp;
  while (op) {
    system("cls");
    printf("        基于SAT的数独游戏求解程序的菜单\n");
    printf("-------------------------------------------------\n");
    printf("    1.creat cnf       2.show cnf\n");
    printf("    3.DPLL            4.res\n");
    printf("    5.improve         0.exit\n");
    printf("----------------------------------------\n");
    printf("请选择你要进行的操作[0-5]:\n");
    scanf("%d", &op);

    switch (op) {
      case 1:  //创建cnf结构体
        printf("请输入文件名:\n");
        scanf("%s", filename);
        fp = fopen(filename, "r");
        CreateCNF(head, fp);
        fclose(fp);
          printf("cnf公式创建成功\n");
        printf("%d %d", boolnum, clausenum);
        /*else {
          printf("cnf公式创建失败\n");
          getchar();
          getchar();
          break;
        }*/
        getchar();
        getchar();
        break;

      case 2:  //显示cnf结构
        
        getchar();
        getchar();
        break;

      case 3:              // DPLL算法
        
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