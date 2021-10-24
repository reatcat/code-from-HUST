/******************************************************************
 在下面编写带参 main0 函数，实现字符串的连接，字符串由命令行给出；
 连接之后的新串无冗余地存储到用`malloc`动态分配的空间，并将该空间首地址赋值给外部指针`p`。
 
 将本地调试通过的 main 改为 main0，可能需要按题目要求作适当修改，
 比如，这里的 main0 只完成连接操作，不需要输出数据。
 ******************************************************************/
 
extern char *p;    // 外部指针的引用性声明，p指向连接后的串
#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main( int argc, char *argv[])
{
    int i;
  /**********  Begin  **********/
  if(argc>=4){
      
    
    p=(char *)malloc(sizeof(char));
    memset(p,'\0',50);
    for(i=2;i<argc;i++)
    strcat(p,argv[i]);
    		
	
	
    printf("%s",p);
      
      }
      return 0;
}



  /**********  End  **********/


