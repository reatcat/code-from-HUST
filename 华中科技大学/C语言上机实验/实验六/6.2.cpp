#include<stdio.h>
#include<string.h>
int RemoveSame(int a[],int n)
{
	int k,i=1,j=1,len=1;
	k=*a;
	for(i=1;i<n;i++){
		if(k!=*(a+i)){
			len++;
			*(a+j)=*(a+i);
			j++;
			k=*(a+i);
		}
	}
	return len;
 } 
 int main()
 {
 	int a[10],i;
     int n;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
 	i=RemoveSame(a,n);
     int j=0;
     for(j=0;j<i;i++)
     {
     	printf("%d ",a[j]);
	 }
     
     printf("\n");
 	printf("%d",i);
 	return 0;
 }
