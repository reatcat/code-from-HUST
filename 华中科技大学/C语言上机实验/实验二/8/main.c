#include <stdio.h>
#include <string.h>
void code(char* ch, int k);
void changeChar(char* p1,char* p2);
void code(char* ch, int k){
    if('A' <= *ch && *ch <= 'Z'){
        *ch += (k - 1);
         if(!('A' <= *ch && *ch <= 'Z')){
            *ch -= 26;
        }
    }
}


void changeChar(char* p1,char* p2){
    char temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main(void){
    char sentence[81];
    gets(sentence);
    int length = strlen(sentence);
    int k,i;
    scanf("%d",&k);

    for( i = 0;i < length;i++){
        code(sentence + i,k);
    }

    for( i = 0;i < length - 1;i += 2){
        changeChar(sentence + i,sentence + i + 1);
    }

    puts(sentence);

    return 0;
}

