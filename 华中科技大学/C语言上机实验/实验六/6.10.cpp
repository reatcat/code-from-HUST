#include <stdio.h>
int main()
{
	int a[200] = {0},b[200] = {0},c[400]={0} ;	
	char sa[200],sb[200];			
	int i,j;
	for(i=0;i<200;i++)
	sa[i]=sb[i]='0';
	int m = 0,n = 0;							
	scanf("%s %s",sa,sb);							
	while(sa[m]!='\0')						
	{
		a[m] = sa[m] - '0';
		m++;
	}
	while(sb[n] != '\0')
	{
		b[n] = sb[n] - '0';
		n++;
	} //得到ab的长度，位数 
	for(j = 0;j <1+n;j++)						
	{
		for(i = 0;i <1+ m;i++)
		{
			c[i + j + 1] += a[j] * b[i];//依照位数相乘，并且存放到相应位 
		}
	}
	for(i = m + n+1;i >= 0;i--)	
	{
		if(c[i] > 9)
		{
			c[i - 1] += c[i] / 10;
			c[i] %= 10;
		}
	} 
	i = 0;
	if(c[0] == 0)						
	{
		for(i = 1;i < m + n;i++)
		{
			printf("%d",c[i]);
		}
	}
	else
	{
		for(i = 0;i < m + n;i++)
		{
		printf("%d",c[i]);
		}
	}
	return 0;
}

