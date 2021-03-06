#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#pragma once
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
int boolnum;
int clausenum;
int IsIn(int record[81], int num) {
  int i;
  for (i = 0; i < 81; i++)
    if (num == record[i])
      return TRUE;
  return FALSE;
}

void Save(int sudoku[10][10], int tran) {
  if (tran < 0)
    return;
  int row, column, num;
  row = (tran - 1) / 81 + 1;
  column = (tran - (row - 1) * 81) / 9 + 1;
  if ((tran - (row - 1) * 81) % 9 == 0) {
    num = 9;
    column--;
  } else
    num = tran - (row - 1) * 81 - (column - 1) * 9;
  sudoku[row][column] = num;
}

void PrintSudoku(int sudoku[10][10]) {
  int i, j;
  for (i = 1; i < 10; i++) {
    printf(" ------------------------------------\n");
    for (j = 1; j < 10; j++) {
      if (sudoku[i][j] == 0)
        printf("ح ");
      else
        printf("ح%d ", sudoku[i][j]);
    }
    printf("ح\n");
  }
  printf(" ------------------------------------\n");
}

void PrintSudoku2(int sudoku[10][10], int sudoku1[10][10]) {
  int i, j;
  for (i = 1; i < 10; i++) {
    printf(" ------------------------------------\n");
    for (j = 1; j < 10; j++) {
      if (sudoku1[i][j] == 0)
        printf("ح  ");
      else if (sudoku[i][j])
        printf("ح%d*", sudoku[i][j]);
      else
        printf("ح%d ", sudoku1[i][j]);
    }
    printf("ح\n");
  }
  printf(" ------------------------------------\n");
}

void PrintConclusion(int solution[51000], FILE* fp) {
  int i, cal = 0;
  fprintf(fp, "v");
  for (i = 0; i <= 51000; i++) {
    if (solution[i] == 1) {
      fprintf(fp, " %d", i);
      cal++;
      if (cal % 20 == 0)
        fprintf(fp, "\n");
    }
  }
}

void PrintSolution(int sudoku[10][10], int solution[1000]) {
  int i, j;
  int row, column, num;
  for (i = 1; i <= 729; i++) {
    if (solution[i] == 1) {
      row = (i - 1) / 81 + 1;
      column = (i - (row - 1) * 81) / 9 + 1;
      if ((i - (row - 1) * 81) % 9 == 0) {
        num = 9;
        column--;
      } else
        num = i - (row - 1) * 81 - (column - 1) * 9;
      sudoku[row][column] = num;
    }
  }
  for (i = 1; i < 10; i++) {
    printf(" ------------------------------------\n");
    for (j = 1; j < 10; j++) {
      printf("ح%d ", sudoku[i][j]);
    }
    printf("ح\n");
  }
  printf(" ------------------------------------\n");
  printf("\n");
}

void PrintInitial(HNode* head, int sudoku[10][10]) {
  int i, j;
  HNode* p = head;
  while (p != NULL) {
    Save(sudoku, p->first->data);
    p = p->next;
  }
  for (i = 1; i < 10; i++) {
    printf(" ------------------------------------\n");
    for (j = 1; j < 10; j++) {
      if (sudoku[i][j] == 0)
        printf("ح  ");
      else
        printf("ح%d*", sudoku[i][j]);
    }
    printf("ح\n");
  }
  printf(" ------------------------------------\n");
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
  } else
    num = tran - (row - 1) * 81 - (column - 1) * 9;
  if (flag)
    fprintf(fp, "%d%d%d ", row, column, num);
  else
    fprintf(fp, "-%d%d%d ", row, column, num);
}

void free0(HNode* head) {  //?ͷ?һ???Ӿ??Ŀռ?
  Node *p = head->first, *q = NULL;
  HNode* k = head;
  if (p == NULL) {
    free(head);
    return;
  }
  if (p->next != NULL)
    q = p->next;
  else
    free(p);
  free(head);
  while (q != NULL) {
    free(p);
    p = q;
    q = p->next;
  }
}

void PrintCNF(HNode* head) {
  if (head == NULL)
    return;
  HNode* p = head;
  Node* q = NULL;
  while (p != NULL) {
    q = p->first;
    while (q != NULL) {
      printf("%d ", q->data);
      q = q->next;
    }
    printf("0\n");
    p = p->next;
  }
}

