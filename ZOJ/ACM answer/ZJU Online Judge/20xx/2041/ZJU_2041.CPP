#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , k , t;
struct person
{
	int t , p , s;
} list[110];
int f[110];

void init()
{
	scanf("%d%d%d" , &n , &k , &t);
	int i;
	for(i=1; i<=n; i++)
		scanf("%d" , &list[i].t);
	for(i=1; i<=n; i++)
		scanf("%d" , &list[i].p);
	for(i=1; i<=n; i++)
		scanf("%d" , &list[i].s);
	list[0].t = list[0].p = list[0].s = 0;
}

int cmp(const void* a , const void* b)
{
	return ((person*)a)->t - ((person*)b)->t;
}

void solve()
{
	qsort((void *)(list + 1) , n , sizeof(person) , cmp);
	int i , j , max;
	memset(f , 0 , sizeof(f));
	max = 0;

	for(i=1; i<=n; i++)
	{
		f[i] = -1;
		for(j=0; j<i; j++)
			if(f[j] >= 0 && list[i].t - list[j].t >= abs(list[i].s - list[j].s))
			{
				if(f[j] + list[i].p > f[i]) f[i] = f[j] + list[i].p;
			}
		if(f[i] > max) max = f[i];
	}
	
	printf("%d\n" , max);
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		init();
		solve();
		if(T) putchar('\n');
	}
	
	return 0;
}
