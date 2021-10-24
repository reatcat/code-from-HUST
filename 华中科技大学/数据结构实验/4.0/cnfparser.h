#pragma once
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef struct lNode {
	int l;         //存储文字
	int mark;      //标记该文字是否被删除，初始值为1，表示没有被删除
	struct lNode* next;
}lNode, * plNode;               //存储一个文字节点
typedef struct cNode {
	int l_count;        //存储一个子句的文字个数
	int flag;           //记录该子句因为flag而被删除，初始值为0，flag为需要删除的文字
	int mark;            //标记该子句是否被删除 ，初始值为1，表示没有被删除
	lNode* firstl;          //指向第一个文字节点
	struct cNode* next;        //指向下一条子句
}cNode, * pcNode;     //子句头节点
typedef struct cnf {
	int varinum;       //变元个数
	int claunum;        //子句个数
	cNode* firstc;      //指向第一个子句节点
}cnf, * pcnf;          //一个cnf公式
typedef struct SqList {
	int* elem;
	int length;
}SqList;              //一个顺序表结构，存储答案和回溯

typedef struct JList {//一个线性表
	int flag;
	struct JList* next;
}JLsit,* pJLsit;
extern int numa;

int destroycnf(cnf &L)
{
	pcNode p = L.firstc,pn;
	if (NULL == p) return OK; 
	while (p)
	{
		plNode q = p->firstl,qn;
		while (q)
		{
			qn = q->next;
			free(q);
			q = qn;
		}
		pn = p->next;
		free(p);
		p = pn;
	}
	L.firstc = NULL;
	if (NULL == p)
	{
		printf("原有cnf公式销毁成功!\n"); return OK;
	}
}

int InitList(cnf& L, SqList& An) {//初始化结果接收顺序表
	An.elem = (int*)malloc((L.varinum + 1) * sizeof(int));//分配存储空间
	if (!An.elem) {
		return ERROR;//分配存储空间失败
	};
	An.length = L.varinum + 1;//初始化线性表的长度
	for (int i = 0; i < An.length; i++) {
		An.elem[i] = 0;                        //表示没有经过单子句简化赋值
	}
	return OK;
}

void quickSort(int* array, int* arraynum, int low, int high)
{
	int i, j, key1, key;
	i = low;
	j = high;
	key1 = array[low];
	key = arraynum[low];
	if (low < high) {
		while (i < j) {
			while (i < j && arraynum[j] <= key) j--;
			if (i < j) {
				array[i] = array[j];
				arraynum[i] = arraynum[j];
			}
			while (i < j && arraynum[i] >= key) i++;
			if (i < j) {
				array[j] = array[i];
				arraynum[j] = arraynum[i];
			}
		}
		array[i] = key1;
		arraynum[i] = key;
		int standard = i;
		quickSort(array, arraynum, low, standard - 1);
		quickSort(array, arraynum, standard + 1, high);
	}
}

void sort(cnf L, int key[3500], int keynum[3500])
{
	memset(keynum, 0, sizeof(keynum));
	for (int i = 1; i < L.varinum+1; i++)
	key[i] = i + 1;
	pcNode p = L.firstc;
	int x[7] = { 0,0,1,2,4,6,8 ,16},k;
	while (p)
	{
		if (p->l_count <= 6)//子句数小于6 
		k = x[p->l_count];
		else k = 1;
		plNode q = p->firstl;
		for (int i = 1; i <= p->l_count; i++)
		{
			int m = q->l;
			m = m > 0 ? m: -m;
			keynum[m-1] *= k;
			q = q->next;
		}
		p = p->next;
	}
	quickSort(key, keynum, 0, L.varinum - 1);
}

void putsort(int* key, int* keynum, int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d %d\n", key[i], keynum[i]);
	}
}
