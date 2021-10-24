#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct intNode {    //存放文字
  int value;
  struct intNode* next;
} intNode;

typedef struct intHead  //存放链表的头
{
  int length;  //长度
  intNode* firstNode;
} intHead;

typedef struct LitNode {//文字
  int tureNum;      //真值的数量
  int falseNum;     //假值的数量
  intHead* poHead;  //记录真值所在的位置
  intHead* neHead;  //记录假值所在的位置
  int statement;    //是否已经使用过这个数字
} LitNode;

typedef struct ClauseNode {
  int length;
  int statement;  //是否被销毁，1表示已被销毁，0表示还未
  intNode* Node;
} ClauseNode;

typedef struct CNF {
  int litNum;     //变元的数量
  int clauseNum;  //子句的数量，用来初始化子句数组和变元数组
  LitNode* lit;
  ClauseNode* Clause;
} CNF;

typedef struct DecisionTreeNode {//由于树形递归
  struct DecisionTreeNode* next;
  struct DecisionTreeNode* pre;
  int statement;  //是怎么得来的，1表示单子句，0表示分裂
  int lit;
} DecisionTreeNode;

typedef struct DecisionTreeHead {//头
  DecisionTreeNode* firstNode;
  int length;
} DecisionTreeHead;

DecisionTreeHead* DPLL(CNF* cnf, int way);
int getFile(CNF*, char*);
void initCnf(CNF*);
void addElem(CNF*, int, int);
int singleLit(CNF*);
DecisionTreeNode* addTreeNode(int single, int n, DecisionTreeHead* aHead);
int singleRule(int currentSingle, CNF* cnf);
DecisionTreeNode* goBack(DecisionTreeNode* TreeNode, CNF* cnf);
int Correct(CNF* cnf);  //判断是否成功
int kownLitNumber(int sudoku[8][8], int n);
void addClause(int sudoku[8][8], int n, CNF* cnf, int* q);
void addKnown(int sudoku[8][8], int n, CNF* cnf, int* q);  //添加已知的子句
void travel(CNF*);
DecisionTreeHead* creatSAT(int sudoku[8][8], int n, int way);
int* getPuzzle(DecisionTreeHead* aHead);
void ShowKey(int length, int* key, int timer);
void ShowPuzzle(int*);
void freeall(CNF* cnf);
void outfile(int* key, int n, int timer, int num, char* filename);
void option1();
void EnterArray(int n[8][8]);
int* createpuzzle();
void dig(int n[8][8]);
int judge(int n[8][8], int row, int line, int k);
int calculateCount(int countA, int countB, int n);
int calculateSize(int n);
void addConstraint1(int n, CNF* cnf, int* q);
void addConstraint2(int n, CNF* cnf, int* q);
void addConstraint3(int n, CNF* cnf, int* q);
int calculateClauseSize(int n);
int selectLit(CNF* cnf, int way);

int Check(CNF* cnf, DecisionTreeHead* aHead) {
  //验算
  DecisionTreeNode* aNode = aHead->firstNode;
  int* key;
  key = (int*)malloc(sizeof(int) * cnf->litNum + 1);
  for (int n = 1; n < cnf->litNum + 1; n++) {
    int p = abs(aNode->lit);
    if (aNode->lit > 0)
      key[p]= 1;
      key[p] = -1;
    aNode = aNode->next;
  }
  for (int n = 1; n < cnf->clauseNum + 1; n++) {
    int flag = 0;
    intNode* newNode = cnf->Clause[n].Node;
    for (; newNode != NULL; newNode = newNode->next) {
      if (newNode->value * key[abs(newNode->value)] > 0)
        flag = 1;
    }
    if (flag == 0) {
      free(key);
    return 0;
    }
    
  }
  free(key);
  return 1;
}

void ShowKey(int length, int* key, int timer) {
  if (key == NULL) {
    printf("s 0\n");
    printf("v\n");
    printf("t %d0\n", timer);
    return;
  }
  printf("s 1\nv ");
  for (int i = 0; i < length; i++)
    printf("%d ", key[i]);
  printf("\nt %dms \n", timer);
}


