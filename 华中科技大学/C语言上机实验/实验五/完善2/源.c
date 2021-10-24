#include<stdio.h>
#define M 10
#define N 3
int main(void)
{
	int a[M], b[M];
	int i, j, k;
	for (i = 0;i < M;i++)
		a[i] = i + 1;
	for (i = M, j = 0;i > 2;i--) {
		for (k = 1;k <= N;k++)
			if (++j > i - 1) j = 0;

	}
}