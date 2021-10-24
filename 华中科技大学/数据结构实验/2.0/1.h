#include <stdio.h>
#include <math.h>
#include <time.h>
#include "suduko.h"
#define INFEASIBLE 0
#define FALSE 0
#define TRUE 1
#define OK 1

typedef struct Node {
	Node* next;
	int data;
} Node;

typedef struct HNode {
	HNode* next;
	Node* first;
} HNode;

typedef struct CNFNode {
	HNode* data;
	char name[30];
} CNFNode;

int sudoku[10][10];
int sudoku1[10][10];
int solution1[729];
int count[103000];
int countclause[130000];
double score[51000];

void PrintConclusion(int solution[51000],FILE *fp) {
	int i,cal=0;
	fprintf(fp,"v");
	for(i=0; i<=51000; i++) {
		if(solution[i]==1) {
			fprintf(fp," %d",i);
			cal++;
			if(cal%20==0) fprintf(fp,"\n");
		}
	}
}



void free0(HNode *head) { //释放一个子句的空间
	Node *p=head->first,*q=NULL;
	HNode *k=head;
	if(p==NULL) {
		free(head);
		return;
	}
	if(p->next!=NULL) q=p->next;
	else free(p);
	free(head);
	while(q!=NULL) {
		free(p);
		p=q;
		q=p->next;
	}
}
void Transform(int tran, FILE* fp) {
	int flag = 1;
	if (tran < 0) {
		flag = 0;
		tran = -tran;
	}
	int row, column, num;
	row = (tran - 1) / 81 + 1;
	column = (tran - (row - 1) * 81) / 9 + 1;
	if ((tran - (row - 1) * 81) % 9 == 0) {
		num = 9;
		column--;
	}
	else num = tran - (row - 1) * 81 - (column - 1) * 9;
	if (flag) fprintf(fp, "%d%d%d ", row, column, num);
	else fprintf(fp, "-%d%d%d ", row, column, num);
}
void PrintCNF(HNode *head) {
	if(head==NULL) return;
	HNode *p=head;
	Node *q=NULL;
	while(p!=NULL) {
		q=p->first;
		while(q!=NULL) {
			printf("%d ",q->data);
			q=q->next;
		}
		printf("0\n");
		p=p->next;
	}
}

void PrintCNFfile(HNode* head,FILE *fp) {
	HNode *p=head;
	Node *q=NULL;
	while(p!=NULL) {
		q=p->first;
		while(q!=NULL) {
			Transform(q->data,fp);
//			fprintf(fp,"%d ",q->data);
			q=q->next;
		}
		fprintf(fp,"0\n");
		p=p->next;
	}
}

int removeClause(HNode* &head,int tar) { //从CNF中删除含tar的子句
	HNode *r=NULL,*p=NULL,*t=NULL;
	int flag=0;
	if(head==NULL) return INFEASIBLE;
	Node *q=head->first;
	while(q!=NULL) {
		if(q->data==tar) {
			t=head;
			head=t->next;
			flag=1;
			free0(t);
			if(head==NULL) return OK;
			q=head->first;
			continue;
		}
		q=q->next;
	}
	r=head;
	p=head->next;
	while(p!=NULL) {
		q=p->first;
		while(q!=NULL) {
			if(q->data==tar) {
				t=p;
				r->next=p->next;
				free0(t);
				flag=1;
				break;
			}
			q=q->next;
		}
		if(q==NULL) r=r->next;
		p=r->next;
	}
	if(flag==0) return INFEASIBLE;
	return OK;
}

int DeleteNode(HNode* head,int tar) { //从CNF中删除文字tar
	int r=0,flag=0;
	HNode *p=head;
	Node *t=NULL,*q=NULL;
	while(p!=NULL) {
		t=p->first;
		if(t==NULL) {
			p=p->next;
			continue;
		}
		if(t->data==tar) {
			q=t->next;
			flag=1;
			p->first=q;
			free(t);
			p=p->next;
			continue;
		}
		q=t->next;
		while(q!=NULL) {
			if(q->data==tar) {
				t->next=q->next;
				q=t->next;
				flag=1;
			} else {
				t=t->next;
				q=q->next;
			}
		}
		p=p->next;
	}
	if(flag==0) return INFEASIBLE;
	return OK;
}

