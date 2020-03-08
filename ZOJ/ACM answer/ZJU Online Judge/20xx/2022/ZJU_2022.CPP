#include <stdio.h>

int main()
{	
	int n , ret;
	int T;

	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		ret = 0;
		while(n)
		{
			ret += n / 5;
			n /= 5;
		}
		printf("%d\n" , ret);
	}
	
	
	return 0;
}
