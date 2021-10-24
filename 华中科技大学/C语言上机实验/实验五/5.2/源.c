#include<stdio.h>
int main()
{
	char name[100];
	int score[100];
	int k;
	for (k = 0;k < 2;k++)
		scanf_s("%s%d", &name[k], &score[k]);
	int i,j,t;
	char s;
	for (i = 0;i < k - 1;i++)
	{
		for(j=0;j<k-i-1;j++)
			if (score[j] < score[j + 1])
			{
				t = score[j], score[j] = score[j + 1], score[j] = t;
				s = name[j], name[j] = name[j + 1], name[j] = s;
			}
	}
	for (i = 0;i < k;i++)
	{
		printf("%s %d", name[i], score[i]);
	}
}