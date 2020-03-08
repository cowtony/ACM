#include <stdio.h>
#include <string.h>

long long n;

int main()
{
	long long p;
	while(scanf("%lld" , &n) > 0)
	{
		p = 1;
		while(1)
		{
			p *= 9;
			if(p >= n) 
			{
				puts("Stan wins.");
				break;
			}
			p *= 2;
			if(p >= n)
			{
				puts("Ollie wins.");
				break;
			}
		}
	}
	
	return 0;
}
