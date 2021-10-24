#include <stdio.h>
#include <math.h>

int main(){
   /* unsigned long IP;
    while (scanf("%lu", &IP) != EOF){
        int decIP[4] = {0, 0, 0, 0};
        int i=0;
        for ( i = 0; i < 32; i++){
            int current = i / 8;
            int digit = IP & 1;
            IP = IP >> 1;
            decIP[current] += digit * pow(2, i - 8 * current);
        }

        printf("%d.%d.%d.%d", decIP[3], decIP[2], decIP[1], decIP[0]);
    }*/
     unsigned long IP,a,b,c,d;
    while (scanf("%lu", &IP) != EOF){
        a=IP>>24;
        b=(IP<<8)>>24;
        c=(IP<<16)>>24;
        d=(IP<<24)>>24;
        printf("%lu.%lu.%lu.%lu",a,b,c,d);
    }
    return 0;
}
