#include <stdio.h>

int main()
{
	int n;
	int left;
	int len;

	while(scanf("%d" , &n) > 0)
	{
		len = 1;
		left = 1 % n;
		while(left)
		{
			len++;
			left = (left * 10 + 1) % n;
		}
		printf("%d\n" , len);
	}

	return 0;
}