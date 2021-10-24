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
	int l;         //�洢����
	int mark;      //��Ǹ������Ƿ�ɾ������ʼֵΪ1����ʾû�б�ɾ��
	struct lNode* next;
}lNode, * plNode;               //�洢һ�����ֽڵ�
typedef struct cNode {
	int l_count;        //�洢һ���Ӿ�����ָ���
	int flag;           //��¼���Ӿ���Ϊflag����ɾ������ʼֵΪ0��flagΪ��Ҫɾ��������
	int mark;            //��Ǹ��Ӿ��Ƿ�ɾ�� ����ʼֵΪ1����ʾû�б�ɾ��
	lNode* firstl;          //ָ���һ�����ֽڵ�
	struct cNode* next;        //ָ����һ���Ӿ�
}cNode, * pcNode;     //�Ӿ�ͷ�ڵ�
typedef struct cnf {
	int varinum;       //��Ԫ����
	int claunum;        //�Ӿ����
	cNode* firstc;      //ָ���һ���Ӿ�ڵ�
}cnf, * pcnf;          //һ��cnf��ʽ
typedef struct SqList {
	int* elem;
	int length;
}SqList;              //һ��˳���ṹ���洢�𰸺ͻ���

typedef struct JList {//һ�����Ա�
	int flag;
	struct JList* next;
}JLsit,* pJLsit;
extern int numa;
int createCNF(cnf &L, char filename[200]) {  //�����ṹ�壬�Ա����ʽ�洢
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		return 0;
	}
	int num = 0;          //Ϊ�����Ӿ���Ŀ�ͱ�Ԫ��Ŀ���м����
	int k = 0;              //��¼ÿ���Ӿ����ָ���
	int m = 0;             //��¼�Ӿ�ĸ���
	int flag;         //��¼����
	char c;             //��ȡ�ļ��ַ�ʹ��
	pcNode p= (cNode*)malloc(sizeof(struct cNode));   //�Ӿ���
	plNode q;    //���ֽڵ�
	p->flag = 0;  //��¼�Ӿ��Ƿ���Ϊflag����ɾ��
	p->mark = 1;  //��¼�Ӿ��Ƿ�ɾ����1��ʾδ��ɾ��
	L.firstc = p;
	fscanf(fp, "%c", &c);
	while (!feof(fp)) {
		if (c == 'c') {            //��c��ͷ��ע��ȥ��
			while (c != '\n') {
				fscanf(fp, "%c", &c);
			}
			fscanf(fp, "%c", &c);
		}
		else if (c == 'p') {
			while (c < '0' || c>'9') {
				fscanf(fp, "%c", &c);
			}
			while (c >= '0' && c <= '9') {        //��ȡ��Ԫ��
				num = num * 10;
				num += c - '0';
				fscanf(fp, "%c", &c);
			}
			L.varinum = num;
			num = 0;
			while (c < '0' || c>'9') {
				fscanf(fp, "%c", &c);
			}
			while (c >= '0' && c <= '9') {        //��ȡ�Ӿ���
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
			q->mark = 1;  //mark����1��ʾû�б�ɾ��
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
		else fscanf(fp, "%c", &c);	//��ֹ�ļ���β�ж������
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
		printf("ԭ��cnf��ʽ���ٳɹ�!\n"); return OK;
	}
}

int InitList(cnf& L, SqList& An) {//��ʼ���������˳���
	An.elem = (int*)malloc((L.varinum + 1) * sizeof(int));//����洢�ռ�
	if (!An.elem) {
		return ERROR;//����洢�ռ�ʧ��
	};
	An.length = L.varinum + 1;//��ʼ�����Ա�ĳ���
	for (int i = 0; i < An.length; i++) {
		An.elem[i] = 0;                        //��ʾû�о������Ӿ�򻯸�ֵ
	}
	return OK;
}

int showCNF(cnf& L) {    //��ʾcnf�ṹ��
	if (L.varinum == -1) {
		printf("cnf��ʽΪ��\n");
		return OK;
	}
	pcNode p = L.firstc;
	plNode q = p->firstl;
	printf("cnf��ʽ��Ԫ����%d  �Ӿ�����%d\n", L.varinum, L.claunum);
	int i = 1;
	while (p) {
		if (p->mark == 1)
		{
			printf("��%d����%d������:   ",i,p->l_count);
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
	for (int i = 1; i < An.length; i++) //��������
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
	filename[i - 3] = 'r';    //ֻ�ı��ļ�����չ��
	filename[i - 2] = 'e';
	filename[i - 1] = 's';
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		return ERROR;
	}
	fprintf(fp, "s %d\n", res);    //res���������1��ʾ���㣬0��ʾ�����㣬-1δ��
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
