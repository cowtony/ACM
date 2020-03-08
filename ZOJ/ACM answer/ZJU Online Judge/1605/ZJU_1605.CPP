#include <stdio.h>
#include <string.h>

#define maxn 2001
int n , m;
char g[maxn][maxn];
short enter[maxn] , father[maxn] , low[maxn];

void init()
{
	int a , b , c;
	memset(g , 0 , 2001 * n);

	while(m--)
	{
		scanf("%d%d%d" , &a , &b , &c);
		a-- , b--;
		if(c == 1)
		{
			g[a][b] = 1;
		}
		else 
		{
			g[a][b] = g[b][a] = 2;
		}
	}
}

int time;

void dfs(int u)
{	
	enter[u] = ++time;
	low[u] = enter[u];

	for(int i=0; i<n; i++)
		if(g[u][i] && i != father[u])
		{
			if(!enter[i])
			{
				father[i] = u;
				dfs(i);
			}
			low[u] = low[u] < low[i] ? low[u] : low[i];
		}
}

void solve()
{
	memset(enter , 0 , sizeof(short) * n);

	time = 0;
	father[0] = -1;
	dfs(0);

	int i , j;
	for(i=1; i<n; i++)
	{
		//Judge a bridge
		if(g[father[i]][i] == 1) continue;
		if(low[i] > enter[father[i]])
		{
			printf("%d %d 2\n" , father[i] + 1 , i + 1);
		}
		else
		{
			printf("%d %d 1\n" , father[i] + 1 , i + 1);
		}
		g[father[i]][i] = g[i][father[i]] = 0;
	}

	for(i=1; i<n; i++)
		for(j=0; j<n; j++)
			if(g[i][j] == 2 && enter[i] > enter[j])
			{
				printf("%d %d 1\n" , i + 1 , j + 1);
			}
}

int main()
{
	//freopen("in.txt" , "r" , stdin);

	while(scanf("%d%d" , &n , &m) > 0)
	{
		init();
		solve();
	}

	return 0;
}