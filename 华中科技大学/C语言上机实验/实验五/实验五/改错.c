#include<stdio.h>
void strcate(char[], char[]);
void strdelc(char[], char c);//�����ַ�
int main(void)
{
	char a[] = "Language", b[] = "Programming";
	printf("%s  %s\n", b, a);
	strcate(b, a);
	printf("%s  %s\n", b, a);
	strdelc(b,'a');//��Ϊ�ַ�
	printf("%s\n", b);
	return 0;
}
void strcate(char t[], char s[])
{
	int i = 0, j = 0;
	while (t[i]!='\0')  i++;
	while ((t[i++] = s[j++]));//�ַ���������ı�־
}
void strdelc(char s[], char c)
{
	int j=0, k=0;
	while(s[j])
	{
		if (s[j] != c)
			s[k++] = s[j];
		j++;
	}
	s[k] = '\0';
}