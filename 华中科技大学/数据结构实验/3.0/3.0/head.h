#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct intNode {//����
  int value;
  struct intNode* next;
} intNode;

typedef struct intHead  //��������ͷ
{
  int length;  //����
  intNode* firstNode;
} intHead;

typedef struct LitNode {
  int tureNum;      //��ֵ������
  int falseNum;     //��ֵ������
  intHead* poHead;  //��¼��ֵ���ڵ�λ��
  intHead* neHead;  //��¼��ֵ���ڵ�λ��
  int statement;    //�Ƿ��Ѿ�ʹ�ù��������
} LitNode;

typedef struct ClauseNode {
  int length;
  int statement;  //�Ƿ����٣�1��ʾ�ѱ����٣�0��ʾ��δ
  intNode* Node;
} ClauseNode;

typedef struct CNF {
  int litNum;     //��Ԫ������
  int clauseNum;  //�Ӿ��������������ʼ���Ӿ�����ͱ�Ԫ����
  LitNode* lit;
  ClauseNode* Clause;
} CNF;

typedef struct DecisionTreeNode {
  struct DecisionTreeNode* next;
  struct DecisionTreeNode* pre;
  int statement;  //����ô�����ģ�1��ʾ���Ӿ䣬0��ʾ����
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
int Correct(CNF* cnf);  //�ж��Ƿ�ɹ�
int kownLitNumber(int sudoku[8][8], int n);
void addClause(int sudoku[8][8], int n, CNF* cnf, int* q);
void addKnown(int sudoku[8][8], int n, CNF* cnf, int* q);  //�����֪���Ӿ�
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