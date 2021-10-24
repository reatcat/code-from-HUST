#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef struct lNode {
  int l;  //存储文字
  int mark;  //标记该文字是否被删除，初始值为1，表示没有被删除
  struct lNode* next;
} lNode, *plNode;  //存储一个文字节点
typedef struct cNode {
  int l_count;  //存储一个子句的文字个数
  int flag;  //记录该子句因为flag而被删除，初始值为0，flag为需要删除的文字
  int mark;  //标记该子句是否被删除 ，初始值为1，表示没有被删除
  lNode* firstl;       //指向第一个文字节点
  struct cNode* next;  //指向下一条子句
} cNode, *pcNode;      //子句头节点
typedef struct cnf {
  int varinum;    //变元个数
  int claunum;    //子句个数
  cNode* firstc;  //指向第一个子句节点
} cnf, *pcnf;     //一个cnf公式
typedef struct SqList {
  int* elem;
  int length;
} SqList;  //一个顺序表结构，存储答案

int createCNF(pcnf* L, char filename[80]);
int showCNF(pcnf L);  //打印CNF公式
int InitList(pcnf L, SqList& An);
int RemoveClause(pcnf L, int flag);
int AddClause(pcnf L, int flag);
int EmptyClause(pcnf L);
int Findl(pcnf L, SqList& An);
int DPLL(pcnf L, SqList& An, int now_l);
int ResWrite(int res, double time, SqList& An, char filename[]);
int main() {
  pcnf L;
  SqList An;
  clock_t start, end;  //记录开始时间与结束时间
  double duration;     //记录程序运行时间
  char filename[200];  //文件名
  int op = 1, tag;     //菜单选择
  int b;
  double time;
  double s;  //记录效率的提升
  while (op) {
    system("cls");
    printf("        基于SAT的数独游戏求解程序的菜单\n");
    printf("-------------------------------------------------\n");
    printf("    1.创建CNF                2.展示CNF\n");
    printf("    3.DPLL算法求解           4.保存为res\n");
    printf("    0.exit\n");
    printf("----------------------------------------\n");
    printf("请选择你要进行的操作[0-5]:\n");
    scanf("%d", &op);

    switch (op) {
      case 1:  //创建cnf结构体
        printf("请输入文件名:\n");
        scanf("%s", filename);
        if (createCNF(&L, filename) == OK)
          printf("cnf公式创建成功\n");
        else {
          printf("cnf公式创建失败\n");
          getchar();
          getchar();
          break;
        }
        if (InitList(L, An) == OK)
          printf("分配结果存储空间成功\n");
        else {
          printf("分配结果存储空间失败\n");
          getchar();
          getchar();
          break;
        }
        getchar();
        getchar();
        break;

      case 2:  //显示cnf结构
        showCNF(L);
        getchar();
        getchar();
        break;

      case 3:              // DPLL算法
        b = Findl(L, An);  //先找到第一个单子句或者用于分裂策略的文字
        start = clock();
        if (DPLL(L, An, b) == OK) {
          tag = 1;
          printf("求解成功\n");
        } else {
          tag = 0;
          printf("求解失败\n");
        }
        end = clock();
        duration = ((double)(end - start)) / CLK_TCK * 1000;
        printf("运行时间为：%f毫秒\n", duration);

        for (int i = 1; i < An.length;
             i++)  //输出求解结果，如果求解不成功，就输出正数
        {
          if (An.elem[i] == -1)
            printf("%5d", -i);
          else
            printf("%5d", i);
          if (i % 10 == 0)
            printf("\n");
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
      case 0:
        break;
    }  // end of switch
  }    // end of while
  return 0;
}

int createCNF(pcnf* L, char filename[200]) {  //创建结构体，以表的形式存储
  pcNode p;                                   //子句结点
  plNode q;                                   //文字节点
  *L = (cnf*)malloc(sizeof(struct cnf));
  p = (cNode*)malloc(sizeof(struct cNode));
  p->flag = 0;  //记录子句是否因为flag而被删除
  p->mark = 1;  //记录子句是否被删除，1表示未被删除
  (*L)->firstc = p;
  FILE* fp;
  int num = 0;  //为计算子句数目和变元数目的中间变量
  int k = 0;    //记录每个子句文字个数
  int m = 0;    //记录子句的个数
  int flag;     //记录正负

  char c;  //读取文件字符使用

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("打开文件失败\n");
    return 0;
  }
  fscanf(fp, "%c", &c);
  while (!feof(fp)) {
    if (c == 'c') {  //把c开头的注释去掉
      while (c != '\n') {
        fscanf(fp, "%c", &c);
      }
      fscanf(fp, "%c", &c);
    } else if (c == 'p') {
      while (c != '\n') {
        while (c < '0' || c > '9') {
          fscanf(fp, "%c", &c);
        }
        while (c >= '0' && c <= '9') {  //获取变元数
          num = num * 10;
          num += c - '0';
          fscanf(fp, "%c", &c);
        }
        (*L)->varinum = num;
        num = 0;
        while (c < '0' || c > '9') {
          fscanf(fp, "%c", &c);
        }
        while (c >= '0' && c <= '9') {  //获取子句数
          num = num * 10;
          num += c - '0';
          fscanf(fp, "%c", &c);
        }
        (*L)->claunum = num;
        num = 0;
      }
      fscanf(fp, "%c", &c);
    } else if ((c >= '0' && c <= '9') || (c == '-')) {
      q = (lNode*)malloc(sizeof(struct lNode));
      q->mark = 1;  // mark等于1表示没有被删除
      p->firstl = q;
      while (c != '\n') {
        while (c != '0') {
          while (c != ' ') {
            flag = 1;
            while ((c >= '0' && c <= '9') || (c == '-')) {
              if (c == '-') {
                fscanf(fp, "%c", &c);
                flag = 0;
              }
              num = num * 10;
              num += c - '0';
              fscanf(fp, "%c", &c);
            }
            if (flag == 0)
              q->l = -num;
            else
              q->l = num;
            num = 0;
            k++;
          }
          fscanf(fp, "%c", &c);
          if (c == '0')
            q->next = NULL;
          else {
            q->next = (lNode*)malloc(sizeof(struct lNode));
            q = q->next;
            q->mark = 1;
          }
        }
        fscanf(fp, "%c", &c);
      }
      fscanf(fp, "%c", &c);
      p->l_count = k;
      k = 0;
      m++;

      if (m < (*L)->claunum) {
        p->next = (cNode*)malloc(sizeof(struct cNode));
        p = p->next;
        p->flag = 0;
        p->mark = 1;
      } else
        p->next = NULL;
    } else
      fscanf(fp, "%c", &c);  //防止文件结尾有多个换行
  }
  fclose(fp);
  return OK;
}

