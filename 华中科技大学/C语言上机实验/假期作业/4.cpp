#include<stdio.h>
int main(){
	int i,x;
	int j = 0 ;
	int c[8];
	int a,b;
	for (i = 1;i < 8 ;i++){
		scanf("%d %d",&a,&b);
		c[i] = a + b ;
	} 
	for (i=1;i<8;i++) {
		if (c[i]>8) {
			x=i ;
			break;
		} else {
			j++ ;
		}
	}
	if ( j == 7 ) {
		printf("0\n");
	} else {
		printf("%d\n",x);
	}
	return 0;
}
