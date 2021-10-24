# include<stdio.h>
# include<string.h>
# include<math.h>
void strnins(char t[],char s[],int n);
int main(){
char s[200];
char t[200];
int n,i=0;
scanf("%s",t);
scanf("%s",s);
scanf("%d",&n);
strnins(t,s,n);


    printf("%s",t);

return 0;
}

void strnins(char t[],char s[],int n)
{
  int i,j,a;
  char temp[200];
  i=strlen(s);
  j=strlen(t);
  if(n<j){
  	 for(a=0;a<j-n+1;a++)
{
    temp[a]=t[n+a];
}
for(a=0;a<i;a++){
    t[n+a]=s[a];
}
strcat(t,temp);
  }
 else strcat(t,s);
}
