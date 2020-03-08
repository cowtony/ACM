#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
struct info
{
	int w , s , idx;
} list[1010];
int f[1010] , prev[1010] , route[1010];

void init()
{
	n = 0;
	while(scanf("%d%d" , &list[n].w , &list[n].s)  > 0)
	{
		list[n].idx = n + 1;
		n++;		
	}
}

int cmp(const void* a , const void* b)
{
	return ((info*)a)->w - ((info*)b)->w;
}

void solve()
{
	qsort((void*)list , n , sizeof(info) , cmp);
	int i , j , k;
	f[0] = 1; prev[0] = -1; k = 0;

	for(i=1; i<n; i++)
	{
		f[i] = 1; prev[i] = -1;
		for(j=0; j<i; j++)
			if(list[i].w > list[j].w && list[i].s < list[j].s)
			{
				if(f[j] + 1 > f[i])
				{
					f[i] = f[j] + 1;
					prev[i] = j;
				}
			}
		if(f[i] > f[k]) k = i;
	}

	printf("%d\n" , f[k]);
	int c = 0;
	while(k >= 0)
	{
		route[++c] = list[k].idx;
		k = prev[k];
	}
	while(c)
	{
		printf("%d\n" , route[c]);
		c--;
	}
}

int main()
{
	freopen("in.txt" , "r" , stdin);

	init();
	solve();
	
	return 0;
}
