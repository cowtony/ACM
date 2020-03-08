#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 100100

int n , m;
struct point
{
	int x , y;
	int nx , ny;
} list[maxn];

void init()
{
	scanf("%d%d" , &n , &m);
	
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d%d" , &list[i].y , &list[i].x);
		list[i].nx = list[i].x + list[i].y;
		list[i].ny = list[i].y - list[i].x;
	}
}

int cmp(const void* a , const void* b)
{
	return ((point*)a)->nx - ((point*)b)->nx;
}

bool check(int h)
{
	int level;
	int p = 0;
	int cnt = 0;
	int x;

	while(p < n)
	{
		cnt++;		
		x = list[p].nx - h;
		level = h - x;
		while(p < n && list[p].ny >= level) p++;
	}
	return cnt <= m;
}

void solve()
{
	qsort((void*)list , n , sizeof(point) , cmp);

	int p , r , m , i;

	p = -3000000;
	r = 3000000;

	for(i=0; i<n; i++)
	{
		if(list[i].y < r) r = list[i].y;
	}

	r ++;
	
	while(p + 1 < r) // [ p , r )
	{
		m = (p + r) / 2;
		if(check(m)) p = m;
		else r = m;
	}

	printf("%d\n" , p);
}

int main()
{
	freopen("in.txt" , "r" , stdin);

	int T , t;
	scanf("%d" , &T);

	for(t=1; t<=T; t++)
	{
		printf("Case %d: " , t);
		init();
		solve();
	}

	return 0;
}