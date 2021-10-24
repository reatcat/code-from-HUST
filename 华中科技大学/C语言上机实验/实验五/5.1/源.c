#include<stdio.h>
#include<string.h>
#define temp 0x0000 
void reverse(char a[]);
int main()
{
	int  n, i;
	char a[32] = { 0 };
	scanf_s("%d", &n);
	if (n < 0)
	{
		n = -n;
		for (i = 0; n > 0; i++) {
			a[i] = n % 2 + '0';
			n /= 2;
		}
		reverse(a);
		a[0] = 1;
		for (i = 1; i < 32; i++)
			if (a[i])
				a[i] = 0;
			else a[i] = 1;
	}
	else {
		for (i = 0; n > 0; i++) {
			a[i] = n % 2 + '0';
			n /= 2;
		}
		reverse(a);
	}
	for (i = 0; i < 32; i++) {
		printf("%c", a[i]);
		if ((i + 1) % 4 == 0)
			printf(" ");
	}

	return 0;
}
void reverse(char a[])
{
	int len = 32;
	int c, j, k;
	for (j = 0, k = 31; j < k; j++, k--)
		c = a[j], a[j] = a[k], a[k] = c;
}