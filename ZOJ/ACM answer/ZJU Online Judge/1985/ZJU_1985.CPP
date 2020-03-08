#include <stdio.h>
#include <string.h>

#define maxn 100010

int n;
double list[maxn];
int prev[maxn] , next[maxn];

void init()
{
	int i , key;
	for(i=1; i<=n; i++)
	{
		scanf("%d" , &key);
		list[i] = key;
	}
}

void predoing()
{
	int i , k;

	list[0] = list[n+1] = -1;
	prev[1] = 1;
	for(i=2; i<=n; i++)
	{
		if(list[i - 1] < list[i])
		{
			prev[i] = i;
		}
		else
		{
			k = i;
			while(list[k - 1] >= list[i])
			{
				k = prev[k - 1];
			}
			prev[i] = k;
		}
	}

	next[n] = n;
	for(i=n-1; i; i--)
	{
		if(list[i + 1] < list[i])
		{
			next[i] = i;
		}
		else
		{
			k = i;
			while(list[k + 1] >= list[i])
			{
				k = next[k + 1];
			}
			next[i] = k;
		}
	}
}

void solve()
{
	double max = 0;
	double tmp;
	int i;

	for(i=1; i<=n; i++)
	{
		tmp = list[i] * ((i + 1 - prev[i]) + (next[i] - i + 1) - 1);
		if(tmp > max) max = tmp;
	}

	printf("%0.lf\n" , max);
}


int main()
{
	while(scanf("%d" , &n) , n)
	{
		init();
		predoing();
		solve();
	}
	
	return 0;
}
