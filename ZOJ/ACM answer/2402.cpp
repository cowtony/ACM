#include <iostream>
using namespace std;

int main()
{
	int cas;
	int n, m;
	int i, j, k, l;
	double accu;
	double arr[21][2001];
	scanf("%d", &cas);
	for(i=0; i<cas; i++)
	{
		scanf("%d%d", &n, &m);
		for(j=1; j<=m; j++)
			arr[1][j] = (double)j;
		for(j=2; j<=n; j++)
		{
			for(k=1; k<=m; k++)
			{
				accu = 0;
				for(l=2; l<=k; l++)
				{
					accu += arr[j-1][l/2];
				}
				arr[j][k] = accu;
			}
		}
		printf("Case %d: n = %d, m = %d, # lists = %.0lf\n", i+1, n, m, arr[n][m]);
	}
	return 0;
}