void PrintCNFfile(HNode* head, FILE* fp) {
  HNode* p = head;
  Node* q = NULL;
  while (p != NULL) {
    q = p->first;
    while (q != NULL) {
      Transform(q->data, fp);
      //			fprintf(fp,"%d ",q->data);
      q = q->next;
    }
    fprintf(fp, "0\n");
    p = p->next;
  }
}

int removeClause(HNode*& head, int tar) {  //??CNF??ɾ????tar???Ӿ?
  HNode *r = NULL, *p = NULL, *t = NULL;
  int flag = 0;
  if (head == NULL)
    return INFEASIBLE;
  Node* q = head->first;
  while (q != NULL) {
    if (q->data == tar) {
      t = head;
      head = t->next;
      flag = 1;
      free0(t);
      if (head == NULL)
        return OK;
      q = head->first;
      continue;
    }
    q = q->next;
  }
  r = head;
  p = head->next;
  while (p != NULL) {
    q = p->first;
    while (q != NULL) {
      if (q->data == tar) {
        t = p;
        r->next = p->next;
        free0(t);
        flag = 1;
        break;
      }
      q = q->next;
    }
    if (q == NULL)
      r = r->next;
    p = r->next;
  }
  if (flag == 0)
    return INFEASIBLE;
  return OK;
}

int DeleteNode(HNode* head, int tar) {  //??CNF??ɾ??????tar
  int r = 0, flag = 0;
  HNode* p = head;
  Node *t = NULL, *q = NULL;
  while (p != NULL) {
    t = p->first;
    if (t == NULL) {
      p = p->next;
      continue;
    }
    if (t->data == tar) {
      q = t->next;
      flag = 1;
      p->first = q;
      free(t);
      p = p->next;
      continue;
    }
    q = t->next;
    while (q != NULL) {
      if (q->data == tar) {
        t->next = q->next;
        q = t->next;
        flag = 1;
      } else {
        t = t->next;
        q = q->next;
      }
    }
    p = p->next;
  }
  if (flag == 0)
    return INFEASIBLE;
  return OK;
}

int CNFempty(HNode* head) {  //?ж?CNF???Ƿ????ڿ??Ӿ?
  HNode* p = head;
  while (p != NULL) {
    if (p->first == NULL)
      return TRUE;
    p = p->next;
  }
  return FALSE;
}

void AddHNode(HNode*& head, int max) {
  HNode* p = (HNode*)malloc(sizeof(HNode));
  p->next = head;
  p->first = (Node*)malloc(sizeof(Node));
  p->first->next = NULL;
  p->first->data = max;
  head = p;
}

int Divide(HNode* head) {  //???Ѳ???
  HNode* p = head;         /*Ȩ?ؼ???*/
  Node* q = NULL;
  int result, i;
  memset(count, 0, sizeof(int) * 103000);
  while (p != NULL) {
    q = p->first;
    while (q != NULL) {
      count[q->data + 51000]++;
      q = q->next;
    }
    p = p->next;
  }

  memset(countclause, 0, sizeof(int) * 130000);
  int cal = 0, max = 0;
  p = head;
  while (p != NULL) {
    q = p->first;
    while (q != NULL) {
      countclause[cal]++;
      q = q->next;
    }
    cal++;
    p = p->next;
  }
  memset(score, 0, sizeof(int) * 51000);
  cal = 0;
  p = head;
  while (p != NULL) {
    q = p->first;
    while (q != NULL) {
      if (q->data > 0)
        score[q->data] += (double)count[q->data + 51000] *
                          pow(0.5, (double)countclause[cal] - 1);
      if (q->data > 0)
        score[-q->data] += (double)count[q->data + 51000] *
                           pow(0.5, (double)countclause[cal] - 1);
      q = q->next;
    }
    cal++;
    p = p->next;
  }
  max = 0;
  int temp;
  for (i = 0; i < 51000; i++) {
    if (score[i] > max) {
      max = score[i];
      temp = i;
    }
  }
  return temp;
}

