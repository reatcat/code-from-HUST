#include<stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100000
int main()
{
	char c;
	int score[MAX];//={0};
	int W=0,L=0;//�ֱ�洢���˵ĵ÷� 
	int i=0;//��i��ͳ�Ʊ����ľ��� 
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
	for(i=1;cin>>c&&c!='E';i++)//ѭ�����룬�������ַ�E���� 
	{
		if(c=='W') score[i]=1; 
		else score[i]=2; 
	}
//11�� 
	for(i=1;1;i++)
	{
		if(score[i]==1) W++;
		if(score[i]==-1) L++;
		if(score[i]==0)//����0���¼�����������¼����ǰ�ķ���
		{
		printf("%d:%d\n\n",W,L);
		break; 
		}//�������û�г���ֱ����� 
		if(W-L>=2||L-W>=2)//�������ľ���������ʱ�������ж� 
		if(W>=11||L>=11)//��˫���ȷ�������2��һ�����������11��� 
			{
				printf("%d:%d\n",W,L);
				W=0;L=0;
			}
	}
//21��
	W=0;
	L=0;
	 for(i=1;1;i++)
	{
		if(score[i]==1) W++;
		if(score[i]==-1) L++;
		if(score[i]==0)//����0���¼�����������¼����ǰ�ķ���
		{
		printf("%d:%d",W,L);
		break; 
		}//�������û�г���ֱ����� 
		//�������ľ���������ʱ�������ж� 
		if(W-L>=2||L-W>=2)
		if(W>=21||L>=21)//��˫���ȷ�������2��һ�����������21��� 
			{
				printf("%d:%d\n",W,L);
				W=0;L=0;
			}
	}
	return 0;
 } 
