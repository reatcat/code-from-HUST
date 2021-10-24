#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define SIZE 9
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
typedef struct SqList {//用于存储答案的顺序表的
  int* elem;
  int length;
} SqList;
SqList Bn;
int choose;
int key[10000];
int value[10000];
int createCNF(pcnf* L, char filename[]);//创建CNF文件
int showCNF(pcnf L);     //打印CNF公式
int InitList(pcnf L,SqList &An);//初始化存储答案的顺序表
void destory(pcnf L);
int RemoveClause(pcnf L, int flag);  //删除含有文字的子句
int AddClause(pcnf L,int flag);//恢复含有文字的子句
int EmptyClause(pcnf L);//判断子句是否为空
int DPLL(pcnf L,SqList &An,int now_l);//DPLL
int single(pcnf L);
void tauto(pcnf L);
void quickSort(int* array, int* arraynum, int low, int high);
void sort(pcnf L, int key[3500], int value[3500]);
int ResWrite(int res, double time, SqList& An,char filename[]);  //将求解的结果写入到res
int option2(pcnf L);//策略选择
int reverse(pcnf L, int flag);//换用文字的负数
int option1(int *m);//策略选择
int creatsuduko(int temp[][9]);//
void printsuduko(int arr[][9]);//打印数独
int get_sudoku(int temp[SIZE][SIZE]);//建立数独
void cleanup(int temp[SIZE][SIZE]);//清空数独
void output_sudoku(int temp[SIZE][SIZE]);//输出数独
int check_sudoku(int temp[SIZE][SIZE], int i, int j, int k);//检查填入数字是否合法
int sd(int sudo[9][9]);//合法性判断
int digsudu(int shudu[9][9], int num, int beifen[9][9]);//挖洞
int check(int shudu[9][9]);//检查是否完成数独游戏
int savecnf(int shudu[9][9], char* filename, int dignum);//数独保存为CNF
int sudures(SqList& An, char filename[],int beifen);//DPLL求解结果写入到res