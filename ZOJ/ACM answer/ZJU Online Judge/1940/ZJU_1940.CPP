#include <stdio.h>
#include <string.h>

int n , m , p;
int x0 , y0 , z0;

char g[32][32][32];
struct node
{
	char x , y , z;
} Q[30 * 30 * 30 + 100];
short int dist[32][32][32];
int head , tail;

void init()
{
	int i , j , k;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			scanf("%s" , g[i][j]);		 
	}
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			for(k=0; k<p; k++)
				if(g[i][j][k] == 'S')
				{
					x0 = i; y0 = j; z0 = k;
				}
}

inline bool valid(char x , char y , char z)
{
	return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < p && g[x][y][z] != '#';
}

const char dir[6][3] =
{0,0,1 , 0,0,-1 , 0,1,0 , 0,-1,0 , 1,0,0 , -1,0,0};

bool push(char x , char y , char z , short int d)
{
	if(g[x][y][z] == 'E')
	{
		printf("Escaped in %d minute(s).\n" , d);
		return 1;
	}
	if(dist[x][y][z] < 0)
	{
		dist[x][y][z] = d;
		++tail;
		Q[tail].x = x;
		Q[tail].y = y;
		Q[tail].z = z;
	}
	return 0;
}

void solve()
{
	memset(dist , 0xff , sizeof(dist));
	head = 0 ; tail = -1;
	push(x0 , y0 , z0 , 0);

	int x , y , z , d , i;

	while(head <= tail)
	{
		x = Q[head].x; y = Q[head].y; z = Q[head].z; d = dist[x][y][z] + 1;		
		head++;
		for(i=0; i<6; i++)
		{
			if(valid(x+dir[i][0] , y+dir[i][1] , z+dir[i][2]))
			{
				if(push(x+dir[i][0] , y+dir[i][1] , z+dir[i][2] , d)) return;
			}
		}
	}
	puts("Trapped!");
}

int main()
{
//	freopen("in.txt" , "r" , stdin);		 
	while(1)
	{
		scanf("%d%d%d" , &n , &m , &p);
		if(n == 0) break;
		init();
		solve();
	}	
	return 0;
}
