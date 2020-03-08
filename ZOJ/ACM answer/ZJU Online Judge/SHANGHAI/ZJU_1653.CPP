#include <stdio.h>
#include <string.h>

int n , k;
int best , pipe[10];
int curr[10];
short f[1000];

int dp(int p)
{
	int i , j;
	f[0] = 0;

	for(i=1; ; i++)
	{
		f[i] = 100;
		for(j=0; j<p; j++)
		{
			if(i >= curr[j] && f[i - curr[j]] + 1 < f[i])
			{
				f[i] = f[i - curr[j]] + 1;
			}
		}
		if(f[i] > n) return i;
	}
}

void search(int prev , int p)
{
	int limit = dp(p);
	if(p == k)
	{
		limit --;
		if(limit > best)
		{
			best = limit;
			memcpy(pipe , curr , sizeof(pipe));
		}
		return;
	}

	for(int i=prev; i<=limit; i++)
	{
		curr[p] = i;
		search(i , p + 1);
	}
}

void solve()
{
	best = 0;

	search(0 , 0);

	printf("%d\n" , best);
	for(int i=0; i<k-1; i++)
		printf("%d " , pipe[i]);
	printf("%d\n" , pipe[k-1]);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	int T;
	scanf("%d" , &T);

	while(T--)
	{
		scanf("%d%d"  , &n , &k);
		k /= 100;

		if(n == 0 || k == 0) puts("sorry");
		else solve();
	}
	
	return 0;
}
