void output_sudoku(int temp[9][9]) {
  int i, j;
  //�����������Ļ
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (j % 3 == 0)
        printf("|");
      if (temp[i][j]!=0)
      printf("%d ",temp[i][j]);
      else {
        printf("_ ");
       } 
      if(j==8)
       printf("\n");
    }
    if ((i + 1) % 3 == 0)
      printf("--------------------\n");
      
  }
}

//ʹ����ȫ������
void cleanup(int temp[SIZE][SIZE]) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      temp[i][j] = 0;
    }
  }
}
int sd(int sudo[9][9]) {
  int i, n;
  srand(time(NULL));
  for (i = 0; i < 1; i++) {
    do {
      cleanup(sudo);
    } while (
        get_sudoku(sudo) ==
        0);  //�����������ʧ�ܣ����ؽ��Ϊ0�������sudo���飬��������ֱ���ɹ�
  }
  return OK;
}
int get_sudoku(int temp[SIZE][SIZE]) {
  int i, j, m, random;
  random = rand() % SIZE + 1;  //�������������һ�е�һ�е���  //ѭ��ÿһ��
  for (i = 0; i < SIZE; i++) {
    //ѭ��ÿһ��
    for (j = 0; j < SIZE; j++) {
      m = 0;
      //�жϴ�������Ƿ��ܹ�ʹ��,�����ʹ������ѭ�����������ѭ��
      while (check_sudoku(temp, i, j, random) == 0) {
        random = rand() % SIZE + 1;  //����һ��0-SIZE�������
        m++;
        //���ͬһ��λ��ʧ��һ�ٴΣ������¿�ʼ
        if (m > 80)
          return 0;
      }
      temp[i][j] = random;  //�����Ѿ�ͨ����飬��������
    }
  }
  return 1;
}
//�ж��Ƿ���Խ���i�С���j�е�����Ϊk
int check_sudoku(int temp[SIZE][SIZE], int i, int j, int k) {
  int m, n;
  //�ж���
  for (n = 0; n < SIZE; n++) {
    if (temp[i][n] == k)
      return 0;
  }
  //�ж���
  for (m = 0; m < SIZE; m++) {
    if (temp[m][j] == k)
      return 0;
  }
  //�ж����ھŹ���
  int t1 = (i / 3) * 3, t2 = (j / 3) * 3;
  for (m = t1; m < t1 + 3; m++) {
    for (n = t2; n < t2 + 3; n++) {
      if (temp[m][n] == k)
        return 0;
    }
  }
  return 1;
}
//�ڶ�
int digsudu(int shudu[9][9], int num,int beifen[9][9]) {
  srand(time(NULL));
  int flag;
  for (; num > 0; ) {
   int i = rand() % 9;
    int j = rand() % 9;
   flag = 0;
   if (shudu[i][j] != 0) {
      for (int k = 1; k <= 9; k++) {
       if (k == beifen[i][j]) {
          k++;
       } else if (check_sudoku(shudu, i, j, k) == OK) {
             break;
           flag=1;
         }
      }
      if (flag == 0) {
 shudu[i][j] = 0;
     num--;
      }
   } else {
     continue;
   }
  }
  return OK;
}
int savecnf(int shudu[9][9],char *filename,int dignum) {
  
  FILE* fp;
   fp= fopen(filename, "w");
  if (fp == NULL) {
    printf("���ļ�ʧ��\n");
    return 0;
  }
  int litnum=729, claunum=7533+2916+81-dignum;
  fprintf(fp, "p %d %d\n", litnum, claunum);
  int i, j, k, m;
  //��Լ��
  //ÿ�ж���1-9
  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++) {
    for (k = 1; k <= 9; k++) {
         fprintf(fp, "%d ", (i-1)*81 +(j-1)*9 + k);//ÿһ���ո񶼿�����1-9����
              
        }fprintf(fp, "0\n");
    };
    
  }  //ÿһ��
//729
  //����ͬʱ����������
for ( i = 1; i <= 9; i++) {  //ÿһ��
    for (j = 1; j <= 9; j++) {
      for (k = 1; k <= 9; k++) {
        for (m = 1; m + j <= 9; m++) {
            fprintf(fp, "-%d -%d ", 
                (i - 1) * 81 + (j - 1) * 9 + k,(i - 1) * 81 + (j - 1+m) * 9 + k);  //ÿһ���ո񶼿�����1-9����
      fprintf(fp, "0\n");}
        }
      
        
    }
  }
