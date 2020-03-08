#include <stdio.h>
#include <string.h>

int n;
int g[7][7];
bool deg[7] , app[7];
int lab[7];

void init()
{
	scanf("%d" , &n);
	memset(g , 0 , sizeof(g));
	memset(deg , 0 , sizeof(deg));
	memset(app , 0 ,sizeof(app));

	int a , b;

	while(n--)
	{
		scanf("%d%d" , &a , &b);
		a-- , b--;
		g[a][b] = g[b][a] = 1;
		deg[a] ^= 1;
		deg[b] ^= 1;
		app[a] = app[b] = 1;
	}
}

int time;

void dfs(int u)
{
	lab[u] = time;
	for(int i=0; i<6; i++)
		if(g[u][i] && !lab[i]) dfs(i);
}

int best;
int p[40][2] , ans[40][2] , cp , cans;
int tmp;
bool mark[7];

void visit(int u)
{
	mark[u] = 1;
	for(int i=0; i<6; i++)
		if(g[u][i] && !mark[i]) visit(i);
}

bool judge_connect()
{
	memset(mark , 0 , sizeof(mark));
	int i;
	for(i=0; i<6; i++) 
	if(app[i])
	{
		visit(i); break;
	}
	for(; i<6; i++) if(app[i]&&!mark[i]) return 0;
	return 1;
}

void search(int k , int cost)
{
	if(cost >= best) return;
	if(k >= time)
	{		
		if(!judge_connect()) return;
		int i,a,ccp = cp;
		a = -1;
		for(i=0; i<6; i++)
			if(deg[i])
			{
				if(a < 0) a = i;
				else 
				{
					p[cp][0] = a+1; p[cp][1] = i+1; cp++;
					cost += a+1+i+1;
					a = -1;
				}
			}
		if(cp > ccp)
		{
			cp--;
			cost -= (p[cp][0] + p[cp][1]);
		}

		if(cost < best)
		{
			best = cost;
			cans = cp;
			memcpy(ans , p , sizeof(p));
		}

		cp = ccp;

		return;
	}
	int i , j;
	for(i=0; i<6; i++)
		if(lab[i] == k)
		for(j=0; j<6; j++)
			if(app[j] && lab[j] != k)
			{
				p[cp][0] = i + 1; p[cp][1] = j + 1; cp++;
				deg[i] ^= 1; deg[j] ^= 1;
				g[i][j]++,g[j][i]++;
				search(k + 1 , cost + i + j + 2);
				g[i][j]--,g[j][i]--;
				cp--;
				deg[i] ^= 1; deg[j] ^= 1;
			}
}

void solve()
{
	int i;
	memset(lab , 0 , sizeof(lab));
	for(i=time=0; i<6; i++)
		if(app[i] & !lab[i]) ++time,dfs(i);
	
	best = 100000000;
	cp = 0;
	search(1,0);
//	if(best == 100000000) best = 0;
	printf("%d\n%d\n" , best , cans);
	for(i=0; i<cans; i++)
	{
		printf("%d %d\n" , ans[i][0] , ans[i][1]);
	}
}

int main()
{
//	freopen("in.txt" ,"r" , stdin);
	int T , t;

	scanf("%d" , &T);
	for(t=0; t<T; t++)
	{
		if(t) putchar('\n');
		init();
		solve();
	}
	
	return 0;
}