int showCNF(pcnf L) {  //显示cnf结构体
  if (L->claunum == 0) {
    printf("cnf公式为空\n");
    return OK;
  }
  pcNode p = L->firstc;
  plNode q = p->firstl;
  printf("cnf公式变元数：%d  子句数：%d\n", L->varinum, L->claunum);
  int i = 1;
  int j;
  while (p) {
    if (p->mark == 0)
      p = p->next;
    else {
      printf("第%d句有%d个文字   ", i++, p->l_count);
      q = p->firstl;
      j = 1;
      while (q) {
        if (q->mark == 0)
          q = q->next;
        else {
          printf("%4d:%5d", j++, q->l);
          q = q->next;
        }
      }
      printf("\n");
      p = p->next;
    }
  }
  return OK;
}

int InitList(pcnf L, SqList& An) {  //初始化结果接收顺序表
  An.elem = (int*)malloc((L->varinum + 1) * sizeof(int));  //分配存储空间
  if (!An.elem) {
    return ERROR;  //分配存储空间失败
  };
  An.length = L->varinum + 1;  //初始化线性表的长度为0
  for (int i = 1; i < An.length; i++) {
    An.elem[i] = 0;  //表示没有经过单子句简化赋值
    // printf("%d  ",An.elem[i]); 查看程序运行进度，没有必要打开
  }
  return OK;
}

int RemoveClause(pcnf L, int flag) {  //一次找出一个变元，并删除
  pcNode p;
  plNode q;
  p = L->firstc;
  q = p->firstl;
  while (p) {
    if (p->mark == 0)
      p = p->next;
    else {
      q = p->firstl;
      while (q) {
        if (q->mark == 0)
          q = q->next;
        else {
          if (q->l == flag) {  //子句中有flag，删除子句
            p->mark = 0;
            p->flag = flag;
            L->claunum--;  //子句数目减一
            break;
          } else if (q->l == -flag) {  //子句中有-flag，删除该文字
            q->mark = 0;
            p->l_count--;  //文字数目减一
            break;
          } else
            q = q->next;
        }
      }
      p = p->next;
    }
  }
  L->varinum--;  //删除变元后，变元数目减一
  return OK;
}

int AddClause(pcnf L, int flag) {  //恢复前面因为flag而删除的元素，子句
  pcNode p;
  plNode q;
  p = L->firstc;
  q = p->firstl;
  while (p) {
    q = p->firstl;
    if (p->mark == 1) {  //恢复非L规则删除的文字
      while (q) {
        if (q->mark == 0 && q->l == -flag) {
          q->mark = 1;
          p->l_count++;  //子句文字数目加一
          break;
        } else
          q = q->next;
      }
    } else if (p->mark == 0 && p->flag == flag) {  //恢复子句
      p->mark = 1;
      p->flag = 0;
      L->claunum++;
    } else {
      while (q) {
        if (q->mark == 0 && q->l == -flag) {
          q->mark = 1;
          p->l_count++;  //子句文字数目加一
          break;
        } else
          q = q->next;
      }
    }
    p = p->next;
  }
  L->varinum++;  //变元数目加一
  return OK;
}

