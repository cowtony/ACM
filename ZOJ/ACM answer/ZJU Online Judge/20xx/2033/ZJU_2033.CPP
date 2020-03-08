#include <stdio.h>
#include <string.h>

int n , m;
int g[11][11];
int t[11][11];
int x0 , y0 , V , L;

void init()
{
	int i , j , k;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d" , &g[i][j]);

	memset(t , 0xff , sizeof(t));
	scanf("%d" , &k);
	while(k--)
	{
		scanf("%d%d" , &i , &j);
		i-- , j--;
		scanf("%d" , &t[i][j]);
	}
	
	scanf("%d%d%d%d" , &x0 , &y0 , &V , &L);
	x0-- , y0--;
}

inline bool valid(int x , int y)
{
	return x >= 0 && x < n  && y >= 0 && y < m;
}

int best;
int route[10];
int mark[11][11];
const int dir[4][2] = { {1,0} , {-1,0} , {0,1} , {0,-1} };


void search(int x , int y , int time)
{
	if(t[x][y] > 0 && time % t[x][y] == 0) return;

	if(!mark[x][y])	route[time] = g[x][y];
	else route[time] = 0;

	mark[x][y]++; time++;
	if(time - 1 == L)
	{
		int stat , sum , i;
		for(stat=(1<<time)-1 ; stat > 0; stat--)
		{
			sum = 0;
			for(i=0; i<time; i++)
				if(stat & (1<<i)) sum += route[i];
			if(sum <= V && sum > best) best = sum;
		}
		mark[x][y] --;
		return ;		
	}
	
	
	for(int i=0; i<4; i++)
	{
		if(valid(x + dir[i][0] , y + dir[i][1]))
			search(x + dir[i][0] , y + dir[i][1] , time);
	}

	search(x , y , time);

	mark[x][y]--;
}

void solve()
{
	best = 0;
	memset(mark , 0 , sizeof(mark));
	search(x0 , y0 , 0);
	printf("%d\n" , best);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	
	while(scanf("%d%d" , &n , &m) > 0)
	{
		init();
		solve();
	}
	return 0;
}
