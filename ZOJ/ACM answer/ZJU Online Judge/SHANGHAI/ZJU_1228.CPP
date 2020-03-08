#include <stdio.h>
#include <string.h>
#include <time.h>

int n , k , m , n1;
int best;

char g[21][21];
short mark[21][21];

const char dir[4][2] = { {0,-1} ,{-1,0} , {0,1} ,   {1,0} };

void init()
{
	int i , j;
	for(i=0; i<n; i++)
		scanf("%s" , g[i]);

	memset(mark , 0xff , sizeof(mark));
	n1 = n - 1;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if( i + j < m || (n1 - i) + (n1 - j) < m ) mark[i][j] = 0;
}

inline bool valid(char x , char y)
{
	return (x >= 0) && (x < n) && (y >= 0) && (y < n);
}

bool color[650][2];
struct{
	char x , y;
	bool jump;
	short prev;
} Q[801];

short head , tail;

void gen_path(short lab , short path[] , short& len){
	len = 0;
	path[len++] = (Q[lab].x << 5) | Q[lab].y;
	char x0 , y0 , i , x1 , y1;

	x0 = Q[lab].x; y0 = Q[lab].y;
	lab = Q[lab].prev;

	while(lab >= 0){
		if(x0 == Q[lab].x){
			if(y0 < Q[lab].y) y1 = Q[lab].y;
			else y1 = y0 , y0 = Q[lab].y;
			for(i=y0+1; i<y1; i++)
				if(g[x0][i] == '.') path[len++] = (x0<<5)|i;
		}
		else{
			if(x0 < Q[lab].x) x1 = Q[lab].x;
			else x1 = x0 , x0 = Q[lab].x;
			for(i=x0+1; i<x1; i++)
				if(g[i][y0] == '.') path[len++] = (i<<5)|y0;
		}
		path[len++] = (Q[lab].x << 5) | Q[lab].y;
		x0 = Q[lab].x; y0 = Q[lab].y;
		lab = Q[lab].prev;
	}
}

bool find_path(short path[] , short& len)
{
	memset(color , 0 , sizeof(color));
	head = tail = 0;

	Q[0].x = Q[0].y = n1; Q[0].jump = 0; color[(n1<<5)|n1][0] = 1; Q[0].prev = -1;

	char i , j , x , y , x1 , y1;
	bool jump;

	while(head <= tail)
	{
		x = Q[head].x; y = Q[head].y; jump = Q[head].jump;
		
		for(i=0; i<4; i++){
			x1 = x + dir[i][0]; y1 = y + dir[i][1];
			if(!valid(x1 , y1) || g[x1][y1] != '.') continue;
			if(!color[(x1<<5)|y1][jump]){
				color[(x1<<5)|y1][jump] = 1;
				++tail;
				Q[tail].prev = head; Q[tail].x = x1; Q[tail].y = y1; Q[tail].jump = jump;
				if(x1 == 0 && y1 == 0){
					gen_path(tail , path , len);
					return 1;
				}
			}
		}		
		
		if(!jump)
		{
			for(i=0; i<4; i++)
			{
				x1 = x + dir[i][0]; y1 = y + dir[i][1];
				if(!valid(x1,y1)  || g[x1][y1] == '*' ) continue;
				for(j=1; j<k; j++){
					x1 += dir[i][0]; y1 += dir[i][1];
					if(!valid(x1,y1) || g[x1][y1] == '*') break;
					if(g[x1][y1] == '.' && !color[(x1<<5)|y1][0] && !color[(x1<<5)|y1][1]){
						color[(x1<<5)|y1][1] = 1;
						++tail;
						Q[tail].prev = head; Q[tail].x = x1; Q[tail].y = y1; Q[tail].jump = 1;
						if(x1 == 0 && y1 == 0){
							gen_path(tail , path , len);
							return 1;
						}
					}
				}
			}
		}

		head ++;
	}

	return 0;
}

void solve(short cost)
{
	if(cost >= best) return;

	short path[401];
	short len;

	if(! find_path(path , len) ) best = cost;
	else
	{		
		cost ++;
		short i;
		for(i=len-1; i>=0; i--)
			if(mark[path[i] >> 5][path[i] & 31] < 0){
				mark[path[i] >> 5][path[i] & 31] = cost;
				g[path[i] >> 5][path[i] & 31] = '*';
				solve(cost);
				g[path[i] >> 5][path[i] & 31] = '.';
			}
			
		for(i=0; i<len; i++)
			if(mark[path[i] >> 5][path[i] & 31] == cost) 
				mark[path[i] >> 5][path[i] & 31] = -1;
	}	
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(1)
	{
		scanf("%d %d %d" , &n , &k , &m);
		if(n == 0) break;

		init();

		best = 1000;
		solve(0);

		if(best == 1000) best = -1;
		printf("%d\n" , best);
	}

//	printf("Run Time :   %.3fs\n" , clock()/(float)CLK_TCK);
	
	return 0;
}
