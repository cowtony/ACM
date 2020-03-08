#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 100
#define inf 1000000000
double mat[MAXN][MAXN];

double prim(int n){
	double min[MAXN],ret=0;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[k][i];
	}
	return ret;
}

int main()
{
	double a[100][4];
	int i, j;
	int n;
	while(scanf("%d", &n) && n)
	{
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				mat[i][j] = inf;
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				mat[i][j] = mat[j][i] = sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1])* (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (a[i][2] - a[j][2])) - a[i][3] - a[j][3];
				if(mat[i][j] < 1e-6)
				{
					mat[i][j] = mat[j][i] = 0;
				}
			}
		}
		double ans = prim(n);
		printf("%.3lf\n", ans);
	}
	return 0;
}
