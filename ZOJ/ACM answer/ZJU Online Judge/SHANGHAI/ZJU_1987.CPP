#include <stdio.h>
#include <string.h>

int g[40][2];
int deg[40] , c[40];
int bits[1<<9];
int m;

void doit_first()
{
	int i , j;
	for(i=0; i<(1<<9); i++)
	{
		bits[i] = 0;
		for(j=0; j<9; j++)
			if(i & (1<<j)) bits[i]++;
	}
}

void init()
{
	int a , b; 

	scanf("%d" , &m);
	memset(deg , 0 , sizeof(deg));
	memset(g , 0 , sizeof(g));

	for(int i=0; i<m; i++)
	{
		scanf("%d %d" , &a , &b);
		a-- , b--;
		if(g[a][b/18] ^ (1<<(b%18))) deg[a]++;
		g[a][b/18] |= (1<<(b%18));
	}
}

inline int count_bit(int k)
{
	return bits[k >> 9] + bits[k & ((1<<9)-1)];
}

int max;

bool search(int k , int s0 , int s1 , int got)
{	
	if(count_bit(s0) + count_bit(s1) <= max) return 0;
	if(got > max){ max = got ; return 1; }
	if(k == 36) return 0;
	if(got + c[k] <= max) return 0;
	if(deg[k] <= max) return search(k + 1 , s0 , s1 , got);	
	
	if(search(k + 1 , s0 & g[k][0] , s1 & g[k][1] , got + 1)) return 1;
	return search(k + 1 , s0 , s1 , got);
}

void solve()
{
	if(m == 0)
	{
		puts("0");
		return;
	}

	int i;

	c[36] = 1; max = 1;
	for(i=35; i>=0; i--)
	{
		c[i] = 36;
		search(i , (1<<18)-1 , (1<<18)-1 , 0);
		c[i] = max;
	}

	printf("%d\n" , max);	
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	doit_first();

	int T;
	scanf("%d" , &T);

	while(T--)
	{
		init();
		solve();
	}
	
	return 0;
}
