#include<stdio.h>
int main()
{
	int n;
 while(scanf("%d", &n) && n) (n & 1) ? printf("Bob\n") : printf("Alice\n");
	return 0;
 } 
