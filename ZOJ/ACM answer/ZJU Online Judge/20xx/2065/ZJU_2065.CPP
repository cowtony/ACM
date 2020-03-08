#include <stdio.h>
#include <string.h>

char g[20][30];
char buf[20];
int x0 , y0 , st;
int x1 , y1 , ed;

bool f[300][300];
bool visited[20][30];
int Q[300];
int dist[300];
int head , tail;

const int dir[6][2] = 
{0,-2 , 0,2 , 1,1 , -1,-1 , -1,1 , 1,-1};

void init()
{
	gets(buf);
	int i , j;	
	for(i=0; i<13; i++)
	{
		gets(g[i]);
	}
	for(i=0; i<13; i++)
	{
		for(j=0; j<20; j++)
		{
			if(g[i][j] == 'S')
			{
				x0 = i; y0 = j; st = i * 20 + j;
			}
			if(g[i][j] == 'E')
			{
				x1 = i; y1 = j; ed = i * 20 + j;
			}
		}
	}
}

inline bool valid(int x , int y)
{
	return x >= 0 && y >= 0;
}

inline bool empty(int x , int y)
{
	return g[x][y] == 'o' || g[x][y] == 'E' || g[x][y] == 'S';
}

int curt;

void step(int x , int y)
{
	for(int i=0; i<6; i++)
		if(valid(x + dir[i][0] , y + dir[i][1]) && empty(x + dir[i][0] , y + dir[i][1]))
		{
			f[curt][(x + dir[i][0])*20 + y + dir[i][1]] = 1;
		}
}

void skip(int x , int y)
{
	if(visited[x][y]) return;
	visited[x][y] = 1;
	f[curt][x*20 + y] = 1;

	for(int i=0; i<6; i++)
		if(valid(x + dir[i][0] * 2 , y + dir[i][1] * 2)
		&& (g[x + dir[i][0]][y + dir[i][1]] == '*')
		&& empty(x + dir[i][0]*2 , y + dir[i][1]*2))
		{
			skip(x + dir[i][0]*2 , y + dir[i][1]*2);
		}
}

void build()
{
	memset(f , 0 , sizeof(f));
	int i , j;
	for(i=0; i<13; i++)
	{
		for(j=0; j<20; j++)
			if(empty(i,j))
			{
				curt = i * 20 + j;
				step(i , j);
				memset(visited , 0 , sizeof(visited));
				skip(i , j);
			}
	}
}

void solve()
{
	int i , k;
	head = tail = 0; Q[0] = st;
	memset(dist , 0xff , sizeof(dist));
	dist[st] = 0;

	while(head <= tail)
	{
		k = Q[head++];
		for(i=0; i<300; i++)
			if(f[k][i] && dist[i] < 0)
			{
				Q[++tail] = i;
				dist[i] = dist[k] + 1;
			}
		if(dist[ed] >= 0) 
		{
			printf("%d steps.\n" , dist[ed]);
			return;
		}
	}

	puts("Impossible.");
}


int main()
{	
	//freopen("in.txt" , "r" , stdin);

	int T;
	scanf("%d" , &T);
	gets(buf);

	for(int t=1; t<=T; t++)
	{
		printf("Chessboard #%d:\n" , t);

		init();
		build();		
		solve();

		if(t < T) putchar('\n');
	}	
	
	return 0;
}
