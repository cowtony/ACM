#include <iostream>
using namespace std;

int main()
{
	int a[50000];
	int sum[50000];
	int i, j;
	int cas;
	int n;
	int pos;
	scanf("%d", &cas);
	while(cas--)
	{
		int max = 0;
		scanf("%d", &n);
		scanf("%d", &a[0]);
		for(i=1; i<n; i++)
		{
			scanf("%d", &a[i]);
			a[i] += a[i-1];
		}
		scanf("%d", &pos);
		int maxin = n - pos +1;
		sum[0] = a[pos-1];
		int right = pos;
		int left = 0;
		for(i=1; i<maxin; i++)
		{
			sum[i] = a[right++] - a[left++];
		}
		int leftindex = 0;
		int maxleft = 0;
		for(i=pos; i<maxin; i++, leftindex++)
		{
			int total = 0;
			if(sum[leftindex] > maxleft) 
			{
				maxleft = sum[leftindex];
			}
			total += (maxleft+sum[i]);
			int maxright = 0;
			for(j=i+pos; j<maxin; j++)
			{
				if(sum[j] > maxright) maxright = sum[j];
			}
			if(total + maxright > max) max = total + maxright;
		}
		printf("%d\n", max);
	}
	return 0;
}