#include<stdio.h>
void f0(int b)
{
	printf("the function %d is called!\n", b);
}
void f1(int b)
{
	printf("the function %d is called!\n", b);
}
void f2(int b)
{
	printf("the function %d is called!\n", b);
}
void f3(int b)
{
	printf("the function %d is called!\n", b);
}
void f4(int b)
{
	printf("the function %d is called!\n", b);
}
void f5(int b)
{
	printf("the function %d is called!\n", b);
}
void f6(int b)
{
	printf("the function %d is called!\n", b);
}
void f7(int b)
{
	printf("the function %d is called!\n", b);
}
int main()
{
	struct bits {
		unsigned char bit0 : 1;
		unsigned char bit1 : 1;
		unsigned char bit2 : 1;
		unsigned char bit3 : 1;
		unsigned char bit4 : 1;
		unsigned char bit5 : 1;
		unsigned char bit6 : 1;
		unsigned char bit7 : 1;
	}fun;
	void (*p_fun[8])(int b);
	int i;
	p_fun[0] = f0;
	p_fun[1] = f1;
	p_fun[2] = f2;
	p_fun[3] = f3;
	p_fun[4] = f4;
	p_fun[5] = f5;
	p_fun[6] = f6;
	p_fun[7] = f7;
	short tell;
	scanf("%d", &tell);
	int a[8] = { 0 };
	for (i = 0;tell > 0;i++) {
		a[i] = tell % 2;
		tell /= 2;
	}
	fun.bit0 = a[7];
	fun.bit1 = a[6];
	fun.bit2 = a[5];
	fun.bit3 = a[4];
	fun.bit4 = a[3];
	fun.bit5 = a[2];
	fun.bit6 = a[1];
	fun.bit7 = a[0];
	if (fun.bit0)
		p_fun[0](1);
	if (fun.bit1)
		p_fun[1](2);
	if (fun.bit2)
		p_fun[2](3);
	if (fun.bit3)
		p_fun[3](4);
	if (fun.bit4)
		p_fun[4](5);
	if (fun.bit5)
		p_fun[5](6);
	if (fun.bit6)
		p_fun[6](7);
	if (fun.bit7)
		p_fun[7](8);
	return 0;
}