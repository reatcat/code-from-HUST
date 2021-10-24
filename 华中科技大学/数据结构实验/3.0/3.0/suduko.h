#pragma once
void EnterArray(int n[8][8]) {
  printf("\n\n����������������\n\n��2��ʾ�ո�\n\n");
  for (int A = 0; A < 8; A++)
    for (int B = 0; B < 8; B++)
      scanf("%d", &n[A][B]);
}
void ShowPuzzle(int* puzzle) {
  for (int A = 0; A < 64; A++) {
    printf("%d ", puzzle[A]);
    if ((A + 1) % 8 == 0)
      printf("\n");
  }
}
int* getPuzzle(DecisionTreeHead* aHead) {
  if (aHead == NULL) {
    return NULL;
  }
  int* n = (int*)malloc(64 * sizeof(int));
  DecisionTreeNode* newNode = aHead->firstNode;
  for (; newNode != NULL; newNode = newNode->next) {
    int a = abs(newNode->lit);
    if (a < 65)
      if (newNode->lit > 0)
        n[a - 1] = 1;
      else
        n[a - 1] = 0;
  }
  return n;
}

DecisionTreeHead* creatSAT(int sudoku[8][8], int n, int way) {
  int q = 1;
  CNF* cnf = (CNF*)malloc(sizeof(CNF));
  cnf->clauseNum = kownLitNumber(sudoku, n) + calculateClauseSize(n) + 56;
  cnf->litNum = calculateSize(n);
  cnf->lit = NULL;
  cnf->Clause = NULL;
  initCnf(cnf);
  addClause(sudoku, n, cnf, &q);
  // travel(cnf);
  DecisionTreeHead* aHead = DPLL(cnf, way);
  // printf("%d    ,",Check(cnf,aHead));
  return aHead;
}

void addClause(int sudoku[8][8], int n, CNF* cnf, int* q) {
  addKnown(sudoku, n, cnf, q);
  addConstraint1(n, cnf, q);
  addConstraint2(n, cnf, q);
  addConstraint3(n, cnf, q);
}

int kownLitNumber(int sudoku[8][8], int n) {
  int c = 0;  //����
  for (int count1 = 0; count1 < n; count1++)
    for (int count2 = 0; count2 < n; count2++)
      if (sudoku[count1][count2] == 1 || sudoku[count1][count2] == 0)
        c++;
  return c;
}
int calculateClauseSize(int n) {
  int c1 = 6 * 2 * 8 * 2;  //Լ��1
  int c2 = 56 * 8 * 4;
  int c3 = 4536;
  return c1 + c2 + c3;
}

int calculateSize(int n)  //�����Ԫ������
{
  int Constraint3 = (3 * n + 1) * n * (n - 1);
  return Constraint3 + n * n;
}

void addKnown(int sudoku[8][8], int n, CNF* cnf, int* q)  //�����֪���Ӿ�
{
  for (int countA = 0; countA < n; countA++) {
    for (int countB = 0; countB < n; countB++) {
      if (sudoku[countA][countB] == 1 || sudoku[countA][countB] == 0) {
        if (sudoku[countA][countB] == 1)
          addElem(cnf, *q, calculateCount(countA, countB, n));
        else
          addElem(cnf, *q, -calculateCount(countA, countB, n));
        (*q)++;
      }
    }
  }
}

int calculateCount(int countA, int countB, int n)  //�����ڶ��������еĸ���
{
  return countA * n + countB + 1;
}

void addConstraint1(int n, CNF* cnf, int* q)  //���Լ��1���Ӿ�
{
  //��
  for (int countA = 0; countA < 8; countA++) {
    for (int countB = 0; countB < 6; countB++) {
      for (int cx = 1; cx > -2; cx = cx - 2) {
        for (int count = 0; count < 3; count++)  //��ȫΪ1ʱ
        {
          addElem(cnf, *q, cx * (calculateCount(countA, countB, n) + count));
        }
        (*q)++;
      }
    }
  }
  //��
  for (int countA = 0; countA < 6; countA++) {
    for (int countB = 0; countB < 8; countB++) {
      for (int cx = 1; cx > -2; cx = cx - 2) {
        for (int count = 0; count < 3; count++)  //��ȫΪ1ʱ
        {
          addElem(cnf, *q,
                  cx * (calculateCount(countA, countB, n) + count * 8));
        }
        (*q)++;
      }
    }
  }
}

