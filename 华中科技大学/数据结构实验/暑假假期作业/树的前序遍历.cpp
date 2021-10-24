#include <stdio.h>
#include <string.h>
char inorder[20], post[20];//为了在子函数中使用 
void dfs(int infirst,int inlen,int pofirst,int postlen) 
{
	if(infirst>inlen||pofirst>postlen)// 
	return ;
    printf("%c", post[postlen]);
    for (int k = infirst; k <= inlen; k++) {
        if (inorder[k] == post[postlen]) 
		{
            dfs(infirst, k-1,pofirst,pofirst+k-infirst-1);
            dfs(k+1, inlen,pofirst+k-infirst,postlen-1);
            break; 
        }
    }
}
int main() 
{
    scanf("%s",inorder);
    scanf("%s",post);
    int len=strlen(inorder)-1;
    dfs(0,len,0,len);// 
    return 0;    
}