HNode* CopyCNF(HNode* head1) {  //???Ʒ?ʽ
  HNode *p = head1, *q = (HNode*)malloc(sizeof(HNode)), *head2 = q;
  q->next = NULL;
  q->first = NULL;
  Node *t = NULL, *r = NULL;
  while (p != NULL) {
    q->next = (HNode*)malloc(sizeof(HNode));
    q = q->next;
    q->next = NULL;
    q->first = NULL;
    t = p->first;
    if (t != NULL) {
      r = (Node*)malloc(sizeof(Node));
      r->data = t->data;
      r->next = NULL;
      q->first = r;
    }
    t = t->next;
    while (t != NULL) {
      r->next = (Node*)malloc(sizeof(Node));
      r = r->next;
      r->data = t->data;
      r->next = NULL;
      t = t->next;
    }
    p = p->next;
  }
  HNode* headcopy = head2->next;
  free(head2);
  return headcopy;
}

int destroyCNF(HNode*& head) {
  if (head == NULL)
    return INFEASIBLE;
  HNode *p = head, *t = NULL;
  while (p != NULL) {
    t = p->next;
    free0(p);
    p = t;
  }
  return OK;
}

void tautologyCheck(HNode*& head) {  //????ʽ????
  int i, top = 0;
  int stack[200];
  HNode* p = head;
  Node* q = p->first;
  while (p != NULL) {
    while (q != NULL) {
      for (i = 0; i < top; i++) {
        if (q->data == -stack[i])
          removeClause(head, stack[0]);
      }
      stack[top++] = q->data;
      q = q->next;
    }
    top = 0;
    p = p->next;
  }
}

void simplifyCheck(HNode*& head, int solution[51000]) {
  HNode* p = head;
  Node* q = NULL;
  int i = 0;
  memset(count, 0, sizeof(int) * 103000);
  while (p != NULL) {
    q = p->first;
    while (q != NULL) {
      count[q->data + 51000]++;
      q = q->next;
    }
    p = p->next;
  }
  for (i = 51001; i < 103000; i++) {
    if (count[i] && !count[102000 - i]) {
      removeClause(head, i - 51000);
      solution[i - 51000] = 1;
    }
    if (!count[i] && count[102000 - i]) {
      removeClause(head, 51000 - i);
      solution[i - 51000] = 0;
    }
  }
}

int DPLL(HNode*& head, int solution[51000]) {
  tautologyCheck(head);
  int tar = 0;
  while (1) {
    HNode* p = head;
    while (p != NULL) {
      if (p->first == NULL)
        break;
      if (p->first->next == NULL) {
        tar = p->first->data;
        if (tar < 0)
          solution[-tar] = 0;
        else
          solution[tar] = 1;
        break;
      }
      tar = 0;
      p = p->next;
    }
    if (tar == 0)
      break;
    else {  // CNF?в????ڵ??Ӿ?
      removeClause(head, tar);
      DeleteNode(head, -tar);
      tar = 0;
    }
  }
  if (head == NULL)
    return TRUE;
  else if (CNFempty(head))
    return FALSE;

  simplifyCheck(head, solution);

  int max = Divide(head);  //???Զ?DPLL????Ӱ???ܴ?
  HNode* headcopy = CopyCNF(head);
  AddHNode(headcopy, max);
  if (DPLL(headcopy, solution))
    return (TRUE);  //?ڵ?һ??֧??????
  destroyCNF(headcopy);
  AddHNode(head, -max);
  return DPLL(head, solution);  //???ݵ???vִ?з?֧???Եĳ?̬??????һ??֧
}

void CreateCNF(HNode* head, FILE* fp) {  //????CNF
  char xxx[100];
  while ('c' == getc(fp)) {
    while ('\n' != getc(fp))
      ;
  }
  fgets(xxx, 6, fp);
  fscanf(fp, "%d%d", &boolnum, &clausenum);
  int i, j, k, data;
  HNode* p = head;
  Node* q = NULL;
  fscanf(fp, "%d", &data);
  p->first = (Node*)malloc(sizeof(Node));
  p->first->data = data;
  p->first->next = NULL;
  q = p->first;
  while (1) {
    fscanf(fp, "%d", &data);
    if (data == 0)
      break;
    q->next = (Node*)malloc(sizeof(Node));
    q = q->next;
    q->data = data;
    q->next = NULL;
  }
  for (i = 1; i < clausenum; i++) {
    p->next = (HNode*)malloc(sizeof(HNode));
    p = p->next;
    p->next = NULL;
    fscanf(fp, "%d", &data);
    if (data == 0)
      continue;
    p->first = (Node*)malloc(sizeof(Node));
    p->first->data = data;
    p->first->next = NULL;
    q = p->first;
    while (1) {
      fscanf(fp, "%d", &data);
      if (data == 0)
        break;
      q->next = (Node*)malloc(sizeof(Node));
      q = q->next;
      q->data = data;
      q->next = NULL;
    }
  }
}

