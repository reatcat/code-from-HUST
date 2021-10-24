#include<stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100000
int main()
{
	char c;
	int score[MAX];//={0};
	int W=0,L=0;//分别存储两人的得分 
	int i=0;//用i来统计比赛的局数 
//	while((c=getchar())!='E')
//	{
//		if(c=='\n')
//		continue;
//		else{
//		i++;
//		if(c=='W')
//		score[i]=1;
//		else score[i]=-1; 
//		}
//		
//	}
	for(i=1;cin>>c&&c!='E';i++)//循环读入，当读到字符E结束 
	{
		if(c=='W') score[i]=1; 
		else score[i]=2; 
	}
//11分 
	for(i=1;1;i++)
	{
		if(score[i]==1) W++;
		if(score[i]==-1) L++;
		if(score[i]==0)//读到0则记录结束，输出记录结束前的分数
		{
		printf("%d:%d\n\n",W,L);
		break; 
		}//如果局数没有超过直接输出 
		if(W-L>=2||L-W>=2)//当比赛的局数超过的时候，重新判断 
		if(W>=11||L>=11)//当双方比分相差大于2且一方分数大等于11输出 
			{
				printf("%d:%d\n",W,L);
				W=0;L=0;
			}
	}
//21分
	W=0;
	L=0;
	 for(i=1;1;i++)
	{
		if(score[i]==1) W++;
		if(score[i]==-1) L++;
		if(score[i]==0)//读到0则记录结束，输出记录结束前的分数
		{
		printf("%d:%d",W,L);
		break; 
		}//如果局数没有超过直接输出 
		//当比赛的局数超过的时候，重新判断 
		if(W-L>=2||L-W>=2)
		if(W>=21||L>=21)//当双方比分相差大于2且一方分数大等于21输出 
			{
				printf("%d:%d\n",W,L);
				W=0;L=0;
			}
	}
	return 0;
 } 
