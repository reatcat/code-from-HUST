#pragma warning(disable:4996)
int createCNF(pcnf* L, char filename[200]) {  //�����ṹ�壬�Ա����ʽ�洢
  pcNode p;                                   //�Ӿ���
  plNode q;                                   //���ֽڵ�
  *L = (cnf*)malloc(sizeof(struct cnf));
  p = (cNode*)malloc(sizeof(struct cNode));
  p->flag = 0;  //��¼�Ӿ��Ƿ���Ϊflag����ɾ��
  p->mark = 1;  //��¼�Ӿ��Ƿ�ɾ����1��ʾδ��ɾ��
  (*L)->firstc = p;
  (*L)->claunum = -1;
  FILE* fp;
  int num = 0;  //Ϊ�����Ӿ���Ŀ�ͱ�Ԫ��Ŀ���м����
  int k = 0;    //��¼ÿ���Ӿ����ָ���
  int m = 0;    //��¼�Ӿ�ĸ���
  int flag;     //��¼����
  int lnum=0;
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
        lnum = 0;
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
              lnum = lnum * 10;
              lnum += c - '0';
              fscanf(fp, "%c", &c);
            }
            if (flag == 0)
              q->l = -lnum;
            else
              q->l = lnum;
            lnum = 0;
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
  if ((*L)->claunum!=num) {
    printf("�ļ����ݲ��Ϸ���\n");
    return FALSE;
  }
  return OK;
}
void destory(pcnf L) {
  pcNode p = L->firstc;
  pcNode pn;
  plNode qn;
  if (p == NULL)
    return;
  else {
    while (p) {
        plNode q = p->firstl;
    while (q) {
      qn = q->next;
      free(q);
      q = qn;
    }
    pn = p->next;
    free(p);
    p = pn;
    }
      
  }
  L->firstc=p;
  L->claunum = 0;
  L->varinum=0;
  return;
}
int InitList(pcnf L, SqList& An) {  //��ʼ���������˳���
  An.elem = (int*)malloc((L->varinum + 1) * sizeof(int));  //����洢�ռ�
  if (!An.elem) {
    return ERROR;  //����洢�ռ�ʧ��
  };
  An.length = L->varinum + 1;  //��ʼ�����Ա�ĳ���Ϊ0
  for (int i = 0; i < An.length; i++) {
    An.elem[i] = 0;  //��ʾû�о������Ӿ�򻯸�ֵ
  }
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
  while (p) {
    if (p->mark == 0)
      p = p->next;
    else {
      printf("��%d��:", i++);
      q = p->firstl;
      while (q) {
        if (q->mark == 0)
          q = q->next;
        else {
          printf("%5d",q->l);
          q = q->next;
        }
      }
      printf("\n");
      p = p->next;
    }
  }
  return OK;
}
void quickSort(int* array, int* arraynum, int low, int high) {  //����
    int i, j, key1, key;
    i = low;
    j = high;
    key1 = array[low];//��ʾ�ڼ�λ
    key = arraynum[low];//Ȩ��
    if (low < high) {
      while (i < j) {
        while (i<j&&arraynum[j] <= key)
          j--;
        if (i < j) {
          array[i] = array[j];
          arraynum[i] = arraynum[j];
        }
        while (i < j && arraynum[i] >= key)
          i++;
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
void sort(pcnf L, int key[3500], int value[3500]) {
  memset(value, 0, sizeof(value));
  for (int i = 0; i < L->varinum; i++)
    key[i] = i + 1;
  pcNode p = L->firstc;
  int  k;
  while (p) {
    if (p->l_count<10)
      k = 100-p->l_count*10;
    else
      k = 1;
    plNode q = p->firstl;
    for (int i = 1; i <= p->l_count; i++) {
      int m = q->l;
      if (m > 0)
        value[m - 1] += k;
      else {
        value[-m - 1] += k;
      }
      q = q->next;
    }
    p = p->next;
  }
  quickSort(key, value, 0, L->varinum - 1);
}