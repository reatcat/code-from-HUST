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
int createCNF(cnf &L, char filename[200]) {  //创建结构体，以表的形式存储
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return 0;
	}
	int num = 0;          //为计算子句数目和变元数目的中间变量
	int k = 0;              //记录每个子句文字个数
	int m = 0;             //记录子句的个数
	int flag;         //记录正负
	char c;             //读取文件字符使用
	pcNode p= (cNode*)malloc(sizeof(struct cNode));   //子句结点
	plNode q;    //文字节点
	p->flag = 0;  //记录子句是否因为flag而被删除
	p->mark = 1;  //记录子句是否被删除，1表示未被删除
	L.firstc = p;
	fscanf(fp, "%c", &c);
	while (!feof(fp)) {
		if (c == 'c') {            //把c开头的注释去掉
			while (c != '\n') {
				fscanf(fp, "%c", &c);
			}
			fscanf(fp, "%c", &c);
		}
		else if (c == 'p') {
			while (c < '0' || c>'9') {
				fscanf(fp, "%c", &c);
			}
			while (c >= '0' && c <= '9') {        //获取变元数
				num = num * 10;
				num += c - '0';
				fscanf(fp, "%c", &c);
			}
			L.varinum = num;
			num = 0;
			while (c < '0' || c>'9') {
				fscanf(fp, "%c", &c);
			}
			while (c >= '0' && c <= '9') {        //获取子句数
				num = num * 10;
				num += c - '0';
				fscanf(fp, "%c", &c);
			}
			L.claunum = num;
			num = 0;
			fscanf(fp, "%c", &c);
		}
		else if ((c >= '0' && c <= '9') || (c == '-')) {
			q = (lNode*)malloc(sizeof(struct lNode));
			q->mark = 1;  //mark等于1表示没有被删除
			p->firstl = q;
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
						if (flag == 0)  q->l = -num;
						else q->l = num;
						num = 0;
						k++;
					}
					fscanf(fp, "%c", &c);
					if (c == '0') q->next = NULL;
					else {
						q->next = (lNode*)malloc(sizeof(struct lNode));
						q = q->next;
						q->mark = 1;
					}
				}
				fscanf(fp, "%c", &c);
			fscanf(fp, "%c", &c);
			p->l_count = k;
			numa += k;
			k = 0;
			m++;
			if (m < L.claunum) {
				p->next = (cNode*)malloc(sizeof(struct cNode));
				p = p->next;
				p->flag = 0;
				p->mark = 1;
			}
			else p->next = NULL;
		}
		else fscanf(fp, "%c", &c);	//防止文件结尾有多个换行
	}
	fclose(fp);
	return OK;
}

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

int showCNF(cnf& L) {    //显示cnf结构体
	if (L.varinum == -1) {
		printf("cnf公式为空\n");
		return OK;
	}
	pcNode p = L.firstc;
	plNode q = p->firstl;
	printf("cnf公式变元数：%d  子句数：%d\n", L.varinum, L.claunum);
	int i = 1;
	while (p) {
		if (p->mark == 1)
		{
			printf("第%d句有%d个文字:   ",i,p->l_count);
			q = p->firstl;
			while (q) {
				if (q->mark == 1)printf("%5d ", q->l);
				q = q->next;
			}
			printf("\n");
		}
		i++;
		p = p->next;
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
	for (int i = 0; i < L.varinum; i++)
	key[i] = i + 1;
	pcNode p = L.firstc;
	int x[7] = { 0,0,1,2,4,6,8 },k;
	while (p)
	{
		if (p->l_count <= 6)k = x[p->l_count];
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

void put(SqList An)  
{
	for (int i = 1; i < An.length; i++) //输出求解结果
	{
		if (An.elem[i] == -1)  printf("%5d", -i);
		else printf("%5d", i);
		if (i % 10 == 0)  printf("\n");
	}
}

int ResWrite(int res, clock_t time, SqList& An, char filename[80])
{
	int i = 0;
	while (filename[i] != '\0') i++;
	filename[i - 3] = 'r';    //只改变文件的扩展名
	filename[i - 2] = 'e';
	filename[i - 1] = 's';
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return ERROR;
	}
	fprintf(fp, "s %d\n", res);    //res是求解结果，1表示满足，0表示不满足，-1未定
	fprintf(fp, "v");
	if(res)
	for (i = 1; i < An.length; i++) {
		if (An.elem[i] == -1)  fprintf(fp, " %d ", -i);
		else fprintf(fp, " %d", i);
	}
	fprintf(fp, "\nt %7ld\n", time);
	fclose(fp);
	return OK;
}

void putsort(int* key, int* keynum, int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d %d\n", key[i], keynum[i]);
	}
}
