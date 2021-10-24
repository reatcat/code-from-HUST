#pragma once
#define MAXSIZE 3500
typedef struct {
  int elem[MAXSIZE];
  int length;
} Stack;

void InitStack(Stack* S)  //��ʼ��ջ
{
  S->length = 0;  //�˴���ջ����Ϊ-1��top��ָ��ļ�Ϊջ����Ԫ��
}
void DestoryStack(Stack* S) {
  memset(S->elem, 0, sizeof(int) * 3500);
  S->length= -1;
}
void Push(Stack* S, int a)  //��Ԫ����ջ
{
  S->length++;
  S->elem[S->length] = a;
}
void Pop(Stack* S, int* e)  //��Ԫ�س�ջ������ֵ��e
{
  *e = S->elem[S->length];
  S->length--;
}
//����Ϊ����ĺ���������ûʲô�ã�
int StackEmpty(Stack* S)  //�ж�ջ����ջ��
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
int searchtop(Stack* S)  //��ѯջ����Ԫ��
{
  return S->elem[S->length];
}