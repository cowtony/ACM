#include<stdio.h>
#include<string.h>
int n;
int s[1010],w[1010],id[1010],a[1010],from[1010];
int main()
{
//	freopen("1108.in","r",stdin);
	n = 0;
	while (scanf("%d%d",&w[n],&s[n])!=EOF)
	{
		n++;
	}
	int i,j,k,max;
	for (i=0; i<n; i++) 
	{
		from[i] = -1;
		id[i] = i;
	}
	for (i=0; i<n; i++)
		for (j=0; j<i; j++)
		{
			if (w[j]>w[i] || (w[j]==w[i] && s[j]<s[i]))   //w increasing && s decreasing
			{
				k = id[i];
				id[i] = id[j];
				id[j] = k;
				k = w[j];
				w[j] = w[i];
				w[i] = k;
				k = s[i];
				s[i] = s[j];
				s[j] = k;
			}
		}
	memset(a,0,sizeof(a));
	a[0] = 1;
	for (i=1; i<n; i++)
	{
		max = 0;
		for (j=0; j<i; j++)
		{
			if (w[j]<w[i] && s[j]>s[i])
			{
				if (max<a[j])
				{
					max = a[j];
					k = j;
				}
			}
		}
		a[i] = max+1;
		if (max>0)  from[i] = k;
	}
	max = 0;
	for (i=0; i<n; i++)
		if (max<a[i])
		{
//			a[i] = max;
			max=a[i];
			k = i;
		}
	n = 0;
	while (true)
	{
		s[n] = id[k]+1;
		n++;
		k = from[k];
		if (k==-1) break;
	}
	printf("%d\n",n);
	for (i=n-1; i>=0; i--)
		printf("%d\n",s[i]);
	return 0;
}