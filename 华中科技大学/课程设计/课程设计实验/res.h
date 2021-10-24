#pragma once
int ResWrite(int res, double time, SqList& An, char filename[]) {
  int i = 0;
  while (filename[i] != '\0')
    i++;
  filename[i - 3] = 'r';  //只改变文件的扩展名
  filename[i - 2] = 'e';
  filename[i - 1] = 's';
  FILE* fp;
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("打开文件失败\n");
    return ERROR;
  }
  fprintf(fp, "s %d\n", res);  // res是求解结果，1表示满足，0表示不满足，-1未定
  fprintf(fp, "v ");
  for (i = 1; i < An.length; i++) {
    if (An.elem[i] == -1)
      fprintf(fp, "%d ", -i);
    else
      fprintf(fp, "%d ", i);
  }
  fprintf(fp, "\nt %f\n", time);
  fclose(fp);
  return OK;
}
int sudures(SqList& An, char filename[],int beifen[9][9]) {
  int i = 0;
  while (filename[i] != '\0')
    i++;
  filename[i - 3] = 'r';  //只改变文件的扩展名
  filename[i - 2] = 'e';
  filename[i - 1] = 's';
  FILE* fp;
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("打开文件失败\n");
    return ERROR;
  }
  int xin[9][9];
  for (i = 1; i < An.length; i++) {
    if (An.elem[i] == 1) {
      for(int row=0;row<9;row++)
        for (int cal = 0; cal < 9; cal++) 
        for (int k = 1; k <= 9; k++) {
            //        if ((i==row*81+cal*9+k)&&k==beifen[row][cal])
          if ((i == row * 81 + cal * 9 + k))
            //             fprintf(fp, "第%d行第%d列该填入的数为：%d \n", row +
            //             1, cal + 1,
            //                 k);
            xin[row][cal] = k;
          }
        
    }
      
  }
  int  j;
  //数独输出到屏幕
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (j % 3 == 0)
        fprintf(fp,"|");
      if (xin[i][j] != 0)
        fprintf(fp,"%d ", xin[i][j]);
      else {
        fprintf(fp,"_ ");
      }
      if (j == 8)
        fprintf(fp,"\n");
    }
    if ((i + 1) % 3 == 0)
      fprintf(fp,"--------------------\n");
  }
  fclose(fp);

  return OK;
}
