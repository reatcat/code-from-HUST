//#include<stdio.h>
//int main()
//{
//	int month,day;
//	scanf("%d-%d",&month,&day);
//	int n;
//	if(month>12&&day>31) n=2;
//	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)//31
//	{
//		if(day>31||day<=0)
//		n=1;
//	}
//	else if(month==4||month==6||month==9||month==11)//30
//    {
//        if(day>30||day<=0)
//        n=1;
//    }
//    else if(month==2)//28
//    {
//        if(day>28||day<=0)
//        n=1;
//    }
//    printf("%d",n);
//	return 0;
//}
#include<stdio.h>
int main()
{
    int month,day,n=1;
    scanf("%d-%d",&month,&day);
    if((month>12||month<=0)&&(day>31||day<=0))
    n=2;  
    else if(month>12||month<=0)//出现99-31的情况 
    {
    	if(day==31)
    	{
		month=month%10;
		if(month==1||month==3||month==5||month==7||month==8||month==2)
		n=1;
//		else
	//	n=2; 
		} 
    } 
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if(day<=31&&day>0)
        n=0;
    }
    if(month==4||month==6||month==9||month==11)
    {
        if(day<=30&&day>0)
        n=0;
    }
    else if(month==2)
    {
        if(day<=28&&day>0)
        n=0;
    }
    printf("%d",n);
}
