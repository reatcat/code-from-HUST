//preorder and postorder,先序和中序求后序
#include <cstdio>
#include <iostream>
using namespace std;
void getpost(char *pre, char *in, int n) {  
    if(n == 0) return;  
    char root = pre[0];  
    int i;  
    for(i = 0; i < n; i++) {  
        if(in[i] == root) {  
            break;  
        }  
    }    
    getpost(pre + 1,in,i);//找左子树 
    getpost(pre + i + 1, in + i + 1, n - i - 1); //找右子树 
    cout << ' ' << root; 
    return;
}  
int main() {  
    char pre[40], in[40];  
    int n;  
    cin >> n;  
    int i, j;  
    for(i = 0; i < n; i++) {  
        scanf("%c", &pre[i]);  
    }  
    for(i = 0; i < n; i++) {  
        scanf("%c", &in[i]);  
    }  
    printf("Postorder:");  
    getpost(pre, in, n-1);  
    printf("\n");  
    return 0;  
} 
