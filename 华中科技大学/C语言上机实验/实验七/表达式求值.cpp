#include<stdio.h>
int main()
{
	char u[]="UVWXYZ",v[]="xyz";
	struct T{
		int x;
		char c;
		char *t;
	}a[]={{11,'A',u},{100,'B',v}},*p=a; 
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("100");break;
		case 2:printf("B");break;
		case 3:printf("x");break;
		case 4:printf("x");break;
		case 5:printf("V");break;
		case 6:printf("V");break;
	}
	return 0;
 } 