int EmptyClause(pcnf L) {  //查看是否有空句
  pcNode p = L->firstc;
  while (p) {
    if (p->l_count == 0 && p->mark == 1)
      return OK;  //当文字数为0，且子句未经过删减，则是空句
    p = p->next;
  }
  return FALSE;
}

int Findl(pcnf L, SqList& An) {  //查找符合要求的变元
  pcNode p;
  plNode q;
  int i;
  int flag = 0;  //用于寻找出现的最高次数和对应的变元
  p = L->firstc;
  while (p) {  //寻找单子句
    if (p->mark == 1 && p->l_count == 1) {
      q = p->firstl;
      while (q) {
        if (q->mark == 1) {
          if (q->l > 0)
            An.elem[q->l] = 1;
          else
            An.elem[-(q->l)] = -1;
          return q->l;
        } else
          q = q->next;
      }
    } else
      p = p->next;
  }
  //改变策略，寻找出现次数最多的变元
  int* a = (int*)malloc((2 * An.length - 1) * sizeof(int));
  for (i = 0; i < 2 * An.length - 1; i++) {
    a[i] = 0;
  }
  p = L->firstc;
  while (p) {  //记录各变元出现的次数
    if (p->mark == 0)
      p = p->next;
    else {
      q = p->firstl;
      while (q) {
        if (q->mark == 0)
          q = q->next;
        else {
          if (q->l > 0)
            a[2 * (q->l) - 1]++;
          else if (q->l < 0)
            a[2 * (-(q->l))]++;
          q = q->next;
        }
      }
      p = p->next;
    }
  }
  for (i = 1; i < 2 * An.length - 1; i++) {  //找出出现次数的最大值
    if (a[i] > flag)
      flag = a[i];
  }
  for (i = 1; i < 2 * An.length - 1; i++) {  //找到变元
    if (a[i] == flag)
      break;
  }
  free(a);
  if (i % 2) {
    An.elem[(i + 1) / 2] = 1;
    return ((i + 1) / 2);
  } else {
    An.elem[i / 2] = -1;
    return (-(i / 2));
  }
}

int DPLL(pcnf L, SqList& An, int now_l) {  // now_l是当前输入用来化简的
  int next_l;                              //利用Findl函数生成的
  if (L->claunum == 0)
    return OK;  // cnf公式为空，化简成功
  else {
    if (EmptyClause(L) == OK) {  //有空子句，是不满足算例
      if (AddClause(L, now_l) != OK)
        printf("恢复失败\n");
      if (now_l > 0)
        An.elem[now_l] = 0;
      else
        An.elem[-now_l] = 0;
      return FALSE;
    } else {  // cnf还未化简完，采用单子句原则+分裂策略
      next_l = Findl(L, An);
      if (next_l == 0)
        return FALSE;

      if (RemoveClause(L, next_l) != OK)
        printf("删除失败\n");

      if (DPLL(L, An, next_l) == OK)
        return OK;
      else {  //化简不成功时，需要改变next_l的真值，进行回溯
        if (AddClause(L, next_l) != OK)
          printf("恢复失败\n");
        if (RemoveClause(L, -next_l) != OK)
          printf("删除失败\n");
        if (DPLL(L, An, -next_l) == OK) {
          if (next_l > 0)
            An.elem[next_l] = -1;
          else
            An.elem[-next_l] = 1;
          return OK;
        } else {  //最后还未成功，将顺序表相应位置修改为未进行真值判断的状态
          if (AddClause(L, -next_l) != OK)
            printf("恢复失败\n");
          if (next_l > 0)
            An.elem[next_l] = 0;
          else
            An.elem[-next_l] = 0;
          return FALSE;
        }
      }
    }
  }
}

int ResWrite(int res, double time, SqList& An, char filename[80]) {
  int i = 0;
  while (filename[i] != '\0')
    i++;
  filename[i - 3] = 'r';  //只改变文件的扩展名
  filename[i - 2] = 'e';
  filename[i - 1] = 's';
  FILE* fp;
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("打开文件失败\n");
    return ERROR;
  }
  fprintf(fp, "s %d\n", res);  // res是求解结果，1表示满足，0表示不满足，-1未定
  fprintf(fp, "v\n");
  for (i = 1; i < An.length; i++) {
    if (An.elem[i] == -1)
      fprintf(fp, "%5d", -i);
    else
      fprintf(fp, "%5d", i);
    if (i % 10 == 0)
      fprintf(fp, "\n");
  }
  fprintf(fp, "\nt %f ms\n", time);
  fclose(fp);
  return OK;
}
