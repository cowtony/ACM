#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
struct rect
{
	double x1 , y1 , x2 , y2;
} list[110];

double lx[210] , ly[210];
int cx , cy;
bool g[200][200];

void init()
{
	int i;
	double x , y , r;

	cx = cy = 0;

	for(i=0; i<n; i++)
	{
		scanf("%lf%lf%lf" , &x , &y , &r);
		list[i].x1 = x - r;
		lx[cx++] = list[i].x1;
		list[i].y1 = y - r; ly[cy++] = list[i].y1;
		list[i].x2 = x + r; lx[cx++] = list[i].x2;
		list[i].y2 = y + r; ly[cy++] = list[i].y2;
	}
}

int cmp(const void* a , const void* b)
{
	if(*(double *)a == *(double *)b) return 0;
	if(*(double *)a < *(double *)b) return -1; else return 1;
}

void dipe(double l[] , int& c)
{
	qsort((void *)l , c , sizeof(double) , cmp);
	int i , cc = 1;
	for(i=1; i<c; i++)
	{
		if(l[i] == l[i-1]) continue;
		l[cc++] = l[i];
	}
	c = cc;
}

int b_search(double l[] , int c , const double& key)
{
	int p , r , m;
	p = 0; r = c - 1;
	while(p <= r)
	{
		m = (p + r) >> 1;
		if(l[m] == key) return m;
		if(l[m] < key) p = m + 1;
		else r = m - 1;
	}	
}

void solve()
{
	memset(g , 0 , sizeof(g));
	int p , i , j , px , rx , py , ry;
	for(p=0; p<n; p++)
	{
		px = b_search(lx , cx , list[p].x1);
		rx = b_search(lx , cx , list[p].x2);

		py = b_search(ly , cy , list[p].y1);
		ry = b_search(ly , cy , list[p].y2);

		for(i=px; i<rx; i++)
			for(j=py; j<ry; j++)
				g[i][j] = 1;	
	}

	double ret = 0;
	for(i=0; i<cx; i++)
		for(j=0; j<cy; j++)
			if(g[i][j])
				ret += (lx[i+1]-lx[i]) * (ly[j+1] - ly[j]);

	printf("%.2lf\n" , ret);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	int caseno = 0;

	while(scanf("%d" , &n) , n)
	{
		init();
		dipe(lx , cx);
		dipe(ly , cy);

		printf("%d " , ++caseno);

		solve();
	}
	
	return 0;
}
