#pragma once
#define MAXSIZE 3500
typedef struct {
  int elem[MAXSIZE];
  int length;
} Stack;

void InitStack(Stack* S)  //初始化栈
{
  S->length = 0;  //此处将栈的置为-1，top所指向的即为栈顶的元素
}
void DestoryStack(Stack* S) {
  memset(S->elem, 0, sizeof(int) * 3500);
  S->length= -1;
}
void Push(Stack* S, int a)  //将元素入栈
{
  S->length++;
  S->elem[S->length] = a;
}
void Pop(Stack* S, int* e)  //将元素出栈，并赋值给e
{
  *e = S->elem[S->length];
  S->length--;
}
//以下为补充的函数（可能没什么用）
int StackEmpty(Stack* S)  //判断栈空与栈满
{
  if (S->length == 0)
    return 1;
  else
    return 0;
}
int StackFull(Stack* S) {
  if (S->length
      == MAXSIZE - 1)
    return 1;
  else
    return 0;
}
int searchtop(Stack* S)  //查询栈顶的元素
{
  return S->elem[S->length];
}