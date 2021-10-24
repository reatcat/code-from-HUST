#include<stdio.h>
#include<string.h>
double fun(int a,int n,double x)
{
//	int l=0,i,j,b;
//	double temp=1.0,sum=0;
//	 int a[50];
//	 for(j=2;j<=n;j++)
//	 {	b=0;
//	 	for(i=2;i<j;i++){
//	 	
//        if(j%i==0)
//            b++;
//	 }
//	 if(b==0) a[l++]=j;//找到所有的素数，存到a中 
//    }
//    for(i=0;i<l;i++)
//    {
////    	printf("%d\t",a[i]);
//    	temp=1.0;
//    	for(j=0;j<=i;j++)
//		 temp*=(-x);
//		 
//		 sum+=temp/a[i];
//	}
int i=0,j;
int temp0=0;
double temp,sum=0;
    for(i=0;i<n;i++)
    {
    	temp=1.0;
    	for(j=0;j<=i;j++){
    		 temp*=(x);
    		 temp0=10*temp0+a;
		}
		 sum+=temp/temp0;}
  return sum;

}
int main()
{
 int n,a;
 double  x;
 double s;
 scanf("%d %d %lf",&a,&n,&x);
// 	 int a[50];
// l=primeNumbers(a,n); 
// for(i=0;i<l;i++)
// {
// 	printf("%d\t",a[i]);
// }
s=fun(a,n,x);
printf("%lf",s); 
 return 0;
}
