#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

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
typedef struct SqList {
  int* elem;
  int length;
} SqList;  //һ��˳���ṹ���洢��

int createCNF(pcnf* L, char filename[80]);
int showCNF(pcnf L);  //��ӡCNF��ʽ
int InitList(pcnf L, SqList& An);
int RemoveClause(pcnf L, int flag);
int AddClause(pcnf L, int flag);
int EmptyClause(pcnf L);
int Findl(pcnf L, SqList& An);
int DPLL(pcnf L, SqList& An, int now_l);
int ResWrite(int res, double time, SqList& An, char filename[]);
int main() {
  pcnf L;
  SqList An;
  clock_t start, end;  //��¼��ʼʱ�������ʱ��
  double duration;     //��¼��������ʱ��
  char filename[200];  //�ļ���
  int op = 1, tag;     //�˵�ѡ��
  int b;
  double time;
  double s;  //��¼Ч�ʵ�����
  while (op) {
    system("cls");
    printf("        ����SAT��������Ϸ������Ĳ˵�\n");
    printf("-------------------------------------------------\n");
    printf("    1.����CNF                2.չʾCNF\n");
    printf("    3.DPLL�㷨���           4.����Ϊres\n");
    printf("    0.exit\n");
    printf("----------------------------------------\n");
    printf("��ѡ����Ҫ���еĲ���[0-5]:\n");
    scanf("%d", &op);

    switch (op) {
      case 1:  //����cnf�ṹ��
        printf("�������ļ���:\n");
        scanf("%s", filename);
        if (createCNF(&L, filename) == OK)
          printf("cnf��ʽ�����ɹ�\n");
        else {
          printf("cnf��ʽ����ʧ��\n");
          getchar();
          getchar();
          break;
        }
        if (InitList(L, An) == OK)
          printf("�������洢�ռ�ɹ�\n");
        else {
          printf("�������洢�ռ�ʧ��\n");
          getchar();
          getchar();
          break;
        }
        getchar();
        getchar();
        break;

      case 2:  //��ʾcnf�ṹ
        showCNF(L);
        getchar();
        getchar();
        break;

      case 3:              // DPLL�㷨
        b = Findl(L, An);  //���ҵ���һ�����Ӿ�������ڷ��Ѳ��Ե�����
        start = clock();
        if (DPLL(L, An, b) == OK) {
          tag = 1;
          printf("���ɹ�\n");
        } else {
          tag = 0;
          printf("���ʧ��\n");
        }
        end = clock();
        duration = ((double)(end - start)) / CLK_TCK * 1000;
        printf("����ʱ��Ϊ��%f����\n", duration);

        for (int i = 1; i < An.length;
             i++)  //���������������ⲻ�ɹ������������
        {
          if (An.elem[i] == -1)
            printf("%5d", -i);
          else
            printf("%5d", i);
          if (i % 10 == 0)
            printf("\n");
        }
        getchar();
        getchar();
        break;

      case 4:
        if (ResWrite(tag, duration, An, filename) == OK)
          printf("���д��ɹ�\n");
        else
          printf("���д��ʧ��\n");
        getchar();
        getchar();
        break;
      case 0:
        break;
    }  // end of switch
  }    // end of while
  return 0;
}

int createCNF(pcnf* L, char filename[200]) {  //�����ṹ�壬�Ա����ʽ�洢
  pcNode p;                                   //�Ӿ���
  plNode q;                                   //���ֽڵ�
  *L = (cnf*)malloc(sizeof(struct cnf));
  p = (cNode*)malloc(sizeof(struct cNode));
  p->flag = 0;  //��¼�Ӿ��Ƿ���Ϊflag����ɾ��
  p->mark = 1;  //��¼�Ӿ��Ƿ�ɾ����1��ʾδ��ɾ��
  (*L)->firstc = p;
  FILE* fp;
  int num = 0;  //Ϊ�����Ӿ���Ŀ�ͱ�Ԫ��Ŀ���м����
  int k = 0;    //��¼ÿ���Ӿ����ָ���
  int m = 0;    //��¼�Ӿ�ĸ���
  int flag;     //��¼����

  char c;  //��ȡ�ļ��ַ�ʹ��

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("���ļ�ʧ��\n");
    return 0;
  }
  fscanf(fp, "%c", &c);
  while (!feof(fp)) {
    if (c == 'c') {  //��c��ͷ��ע��ȥ��
      while (c != '\n') {
        fscanf(fp, "%c", &c);
      }
      fscanf(fp, "%c", &c);
    } else if (c == 'p') {
      while (c != '\n') {
        while (c < '0' || c > '9') {
          fscanf(fp, "%c", &c);
        }
        while (c >= '0' && c <= '9') {  //��ȡ��Ԫ��
          num = num * 10;
          num += c - '0';
          fscanf(fp, "%c", &c);
        }
        (*L)->varinum = num;
        num = 0;
        while (c < '0' || c > '9') {
          fscanf(fp, "%c", &c);
        }
        while (c >= '0' && c <= '9') {  //��ȡ�Ӿ���
          num = num * 10;
          num += c - '0';
          fscanf(fp, "%c", &c);
        }
        (*L)->claunum = num;
        num = 0;
      }
      fscanf(fp, "%c", &c);
    } else if ((c >= '0' && c <= '9') || (c == '-')) {
      q = (lNode*)malloc(sizeof(struct lNode));
      q->mark = 1;  // mark����1��ʾû�б�ɾ��
      p->firstl = q;
      while (c != '\n') {
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
            if (flag == 0)
              q->l = -num;
            else
              q->l = num;
            num = 0;
            k++;
          }
          fscanf(fp, "%c", &c);
          if (c == '0')
            q->next = NULL;
          else {
            q->next = (lNode*)malloc(sizeof(struct lNode));
            q = q->next;
            q->mark = 1;
          }
        }
        fscanf(fp, "%c", &c);
      }
      fscanf(fp, "%c", &c);
      p->l_count = k;
      k = 0;
      m++;

      if (m < (*L)->claunum) {
        p->next = (cNode*)malloc(sizeof(struct cNode));
        p = p->next;
        p->flag = 0;
        p->mark = 1;
      } else
        p->next = NULL;
    } else
      fscanf(fp, "%c", &c);  //��ֹ�ļ���β�ж������
  }
  fclose(fp);
  return OK;
}

