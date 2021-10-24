//#include<stdio.h>
//#include<string.h>
//#include <stdlib.h>
//struct a{
//	char b;
//	struct a *next;
//};
//int main()
//{
//	char *n;
//	int i;
//	char c;
//	struct a  *head,*tail,*p;
//	p=head=tail=(struct a*)malloc(sizeof(struct a));
//	head=p;
//	while((c=getchar())!='\n')
//	{
//		p->b=c; 
//		p->next=(struct a*)malloc(sizeof(struct a));
//		p=p->next;
//		tail=p;
//	}
//	char tell;
//	scanf("%c",&tell);
//	p=head;
//    int j;
//    for(j=0;j<i;j++)
//    {
//    	printf("%c",p);
//    	p=p->next;
//	}
// 	p=head;
// 	int flag=0;
// 	for(j=0;j<i;j++)
// 	{
// 		if(p->b!=tell)
// 		p=p->next;
// 		else{
// 			flag=1;
// 			p=p->next;
//		 }
//	 }
//	 p=head;
//	 if(flag==1)
//	 {
//	 	for(j=0;j<i;j++)
//	 	{
//	 		if(p->b==tell)
//	 		p=p->next;
//	 		else {
//	 			printf("%c",p->b);
//	 			p=p->next; 
//			 }
//		 }
//	  }
//	  else
//	  {
//	  	struct a *node;
//	  	int m,n=0xffff;
//	  	for(j=0;j<i;j++)
//	  	{
//	  		if(p->b-tell<0)
//			  m=tell-p->b;
//			  else m=p->b-tell;
//			  if(m<n)
//			  {
//			  	n=m;
//			  	node=p;
//			  }
//			   p=p->next;
//		  }
//		  p=head;
//		  for(j=0;j<i;j++)
//		  {
//		  	if(p!=node)
//		  	{
//		  		printf("%c",p->b);
//		  		p=p->next;
//		  		
//			  }
//			  else {
//			  	printf("%c%c",p->b,tell);
//			  	p=p->next;
//			  }
//		  }
//	   } 
//	return 0;
// } 
//#include <stdio.h>
//#include <stdlib.h>
//struct str{
//    char b;
//    struct str *next;
//};
//int main()
//{
//    struct str *head,*p,*tail;
//    char c;
//    char tell;
//    int i=0;
//    tail=p=head=(struct str *)malloc(sizeof(struct str));
//    while((c=getchar())!='\n')
//    {
//        p->next=(struct str *)malloc(sizeof(struct str));
//        p->b=c;
//        p=p->next;
//        tail=p;
//        i++;
//    }
//    scanf("%c",&tell);
//    int j;
//    p=head;
//    for(j=0;j<i;j++)
//    {
//        if(j<i-1)
//        printf("%c ",p->b);
//        else
//        printf("%c\t",p->b);
//        p=p->next;
//    }
//    p=head;
//    for(j=0;j<i;j++)
//    {
//        printf("%c",p->b);
//        p=p->next;
//    }
//    p=head;
//    int flag=0;
//    for(j=0;j<i;j++)
//    {
//        if(p->b!=tell) p=p->next;
//        else {flag=1;
//        p=p->next;}
//    }
//    p=head;
//    if(flag==1)
//    {
//        for(j=0;j<i;j++)
//        {
//            if(p->b==tell) p=p->next;
//            else {printf("%c",p->b);
//            p=p->next;}
//        }
//    }
//    else
//    {
//        struct str *node;
//        int m,n;
//        for(j=0;j<i;j++)
//        {
//            if(p->b-tell<0) m=tell-p->b;
//            else m=p->b-tell;
//            if(m<n)
//			 {
//			 n=m;
//			 node=p;
//			 }
//            p=p->next;
//        }
//        p=head;
//        for(j=0;j<i;j++)
//        {
//            if(p!=node)
//            {
//			printf("%c",p->b);
//            p=p->next;
//			}
//            else
//			{
//			printf("%c%c",p->b,tell);
//            p=p->next;
//			}
//        }
//    }
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>
struct str{
    char c;
    struct str *next;
};
int main()
{
    struct str *head=NULL;
    struct str *p=NULL;
    struct str *end=NULL;
    char data='0';
    char tell;
    int i=0;
    head=(struct str *)malloc(sizeof(struct str));
    end=(struct str *)malloc(sizeof(struct str));
    p=(struct str *)malloc(sizeof(struct str));
    head=p;
    while(data!='\n')
    {
        p->next=(struct str *)malloc(sizeof(struct str));
        scanf("%c",&data);
        p->c=data;
        p=p->next;
        end=p;
        i++;
    }
    scanf("%c",&tell);
    int j;
    p=head;
    for(j=0;j<i;j++)
    {
        if(j<i-1)
        printf("%c ",p->c);
        else
        printf("%c",p->c);
        p=p->next;
    }
    p=head;
    for(j=0;j<i;j++)
    {
        printf("%c",p->c);
        p=p->next;
    }
    p=head;
    int flag=0;
    for(j=0;j<i;j++)
    {
        if(p->c!=tell) p=p->next;
        else {flag=1;
        p=p->next;}
    }
    p=head;
    if(flag==1)
    {
        for(j=0;j<i;j++)
        {
            if(p->c==tell) p=p->next;
            else {printf("%c",p->c);
            p=p->next;}
        }
    }
    else
    {
        struct str *node=NULL;
        int m,n=0xFFFF;
        for(j=0;j<i;j++)
        {
            if(p->c-tell<0) m=tell-p->c;
            else m=p->c-tell;
            if(m<n) {n=m;node=p;}
            p=p->next;
        }
        p=head;
        for(j=0;j<i;j++)
        {
            if(p!=node)
            {printf("%c",p->c);
            p=p->next;}
            else{printf("%c%c",p->c,tell);
            p=p->next;}
        }
    }
    return 0;
}
