#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m , n;
struct str
{
	char s[100];
	int k , idx;
} list[110];

void init()
{
	scanf("%d%d" , &m , &n);
	for(int i=0; i<n; i++) scanf("%s" , list[i].s);
}

int cmp(const void* a , const void* b)
{
	if( ((str*)a)->k != ((str*)b)->k ) return ((str*)a)->k - ((str*)b)->k;
	return ((str*)a)->idx - ((str*)b)->idx;
}

void solve()
{
	int i , j , k;
	for(k=0; k<n; k++)
	{
		list[k].k = 0;
		for(i=0; i<m; i++)
			for(j=i+1; j<m; j++)
				if(list[k].s[j] < list[k].s[i]) list[k].k++;
		list[k].idx = k;
	}

	qsort((void *)list , n , sizeof(str) , cmp);

	for(i=0; i<n; i++)
		printf("%s\n" , list[i].s);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	int T;
	scanf("%d" , &T);
	bool first = 1;

	while(T--)
	{
		if (first) first = 0; else putchar('\n');
		init();
		solve();
	}
	
	return 0;
}
