#include <stdio.h>
#include <string.h>
#define MAX 100
void getpost(char pre[], char in[], int n) {  
    if(n == 0) return;  
    char root = pre[0];  
    int i;  
    for(i = 0; i < n; i++) {  
        if(in[i] == root) {//���ڵ� 
            break;  
        }  
    }    
    getpost(pre + 1,in,i);//�������� 
    getpost(pre + i + 1, in + i + 1, n - i - 1); //�������� 
    printf("%c",root);//�ҵ����ڵ㲢�������
    return;
}  
int main() {  
    char pre[MAX], in[MAX];  
    int n;  
	scanf("%s",in); 
    scanf("%s",pre);
      
    n=strlen(pre); 
    getpost(pre, in, n);  
    return 0;  
} 
