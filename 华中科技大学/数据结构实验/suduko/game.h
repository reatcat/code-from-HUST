void output_sudoku(int temp[9][9]) {
  int i, j;
  //数独输出到屏幕
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

//使数独全部清零
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
        0);  //如果数独生成失败，返回结果为0，则清空sudo数组，继续再试直到成功
  }
  return OK;
}
int get_sudoku(int temp[SIZE][SIZE]) {
  int i, j, m, random;
  random = rand() % SIZE + 1;  //随机生成数独第一行第一列的数  //循环每一行
  for (i = 0; i < SIZE; i++) {
    //循环每一列
    for (j = 0; j < SIZE; j++) {
      m = 0;
      //判断此随机数是否能够使用,如果能使用跳出循环，否则继续循环
      while (check_sudoku(temp, i, j, random) == 0) {
        random = rand() % SIZE + 1;  //生成一个0-SIZE的随机数
        m++;
        //如果同一个位置失败一百次，则重新开始
        if (m > 80)
          return 0;
      }
      temp[i][j] = random;  //此数已经通过检查，放入数独
    }
  }
  return 1;
}
//判断是否可以将第i行、第j列的数设为k
int check_sudoku(int temp[SIZE][SIZE], int i, int j, int k) {
  int m, n;
  //判断行
  for (n = 0; n < SIZE; n++) {
    if (temp[i][n] == k)
      return 0;
  }
  //判断列
  for (m = 0; m < SIZE; m++) {
    if (temp[m][j] == k)
      return 0;
  }
  //判断所在九宫格
  int t1 = (i / 3) * 3, t2 = (j / 3) * 3;
  for (m = t1; m < t1 + 3; m++) {
    for (n = t2; n < t2 + 3; n++) {
      if (temp[m][n] == k)
        return 0;
    }
  }
  return 1;
}
//挖洞
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
    printf("打开文件失败\n");
    return 0;
  }
  int litnum=729, claunum=7533+2916+81-dignum;
  fprintf(fp, "p %d %d\n", litnum, claunum);
  int i, j, k, m;
  //行约束
  //每行都有1-9
  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++) {
    for (k = 1; k <= 9; k++) {
         fprintf(fp, "%d ", (i-1)*81 +(j-1)*9 + k);//每一个空格都可以填1-9个数
              
        }fprintf(fp, "0\n");
    };
    
  }  //每一行
//729
  //不能同时有两个数字
for ( i = 1; i <= 9; i++) {  //每一行
    for (j = 1; j <= 9; j++) {
      for (k = 1; k <= 9; k++) {
        for (m = 1; m + j <= 9; m++) {
            fprintf(fp, "-%d -%d ", 
                (i - 1) * 81 + (j - 1) * 9 + k,(i - 1) * 81 + (j - 1+m) * 9 + k);  //每一个空格都可以填1-9个数
      fprintf(fp, "0\n");}
        }
      
        
    }
  }
for (i = 1; i <= 9; i++) {  //每一行
  for (j = 1; j <= 9; j++) {
    for (k = 1; k <= 9; k++) {
      for (m = 1; m + k <= 9; m++) {
        fprintf(
            fp, "-%d -%d ", (i - 1) * 81 + (j - 1) * 9 + k,
            (i - 1) * 81 + (j - 1 ) * 9 + k+m);  //每一个空格都可以填1-9个数
        fprintf(fp, "0\n");
      }
    }
  }
}
//列约束
  for (k = 1; k <= 9; k++) {  //每一列
      for (j = 1; j <= 9; j++) {
      for (i= 1; i <= 9; i++)
        fprintf(fp, "%d ",
                (i-1)*81+ (j-1)*9 + k);  //每一个空格都可以填1-9个数
      fprintf(fp, "0\n");
    }
  }//729

for (k= 1; k <= 9; k++)
     {  //每一行
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
//检查是否完成数独游戏
int check(int shudu[9][9])
{
  for (int i = 0; i < 9; i++)
    for (int j=0; j < 9; j++)
      if (shudu[i][j] == 0)
        return FALSE;
  return OK;
}