int* getKey(DecisionTreeHead* aHead) {
  if (aHead == NULL)
    return NULL;
  int* key = (int*)malloc(aHead->length * sizeof(int));
  DecisionTreeNode* newHead = aHead->firstNode;
  for (; newHead != NULL; newHead = newHead->next)
    key[abs(newHead->lit) - 1] = newHead->lit;
  return key;
}


DecisionTreeHead* DPLL(CNF* cnf, int way)  // way决策的方法，1顺序，2逆序，3随机
{
  DecisionTreeHead* aHead = (DecisionTreeHead*)malloc(sizeof(DecisionTreeHead));
  aHead->firstNode = NULL;
  aHead->length = cnf->litNum;
  int flag = 1;
  int currentSingle = 0;
  DecisionTreeNode* TreeNode = NULL;
  while (!Correct(cnf))  //当这个解还没完成
  {
    while (flag && (currentSingle = singleLit(cnf))) {
      TreeNode = addTreeNode(currentSingle, 1, aHead);  //指向当前刚创建的决策树
      flag = singleRule(currentSingle, cnf);  //进行单子句规则执行
       // travel(cnf);
    }
    if (flag == 1)  //如果还没失败，且单子句都被选完了
    {
      currentSingle = selectLit(cnf, way);
      if (currentSingle == 0) {
        freeall(cnf);
        return aHead;  //完成了
      }
      TreeNode = addTreeNode(currentSingle, 0, aHead);
      flag = singleRule(currentSingle, cnf);
      // travel(cnf);
    } else  //如果失败了
    {
      TreeNode = goBack(TreeNode, cnf);
      if (TreeNode == NULL) {
        freeall(cnf);
        return NULL;
      }
      flag = singleRule(TreeNode->lit, cnf);
    }
  }
  freeall(cnf);
  return aHead;
}

void freeall(CNF* cnf) {
  if (cnf == NULL) {
    return;
  }
  for (int q1 = 1; q1 < cnf->litNum + 1; q1++) {
    for (intNode* p = cnf->lit[q1].poHead->firstNode; p != NULL;) {
      intNode* temp = p;
      p = p->next;
      free(temp);
    }
    for (intNode* p = cnf->lit[q1].neHead->firstNode; p != NULL;) {
      intNode* temp = p;
      p = p->next;
      free(temp);
    }
  }
  free(cnf->lit);
  for (int q1 = 1; q1 < cnf->clauseNum + 1; q1++)
    for (intNode* p = cnf->Clause[q1].Node; p != NULL;) {
      intNode* temp = p;
      p = p->next;
      free(temp);
    }
  free(cnf->Clause);
  free(cnf);
}

void recover(int n, CNF* cnf) {
  int lit = abs(n);
  intNode* recoverC = NULL;
  intNode* recoverL = NULL;
  cnf->lit[lit].statement = 0;  //已恢复
  if (n > 0) {
    recoverC = cnf->lit[lit].poHead->firstNode;
    recoverL = cnf->lit[lit].neHead->firstNode;
  } else {
    recoverC = cnf->lit[lit].neHead->firstNode;
    recoverL = cnf->lit[lit].poHead->firstNode;
  }
  for (; recoverL != NULL; recoverL = recoverL->next)
    if (cnf->Clause[recoverL->value].statement == 0)
      cnf->Clause[recoverL->value].length++;
  for (; recoverC != NULL; recoverC = recoverC->next)
    if (cnf->Clause[recoverC->value].statement == n)
      cnf->Clause[recoverC->value].statement = 0;
  // travel(cnf);
}

DecisionTreeNode* goBack(DecisionTreeNode* TreeNode, CNF* cnf) {
  while (TreeNode->statement == 1 &&
         TreeNode->pre !=
             NULL)  //当这个结点时单子句获得来的，且前一个结点还存在
  {
    DecisionTreeNode* newNode = TreeNode;
    recover(newNode->lit, cnf);
    TreeNode = TreeNode->pre;
    TreeNode->next = NULL;
    free(newNode);
    newNode = NULL;
  }
  if (!TreeNode->statement)  //如果这个结点是选择来的
  {
    recover(TreeNode->lit, cnf);
    TreeNode->statement = 1;
    TreeNode->lit = -TreeNode->lit;
    return TreeNode;
  } else  //说明没有了
  {
    return NULL;
  }
}

