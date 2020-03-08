#include <stdio.h>
#include <string.h>

int n , m;

double g[101][101];
int v[101];

void init()
{
	int i , j;
	double k;
	for(i=0; i<n-1; i++)
	{
		scanf("%d" , v + i);
	}
	memset(g , 0 , sizeof(g));
	while(m--)
	{
		scanf("%d%d" , &i , &j); i-- , j--;
		scanf("%lf" , &k);
		k = (1 - k);
		if(k > g[i][j])
		{
			g[i][j] = g[j][i] = k;
		}
	}	
}

double low[101];
bool inq[101];

void solve()
{
	memset(low , 0 , sizeof(low));
	memset(inq , 0 , sizeof(inq));

	inq[n-1] = 1; low[n-1] = 1;

	int i , j;
	bool modify;

	while(1)
	{
		modify = 0;

		for(i=0; i<n; i++)
			if(inq[i])
			{
				for(j=0; j<n; j++)
					if(low[i] * g[i][j] > low[j])
					{
						low[j] = low[i] * g[i][j];
						inq[j] = 1;
						modify = 1;
					}
				inq[i] = 0;
			}

		if(!modify) break;
	}

	double ret = 0;
	for(i=0; i<n-1; i++)
		ret += low[i] * v[i];
	printf("%.2lf\n" , ret);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%d%d" ,&n , &m) > 0)
	{
		init();
		solve();
	}
	
	return 0;
}
