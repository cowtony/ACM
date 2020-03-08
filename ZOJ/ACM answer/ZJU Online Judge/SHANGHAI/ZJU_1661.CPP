#include <stdio.h>
#include <string.h>

int n;
char s[30];
int c[30];
int f[210];

void init()
{
	int i , j;

	memset(c , 0 , sizeof(c));
	for(i=0; i<5; i++)
	{
		scanf("%s" , s);
		for(j=0; j<n; j++)
			c[j] = (c[j] << 1) | (s[j] == 'X');
	}
}

int best;

void search(int u , int cnt)
{
	if(u >= best) return;
	if(cnt == 10)
	{
		best = u;
		return;
	}	
	int i , j;
	for(i=u-n+1; i<u; i++)
	{
		for(j=0; j<n; j++)
		{
			if(f[i+j] & c[j]) break;
			f[i+j] |= c[j];
		}
		if(j==n) search(i + n , cnt + 1);
		for(j--; j>=0; j--)
		{
			f[i+j] ^= (c[j]);
		}
	}
}

void solve()
{
	best = 10 * n;

	memset(f , 0 , sizeof(f));

	search(n-1 , 0);

	printf("%d\n" , best);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	while(scanf("%d" , &n) , n)
	{
		init();
		solve();
	}
	
	return 0;
}
