#include <stdio.h>
#include <string.h>

int n;
typedef char graph[10][10];
graph st;
const int dir[8][2] = {{1,0} , {-1,0} , {0,1} , {0,-1} , {1,1} , {1,-1} , {-1,1} , {-1,-1}};
void init()
{
	scanf("%d" , &n);
	char buf[10];
	gets(buf);

	int i;
	for(i=0; i<8; i++)
		gets(st[i]);	
}

int best;
inline char opp(char ch)
{
	if(ch == 'B') return 'W';
	else return 'B';
}

void count(graph g)
{
	int i , j;
	int cnt = 0;
	for(i=0; i<8; i++)
		for(j=0; j<8; j++)
			if (g[i][j] == 'B') cnt++;
			else if (g[i][j] == 'W') cnt--;
	if(cnt > best) best = cnt;
}

inline bool valid(int x , int y)
{
	return 0 <= x && x < 8 && 0 <= y && y < 8;
}

bool test(int x , int y , graph g0 , char op , graph g)
{
	memcpy(g , g0 , sizeof(graph));
	g[x][y] = op;

	bool modify = 0;
	int p , i , j , c;

	for(p=0; p<8; p++)
	{
		i = x , j = y; c = 0;
		while(1)
		{
			i += dir[p][0]; j += dir[p][1];
			if(!valid(i , j)) break;

			if(g[i][j] == ' ') break;
			if(g[i][j] != op) c++;
			if(g[i][j] == op)
			{
				if(c > 0)
				{
					modify = 1;
					while(i != x || j != y)
					{
						g[i][j] = op;
						i -= dir[p][0]; j -= dir[p][1];
					}
				}

				break;
			}
		}
	}
		
	return modify;
}

void search(int k , char op , graph g)
{
	if(k == 0)
	{
		count(g);
		return;
	}
	
	graph curr;
	int i , j;
	bool step = 0;

	for(i=0; i<8; i++)
		for(j=0; j<8; j++)
		{
			if(g[i][j] != ' ') continue;
			if(test(i , j , g , op , curr))
			{
				step = 1;
				search(k - 1 , opp(op) , curr);
			}			
		}	
	if(step == 0) search(k - 1 , opp(op) , g);
}

void solve()
{
	best = - 64;
	search(n , 'B' , st);
	printf("%d\n" , best);
}

int main(){
//	freopen("in.txt" , "r" , stdin);
	
	int T;
	scanf("%d" , &T);
	
	while(T--)
	{
		init();
		solve();
	}
	
	return 0;
}
