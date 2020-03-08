#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int n , m;
struct point
{
	double x , y;
} list[201];
double low[201];

inline double dist(const point& a , const point& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void init()
{
	int i;
	for(i=0; i<n; i++)
		scanf("%lf%lf" , &list[i].x , &list[i].y);
}

void solve()
{
	int i , k;
	double min , ans = 0 , t;

	for(i=1; i<n; i++) low[i] = dist(list[0] , list[i]);
	low[0] = -1;

	for(;;)
	{
		min = 1e20;
		for(i=1; i<n; i++)
			if(low[i] >= 0 && low[i] < min)
			{
				min = low[i];
				k = i;
			}
		if(min > ans) ans = min;
		if(k == 1)
		{
			printf("Frog Distance = %.3lf\n" , ans);
			break;
		}
		low[k] = -1;
		for(i=0; i<n; i++)
			if((t = dist(list[k] , list[i])) < low[i]) low[i] = t;
	}
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	int t = 0;

	while(1)
	{
		scanf("%d" , &n);
		if(!n) break;

		printf("Scenario #%d\n" , ++t);
		init();
		solve();
		putchar('\n');
	}

	return 0;
}