void CreateSudoku(HNode* head) {
  int i, j, k;
  //??Լ??
  HNode* p = head;
  Node* q = NULL;
  while (p->next != NULL)
    p = p->next;
  for (i = 1; i <= 729; i++) {
    if ((i - 1) % 9 == 0) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = NULL;
      p->next = NULL;
      q = (Node*)malloc(sizeof(Node));
      p->first = q;
    }
    q->data = i;
    if (i % 9 != 0) {
      q->next = (Node*)malloc(sizeof(Node));
      q = q->next;
    }
    q->next = NULL;
  }

  for (i = 1; i < 729; i++) {
    for (j = i + 1; j <= ((i - 1) / 9 + 1) * 9; j++) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = NULL;
      p->next = NULL;
      q = (Node*)malloc(sizeof(Node));
      p->first = q;
      q->data = -i;
      q->next = (Node*)malloc(sizeof(Node));
      q->next->next = NULL;
      q->next->data = -j;
    }
  }

  //??Լ??
  for (k = 1; k <= 649; k += 81) {
    for (i = k; i <= k + 8; i++) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = NULL;
      p->next = NULL;
      q = (Node*)malloc(sizeof(Node));
      p->first = q;
      for (j = i; j <= i + 72; j += 9) {
        q->data = j;
        if (j != i + 72) {
          q->next = (Node*)malloc(sizeof(Node));
          q = q->next;
        }
        q->next = NULL;
      }
    }
  }

  for (i = 1; i <= 720; i++) {
    for (j = i + 9; j <= ((i - 1) / 81 + 1) * 81; j += 9) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = NULL;
      p->next = NULL;
      q = (Node*)malloc(sizeof(Node));
      p->first = q;
      q->data = -i;
      q->next = (Node*)malloc(sizeof(Node));
      q->next->next = NULL;
      q->next->data = -j;
    }
  }

  //??Լ??
  for (k = 1; k <= 73; k += 9) {
    for (i = k; i <= k + 8; i++) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = NULL;
      p->next = NULL;
      q = (Node*)malloc(sizeof(Node));
      p->first = q;
      for (j = i; j <= i + 648; j += 81) {
        q->data = j;
        if (j != i + 648) {
          q->next = (Node*)malloc(sizeof(Node));
          q = q->next;
        }
        q->next = NULL;
      }
    }
  }

  for (i = 1; i <= 648; i++) {
    for (j = i + 81; j <= (i - (i - 1) / 81 * 81 - 1) / 9 * 9 + 657; j += 81) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = NULL;
      p->next = NULL;
      q = (Node*)malloc(sizeof(Node));
      p->first = q;
      q->data = -i;
      q->next = (Node*)malloc(sizeof(Node));
      q->next->next = NULL;
      q->next->data = -j;
    }
  }
  //??Լ??
  int count = 0, flag = 0;
  for (i = 1; i <= 541; i += 27) {
    if ((i - 1) % 81 == 0 && i != 1)
      flag = 1;
    if (flag == 1) {
      count++;
      if (count % 7 != 0)
        continue;
      flag = 0;
    }
    for (j = i; j <= i + 8; j++) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = NULL;
      p->next = NULL;
      q = (Node*)malloc(sizeof(Node));
      p->first = q;
      for (k = j; k <= j + 18; k += 9) {
        q->data = k;
        q->next = (Node*)malloc(sizeof(Node));
        q = q->next;
        q->next = NULL;
      }
      for (k = j + 81; k <= j + 99; k += 9) {
        q->data = k;
        q->next = (Node*)malloc(sizeof(Node));
        q = q->next;
        q->next = NULL;
      }
      for (k = j + 162; k <= j + 180; k += 9) {
        q->data = k;
        if (k != j + 180) {
          q->next = (Node*)malloc(sizeof(Node));
          q = q->next;
        }
        q->next = NULL;
      }
    }
  }

  int trig1 = 1, trig2 = 1, cou = 0, t = 0;
  for (t = 1; t <= 55; t += 27) {
    trig1 = 1, trig2 = 1, cou = 0;
    for (i = t; i <= t + 171; i += 9) {
      if (trig1 && i > 20 + t && i < 80 + t)
        continue;
      if (i > 80 + t)
        trig1 = 0;
      if (trig2 && i > 101 + t && i < 162 + t)
        continue;
      if (i > 162 + t)
        trig2 = 0;
      for (j = i; j <= i + 8; j++) {
        for (k = j + 9; k <= j + 18 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }

        if ((float)cou / 3 > 1.8)
          goto loop;
        for (k = j + 81 - cou % 3 * 9; k <= j + 99 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }

        if ((float)cou / 3 > 0.9)
          goto loop;
        for (k = j + 162 - cou % 3 * 9; k <= j + 180 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }
      loop:;
      }
      cou++;
    }
  }

  for (t = 244; t <= 298; t += 27) {
    cou = 0, trig1 = 1, trig2 = 1;
    for (i = t; i <= t + 171; i += 9) {
      if (trig1 && i > 263 + t - 244 && i < 323 + t - 244)
        continue;
      if (i > 323 + t - 244)
        trig1 = 0;
      if (trig2 && i > 344 + t - 244 && i < 404 + t - 244)
        continue;
      if (i > 404 + t - 244)
        trig2 = 0;
      for (j = i; j <= i + 8; j++) {
        for (k = j + 9; k <= j + 18 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }

        if ((float)cou / 3 > 1.8)
          goto loop1;
        for (k = j + 81 - cou % 3 * 9; k <= j + 99 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }

        if ((float)cou / 3 > 0.9)
          goto loop1;
        for (k = j + 162 - cou % 3 * 9; k <= j + 180 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }
      loop1:;
      }
      cou++;
    }
  }

  for (t = 487; t <= 541; t += 27) {
    cou = 0, trig1 = 1, trig2 = 1;
    for (i = t; i <= t + 171; i += 9) {
      if (trig1 && i > 507 + t - 487 && i < 566 + t - 487)
        continue;
      if (i > 566 + t - 487)
        trig1 = 0;
      if (trig2 && i > 587 + t - 487 && i < 648 + t - 487)
        continue;
      if (i > 648 + t - 487)
        trig2 = 0;
      for (j = i; j <= i + 8; j++) {
        for (k = j + 9; k <= j + 18 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }

        if ((float)cou / 3 > 1.8)
          goto loop2;
        for (k = j + 81 - cou % 3 * 9; k <= j + 99 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }

        if ((float)cou / 3 > 0.9)
          goto loop2;
        for (k = j + 162 - cou % 3 * 9; k <= j + 180 - cou % 3 * 9; k += 9) {
          p->next = (HNode*)malloc(sizeof(HNode));
          p = p->next;
          p->first = NULL;
          p->next = NULL;
          q = (Node*)malloc(sizeof(Node));
          p->first = q;
          q->data = -j;
          q->next = (Node*)malloc(sizeof(Node));
          q->next->next = NULL;
          q->next->data = -k;
        }
      loop2:;
      }
      cou++;
    }
  }
}

