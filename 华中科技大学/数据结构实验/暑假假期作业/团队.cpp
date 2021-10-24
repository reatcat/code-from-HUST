#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,team[1000001],ans;
char ch[20];
int main()
{
    while(1)
    {
        ans++;
        int state=0;
        queue<int>Q;
        queue<int>q[1001];
        scanf("%d",&n);
        if(n==0)
        return 0;
        for(int i=1;i<=n;i++)
        {
            int num;
            scanf("%d",&num);
            for(int j=1;j<=num;j++)
            {
                int k;
                scanf("%d",&k);
                team[k]=i;
            }
        }
        while(1)
        {
        	scanf("%s",ch);
            int num;
            if(ch[0]=='E')
            {
                scanf("%d",&num);
                if(q[team[num]].empty())
                {
                    Q.push(team[num]);
                    q[team[num]].push(num);
                }
                else
                q[team[num]].push(num);
            }
            if(ch[0]=='D')
            {
                if(state==0){
                	printf("Scenario #%d\n",ans);
					state=1;
				}
                    while(q[Q.front()].empty())
                    {
                    	Q.pop();
					}
                    printf("%d\n",q[Q.front()].front());
                    q[Q.front()].pop();
            }
            if(ch[0]=='S')
            {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
