#include <stdio.h>
#include <string.h>
void post(char pre[], char in[], int n) {
    if (n == 0) return;
    char root = pre[0];
    int i;
    for (i = 0; i < n; i++) {
        if (in[i] == root) {
            printf("%c", root);
            break;
        }
    }
    post(pre + 1, in, i);//ÕÒ×ó×ÓÊ÷ 
    post(pre + i + 1, in + i + 1, n - i - 1); //ÕÒÓÒ×ÓÊ÷ 

    return;
}
int main() {
    char pre[40], in[40];
    int n;
    scanf("%s", pre);
    scanf("%s", in);
    n = strlen(pre);
    post(pre, in, n);
    return 0;
}