int selectLit(CNF* cnf, int way) {
  //顺序
  if (way == 1) {
    int i = 1;
    for (; i < cnf->litNum + 1; i++)
      if (cnf->lit[i].statement == 0) {
        return i;
      }
    return 0;
  }
  //逆序
  if (way == 2) {
    int i = cnf->litNum;

    for (; i > 0; --i)
      if (cnf->lit[i].statement == 0) {
        return i;
      }
    return 0;
  }
  //随机，选择200次，如果都没选出来就进行顺序
  if (way == 3) {
    int count = 0;
    if (Correct(cnf))
      return 0;
    srand((unsigned)time(NULL));
    int i = (rand()) % cnf->litNum + 1;
    while (1) {
      count++;
      if (cnf->lit[i].statement == 0) {
        return i;
      }
      i = (rand()) % cnf->litNum + 1;
      if (count > 200)
        break;
    }
    for (; i < cnf->litNum + 1; i++)
      if (cnf->lit[i].statement == 0) {
        return i;
      }
    return 0;
  }
}

int singleRule(int currentSingle, CNF* cnf) {
  int flag = 1;
  int single = abs(currentSingle);
  cnf->lit[single].statement = 1;  //表示已使用过

  intNode* deleteNode = NULL;   //把这个子句的部分内容删除
  intNode* destroyNode = NULL;  //销毁这个子句

  if (currentSingle > 0) {
    deleteNode = cnf->lit[single].neHead->firstNode;
    destroyNode = cnf->lit[single].poHead->firstNode;
  } else {
    deleteNode = cnf->lit[single].poHead->firstNode;
    destroyNode = cnf->lit[single].neHead->firstNode;
  }
  //摧毁子句
  for (; destroyNode != NULL; destroyNode = destroyNode->next)
    if (cnf->Clause[destroyNode->value].statement == 0) {
      cnf->Clause[destroyNode->value].statement = currentSingle;
    }
  for (; deleteNode != NULL; deleteNode = deleteNode->next)
    if (cnf->Clause[deleteNode->value].statement == 0) {
      cnf->Clause[deleteNode->value].length--;
      if (cnf->Clause[deleteNode->value].length == 0)
        flag = 0;  //出现错误，决策失败
    }
  return flag;  //完美解决
}

DecisionTreeNode* addTreeNode(int single,
          int n,
        DecisionTreeHead* aHead)  //把这个点添加进决策树
{
  DecisionTreeNode* newNode = aHead->firstNode;
  if (newNode == NULL)  //如果这是第一个生成的决策树
  {
    aHead->firstNode = (DecisionTreeNode*)malloc(sizeof(DecisionTreeNode));
    newNode = aHead->firstNode;
    newNode->next = NULL;
    newNode->pre = NULL;
    newNode->statement = n;
    newNode->lit = single;
    return aHead->firstNode;
  } else {
    while (newNode->next != NULL)  //找到最后一个node
      newNode = newNode->next;
    newNode->next = (DecisionTreeNode*)malloc(sizeof(DecisionTreeNode));
    newNode->next->pre = newNode;
    newNode->next->lit = single;
    newNode->next->next = NULL;
    newNode->next->statement = n;
    return newNode->next;
  }
}

int Correct(CNF* cnf)  //判断是否成功
{
  //所有的子句都要被销毁
  for (int n = cnf->clauseNum; n > 0; n--) {
    if (cnf->Clause[n].statement == 0)
      return 0;
  }
  return 1;
}

