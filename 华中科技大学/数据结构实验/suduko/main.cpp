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
  clock_t start, end;  //记录开始时间与结束时间
  double duration;     //记录程序运行时间
  char filename[200];  //文件名
  int op = 1, tag;     //菜单选择
  int b;
  int num;
  int dignum = 0;
  double time;
  double s;  //记录效率的提升
  while (op) {
    system("cls");
    printf("        基于SAT的数独游戏求解程序的菜单\n");
    printf("-------------------------------------------------\n");
    printf("    1.读取cnf文件      2.展示cnf文件\n");
    printf("    3.DPLL求解算例     4.保存为res\n");
    printf("    5.数独游戏         0.退出\n");
    printf("----------------------------------------\n");
    printf("请选择你要进行的操作[0-5]:\n");
    scanf("%d", &op);

    switch (op) {
      case 1:  //创建cnf结构体
          if (Bn.elem)
          {
          free(Bn.elem);
            Bn.elem = NULL;
          free(An.elem);
            An.elem = NULL;
          destory(L);
          }
        printf("请输入文件名:\n");
        scanf("%s", filename);
        if (createCNF(&L, filename) == OK) {
        printf("cnf创建成功\n");
        InitList(L, An);
        InitList(L, Bn);
        Bn.length = 0;
        sort(L, key, value);
        } 
        else
        printf("cnf创建失败\n");
        getchar();
        getchar();
        break;

      case 2:  //显示cnf结构
        showCNF(L);
        getchar();
        getchar();
        break;

      case 3:   // DPLL算法
        start = clock();
        tauto(L);
        printf("请选择分裂策略：\n");
        printf("策略1：按照文字出现次数优先\t策略2：按照子句的长度优先\n");
        scanf("%d", &choose);
        if (DPLL(L, An) == OK) {
          tag = 1;
          printf("该算例为可满足算例\n");
        } else {
          tag = 0;
          printf("该算例为不可满足算例\n");
        }
        end = clock();
        duration = ((double)(end - start)) / CLK_TCK * 1000;
        printf("运行时间为：%f毫秒\n", duration);

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
          printf("结果写入成功\n");
        else
          printf("结果写入失败\n");
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
          printf("        \t数独游戏          \n");
          printf("-------------------------------------------------\n");
          printf("    1.生成数独棋盘       2.挖洞\n");
          printf("    3.游戏              4.保存为cnf\n");
          printf("    5.使用DPLL求解       6.输出答案\n");
          printf("    0.Exit\n");
          printf("----------------------------------------\n");
          printf("请选择你要进行的操作[0-6]:\n");
          scanf("%d", &suc);
          
          switch (suc) {
            case 1:
              if (sd(shudu) == OK)
                printf("随机数独生成成功！\n");
              output_sudoku(shudu);
              for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                  beifen[i][j] = shudu[i][j];
        getchar();
        getchar();
        break;
            case 2:
              
              printf("请输入需要挖去的个数（一般不超过30）\n");
              scanf("%d", &dignum);

              if (digsudu(shudu, dignum,beifen) == OK)
                printf("挖洞法生成数独成功！\n");
              else
                printf("挖洞法生成数独失败！\n");
              output_sudoku(shudu);
              getchar();
              getchar();
              break;
            case 3:
              while (option) {
                system("cls");
                output_sudoku(shudu);
                printf("请输入想要填入的行列号：(例如1 1)\n");
                int row, col;
                scanf("%d %d", &row, &col);
                while(shudu[row - 1][col - 1] != 0) {
                  printf("请正确输入行列数!\n");
                  printf("请输入想要填入的行列号：(例如1 1)\n");
                scanf("%d %d", &row, &col);
                }
                printf("请输入要填入的数字：\n");
                int state;
                scanf("%d", &state);
                if (check_sudoku(shudu, row-1, col-1, state) == OK){
                  shudu[row-1][col-1] = state;
                printf("恭喜填入正确！\n");
                  if (check(shudu) == OK) { printf("你是个狠人！");
                  break;
                  }
              }
              else{
                  printf("填入错误！\n");
              }   
              printf("你还想继续填吗？（1/0）:");
              scanf("%d", &option);
              }
              getchar();
              getchar();
              break;
            case 4:
              printf("请输入文件名:\n");
              scanf("%s", filename);
             if (savecnf(shudu, filename,dignum) == OK)
                printf("保存为cnf成功");
             else
                printf("保存失败");
              getchar();
              getchar();
              break;
            case 5:
              printf("请输入文件名:\n");
              scanf("%s", filename);
              if (createCNF(&L, filename) == OK) {
                printf("cnf创建成功\n");
                InitList(L, An);
                InitList(L, Bn);
                Bn.length = 0;
                sort(L, key, value);
              } else
                printf("cnf创建失败\n");
              start = clock();
              tauto(L);
              printf("请选择分裂策略：\n");
              printf(
                  "策略1：按照文字出现次数优先\t策略2：按照子句的长度优先\n");
              scanf("%d", &choose);
              if (DPLL(L, An) == OK) {
                tag = 1;
                printf("该算例为可满足算例\n");
              } else {
                tag = 0;
                printf("该算例为不可满足算例\n");
              }
              end = clock();
              duration = ((double)(end - start)) / CLK_TCK * 1000;
              printf("运行时间为：%f毫秒\n", duration);
              if (sudures(An, filename,beifen) == OK)
                printf("保存数独答案成功！");
              else {
                printf("未能成功保存答案！");
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
              printf("请输入正确的语句！");
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
        printf("请输入正确的语句！");
        getchar();
        getchar();
        break;
      case 0:
        break;
    }  // end of switch
  }    // end of while
  return 0;
}