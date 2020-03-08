#include <stdio.h>
#include <string.h>

int n , m;
int dieta[110][110];

void init()
{
	scanf("%d%d" , &n , &m);
	for(int i=0; i<n; i++)
		scanf("%d" , &dieta[0][i]);
}

void solve()
{
	int i , j;
	for(i=1; i<n; i++)
	{
		for(j=0; j<n-i; j++)
			dieta[i][j] = dieta[i-1][j] - dieta[i-1][j+1];
	}
	for(i=0; i<m; i++)
	{
		dieta[n-1][i+1] = dieta[n-1][i];
		for(j=n-2; j>=0; j--)
		{
			dieta[j][i+n-j] = dieta[j][i+n-j-1] - dieta[j+1][i+n-j-1];
		}	
		if(i) putchar(' ');
		printf("%d" , dieta[0][n+i]);
	}
	putchar('\n');
}

int main()
{
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		init();
		solve();
	}

	return 0;
}
