#include<stdio.h>
#include<string.h>
int main()
{
	int p1,p2,p3;
	scanf("%d %d %d\n",&p1,&p2,&p3);
	char a[5000];
	gets(a);
	int i=0,j=0,l,t;
	l=strlen(a);
	  for(i=0;i<l;i++)
	   {
	   	if(i==0&&a[i]=='-')
	   	printf("-");
	   	else if(a[i-1]=='-'&&a[i]=='-')
	   	printf("-");
	   	else if(i==l-1&&a[i]=='-')
	   	printf("-");
        else if(a[i]!='-')
        {
        printf("%c",a[i]);	
		}
       	else 
		   {
		   	if(a[i-1]>=a[i+1]||(a[i-1]-'a'<0&&a[i+1]-'a'>=0)||(a[i-1]-'a'>=0&&a[i+1]-'a'<0))
		   printf("-");
		   else if(a[i-1]+1!=a[i+1])
		   {
		   if(p1==1)
		   {
		   	 if(p3==2)//����
             {
            if(a[i+1]<='9'&&a[i+1]>='0')//ǰ��Ϊ����
            {
                for(t=a[i-1]+1;t<a[i+1];t++)
            {
                for(j=0;j<p2;j++)
            {
                printf("%c",t);
                        }
                }
                }
                        else//ǰ��Ϊ��ĸ
                        {
                            for(t=a[i+1]-1;t>a[i-1];t--)
                            {
                                for(j=0;j<p2;j++)//ע�����
                                {
                                    printf("%c",t);
                                }    
                            }
                        }
                    }
                    else//�������
                    {
                        for(t=a[i-1]+1;t<a[i+1];t++)
                        {
                            for(j=0;j<p2;j++)
                            {
                                printf("%c",t);
                            }
                        }
                    }
		   }
		   
	  		if(p1==2)    
                {
                    if(p3==2)
                    {
                        if(a[i+1]<='9'&&a[i+1]>='0')
                        {
                            for(t=a[i+1]-1;t>=a[i-1]+1;t--)
                            {
                                for(j=0;j<p2;j++)
                                {
                                    printf("%c",t);
                                }
                            }
                        }
                        else
                        {
                            for(t=a[i+1]-'a'+'A'-1;t>a[i-1]-'a'+'A';t--)//�ĳɴ�д��ĸ
                            {
                                for(j=0;j<p2;j++)
                                {
                                    printf("%c",t);
                                }
                            }
                        }
                    }
                    else
                    {
                        for(t=a[i-1]-'a'+'A'+1;t<a[i+1]-'a'+'A';t++)
                        {
                            for(j=0;j<p2;j++)
                            {
                                printf("%c",t);
                            }
                        }
                    }
                }
                if(p1==3)//����Ǻ�
                {
                    for(t=a[i-1]+1;t<a[i+1];t++)
                    {
                        for(j=0;j<p2;j++)
                        {
                            printf("*");
                        }
                    }
                }
            }
            }
        }
	return 0;
}
