#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define maxn 10001
#define EPS 1e-10

const double pi = acos(0) * 2;

int n , m;
struct point
{
	double x , y;
} list[maxn];
struct p2
{
	double v;
	int w;
} f[maxn * 4];

void init()
{
	for(int i=0; i<n; i++)
	{
		scanf("%lf%lf" , &list[i].x , &list[i].y);
	}
	list[n] = list[0];
}

void calc_segment(const point& a , const point& b)
{
	double A = atan2(a.y , a.x) * 180 / pi;
	double B = atan2(b.y , b.x) * 180 / pi;

	if(A < 0) A+= 360;
	if(B < 0) B+= 360;

	if(A > B)
	{
		double tmp = A;
		A = B;
		B = tmp;
	}

	if(A + 180 < B)
	{
		f[m].v = 0;	f[m].w = 1; m++;
		f[m].v = 360; f[m].w = -1; m++;
		f[m].v = A; f[m].w = -1; m++;
		f[m].v = B; f[m].w = 1; m++;		
	}
	else
	{
		f[m].v = A; f[m].w = 1; m++;
		f[m].v = B; f[m].w = -1; m++;
	}
}

int p2_cmp(const void* a , const void* b)
{
	p2 A = *(p2*)a;
	p2 B = *(p2*)b;
	
	if(fabs(A.v - B.v) <= EPS) return B.w - A.w;
	if(A.v < B.v) return -1;
	return 1;
}

void solve()
{
	int i;
	m = 0;
	for(i=0; i<n; i++)
	{
		calc_segment(list[i] , list[i + 1]);
	}

	qsort((void *)f , m , sizeof(p2) , p2_cmp);
	int cnt , max;
	cnt = max = 0;
	
	for(i=0; i<m; i++)
	{
		cnt += f[i].w;
		max = max > cnt ? max : cnt;
	}

	printf("%d\n" , max);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	
	while(scanf("%d" , &n) > 0)
	{
		init();
		solve();
	}

	return 0;
}