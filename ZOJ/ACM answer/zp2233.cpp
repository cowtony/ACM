#include<iostream.h>
#include <stdio.h>

long a[101][101],b[101],in[101],sum[101],n,i1,i,k,l,j,x,y,m,t;
double result[101],sumw[101],w[101];
void doit(long p)
{
	long j;
	for (j=1;j<=n;j++)
	{
		if (a[j][p]==1&&in[j]==0)
		{
			sum[k]+=b[j]; sumw[k]+=w[j];
			in[j]=k;
			doit(j);
		}
	}
}

int main()
{
	cin>>t;
	for (i1=1;i1<=t;i1++)
	{
		cin>>n>>m;
		for (i=1;i<=n;i++)
			cin>>w[i];
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				a[i][j]=0;
		for (i=1;i<=m;i++)
		{
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		for (i=1;i<=n;i++)
		{
			b[i]=0;
			for (j=1;j<=n;j++)
			{
				if (i!=j&&a[i][j]==1)
					b[i]++;
			}
		}
		for (i=1;i<=n;i++)
			in[i]=0;
		k=0;
		for(i=1;i<=n;i++)
		{
			k++;sum[k]=0;sumw[k]=0;
			if (in[i]==0)
			{
				sum[k]+=b[i];sumw[k]+=w[i];
				in[i]=k;
				doit(i);
			}
		}

		for (l=1;l<=k;l++)
		{
			for (i=1;i<=n;i++)
			{
				if (in[i]==l)
				{
					if (sum[l]==0)
						result[i]=sumw[i];
					else
            result[i]=double(b[i])/sum[l]*sumw[l];
				}
			}
		}
		for(i=1;i<=n;i++)
			printf("%0.3f\n",result[i]);
		printf("\n");
	}
	return 0;
}