void addConstraint2(int n, CNF* cnf, int* q)  //���Լ��2���Ӿ�
{
  for (int row = 0; row < 57; row = row + 8) {
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    int cx;
    for (; a < b; a++)
      for (b = a + 1; b < c; b++)
        for (c = b + 1; c < d; c++)
          for (d = c + 1; d < e; d++)
            for (e = d + 1; e < 9; e++)
              for (cx = 1; cx > -2; cx = cx - 2) {
                addElem(cnf, *q, cx * (row + a));
                addElem(cnf, *q, cx * (row + b));
                addElem(cnf, *q, cx * (row + c));
                addElem(cnf, *q, cx * (row + d));
                addElem(cnf, *q, cx * (row + e));
                (*q)++;
              }
  }

  //��
  for (int row = 1; row < 9; row++) {
    int a = 0, b = 1, c = 2, d = 3, e = 4;
    int cx;
    for (; a < b; a++)
      for (b = a + 1; b < c; b++)
        for (c = b + 1; c < d; c++)
          for (d = c + 1; d < e; d++)
            for (e = d + 1; e < 8; e++)
              for (cx = 1; cx > -2; cx = cx - 2) {
                addElem(cnf, *q, cx * (row + a * 8));
                addElem(cnf, *q, cx * (row + b * 8));
                addElem(cnf, *q, cx * (row + c * 8));
                addElem(cnf, *q, cx * (row + d * 8));
                addElem(cnf, *q, cx * (row + e * 8));
                (*q)++;
              }
  }
}

void addConstraint3(int n, CNF* cnf, int* q) {
  //��
  int count = 64;  //�����ǵڼ���ѭ��
  int row1 = 1, row2 = 2;
  for (; row1 < row2; row1++)
    for (row2 = row1 + 1; row2 < 9; row2++) {
      for (int c = 1; c < 9; c++)  //�Ȱ�ǰ16�����
      {
        for (int cx = 1; cx > -2; cx = cx - 2) {
          addElem(cnf, *q, ((row1 - 1) * 8 + c) * cx);
          if (cx > 0)
            addElem(cnf, *q, -1 * (count + c * 2 - 1));
          else
            addElem(cnf, *q, -1 * (count + c * 2));
          (*q)++;
          //������һ��ͷ���
          addElem(cnf, *q, ((row2 - 1) * 8 + c) * cx);
          if (cx > 0)
            addElem(cnf, *q, -1 * (count + c * 2 - 1));
          else
            addElem(cnf, *q, -1 * (count + c * 2));
          (*q)++;
          //������һ��ͷ���
          addElem(cnf, *q, (-1 * ((row1 - 1) * 8 + c)) * cx);
          addElem(cnf, *q, (-1 * ((row2 - 1) * 8 + c)) * cx);
          if (cx > 0)
            addElem(cnf, *q, (count + c * 2 - 1));
          else
            addElem(cnf, *q, (count + c * 2));
          (*q)++;
          //������һ��ͷ���
          if (cx == 1)
            addElem(cnf, *q, -1 * (count + c * 2 - 1));
          else
            addElem(cnf, *q, -1 * (count + c * 2));
          addElem(cnf, *q, (count + 16 + c));
          (*q)++;
          //������һ��ͷ���
        }
        addElem(cnf, *q, count + c * 2 - 1);
        addElem(cnf, *q, count + c * 2);
        addElem(cnf, *q, -1 * (count + 16 + c));
        (*q)++;
        //������һ��ͷ���
      }
      //���һ��
      addElem(cnf, *q, -1 * (count + 16 + 8 + 1));
      for (int m = 1; m < 9; m++) {
        addElem(cnf, *q, -1 * (count + 16 + m));
      }
      for (int m = 1; m < 9; m++) {
        (*q)++;
        addElem(cnf, *q, (count + 16 + m));
        addElem(cnf, *q, count + 25);
      }
      (*q)++;
      addElem(cnf, *q, count + 25);
      (*q)++;
      count = count + 25;
    }
  //��
  int line1 = 1, line2 = 2;
  for (; line1 < line2; line1++)
    for (line2 = line1 + 1; line2 < 9; line2++) {
      for (int c = 1; c < 9; c++)  //�Ȱ�ǰ16�����
      {
        for (int cx = 1; cx > -2; cx = cx - 2) {
          addElem(cnf, *q, (line1 + (c - 1) * 8) * cx);
          if (cx > 0)
            addElem(cnf, *q, -1 * (count + c * 2 - 1));
          else
            addElem(cnf, *q, -1 * (count + c * 2));
          (*q)++;
          //������һ��ͷ���
          addElem(cnf, *q, (line2 + (c - 1) * 8) * cx);
          if (cx > 0)
            addElem(cnf, *q, -1 * (count + c * 2 - 1));
          else
            addElem(cnf, *q, -1 * (count + c * 2));
          (*q)++;
          //������һ��ͷ���
          addElem(cnf, *q, (-1 * (line1 + (c - 1) * 8)) * cx);
          addElem(cnf, *q, (-1 * (line2 + (c - 1) * 8)) * cx);
          if (cx > 0)
            addElem(cnf, *q, (count + c * 2 - 1));
          else
            addElem(cnf, *q, count + c * 2);
          (*q)++;
          //������һ��ͷ���
          //Ȼ���м�8
          if (cx == 1)
            addElem(cnf, *q, -1 * (count + c * 2 - 1));
          else
            addElem(cnf, *q, -1 * (count + c * 2));
          addElem(cnf, *q, (count + 16 + c));
          //������һ��ͷ���
          (*q)++;
        }
        addElem(cnf, *q, (count + c * 2 - 1));
        addElem(cnf, *q, count + c * 2);
        addElem(cnf, *q, -1 * (count + 16 + c));
        (*q)++;
        //������һ��ͷ���
      }
      //���һ��
      addElem(cnf, *q, -1 * (count + 16 + 8 + 1));
      for (int m = 1; m < 9; m++) {
        addElem(cnf, *q, -1 * (count + 16 + m));
      }
      for (int m = 1; m < 9; m++) {
        (*q)++;
        addElem(cnf, *q, (count + 16 + m));
        addElem(cnf, *q, count + 25);
      }
      (*q)++;
      addElem(cnf, *q, (count + 25));
      (*q)++;
      count = count + 25;
    }
}

