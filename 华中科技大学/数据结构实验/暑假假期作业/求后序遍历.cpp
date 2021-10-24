#include <stdio.h>
#include <string.h>
#define MAX 100
void getpost(char pre[], char in[], int n) {  
    if(n == 0) return;  
    char root = pre[0];  
    int i;  
    for(i = 0; i < n; i++) {  
        if(in[i] == root) {//根节点 
            break;  
        }  
    }    
    getpost(pre + 1,in,i);//找左子树 
    getpost(pre + i + 1, in + i + 1, n - i - 1); //找右子树 
    printf("%c",root);//找到根节点并进行输出
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
