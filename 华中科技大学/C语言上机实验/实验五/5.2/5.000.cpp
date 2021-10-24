#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sca();
void paixu();
void pri();
int cha();
char a[100][100],b[100];
int n;
 int main()
{
    int c;
    scanf("%d",&c);
    while(c>0)//菜单选择
    {
       if(c==1)
       sca();
       else if(c==2)
       paixu();
       else if(c==4)
       {
           int temp;
           temp=cha();
           if(temp==0)
           printf("not found");

           break;
       }
       else if(c==3)
       {
        pri();
        break;//输出之后没有菜单选择
       }
      
        scanf("%d",&c);
    }
   return 0;

}
void sca()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&a[i][0]);//每行输入一个名字
		scanf("%d",&b[i]); 
	}
}
void paixu()
{
	int i,j,t;
	char c[20]={'\0'};//终止符
    for(i=0;i<n-1;i++)//冒泡排序法
	{
		for(j=0;j<n-i-1;j++)
		{
			if(b[j]<b[j+1])
			{
                t=b[j],b[j]=b[j+1],b[j+1]=t;
			    strcpy(c,a[j]);//将姓名交换
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],c);
               char c[20]={'\0'};
            }
            if(b[j]==b[j+1])
            {
                if(a[j][0]>a[j+1][0])//姓名首字母比较
                {
                    strcpy(c,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],c);
                   char c[20]={'\0'};
                }
                else if(a[j][0]=a[j][0])
                {
                    if(a[j][1]>a[j][2])
                    {
                        strcpy(c,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],c);
                   char c[20]={'\0'};
                    }
                }

            }
		}
    }
}
void pri()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",a[i],b[i]);
    }
}
int cha()
{
	int m,mid,fro=0,bac=n-1;
	scanf("%d",&m);
	//二分法 
	while(fro<=bac){
     mid=(fro+mid)/2;
     if(m<b[mid]){
         bac=mid-1;
     }
     else if(m>b[mid]){
         fro=mid+1;}
         else {
           
           if(b[mid]==b[mid+1]){
             printf("%s %d",a[mid],b[mid]);
              printf("\n");
               printf("%s %d",a[mid+1],b[mid+1]);
               return 1;
           }
           else {
              printf("%s %d",a[mid],b[mid]) ;
              return 1;
           }
         }
    
    }
    return 0;
}


