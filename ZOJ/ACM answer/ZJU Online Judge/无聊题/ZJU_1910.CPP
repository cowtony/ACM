#include <stdio.h>

int n;

void calc()
{
	int min , k , tmp , p , q;
	min = 100000000;
	for(k=1; k*k<=n; k++)
		if(n % k ==	0)
		{
			tmp = n / k;
			for(p=1; p*p<=tmp; p++)
				if(tmp % p == 0)
				{
					q = tmp / p;
					if((p*q+p*k+q*k)*2 < min) min = (p*q+p*k+q*k)*2;
				}
		}
	printf("%d\n" , min);
}

int main()
{
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		scanf("%d" , &n);
		calc();
	}

	return 0;
}