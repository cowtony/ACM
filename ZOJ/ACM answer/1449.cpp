#include <iostream>
using namespace std;

int main()
{
	int a[20][20][20];
	int sum[20][20][20];
	int b[20][20];
	int summ[20][20];
	int c[20];
	int n, i, j, k, l, lx;
	int temp;
	int max;
	while(scanf("%d",&n) && n)
	{
		max = -100000000;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				temp = 0;
				for(k=0; k<n; k++)
				{
					scanf("%d", &a[i][j][k]);
					temp += a[i][j][k];
					sum[i][j][k] = temp;
				}
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=i; j<n; j++)
			{
				for(k=0; k<n; k++)
				{
					temp = 0;
					for(l=0; l<n; l++)
					{
						b[k][l] = sum[l][k][j] - sum[l][k][i] + a[l][k][i];
						temp += b[k][l];
						summ[k][l] = temp;
					}
				}
				for(k=0; k<n; k++)
				{
					for(l=k; l<n; l++)
					{
						for(lx=0; lx<n; lx++)
						{
							c[lx] = summ[lx][l] - summ[lx][k] + b[lx][k];
						}
						int minsum = 0;
						int cusum = 0;
						for(lx=0; lx<n; lx++)
						{
							cusum += c[lx];
							if(cusum - minsum > max) max = cusum - minsum;
							if(cusum < minsum) minsum = cusum;
						}
					}
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
