#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct intNode {//文字
  int value;
  struct intNode* next;
} intNode;

typedef struct intHead  //存放链表的头
{
  int length;  //长度
  intNode* firstNode;
} intHead;

typedef struct LitNode {
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

typedef struct DecisionTreeNode {
  struct DecisionTreeNode* next;
  struct DecisionTreeNode* pre;
  int statement;  //是怎么得来的，1表示单子句，0表示分裂
  int lit;
} DecisionTreeNode;

typedef struct DecisionTreeHead {
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