for (i = 1; i <= 9; i++) {  //ÿһ��
  for (j = 1; j <= 9; j++) {
    for (k = 1; k <= 9; k++) {
      for (m = 1; m + k <= 9; m++) {
        fprintf(
            fp, "-%d -%d ", (i - 1) * 81 + (j - 1) * 9 + k,
            (i - 1) * 81 + (j - 1 ) * 9 + k+m);  //ÿһ���ո񶼿�����1-9����
        fprintf(fp, "0\n");
      }
    }
  }
}
//��Լ��
  for (k = 1; k <= 9; k++) {  //ÿһ��
      for (j = 1; j <= 9; j++) {
      for (i= 1; i <= 9; i++)
        fprintf(fp, "%d ",
                (i-1)*81+ (j-1)*9 + k);  //ÿһ���ո񶼿�����1-9����
      fprintf(fp, "0\n");
    }
  }//729

for (k= 1; k <= 9; k++)
     {  //ÿһ��
    for (j= 1; j <= 9; j++) {
      for (i = 1; i <= 9;i++) {
        for (m = 1; m+i<=9; m++) {
            fprintf(
              fp, "-%d -%d ", (i - 1) *81+ (j - 1) *9 + k,
              (i - 1) * 81 + (j - 1) * 9 + k + m*81);
        fprintf(fp, "0\n");
        }
      }
    }
  }
for (k = 1; k <= 9; k++) {
      for (i = 1; i <= 3; i++)
          for (j = 1; j <= 3; j++)
            fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
      fprintf(fp, "0\n");
  }
for (k = 1; k <= 9; k++) {
    for (i = 4; i <= 6; i++)
      for (j = 1; j <= 3; j++)
        fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
    fprintf(fp, "0\n");
  }

for (k = 1; k <= 9; k++) {
  for (i = 1; i <= 3; i++)
    for (j = 4; j <= 6; j++)
      fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
  fprintf(fp, "0\n");
}
for (k = 1; k <= 9; k++) {
  for (i = 1; i <= 3; i++)
    for (j = 7; j <= 9; j++)
      fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
  fprintf(fp, "0\n");
}
for (k = 1; k <= 9; k++) {
  for (i = 4; i <= 6; i++)
    for (j = 4; j <= 6; j++)
      fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
  fprintf(fp, "0\n");
}
for (k = 1; k <= 9; k++) {
  for (i = 4; i <= 6; i++)
    for (j = 7; j <= 9; j++)
      fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
  fprintf(fp, "0\n");
}
for (k = 1; k <= 9; k++) {
  for (i = 7; i <= 9; i++)
    for (j = 1; j <= 3; j++)
      fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
  fprintf(fp, "0\n");
}
for (k = 1; k <= 9; k++) {
  for (i = 7; i <= 9; i++)
    for (j = 4; j <= 6; j++)
      fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
  fprintf(fp, "0\n");
}
for (k = 1; k <= 9; k++) {
  for (i = 7; i <= 9; i++)
    for (j = 7; j <= 9; j++)
      fprintf(fp, "%d ", (i - 1) * 81 + (j - 1) * 9 + k);
  fprintf(fp, "0\n");
}
for (i = 0;i < 3; i++)
{
    for( j=0;j<3;j++)
        for(int z=1;z<=9;z++)
            for(int x=0;x<3;x++)
                for(int y=0;y<3;y++)
                    for(int k=x+1;k<3;k++)
                        for (int l = 0; l < 3; l++)
                        {
                        if (y != l)
                          fprintf(
                              fp, "-%d -%d 0\n",
                              (3 * i + x ) * 81 + (3 * j + y) * 9 + z,
                              (3 * i + k ) * 81 + (3 * j + l) * 9 + z);
                        }
}
  for(i=0;i<9;i++)
    for(j=0;j<9;j++) {
    if (shudu[i][j] != 0)
      fprintf(fp, "%d 0\n",i*81+j*9+shudu[i][j]);
    }
  fclose(fp);
  return OK;
}
//����Ƿ����������Ϸ
int check(int shudu[9][9])
{
  for (int i = 0; i < 9; i++)
    for (int j=0; j < 9; j++)
      if (shudu[i][j] == 0)
        return FALSE;
  return OK;
}