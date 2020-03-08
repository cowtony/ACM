#include <stdio.h>
#include <string.h>

#define max_node 1250

int n , m , X , Y;
char g[51][51];
int lx[51][51];
int ly[51][51];
bool G[max_node][max_node];
 
void init()
{
	scanf("%d%d" , &n , &m);
	for(int i=0; i<n; i++)
		scanf("%s" , g[i]);
}

void build()
{
	memset(lx , 0xff , sizeof(lx));
	memset(ly , 0xff , sizeof(ly));
	X = 0;

	int i , j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(g[i][j] == 'o')
			{
				for(;j<m;j++)
				{
					if(g[i][j] == '#') break;
					lx[i][j] = X;
				}
				X++;
			}
		}
	}

	Y = 0;
	for(j=0; j<m; j++)
	{
		for(i=0; i<n; i++)
			if(g[i][j] == 'o')
			{
				for(;i<n;i++)
				{
					if(g[i][j] == '#') break;
					ly[i][j] = Y;
				}
				Y++;
			}
	}

	memset(G , 0 , sizeof(G));
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(g[i][j] == 'o')
				G[lx[i][j]][ly[i][j]] = 1;

/*
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			printf("%3d " , lx[i][j]);
		putchar('\n');
	}
	putchar('\n');
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			printf("%3d " , ly[i][j]);
		putchar('\n');
	}
*/
}

int cx[max_node] , cy[max_node];
bool visited[max_node];

int path(int u)
{
	for(int i=0; i<Y; i++)
		if(G[u][i] && !visited[i])
		{
			visited[i] = 1;
			if(cy[i] < 0 || path(cy[i]))
			{
				cx[u] = i; cy[i] = u;
				return 1;
			}
		}
	return 0;
}

void solve()
{
	memset(cx , 0xff , sizeof(cx));
	memset(cy , 0xff , sizeof(cy));

	int ret = 0;
	for(int i=0; i<X; i++)
		if(cx[i] < 0)
		{
			memset(visited , 0 , sizeof(visited));
			ret += path(i);
		}

	printf("%d\n" , ret);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	int T , t;
	scanf("%d" , &T);
	for(t=1; t<=T; t++)
	{
		init();
		build();
		printf("Case :%d\n" , t);
		solve();
	}
		
	return 0;
}
