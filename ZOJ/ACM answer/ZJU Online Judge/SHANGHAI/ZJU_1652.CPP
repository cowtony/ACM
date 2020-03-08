#include <stdio.h>
#include <string.h>

int n;

__int64 ret;

int main()
{
	int i , k;
	while(scanf("%d" , &n) > 0)
	{
		ret = 1;
		for(i=k=1; k<=n; k++)
		{
			ret += i;
			i++;
			ret += 2 * i;
			i+=2;
		}

		ret -= 4 * n;
		printf("%I64d\n" , ret);
	}
	
	return 0;
}

/////////////////////////////////////

#include <stdio.h>
#include <string.h>

int n;

long long ret;

int main()
{
	int i , k;
	while(scanf("%d" , &n) > 0)
	{
		ret = 1;
		for(i=k=1; k<=n; k++)
		{
			ret += i;
			i++;
			ret += 2 * i;
			i+=2;
		}

		ret -= 4 * n;
		printf("%lld\n" , ret);
	}
	
	return 0;
}
