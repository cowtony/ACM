#include <iostream>

int a[11][11];
bool visit[11];
int n;

bool dfs(int v,int count)
{
	if(count==n&&a[v][0]) return true;
	for(int i=1;i<=n;i++)
	{
		if(!visit[i]&&a[v][i])
		{
			visit[i]=true;
			if(dfs(i,count+1)) return true;
			visit[i]=false;
		}
	}
	return false;
}

int main()
{
	int i,j;
	char c;
	int temp=1;
	while(scanf("%d%*c",&n))
	{
		if(!n) break;
		memset(a,0,sizeof(a));
		memset(visit,false,sizeof(visit));
		for(i=1;i<=n;i++)
		{
			while(scanf("%c",&c))
			{
				if(c=='\n') break;
				if(c>='0'&&c<='9')
				{
					a[i][c-48]=a[c-48][i]=1;
				}
			}
		}
		visit[0]=true;
		if(dfs(0,0)) printf("Case %d: Granny can make the circuit.\n",temp++);
		else printf("Case %d: Granny can not make the circuit.\n",temp++);
	}
	return 0;
}
