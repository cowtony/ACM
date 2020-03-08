#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

int main()
{
	int n, m, k;
	int i, j;
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		deque <int> ans;
		double *a = new double [m];
		double *b = new double [m];
		double val;
		for(i=0; i<m; i++)
		{
			scanf("%lf", &a[i]);
			b[i] = a[i];
		}
		for(i=1; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%lf", &val);
				a[j] += val;
			}
		}
		for(i=0; i<m; i++)
			b[i] = a[i];
		sort(b, b+m);
		for(i=m-k; i<m; i++)
		{
			for(j=0; j<m; j++)
			{
				if(fabs(a[j] - b[i]) < 10e-6)
				{
					a[j] = -100000000;
					ans.push_back(j);
					break;
				}
			}
		}
		sort(ans.begin(), ans.end());
		for(i=ans.size()-1; i>=0; i--)
		{
			if(i==0) printf("%d\n", ans[i]+1);
			else printf("%d ", ans[i]+1);
		}
		delete [] a;
	}
	return 0;
}