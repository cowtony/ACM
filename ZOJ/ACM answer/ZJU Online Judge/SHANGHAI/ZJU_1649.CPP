#include <stdio.h>
#include <string.h>

int n , m;
char g[201][201];
int x0 , y0;

void init()
{
	for(int i=0; i<n; i++)
	{
		scanf("%s" , g[i]);
	}
	for(x0=0; x0<n; x0++)
		for(y0=0; y0<m; y0++)
			if(g[x0][y0] == 'a') return;
}

struct point{
	short int x , y , len;
} Q[200 * 200 + 100];

int head , tail , cnt;

point tmp[200 * 200];
bool mark[201][201];
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void inq(int x , int y , int len)
{
	++tail;
	Q[tail].x = x;
	Q[tail].y = y;
	Q[tail].len = len;	
	mark[x][y] = 1;
}

inline bool valid(int x , int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void solve()
{
	head = tail = 0;
	Q[0].x = x0;  Q[0].y = y0; Q[0].len = 0;
	memset(mark , 0 , sizeof(mark)); mark[x0][y0] = 1;

	int cent = 0 , i;

	while(head <= tail)
	{
		cnt = 0;

		while(head <= tail && Q[head].len == cent)
		{			
			for(i=0; i<4; i++)
				if(valid(Q[head].x+dir[i][0],Q[head].y+dir[i][1]) && !mark[Q[head].x + dir[i][0]][Q[head].y + dir[i][1]])
				{
					if(g[Q[head].x + dir[i][0]][Q[head].y + dir[i][1]] == '#') continue;
					if(g[Q[head].x + dir[i][0]][Q[head].y + dir[i][1]] == '.') inq(Q[head].x + dir[i][0] , Q[head].y + dir[i][1] , cent + 1);
					else if(g[Q[head].x + dir[i][0]][Q[head].y + dir[i][1]] == 'r')
					{
						printf("%d\n" , cent + 1); return;
					}
					else{						
						tmp[cnt].x = Q[head].x + dir[i][0];
						tmp[cnt].y = Q[head].y + dir[i][1];
						cnt++;
					}
				}
			head ++;
		}
		cent++;
		for(i=0; i<cnt; i++)
			inq(tmp[i].x , tmp[i].y , cent + 1);
	}
	puts("Poor ANGEL has to stay in the prison all his life.");
}

int main()
{
//	freopen("in.txt",  "r" , stdin);

	while(scanf("%d%d" , &n , &m) > 0)
	{
		init();
		solve();
	}
	
	return 0;
}
