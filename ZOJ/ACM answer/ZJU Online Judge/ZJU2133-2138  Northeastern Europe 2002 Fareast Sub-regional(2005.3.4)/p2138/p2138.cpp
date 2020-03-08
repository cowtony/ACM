#include <cstdio>
#include <cstring>

const int maxp = 110;

int n , p;
int line[maxp];
int cnt[maxp];

void solve()
{
	scanf("%d%d" , &n , &p);
	
	int i , j;
	int min , max;

	memset(cnt , 0 , sizeof(cnt));

	for(i=0; i<n; i++)
	{
		min = 1010; max = -1;
		for(j=0; j<p; j++)
		{
			scanf("%d" , &line[j]);
			if(line[j] > max) max = line[j];
			if(line[j] < min) min = line[j];
		}

		for(j=0; j<p; j++)
		{
			if(line[j] == max) cnt[j] -= n;
			if(line[j] == min) cnt[j]++;
		}
	}

	int k = n / 2 + 1;
	bool found = 0;

	for(i=0; i<p; i++)
	{
		if(cnt[i] >= k)
		{
			if(found) putchar(' '); else found = 1;
			printf("%d" , i + 1);
		}
	}
	if(!found) printf("%d" , 0);
	putchar('\n');
}

int main()
{
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		solve();
		if(T) putchar('\n');
	}
	return 0;
}