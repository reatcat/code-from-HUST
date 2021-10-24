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
	clock_t start, end; //记录开始时间与结束时间
	double duration;   //记录程序运行时间
	char filename[200]; //文件名
	int op = 1, tag;            //菜单选择
	double time;
	double s;//记录效率的提升
	while (op)
	{
		system("cls");
		printf("            Menu for sat\n");
		printf("----------------------------------------\n");
		printf("    1.creat cnf         2.show cnf\n");
		printf("    3.improveDPLL&&res  4.sudoku\n");
		printf("    0.exit\n");
		printf("----------------------------------------\n");
		printf("请选择你要进行的操作[0-5]:\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1: //创建cnf结构体
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
			printf("请输入文件名:\n");
			scanf("%s", filename);
			if (createCNF(L, filename) == OK)
				printf("cnf公式创建成功\n");
			else
			{
				printf("cnf公式创建失败\n");
				getchar(); getchar();
				break;
			}
			if (InitList(L, An) == OK) printf("分配结果存储空间成功\n");
			else
			{
				printf("分配结果存储空间失败\n");
				getchar(); getchar();
				break;
			}
			InitList(L, Back); Back.length = 0;
			sort(L, key, keynum);
			getchar(); getchar();
			break;

		case 2: //显示cnf结构
			showCNF(L);
			getchar(); getchar();
			break;

		case 3: //DPLL算法
			Cancel(L);
			start = clock();
			if (dpllimproving(L, An) == OK)
			{
				tag = 1;
				printf("求解成功\n");
			}
			else
			{
				tag = 0;
				printf("求解失败\n");
			}
			end = clock();
			printf("运行时间为：%7ld毫秒\n", end - start);
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
