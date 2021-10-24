#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dec(int n)
{
    int flag=0,k,i=2;
     k=sqrt(n);
     if(n!=2){
        do{
            if(n%i==0)
                flag=1;
            i++;
        }while(i<k);
     }

    return flag;
}
int main()
{
    int n=100,flag,a;
    while(n<1000){
           flag=dec(n);
        if(flag==1)
        {
            a=n/10;
        flag=dec(a);
        if(flag==1){
                a=a/10;
         flag=dec(a);
         if(flag==1){
            printf("%d\t",n);
            }
            }
            }
            n++;
    }
    return 0;
}
