#include <cstdio>
#include <cstring>

const int maxn = 1010;

int n;
int list[maxn];
int f[maxn];

void init()
{
	scanf("%d" , &n);
	for(int i=0; i<n; i++)
		scanf("%d" , &list[i]);
}

void solve()
{
	int i , j;
	int ret = 1;
	for(i=0; i<n; i++)
	{
		f[i] = 1;
		for(j=0; j<i; j++)
			if(list[j] < list[i] && f[j] + 1 > f[i]) f[i] = f[j] + 1;
		if(f[i] > ret) ret = f[i];
	}
	printf("%d\n" , ret);
}

int main()
{
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		init();
		solve();
		if(T) putchar('\n');
	}

	return 0;
}