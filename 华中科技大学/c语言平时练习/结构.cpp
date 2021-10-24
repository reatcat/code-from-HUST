#include<stdio.h>
#include<string.h>
void sort(struct web webs[],int n);

struct web  /*  设计表示网址的结构  */
{
    /**********  Begin  **********/
  char a[5];
  char b[50];
  char c[50];

	/**********   End   **********/
};

#define N  4      /*  网址表大小  */

int main()
{
	/**********  Begin  **********/
int i;
struct web w[N];
for(i=0;i<N;i++)
{
scanf("%s",w[i].a);
scanf("%s",w[i].b);
scanf("%s",w[i].c);
}
char d[5];
scanf("%s",d);
sort(w,N);
for(i=0;i<N;i++)
{
    printf("%s %s %s\n",w[i].a,w[i].b,w[i].c);
}
int j=0;
	for(i=0;i<N;i++)
{
	if(d[0]==w[i].a[0])
	{
		printf("%s\n",w[i].c);
}
else j++;
}
if(j==4){
	printf("未找到搜寻的网址");
}

	/**********   End   **********/
	return 0; 

}

void sort(struct web webs[],int n)
{
	/**********  Begin  **********/
struct web *p=webs;
	struct web temp;
int i,j;
for(i=0;i<N-1;i++){
    for(j=0;j<N-i-1;j++)
    {
        if((strcmp((p+j)->a,(p+j+1)->a)>0))
        {
            temp=*(p+j);
            *(p+j)=*(p+j+1);
            *(p+j+1)=temp;
            
        }
    }
}



	/**********   End   **********/
}