int* createpuzzle() {
  int n[8][8];  //����һ���յ�
  for (int a = 0; a < 8; a++)
    for (int b = 0; b < 8; b++)
      n[a][b] = 2;
  DecisionTreeHead* aHead = creatSAT(n, 8, 3);
  int* puzzle = getPuzzle(aHead);  //�Ѿ����һ������
  for (int a = 0; a < 8; a++)
    for (int b = 0; b < 8; b++)
      n[a][b] = puzzle[a * 8 + b];  //�����ɵ�����ת��Ϊ��ά����
  dig(n);
  for (int a = 0; a < 8; a++) {
    for (int b = 0; b < 8; b++)
      printf("%d ", n[a][b]);
    printf("\n");
  }
  for (int a = 0; a < 8; a++)
    for (int b = 0; b < 8; b++)
      puzzle[a * 8 + b] = n[a][b];
  return puzzle;
}

void dig(int n[8][8]) {
  int count = 0;
  srand((unsigned)time(NULL));
  int row;
  int line;
  while (1)  //���������������
  {
    if (count > 44)
      return;
    while (1)  //�ҵ����ʵ�һ����
    {
      row = (rand()) % 8;
      line = (rand()) % 8;
      if (n[row][line] != 2)
        break;
    }
    int k = n[row][line];
    if (judge(n, row, line, k))  //˵����ͬһ����
    {
      count++;
      n[row][line] = 2;
    } else  //����ͬһ����
      n[row][line] = k;
  }
}

int judge(int n[8][8], int row, int line, int k) {
  int q[8][8];
  for (int a = 0; a < 8; a++)
    for (int b = 0; b < 8; b++) {
      q[a][b] = n[a][b];
    }
  if (k == 1)
    q[row][line] = 0;
  else
    q[row][line] = 1;
  DecisionTreeHead* aHead = creatSAT(q, 8, 1);
  if (aHead == NULL)
    return 1;
  else
    return 0;
}
void showN(int n[8][8]) {
  for (int a = 0; a < 8; a++) {
    for (int b = 0; b < 8; b++)
      printf("%d", n[a][b]);
    printf("\n");
  }
}