int showCNF(pcnf L) {  //��ʾcnf�ṹ��
  if (L->claunum == 0) {
    printf("cnf��ʽΪ��\n");
    return OK;
  }
  pcNode p = L->firstc;
  plNode q = p->firstl;
  printf("cnf��ʽ��Ԫ����%d  �Ӿ�����%d\n", L->varinum, L->claunum);
  int i = 1;
  int j;
  while (p) {
    if (p->mark == 0)
      p = p->next;
    else {
      printf("��%d����%d������   ", i++, p->l_count);
      q = p->firstl;
      j = 1;
      while (q) {
        if (q->mark == 0)
          q = q->next;
        else {
          printf("%4d:%5d", j++, q->l);
          q = q->next;
        }
      }
      printf("\n");
      p = p->next;
    }
  }
  return OK;
}

int InitList(pcnf L, SqList& An) {  //��ʼ���������˳���
  An.elem = (int*)malloc((L->varinum + 1) * sizeof(int));  //����洢�ռ�
  if (!An.elem) {
    return ERROR;  //����洢�ռ�ʧ��
  };
  An.length = L->varinum + 1;  //��ʼ�����Ա�ĳ���Ϊ0
  for (int i = 1; i < An.length; i++) {
    An.elem[i] = 0;  //��ʾû�о������Ӿ�򻯸�ֵ
    // printf("%d  ",An.elem[i]); �鿴�������н��ȣ�û�б�Ҫ��
  }
  return OK;
}

int RemoveClause(pcnf L, int flag) {  //һ���ҳ�һ����Ԫ����ɾ��
  pcNode p;
  plNode q;
  p = L->firstc;
  q = p->firstl;
  while (p) {
    if (p->mark == 0)
      p = p->next;
    else {
      q = p->firstl;
      while (q) {
        if (q->mark == 0)
          q = q->next;
        else {
          if (q->l == flag) {  //�Ӿ�����flag��ɾ���Ӿ�
            p->mark = 0;
            p->flag = flag;
            L->claunum--;  //�Ӿ���Ŀ��һ
            break;
          } else if (q->l == -flag) {  //�Ӿ�����-flag��ɾ��������
            q->mark = 0;
            p->l_count--;  //������Ŀ��һ
            break;
          } else
            q = q->next;
        }
      }
      p = p->next;
    }
  }
  L->varinum--;  //ɾ����Ԫ�󣬱�Ԫ��Ŀ��һ
  return OK;
}

int AddClause(pcnf L, int flag) {  //�ָ�ǰ����Ϊflag��ɾ����Ԫ�أ��Ӿ�
  pcNode p;
  plNode q;
  p = L->firstc;
  q = p->firstl;
  while (p) {
    q = p->firstl;
    if (p->mark == 1) {  //�ָ���L����ɾ��������
      while (q) {
        if (q->mark == 0 && q->l == -flag) {
          q->mark = 1;
          p->l_count++;  //�Ӿ�������Ŀ��һ
          break;
        } else
          q = q->next;
      }
    } else if (p->mark == 0 && p->flag == flag) {  //�ָ��Ӿ�
      p->mark = 1;
      p->flag = 0;
      L->claunum++;
    } else {
      while (q) {
        if (q->mark == 0 && q->l == -flag) {
          q->mark = 1;
          p->l_count++;  //�Ӿ�������Ŀ��һ
          break;
        } else
          q = q->next;
      }
    }
    p = p->next;
  }
  L->varinum++;  //��Ԫ��Ŀ��һ
  return OK;
}