int CNFempty(HNode *head) { //判断CNF中是否存在空子句
	HNode *p=head;
	while(p!=NULL) {
		if(p->first==NULL) return TRUE;
		p=p->next;
	}
	return FALSE;
}

void AddHNode(HNode *&head,int max) {
	HNode *p=(HNode*)malloc(sizeof(HNode));
	p->next=head;
	p->first=(Node*)malloc(sizeof(Node));
	p->first->next=NULL;
	p->first->data=max;
	head=p;
}

int Divide(HNode* head) { //分裂策略
	HNode *p=head;   /*权重计算*/
	Node *q=NULL;
	int result,i;
	memset(count,0,sizeof(int)*103000);
	while(p!=NULL) {
		q=p->first;
		while(q!=NULL) {
			count[q->data+51000]++;//标记 
			q=q->next;
		}
		p=p->next;
	}

	memset(countclause,0,sizeof(int)*130000);
	int cal=0,max=0;
	p=head;
	while(p!=NULL) {
		q=p->first;
		while(q!=NULL) {
			countclause[cal]++;//表示子句的文字数 
			q=q->next;
		}
		cal++;
		p=p->next;
	}
	memset(score,0,sizeof(int)*51000);
	cal=0;
	p=head;
	while(p!=NULL) {
		q=p->first;
		while(q!=NULL) {
			if(q->data>0)
				score[q->data]+=(double)if
			if(q->data<0)
				score[-q->data]+=(double)count[q->data+51000]*pow(0.5,(double)countclause[cal]-1);
			q=q->next;
		}
		cal++;//标记子句的这个次序 
		p=p->next;
	}
	max=0;
	int temp;
	for(i=0; i<51000; i++) {
		if(score[i]>max) {
			max=score[i];
			temp=i;
		}
	}
	return temp;

}

HNode* CopyCNF(HNode* head1) { //复制范式
	HNode* p=head1,*q=(HNode*)malloc(sizeof(HNode)),*head2=q;
	q->next=NULL;
	q->first=NULL;
	Node *t=NULL,*r=NULL;
	while(p!=NULL) {
		q->next=(HNode*)malloc(sizeof(HNode));
		q=q->next;
		q->next=NULL;
		q->first=NULL;
		t=p->first;
		if(t!=NULL) {
			r=(Node*)malloc(sizeof(Node));
			r->data=t->data;
			r->next=NULL;
			q->first=r;
		}
		t=t->next;
		while(t!=NULL) {
			r->next=(Node*)malloc(sizeof(Node));
			r=r->next;
			r->data=t->data;
			r->next=NULL;
			t=t->next;
		}
		p=p->next;
	}
	HNode *headcopy=head2->next;
	free(head2);
	return headcopy;
}

int destroyCNF(HNode *&head) {
	if(head==NULL) return INFEASIBLE;
	HNode *p=head,*t=NULL;
	while(p!=NULL) {
		t=p->next;
		free0(p);
		p=t;
	}
	return OK;
}

void tautologyCheck(HNode *&head) {//重言式检查 
	int i,top=0;
	int stack[200];
	HNode *p=head;
	Node *q=p->first;
	while(p!=NULL) {
		while(q!=NULL) {
			for(i=0; i<top; i++) {
				if(q->data==-stack[i]) removeClause(head,stack[0]);
			}
			stack[top++]=q->data;
			q=q->next;
		}
		top=0;
		p=p->next;
	}
}

void simplifyCheck(HNode *&head,int solution[51000]) {
	HNode *p=head;
	Node *q=NULL;
	int i=0;
	memset(count,0,sizeof(int)*103000);
	while(p!=NULL) {
		q=p->first;
		while(q!=NULL) {
			count[q->data+51000]++;
			q=q->next;
		}
		p=p->next;
	}
	for(i=51001; i<103000; i++) {
		if(count[i]&&!count[102000-i]) {
			removeClause(head,i-51000);
			solution[i-51000]=1;
		}
		if(!count[i]&&count[102000-i]) {
			removeClause(head,51000-i);
			solution[i-51000]=0;
		}
	}
}