int singleLit(CNF* cnf)  //获取当前的单子句的内容
{
  intNode* newNode = NULL;
  for (int n = 1; n < cnf->clauseNum + 1; n++)  //遍历所有的子句
  {
    if (cnf->Clause[n].length == 1 && cnf->Clause[n].statement == 0) {
      newNode = cnf->Clause[n].Node;
      for (; newNode != NULL; newNode = newNode->next) {
        if (cnf->lit[abs(newNode->value)].statement == 0) {
          //  printf("%d\n",newNode->value);
          return newNode->value;  //发现单子句
        }
      }
    }
  }
  return 0;  //没发现返回0
}

void travel(CNF* cnf) {
  for (int n = 1; n < cnf->clauseNum + 1; n++) {
    if (cnf->Clause[n].statement != 0)
      continue;

    intNode* newNode = cnf->Clause[n].Node;
    for (; newNode != NULL; newNode = newNode->next)
      if (cnf->lit[abs(newNode->value)].statement == 0)
        printf("%d  ", newNode->value);
    printf("\n");
  }
}

int getFile(CNF* cnf, char* filename) {
  FILE* fin;  //输入文件
  char ch;    //用于读取到字符p
  char str[500];
  if ((fin = fopen(filename, "r")) == NULL)  //打开文件
  {
    printf("\n\n\tFail to open file!\n");
    return 0;
  }
  ch = fgetc(fin);
  while (ch == 'c') {
    fgets(str, 500, fin);
    ch = fgetc(fin);
  }
  fscanf(fin, "%s", str);  //读取“cnf”
  fscanf(fin, "%d %d", &cnf->litNum,&cnf->clauseNum);  //读取到变元大小和子句数量
  initCnf(cnf);             //初始化cnf
  int unit;
  for (int n = 1; n < cnf->clauseNum + 1; n++) {
    int ClauseLength = 0;
    while (1) {
      fscanf(fin, "%d", &unit);
      if (unit == 0)
        break;
      ClauseLength++;
      addElem(cnf, n, unit);
    }
    cnf->Clause[n].length = ClauseLength;
  }
  fclose(fin);
  return 1;
}

void addElem(CNF* cnf, int n, int value) {
  intNode* newLitNode = (intNode*)malloc(sizeof(intNode));
  newLitNode->value = n;
  intNode* newClauseNode = (intNode*)malloc(sizeof(intNode));
  newClauseNode->value = value;
  cnf->Clause[n].length++;
  newClauseNode->next = cnf->Clause[n].Node;
  cnf->Clause[n].Node = newClauseNode;
  if (value > 0) {
    cnf->lit[value].tureNum++;
    newLitNode->next = cnf->lit[value].poHead->firstNode;
    cnf->lit[value].poHead->firstNode = newLitNode;
  } else {
    cnf->lit[-value].falseNum++;
    newLitNode->next = cnf->lit[-value].neHead->firstNode;
    cnf->lit[-value].neHead->firstNode = newLitNode;
  }
}

void initCnf(CNF* cnf)  //初始化，将变元数组和子句数组都创建好
{
  cnf->lit = (LitNode*)malloc((cnf->litNum + 1) * sizeof(LitNode));
  cnf->Clause = (ClauseNode*)malloc((cnf->clauseNum + 1) * sizeof(ClauseNode));
  for (int count = 0; count < cnf->clauseNum + 1; count++) {
    cnf->Clause[count].length = 0;
    cnf->Clause[count].statement = 0;
    cnf->Clause[count].Node = NULL;
  }
  for (int count = 0; count < cnf->litNum + 1; count++) {
    cnf->lit[count].falseNum = 0;
    cnf->lit[count].tureNum = 0;
    cnf->lit[count].statement = 0;
    cnf->lit[count].neHead = (intHead*)malloc(sizeof(intHead));
    cnf->lit[count].poHead = (intHead*)malloc(sizeof(intHead));
    cnf->lit[count].neHead->length = 0;
    cnf->lit[count].neHead->firstNode = NULL;
    cnf->lit[count].poHead->length = 0;
    cnf->lit[count].poHead->firstNode = NULL;
  }
}