int isUnitClause(HNode* head) {
  if (head != NULL)
    if (head->next == NULL)
      return TRUE;
  return FALSE;
}

void addClause(HNode*& head, int a[100], int num) {
  HNode* p = (HNode*)malloc(sizeof(HNode));
  Node *q = (Node*)malloc(sizeof(Node)), *t = q;
  int i;
  t->data = a[0];
  for (i = 1; i < num; i++) {
    t->next = (Node*)malloc(sizeof(Node));
    t = t->next;
    t->data = a[i];
    t->next = NULL;
  }
  p->first = q;
  p->next = head;
  head = p;
  return;
}

void AddSolution(HNode*& head, int solution[51000]) {  //?ó??Ľ???Ϊһ???Ӿ?
  int i = 0;
  HNode* p = (HNode*)malloc(sizeof(HNode));
  Node* q = (Node*)malloc(sizeof(Node));
  while (solution[i] != 1)
    i++;
  q->data = -i;
  q->next = NULL;
  p->first = q;
  p->next = head;
  head = p;
  for (i++; i <= 729; i++) {
    if (solution[i] == 1) {
      q->next = (Node*)malloc(sizeof(Node));
      q = q->next;
      q->next = NULL;
      q->data = -i;
    }
  }
}

HNode* GenerateSudoku(int solution[1000], int level) {
loopx:;
  int i, j, k;

  //	while(1) { //????????һ?????õ?????
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

  while (1) {
    srand((unsigned)time(0));
    int b[11];
    b[0] = rand() % 9 + 1;
    b[1] = rand() % 9 + 109;
    b[2] = rand() % 9 + 217;
    b[3] = rand() % 9 + 253;
    b[4] = rand() % 9 + 361;
    b[5] = rand() % 9 + 469;
    b[6] = rand() % 9 + 505;
    b[7] = rand() % 9 + 613;
    b[8] = rand() % 9 + 721;

    HNode* head = (HNode*)malloc(sizeof(HNode));
    HNode* p = head;
    p->first = (Node*)malloc(sizeof(Node));
    p->first->data = b[0];
    p->first->next = NULL;
    for (i = 1; i < 9; i++) {
      p->next = (HNode*)malloc(sizeof(HNode));
      p = p->next;
      p->first = (Node*)malloc(sizeof(Node));
      p->first->data = b[i];
      p->first->next = NULL;
      p->next = NULL;
    }
    CreateSudoku(head);
    int result = DPLL(head, solution);
    if (result == TRUE)
      break;
  }

  i = 0;  //?????ɵ???????ΪCNF
  while (solution[i] != 1)
    i++;
  HNode* head = (HNode*)malloc(sizeof(HNode));
  HNode* p = head;
  p->first = (Node*)malloc(sizeof(Node));
  p->first->data = i;
  p->first->next = NULL;
  for (i++; i <= 729; i++) {
    if (solution[i] != 1)
      continue;
    p->next = (HNode*)malloc(sizeof(HNode));
    p = p->next;
    p->first = (Node*)malloc(sizeof(Node));
    p->first->data = i;
    p->first->next = NULL;
    p->next = NULL;
  }

  int dig;
  if (level == 1)
    dig = 50 - rand() % 7;
  if (level == 2)
    dig = 57 - rand() % 7;
  if (level == 3)
    dig = 62 - rand() % 5;
  int record[81];
  memset(record, 0, sizeof(int) * 81);
  int countx = 0, cou = 0, del_tar, avo, sta, result;
  for (i = 1; i <= dig; i++) {  //??????ȥ60?????????ұ?֤????Ψһ??
    del_tar = rand() % (81 - countx) + 1;
    p = head;
    for (j = 1; j < del_tar; j++)
      p = p->next;
    avo = p->first->data;
    if (cou + countx == 81) {
      destroyCNF(head);
      memset(solution1, 0, sizeof(int) * 730);
      memset(solution, 0, sizeof(int) * 730);
      goto loopx;
    }
    if (IsIn(record, avo)) {
      i--;
      continue;
    }
    removeClause(head, avo);
    //				sta=avo/9*9;
    //				if(avo%9==0) sta-=9;
    //				start=clock();
    //				for(j=1; j<=9; j++) {
    //					if(j+sta==avo) continue;

    HNode* headcopy = CopyCNF(head);
    CreateSudoku(headcopy);

    AddSolution(headcopy, solution);
    memset(solution1, 729, sizeof(int) * 81);
    result = DPLL(headcopy, solution1);

    if (result) {
      record[cou++] = avo;
      AddHNode(head, avo);
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

int Evaluate(int solution[1000], int sudoku[10][10]) {
  int i, row, column, num;
  for (i = 1; i <= 729; i++) {
    if (solution[i] == 1) {
      row = (i - 1) / 81 + 1;
      column = (i - (row - 1) * 81) / 9 + 1;
      if ((i - (row - 1) * 81) % 9 == 0) {
        num = 9;
        column--;
      } else
        num = i - (row - 1) * 81 - (column - 1) * 9;
      if (sudoku[row][column] != num)
        return FALSE;
    }
  }
  return TRUE;
}