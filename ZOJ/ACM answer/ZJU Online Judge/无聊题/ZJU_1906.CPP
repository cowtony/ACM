#include <stdio.h>

int n;

int phi(int k)
{
	double ret = k;
	int m = 2;
	while(m * m <= k)
	{
		if(k % m == 0)
		{
			ret *= (1 - 1.0 / m);
			while(k % m == 0) k/=m;
		}
		m++;
	}
	if(k>1) ret *= (1 - 1.0 / k);
	return ret;
}

int main()
{
	while(scanf("%d" , &n) , n)
	{
		printf("%d\n" , phi(n));
	}
}