int EmptyClause(pcnf L) {  //�鿴�Ƿ��пվ�
  pcNode p = L->firstc;
  while (p) {
    if (p->l_count == 0 && p->mark == 1)
      return OK;  //��������Ϊ0�����Ӿ�δ����ɾ�������ǿվ�
    p = p->next;
  }
  return FALSE;
}

int Findl(pcnf L, SqList& An) {  //���ҷ���Ҫ��ı�Ԫ
  pcNode p;
  plNode q;
  int i;
  int flag = 0;  //����Ѱ�ҳ��ֵ���ߴ����Ͷ�Ӧ�ı�Ԫ
  p = L->firstc;
  while (p) {  //Ѱ�ҵ��Ӿ�
    if (p->mark == 1 && p->l_count == 1) {
      q = p->firstl;
      while (q) {
        if (q->mark == 1) {
          if (q->l > 0)
            An.elem[q->l] = 1;
          else
            An.elem[-(q->l)] = -1;
          return q->l;
        } else
          q = q->next;
      }
    } else
      p = p->next;
  }
  //�ı���ԣ�Ѱ�ҳ��ִ������ı�Ԫ
  int* a = (int*)malloc((2 * An.length - 1) * sizeof(int));
  for (i = 0; i < 2 * An.length - 1; i++) {
    a[i] = 0;
  }
  p = L->firstc;
  while (p) {  //��¼����Ԫ���ֵĴ���
    if (p->mark == 0)
      p = p->next;
    else {
      q = p->firstl;
      while (q) {
        if (q->mark == 0)
          q = q->next;
        else {
          if (q->l > 0)
            a[2 * (q->l) - 1]++;
          else if (q->l < 0)
            a[2 * (-(q->l))]++;
          q = q->next;
        }
      }
      p = p->next;
    }
  }
  for (i = 1; i < 2 * An.length - 1; i++) {  //�ҳ����ִ��������ֵ
    if (a[i] > flag)
      flag = a[i];
  }
  for (i = 1; i < 2 * An.length - 1; i++) {  //�ҵ���Ԫ
    if (a[i] == flag)
      break;
  }
  free(a);
  if (i % 2) {
    An.elem[(i + 1) / 2] = 1;
    return ((i + 1) / 2);
  } else {
    An.elem[i / 2] = -1;
    return (-(i / 2));
  }
}

int DPLL(pcnf L, SqList& An, int now_l) {  // now_l�ǵ�ǰ�������������
  int next_l;                              //����Findl�������ɵ�
  if (L->claunum == 0)
    return OK;  // cnf��ʽΪ�գ�����ɹ�
  else {
    if (EmptyClause(L) == OK) {  //�п��Ӿ䣬�ǲ���������
      if (AddClause(L, now_l) != OK)
        printf("�ָ�ʧ��\n");
      if (now_l > 0)
        An.elem[now_l] = 0;
      else
        An.elem[-now_l] = 0;
      return FALSE;
    } else {  // cnf��δ�����꣬���õ��Ӿ�ԭ��+���Ѳ���
      next_l = Findl(L, An);
      if (next_l == 0)
        return FALSE;

      if (RemoveClause(L, next_l) != OK)
        printf("ɾ��ʧ��\n");

      if (DPLL(L, An, next_l) == OK)
        return OK;
      else {  //���򲻳ɹ�ʱ����Ҫ�ı�next_l����ֵ�����л���
        if (AddClause(L, next_l) != OK)
          printf("�ָ�ʧ��\n");
        if (RemoveClause(L, -next_l) != OK)
          printf("ɾ��ʧ��\n");
        if (DPLL(L, An, -next_l) == OK) {
          if (next_l > 0)
            An.elem[next_l] = -1;
          else
            An.elem[-next_l] = 1;
          return OK;
        } else {  //���δ�ɹ�����˳�����Ӧλ���޸�Ϊδ������ֵ�жϵ�״̬
          if (AddClause(L, -next_l) != OK)
            printf("�ָ�ʧ��\n");
          if (next_l > 0)
            An.elem[next_l] = 0;
          else
            An.elem[-next_l] = 0;
          return FALSE;
        }
      }
    }
  }
}

int ResWrite(int res, double time, SqList& An, char filename[80]) {
  int i = 0;
  while (filename[i] != '\0')
    i++;
  filename[i - 3] = 'r';  //ֻ�ı��ļ�����չ��
  filename[i - 2] = 'e';
  filename[i - 1] = 's';
  FILE* fp;
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("���ļ�ʧ��\n");
    return ERROR;
  }
  fprintf(fp, "s %d\n", res);  // res���������1��ʾ���㣬0��ʾ�����㣬-1δ��
  fprintf(fp, "v\n");
  for (i = 1; i < An.length; i++) {
    if (An.elem[i] == -1)
      fprintf(fp, "%5d", -i);
    else
      fprintf(fp, "%5d", i);
    if (i % 10 == 0)
      fprintf(fp, "\n");
  }
  fprintf(fp, "\nt %f ms\n", time);
  fclose(fp);
  return OK;
}
