#include <stdio.h>
int win[62503]; 
int W,L;
int i;
int main()
{
	char c;
	while((c=getchar())!='E')
	{
		if(c=='\n')
		continue;
		else{
		i++;
		if(c=='W')
		win[i]=1;
		else win[i]=2; 
		}
		
	}
	//----------------11分制 ----------------
	for(i=1;1;i++)
	{
		if(win[i]==1)W++;//胜场+1 
		if(win[i]==2)L++;//负场+1 
		if(win[i]==0)//读到0则记录结束，输出记录结束前的分数。 
		{
			printf("%d:%d\n\n",W,L);
			break;
		}
		if(W-L>=2||L-W>=2)
			if(W>=11||L>=11)//当双方比分相差大于2且一方分数大等于11输出 
			{
				printf("%d:%d\n",W,L);
				W=0;//比分清零 
				L=0;
			}
	}
	W=0;//清零，为21分制计算做准备 
	L=0;
	//----------------21分制 ----------------
	for(i=1;1;i++)
	{
		if(win[i]==1)W++;//胜场+1 
		if(win[i]==2)L++;//负场+1 
		if(win[i]==0)//读到0则记录结束，输出记录结束前的分数。 
		{
			printf("%d:%d",W,L);
			break;
		}
		if(W-L>=2||L-W>=2)
			if(W>=21||L>=21)//当双方比分相差大于2且一方分数大等于11输出 
			{
				printf("%d:%d\n",W,L);
				W=0;//比分清零 
				L=0;
			}
	}
	return 0;//华丽地结束  ㄟ(▔▽▔)ㄏ
} 