void outfile(int* key, int n, int timer, int num, char* filename) {
  char resultfilename[100];
  int i = 0;
  while ('\0' != (resultfilename[i] = filename[i])) {
    i++;
  }
  resultfilename[i - 1] = 's';
  resultfilename[i - 2] = 'e';
  resultfilename[i - 3] = 'r';
  FILE* fp = fopen(resultfilename, "w");
  if (n == 1) {
    fprintf(fp, "s 1\nv ");
    for (int i = 0; i < num; ++i) {
      fprintf(fp, "%d ", key[i]);
    }
    fprintf(fp, "\nt %dms\n", timer);
    printf("\n保存成功！\n");
  } else {
    fprintf(fp, "s 0\nv ");
    for (int i = 1; i <= num; ++i) {
      fprintf(fp, "%d ", i);
    }
    fprintf(fp, "\nt %dms\n", timer);
  }
  fclose(fp);
  getchar();
}


void freeHead(DecisionTreeHead* aHead) {
  DecisionTreeNode* newNode = aHead->firstNode;

  for (; newNode != NULL;) {
    DecisionTreeNode* tem = newNode;
    newNode = newNode->next;
    free(tem);
  }
  free(aHead);
  return;
}

int main() {
  //主页面
  int op = 1;
  while (op) {
    system("cls");
    printf("        基于SAT的数独游戏求解程序的菜单\n");
    printf("    1.cnf      2.suduko\n");
    printf("请输入op:\n");
    scanf("%d", &op);
    if (op== 1) {
      char filename[100];
      printf("请输入的文件名:\n");
      scanf("%s", filename);
      CNF* cnf = (CNF*)malloc(sizeof(CNF));
      if (!getFile(cnf, filename)) {
        return 0;
      }
      printf("cnf文件读取成功！\n");
      printf("请选择分裂方式\n1.顺序\n2.逆序\n3.优化\n");
      int way;
      scanf("%d", &way);
      int num = cnf->litNum;
      int start;
      int end;
      int timer;
      start = clock();
      DecisionTreeHead* aHead = DPLL(cnf, way);  //此时head就是解
      end = clock();
      int* key = getKey(aHead);
      timer = end - start;
      if (aHead == NULL) {
        printf("该算例是不满足算例\n");
        outfile(key, 0, timer, num, filename);
      }
      else {
        ShowKey(aHead->length, key, timer);
        outfile(key, 1, timer, num, filename);
      }
      getchar();
    }

    //if (op == 2) {
    //  printf(
    //      "\n\n\t请选择想要进行的操作\n\t1.求解一个数独问题\n\t2."
    //      "生成一个数独\n\t");
    //  int op;
    //  scanf("%d", &op);
    //  system("cls");
    //  if (op == 1) {
    //    int n[8][8];
    //    EnterArray(n);
    //    DecisionTreeHead* aHead = creatSAT(n, 8, 1);

    //    int* puzzle = NULL;
    //    puzzle = getPuzzle(aHead);  // puzzle为要传出去的一维数组
    //    if (!puzzle) {
    //      printf("无解！");  //无解
    //      return 0;
    //    } else
    //      ShowPuzzle(puzzle);
    //    system("pause");
    //  } else if (op == 2) {
    //    printf("\n\n已生成一个只有唯一解的二进制数独游戏:\n");
    //    int* puzzle = createpuzzle();
    //    printf("\n\t是否求解？(Y\\N):   ");
    //    char op = 0;
    //    getchar();
    //    scanf("%c", &op);
    //    while (op != 'Y' && op != 'N' && op != 'y' && op != 'n') {
    //      getchar();
    //      printf("请输入Y 或 N:\n");
    //      scanf("%c", &op);
    //    }
    //    if (op == 'Y' || op == 'y') {
    //      int q[8][8];
    //      for (int a = 0; a < 8; a++)
    //        for (int b = 0; b < 8; b++)
    //          q[a][b] = puzzle[a * 8 + b];  //把生成的数组转换为二维数组
    //      DecisionTreeHead* key = creatSAT(q, 8, 1);
    //      puzzle = getPuzzle(key);
    //      ShowPuzzle(puzzle);
    //    }
    //    system("pause");
    //  }
    //}
  }
}