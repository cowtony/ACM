#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , k;
struct node
{
	short int father , indeg , outdeg , depth , idx;
} list[110];
short int pos[110];

void init()
{
	int i;
	int a , b;
	memset(list , 0 , sizeof(list));

	for(i=1; i<n; i++)
	{
		scanf("%d%d" , &a , &b);
		a-- , b--;
		list[a].father = b;
		list[a].indeg++;
		list[b].outdeg++;
	}
}

void build()
{
	int i;
	for(i=0; i<n; i++)
	{
		if(list[i].indeg == 0)
		{
			list[i].father = n;
			list[i].depth = 1;
		}
		list[i].idx = i;
	}

	bool modify = 1;
	while(modify)
	{
		modify = 0;
		for(i=0; i<n; i++)
		{
			if(list[i].depth == 0 && list[list[i].father].depth > 0)
			{
				modify = 1;
				list[i].depth = list[list[i].father].depth + 1;
			}
		}
	}
}

int cmp(const void* a , const void* b)
{
	return - ((node*)a)->depth + ((node*)b)->depth;
}

void solve()
{
	int cnt;	
	int i , less , pk;

	qsort((void *)list , n , sizeof(node) , cmp);
	for(i=0; i<n; i++)
		pos[list[i].idx] = i;

	for(cnt=0, less = n; less; cnt++)
	{
		pk = k;
		for(i=0; i<n && pk; i++)
			if(list[i].outdeg == 0)
			{
				pk--;
				less--;
				list[pos[list[i].father]].outdeg --;
				if(list[pos[list[i].father]].outdeg == 0) list[pos[list[i].father]].outdeg = -1;
				list[i].outdeg = -2;
			}
		for(i=0; i<n; i++)
			if(list[i].outdeg == -1) list[i].outdeg = 0;
	}
	printf("%d\n" , cnt);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	while(scanf("%d%d" , &n , &k) , n)
	{
		init();
		build();
		solve();
	}

	return 0;
}