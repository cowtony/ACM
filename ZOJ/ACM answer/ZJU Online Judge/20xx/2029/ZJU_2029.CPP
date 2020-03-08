#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , m;
int list[1000];

int cmp(const void* a , const void* b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i , k , a;
	while(scanf("%d%d" , &n , &m) > 0)
	{
		for(i=0; i<n; i++)
			scanf("%d" , list + i);
		qsort((void *)list , n , sizeof(int) , cmp);

		while(m--)
		{
			scanf("%d" , &k);
			a = -1;
			for(i=0; i<n-1; i++)
				if(list[i] <= k && list[i+1] > k)
				{
					if(a < 0 || list[i+1] - list[i] < list[a+1] - list[a])
						a = i;
				}
			if(a >= 0) printf("[%d,%d)\n" , list[a] , list[a+1]);
			else puts("no such interval");
		}
		putchar('\n');

	}
	
	return 0;
}