int DPLL(HNode* &head,int solution[51000]) {
	tautologyCheck(head);
	int tar=0;
	while(1) {
		HNode *p=head;
		while(p!=NULL) {
			if(p->first==NULL) break;
			if(p->first->next==NULL) {//单子句 
				tar=p->first->data;
				if(tar<0) solution[-tar]=0;
				else solution[tar]=1;
				break;
			}
			tar=0;
			p=p->next;
		}
		if(tar==0) break;
		else { //CNF中存在单子句
			removeClause(head,tar);
			DeleteNode(head,-tar);
			tar=0;
		}
	}
	if(head==NULL) return TRUE;
	else if(CNFempty(head)) return FALSE;

	simplifyCheck(head,solution);

	int max=Divide(head);         //策略对DPLL性能影响很大
	HNode *headcopy=CopyCNF(head);
	AddHNode(headcopy,max);
	if(DPLL(headcopy,solution)) return(TRUE);  //在第一分支中搜索
	destroyCNF(headcopy);
	AddHNode(head,-max);
	return DPLL(head,solution);//回溯到对v执行分支策略的初态进入另一分支
}

void CreateCNF(HNode* head,FILE *fp) {    //创建CNF
	char xxx[100];
	while('c'==getc(fp)) {
		while('\n'!=getc(fp));
	}
	fgets(xxx,6,fp);
	int clause,boolnum;
	fscanf(fp,"%d%d",&boolnum,&clause);
	int i,j,k,data;
	HNode *p=head;
	Node *q=NULL;
	fscanf(fp,"%d",&data);
	p->first=(Node*)malloc(sizeof(Node));
	p->first->data=data;
	p->first->next=NULL;
	q=p->first;
	while(1) {
		fscanf(fp,"%d",&data);
		if(data==0) break;
		q->next=(Node*)malloc(sizeof(Node));
		q=q->next;
		q->data=data;
		q->next=NULL;
	}
	for(i=1; i<clause; i++) {
		p->next=(HNode*)malloc(sizeof(HNode));
		p=p->next;
		p->next=NULL;
		fscanf(fp,"%d",&data);
		if(data==0) continue;
		p->first=(Node*)malloc(sizeof(Node));
		p->first->data=data;
		p->first->next=NULL;
		q=p->first;
		while(1) {
			fscanf(fp,"%d",&data);
			if(data==0) break;
			q->next=(Node*)malloc(sizeof(Node));
			q=q->next;
			q->data=data;
			q->next=NULL;
		}
	}
}


int isUnitClause(HNode *head) {
	if(head!=NULL)
		if(head->next==NULL)
			return TRUE;
	return FALSE;
}

void addClause(HNode *&head,int a[100],int num) {
	HNode *p=(HNode*)malloc(sizeof(HNode));
	Node *q=(Node*)malloc(sizeof(Node)),*t=q;
	int i;
	t->data=a[0];
	for(i=1; i<num; i++) {
		t->next=(Node*)malloc(sizeof(Node));
		t=t->next;
		t->data=a[i];
		t->next=NULL;
	}
	p->first=q;
	p->next=head;
	head=p;
	return;
}

void AddSolution(HNode *&head,int solution[51000]) { //得出的解作为一个子句
	int i=0;
	HNode *p=(HNode*)malloc(sizeof(HNode));
	Node *q=(Node*)malloc(sizeof(Node));
	while(solution[i]!=1) i++;
	q->data=-i;
	q->next=NULL;
	p->first=q;
	p->next=head;
	head=p;
	for(i++; i<=729; i++) {
		if(solution[i]==1) {
			q->next=(Node*)malloc(sizeof(Node));
			q=q->next;
			q->next=NULL;
			q->data=-i;
		}
	}
}

