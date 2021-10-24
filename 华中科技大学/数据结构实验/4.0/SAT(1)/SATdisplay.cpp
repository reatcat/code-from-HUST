#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sudoku.h"
SqList Back;
int key[3500] = { 0 }, keynum[3500] = { 0 },numa;
int main() {
	cnf L;
	L.varinum = -1,L.claunum=0,L.firstc=NULL;
	SqList An;
	An.elem = NULL, Back.elem = NULL;
	clock_t start, end; //��¼��ʼʱ�������ʱ��
	double duration;   //��¼��������ʱ��
	char filename[200]; //�ļ���
	int op = 1, tag;            //�˵�ѡ��
	double time;
	double s;//��¼Ч�ʵ�����
	while (op)
	{
		system("cls");
		printf("            Menu for sat\n");
		printf("----------------------------------------\n");
		printf("    1.creat cnf         2.show cnf\n");
		printf("    3.improveDPLL&&res  4.sudoku\n");
		printf("    0.exit\n");
		printf("----------------------------------------\n");
		printf("��ѡ����Ҫ���еĲ���[0-5]:\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1: //����cnf�ṹ��
			if (Back.elem) 
			{
				free(Back.elem); Back.elem = NULL;
			}
			if (An.elem)
			{
				free(An.elem); An.elem = NULL;
			}
			destroycnf(L);
			numa = 0;
			printf("�������ļ���:\n");
			scanf("%s", filename);
			if (createCNF(L, filename) == OK)
				printf("cnf��ʽ�����ɹ�\n");
			else
			{
				printf("cnf��ʽ����ʧ��\n");
				getchar(); getchar();
				break;
			}
			if (InitList(L, An) == OK) printf("�������洢�ռ�ɹ�\n");
			else
			{
				printf("�������洢�ռ�ʧ��\n");
				getchar(); getchar();
				break;
			}
			InitList(L, Back); Back.length = 0;
			sort(L, key, keynum);
			getchar(); getchar();
			break;

		case 2: //��ʾcnf�ṹ
			showCNF(L);
			getchar(); getchar();
			break;

		case 3: //DPLL�㷨
			Cancel(L);
			start = clock();
			if (dpllimproving(L, An) == OK)
			{
				tag = 1;
				printf("���ɹ�\n");
			}
			else
			{
				tag = 0;
				printf("���ʧ��\n");
			}
			end = clock();
			printf("����ʱ��Ϊ��%7ld����\n", end - start);
			if (tag == 1)put(An);
			ResWrite(tag, end - start, An, filename);
			getchar(); getchar();
			break;
		case 4:
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	return 0;
}
