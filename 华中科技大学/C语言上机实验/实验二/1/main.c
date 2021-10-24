#include<stdio.h>

int main()
{
	/**********  Begin  **********/
    char c;
    int  num[10]={0},letter[26]={0},i,others=0;
    while((c=getchar)!='\n')
    {
        if(c>='0'&&c<='9'){
            num[c-'0']++;
        }
        if(c>='a'&&c<='z'){
            letter[c-'a']++;
        }
        if(c>='A'&&c<='Z'){
            letter[c-'A']++;
        }
        else others++;
    }
    for(i=0;i<10;i++){
        if(num[i]>0){
        printf("%d:%d\n",i,num[i]);
    }
    }
    for(i=0;i<26;i++){
        if(letter[i]>0){
        printf("%c:%d",i+'A',letter[i]);
    }

    }
    printf("others:%d",others);
	/**********  End  **********/
	return 0;
}