HNode* GenerateSudoku(int solution[1000],int level) {
loopx:
	;
	int i,j,k;

//	while(1) { //随机生成一个填好的数独
//		srand((unsigned)time(0));
//		HNode *head=(HNode*)malloc(sizeof(HNode));
//		HNode *p=head;
//		p->first=(Node*)malloc(sizeof(Node));
//		p->first->data=rand()%729+1;
//		p->first->next=NULL;
//		for(i=2; i<12; i++) {
//			p->next=(HNode*)malloc(sizeof(HNode));
//			p=p->next;
//			p->first=(Node*)malloc(sizeof(Node));
//			p->first->data=rand()%729+1;
//			p->first->next=NULL;
//			p->next=NULL;
//		}
//		CreateSudoku(head);
//		int result=DPLL(head,solution);
//		if(result==TRUE) break;
//	}

	while(1) {
		srand((unsigned)time(0));
		int b[11];
		b[0]=rand()%9+1;
		b[1]=rand()%9+109;
		b[2]=rand()%9+217;
		b[3]=rand()%9+253;
		b[4]=rand()%9+361;
		b[5]=rand()%9+469;
		b[6]=rand()%9+505;
		b[7]=rand()%9+613;
		b[8]=rand()%9+721;

		HNode *head=(HNode*)malloc(sizeof(HNode));
		HNode *p=head;
		p->first=(Node*)malloc(sizeof(Node));
		p->first->data=b[0];
		p->first->next=NULL;
		for(i=1; i<9; i++) {
			p->next=(HNode*)malloc(sizeof(HNode));
			p=p->next;
			p->first=(Node*)malloc(sizeof(Node));
			p->first->data=b[i];
			p->first->next=NULL;
			p->next=NULL;
		}
		CreateSudoku(head);
		int result=DPLL(head,solution);
		if(result==TRUE) break;
	}

	i=0;  //将完成的数独化为CNF
	while(solution[i]!=1) i++;
	HNode *head=(HNode*)malloc(sizeof(HNode));
	HNode *p=head;
	p->first=(Node*)malloc(sizeof(Node));
	p->first->data=i;
	p->first->next=NULL;
	for(i++; i<=729; i++) {
		if(solution[i]!=1) continue;
		p->next=(HNode*)malloc(sizeof(HNode));
		p=p->next;
		p->first=(Node*)malloc(sizeof(Node));
		p->first->data=i;
		p->first->next=NULL;
		p->next=NULL;
	}

	int dig;
	if(level==1) dig=50-rand()%7;
	if(level==2) dig=57-rand()%7;
	if(level==3) dig=62-rand()%5;
	int record[81];
	memset(record,0,sizeof(int)*81);
	int countx=0,cou=0,del_tar,avo,sta,result;
	for(i=1; i<=dig; i++) { //随机挖去60个洞，并且保证解的唯一性
		del_tar=rand()%(81-countx)+1;
		p=head;
		for(j=1; j<del_tar; j++) p=p->next;
		avo=p->first->data;
		if(cou+countx==81) {
			destroyCNF(head);
			memset(solution1,0,sizeof(int)*730);
			memset(solution,0,sizeof(int)*730);
			goto loopx;
		}
		if(IsIn(record,avo)) {
			i--;
			continue;
		}
		removeClause(head,avo);
//				sta=avo/9*9;
//				if(avo%9==0) sta-=9;
//				start=clock();
//				for(j=1; j<=9; j++) {
//					if(j+sta==avo) continue;

		HNode *headcopy=CopyCNF(head);
		CreateSudoku(headcopy);

		AddSolution(headcopy,solution);
		memset(solution1,729,sizeof(int)*81);
		result=DPLL(headcopy,solution1);

		if(result) {
			record[cou++]=avo;
			AddHNode(head,avo);
			i--;
		} else {
			countx++;
		}


//					AddHNode(headcopy,sta+j);
//					CreateSudoku(headcopy);
//
//
//					if(DPLL(headcopy,solution)) {
//						record[cou++]=avo;
//						AddHNode(head,avo);
//						i--;
//						break;
//					}
//				}
//				end=clock();
//				printf("%fs\n",(float)(end-start)/1000);
//				end=clock();
//				if(j==10) countx++;

	}
	return head;
}

int Evaluate(int solution[1000],int sudoku[10][10]) {
	int i,row,column,num;
	for(i=1; i<=729; i++) {
		if(solution[i]==1) {
			row=(i-1)/81+1;
			column=(i-(row-1)*81)/9+1;
			if((i-(row-1)*81)%9==0) {
				num=9;
				column--;
			} else num=i-(row-1)*81-(column-1)*9;
			if(sudoku[row][column]!=num)
				return FALSE;
		}
	}
	return TRUE;
}
