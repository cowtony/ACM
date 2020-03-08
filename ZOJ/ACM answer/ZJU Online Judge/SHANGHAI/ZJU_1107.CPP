#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , k , c;
int g[101][101];
struct point
{
	char x , y;
} list[10010];
int f[10010];
int lab[101][101];

int cmp(const void* a , const void* b)
{
	return g[((point*)a)->x][((point*)a)->y] - 
		   g[((point*)b)->x][((point*)b)->y];
}

void init()
{
	int i , j;
	c = 0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			scanf("%d" , &g[i][j]);
			list[c].x = i;
			list[c].y = j;
			c++;
		}
	qsort((void*)list , c , sizeof(point) , cmp);
}

const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

inline bool valid(int x , int y)
{
	return (x >= 0) && (x < n) && (y >= 0) && (y < n);
}

void solve()
{
	int i , j , p;
	int x , y;
	for(i=0; i<c; i++)
	{
		f[i] = -100000000;
		lab[list[i].x][list[i].y] = i;
	}
	f[lab[0][0]] = 0;

	int max = 0;

	for(i=lab[0][0]; i<c; i++)
	{
		f[i] += g[list[i].x][list[i].y];
		if(max < f[i]) max = f[i];
		for(j=1; j<=k; j++)
			for(p=0; p<4; p++)
			{
				x = list[i].x + j * dir[p][0];
				y = list[i].y + j * dir[p][1];

				if(valid(x , y) && g[x][y] > g[list[i].x][list[i].y])
				{
					if(f[i] > f[lab[x][y]]) f[lab[x][y]] = f[i];
				}
			}
	}

	printf("%d\n" , max);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	while(1)
	{
		scanf("%d%d" , &n , &k);
		if(n < 0) break;
		init();
		solve();
	}

	
	return 0;
}
