#include <iostream>
using namespace std;

int main()
{
	double a[101];
	int i, j;
	int n, m;
	a[1] = 0;
	a[2] = 1.0;
	for(i=3; i<=100; i++)
	{
		a[i] = (double)(i-1) * ( a[i-1] + a[i-2]);
	}
	double ans;
	while(scanf("%d%d", &n, &m)!= EOF)
	{
		if(m==n) 
		{
			ans = 1.0;
			for(i=2; i<=n; i++)
			{
				ans /= (double)i;
			}
			printf("%.8lf\n", ans);
			continue;
		}
		else
		{
			ans = a[n-m];
			for(i=m; i>=2; i--)
			{
				ans /= (double)i;
			}
			for(i=n-m; i>=2; i--)
			{
				ans /= (double)i;
			}
		}
		printf("%.8lf\n", ans);
	}
	return 0;
}