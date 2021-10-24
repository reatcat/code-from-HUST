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
  int l;  //�洢����
  int mark;  //��Ǹ������Ƿ�ɾ������ʼֵΪ1����ʾû�б�ɾ��
  struct lNode* next;
} lNode, *plNode;  //�洢һ�����ֽڵ�
typedef struct cNode {
  int l_count;  //�洢һ���Ӿ�����ָ���
  int flag;  //��¼���Ӿ���Ϊflag����ɾ������ʼֵΪ0��flagΪ��Ҫɾ��������
  int mark;  //��Ǹ��Ӿ��Ƿ�ɾ�� ����ʼֵΪ1����ʾû�б�ɾ��
  lNode* firstl;       //ָ���һ�����ֽڵ�
  struct cNode* next;  //ָ����һ���Ӿ�
} cNode, *pcNode;      //�Ӿ�ͷ�ڵ�
typedef struct cnf {
  int varinum;    //��Ԫ����
  int claunum;    //�Ӿ����
  cNode* firstc;  //ָ���һ���Ӿ�ڵ�
} cnf, *pcnf;     //һ��cnf��ʽ
typedef struct SqList {//���ڴ洢�𰸵�˳����
  int* elem;
  int length;
} SqList;
SqList Bn;
int choose;
int key[10000];
int value[10000];
int createCNF(pcnf* L, char filename[]);//����CNF�ļ�
int showCNF(pcnf L);     //��ӡCNF��ʽ
int InitList(pcnf L,SqList &An);//��ʼ���洢�𰸵�˳���
void destory(pcnf L);
int RemoveClause(pcnf L, int flag);  //ɾ���������ֵ��Ӿ�
int AddClause(pcnf L,int flag);//�ָ��������ֵ��Ӿ�
int EmptyClause(pcnf L);//�ж��Ӿ��Ƿ�Ϊ��
int DPLL(pcnf L,SqList &An,int now_l);//DPLL
int single(pcnf L);
void tauto(pcnf L);
void quickSort(int* array, int* arraynum, int low, int high);
void sort(pcnf L, int key[3500], int value[3500]);
int ResWrite(int res, double time, SqList& An,char filename[]);  //�����Ľ��д�뵽res
int option2(pcnf L);//����ѡ��
int reverse(pcnf L, int flag);//�������ֵĸ���
int option1(int *m);//����ѡ��
int creatsuduko(int temp[][9]);//
void printsuduko(int arr[][9]);//��ӡ����
int get_sudoku(int temp[SIZE][SIZE]);//��������
void cleanup(int temp[SIZE][SIZE]);//�������
void output_sudoku(int temp[SIZE][SIZE]);//�������
int check_sudoku(int temp[SIZE][SIZE], int i, int j, int k);//������������Ƿ�Ϸ�
int sd(int sudo[9][9]);//�Ϸ����ж�
int digsudu(int shudu[9][9], int num, int beifen[9][9]);//�ڶ�
int check(int shudu[9][9]);//����Ƿ����������Ϸ
int savecnf(int shudu[9][9], char* filename, int dignum);//��������ΪCNF
int sudures(SqList& An, char filename[],int beifen);//DPLL�����д�뵽res