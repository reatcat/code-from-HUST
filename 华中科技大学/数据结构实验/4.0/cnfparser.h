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
		if (p->l_count <= 6)//�Ӿ���С��6 
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
